#include "rrt/rrt.h"
#include <ros/console.h>

rrgraph::Graph g = rrgraph::Graph();
kdtree *kd = kd_create(3);


float distance(Vector3 v1, Vector3 v2)
{
    Vector3 res = v1 - v2;
    return sqrt(pow(res(0),2) + pow(res(1),2) + pow(res(2),2));
}

Vector3Array rrt::get_vertices()
{
    return g.vertices;
}


std::vector<std::pair<Vector3, Vector3>> rrt::get_edges()
{
    return g.edges;
}

void rrt::clear_tree()
{
    // TODO : clear the kd_tree as well
    g.clearGraph();
    kd_clear(kd);
}


Vector3 rrt::random_state(Vector3 minvals, Vector3 maxvals)
{
    //ROS_INFO("RRT : Random State");
    // minvals and maxvals are of the form (x_min, y_min, z_min) and (x_max, y_max, z_max) respectively.
    return sampler::sample_state(minvals, maxvals);
}


Vector3 rrt::nearest_neighbour(Vector3 x_rand)
{
    double pos[3];
    //This needs to be freed.
    auto res = kd_nearest_range3f(kd,x_rand(0), x_rand(1), x_rand(2), 10);
    //ROS_INFO("KDTree : Result");
    if (kd_res_size(res) > 1)
    {
        // taking only 1 nearest neighbour returns the same point if the point 
        // is already in the vertice set
        kd_res_next(res); 
        auto pch = (char*)kd_res_item( res, pos );
        kd_res_free(res);
        //ROS_INFO("KDTree : Next Result");
    }
    else
    {
        auto pch = (char*)kd_res_item( res, pos );
        kd_res_free(res);
    }
    
    
    return Vector3(pos[0], pos[1], pos[2]);

}

Vector3Array rrt::select_node(const Vector3 mins, const Vector3 maxs)
{
    Vector3Array res;
    Vector3 x_rand = random_state(mins, maxs);
    //ROS_INFO("RRT : Random Sample Obtained");
    Vector3 x_near = nearest_neighbour(x_rand);
    //ROS_INFO("RRT : Nearest Neighbour Obtained");
    res.push_back(x_rand);
    res.push_back(x_near);
    return res;
}


Vector3 rrt::new_node(Vector3 x_rand, Vector3 x_near)
{
    bool reachable = false;

    float dist_max = 1; // hardcoding the max dist limit for now

    if (distance(x_rand, x_near) < dist_max)
        return x_rand;
    
    auto delta_y = x_rand(1) - x_near(1);
    auto delta_x = x_rand(0) - x_near(0);
    auto yaw =  atan2(delta_y,delta_x);

    auto new_x = x_near(0) + (dist_max * cos(yaw));
    auto new_y = x_near(1) + (dist_max * sin(yaw));

    // TODO : add reachablity check ( obstacle checks)
    // also bounds checks to enforce the new point is within the map

    return Vector3(new_x,new_y,x_near(2));

}


void rrt::extend(Vector3 x_rand, Vector3 x_near)
{
    Vector3 x_new = new_node(x_rand, x_near);
    // TODO : add conectivity checks here
    assert(kd_insert3(kd, x_new(0), x_new(1), x_new(2), 0) == 0);
    g.addVertex(x_new);
    g.addEdge(x_near, x_new);

}

/////////////  higher  abstractions  ///////////////



void rrt::init_rrt(Vector3 x_init)
{
    //ROS_INFO("RRT : Init Begin");
    assert(kd_insert3(kd, x_init(0), x_init(1), x_init(2), 0) == 0);
    g.addVertex(x_init); // any other attributes of the node can be added here
    //ROS_INFO("RRT : Initialized");
}


void rrt::step_rrt(Vector3 mins, Vector3 maxs)
{
    //ROS_INFO("RRT : Selecting node");
    Vector3Array res_nodes = select_node(mins, maxs);
    //ROS_INFO("RRT : Node Selected");
    extend(res_nodes[0], res_nodes[1]);
    //return g;  to be used optionally on recieving end
}

