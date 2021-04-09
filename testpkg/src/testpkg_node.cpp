#include <ros/ros.h>
#include "rrt/rrt.h"
#include <ros/console.h>
#include "visualizer/visualizer.h"


int main(int argc, char** argv)
{

    ros::init (argc, argv, "rrt_base_node");
    ros::NodeHandle nh;
    visualizer::Visualizer sampleViz(nh); 

    //Graph Testing
    auto v1 = Vector3(-10.0f,-10.0f,0.0f);
    auto v2 = Vector3(10.0f,10.0f,0.0f);


    //RRT Testing    
    // rrt::random_state(v1, v2);
    // rrt::init_rrt(Vector3(0.0f,0.0f,0.0f));
    // for (int i = 0; i < 50; i++)
    //     rrt::step_rrt(v1, v2);


    //ROS_INFO("Spinning node");
    ros::Rate loop_rate(1);
    // Vector3Array points;

    int iter_count;

    while(ros::ok())
    {
        
        rrt::clear_tree();
        // points.clear();
        iter_count = 1;
        rrt::init_rrt(Vector3(0.0f,0.0f,0.0f));
        for(int i =0; i <50; i++)
        {
            ROS_INFO("Iteration %d",iter_count);
            iter_count++;

            // points.push_back(rrt::random_state(v1,v2));
            rrt::step_rrt(v1, v2);
            sampleViz.publish_graph(rrt::get_vertices(), rrt::get_edges());
            loop_rate.sleep();
            

        }

        // sampleViz.publish_points(points);
        // sampleViz.publish_graph(rrt::get_vertices(), rrt::get_edges());
        loop_rate.sleep();
        // std::cin. get();
        ros::spinOnce();

    }
}

