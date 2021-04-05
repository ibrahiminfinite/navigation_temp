
#include "visualizer/visualizer.h"

namespace visualizer
{

Visualizer::Visualizer(const ros::NodeHandle& nh):nh_(nh)
{
    //ROS_INFO(" Visualizer Class Initialized..");
    samplePointsPub = nh_.advertise<visualization_msgs::Marker>("sampled_points", 10);
    graphPub = nh_.advertise<visualization_msgs::Marker>("rrt_graph", 10);
}

void Visualizer::publish_points(Vertices samples)
{
    //Clear the points array for saftey
    SamplePointsMarker.points.clear();
    SamplePointsMarker.header.frame_id = "/map";
    SamplePointsMarker.header.stamp = ros::Time::now();
    SamplePointsMarker.action = visualization_msgs::Marker::ADD;
    SamplePointsMarker.pose.orientation.w = 1.0;
    SamplePointsMarker.id = 0;
    SamplePointsMarker.lifetime = ros::Duration(1.0);

    // Set type of marker
    SamplePointsMarker.type = visualization_msgs::Marker::POINTS;
    SamplePointsMarker.scale.x = 0.2;
    SamplePointsMarker.scale.y = 0.2;
    SamplePointsMarker.color.g = 1.0f;
    SamplePointsMarker.color.a = 1.0;

    BOOST_FOREACH (const Vertex& pt, samples)
    {
        // Add each point from sample to the marker points
        // The "points" attribute is of type geometry_msgs::Points
        geometry_msgs::Point p;
        p.x = pt(0);
        p.y = pt(1);
        p.z = pt(2);
        SamplePointsMarker.points.push_back(p);
    }    
    samplePointsPub.publish(SamplePointsMarker);
}


void Visualizer::publish_graph(Vertices vertices, Edges edges)
{
    GraphMarker.points.clear();
    //when there are no edges, dont try to publish, this gives seg fault
    if (edges.size() < 1 ) 
    {
        //ROS_INFO("NO EDGES !!!!");
        return;
    }
    
    GraphMarker.header.frame_id = "/map";
    GraphMarker.header.stamp = ros::Time::now();
    GraphMarker.action = visualization_msgs::Marker::ADD;
    GraphMarker.pose.orientation.w = 1.0;
    GraphMarker.id = 1;
    GraphMarker.lifetime = ros::Duration(2.0);

    // Set type of marker
    GraphMarker.type = visualization_msgs::Marker::LINE_LIST;
    GraphMarker.scale.x = .005;
    GraphMarker.color.b = 1.0f;
    GraphMarker.color.a = 1.0;

    edges.erase(edges.end());
    BOOST_FOREACH (auto e, edges)
    {
        // Add each point from sample to the marker points
        // The "points" attribute is of type geometry_msgs::Points
        geometry_msgs::Point p1,p2;
        // std::cout<<e.first<<"\n"<<e.second<<"\n";
        p1.x = e.first(0);
        p1.y = e.first(1);
        p1.z = e.first(2);
        p2.x = e.second(0);
        p2.y = e.second(1);
        p2.z = e.second(2);
    
        GraphMarker.points.push_back(p1);
        GraphMarker.points.push_back(p2);
    }
    

    graphPub.publish(GraphMarker);

}
 
}