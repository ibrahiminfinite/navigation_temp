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
    auto v1 = Vector3(-50.0f,-50.0f,-50.0f);
    auto v2 = Vector3(50.0f,50.0f,50.0f);


    //RRT Testing    
    // rrt::random_state(v1, v2);
    rrt::init_rrt(v1);
    // for (int i = 0; i < 50; i++)
    //     rrt::step_rrt(v1, v2);


    ROS_INFO("Spinning node");
    ros::Rate loop_rate(0.5);
    Vector3Array points;
    while(ros::ok())
    {
        
        rrt::clear_tree();
        points.clear();
        for(int i =0; i <1000; i++)
        {
            // points.push_back(rrt::random_state(v1,v2));
            rrt::step_rrt(v1, v2);
        }
        // sampleViz.publish_points(points);
        sampleViz.publish_graph(rrt::get_vertices(), rrt::get_edges());
        ros::spinOnce();
        loop_rate.sleep();
    }
}

