/** Author : V Mohammed Ibrahim
 * Utilities for visualizing various components of the navigation system
 * */

#include <ros/ros.h>
#include <Eigen/Dense>
#include <boost/foreach.hpp>
#include <visualization_msgs/Marker.h>

typedef std::vector<Eigen::Vector3f> Vertices;
typedef Eigen::Vector3f Vertex;
typedef std::pair<Vertex, Vertex> Edge;
typedef std::vector<Edge> Edges;

namespace visualizer
{
    class Visualizer
    {
 
        private:
            visualization_msgs::Marker SamplePointsMarker, GraphMarker;
            ros::NodeHandle nh_;
            ros::Publisher samplePointsPub;
            ros::Publisher graphPub;

        public:

            Visualizer();
            void publish_points(Vertices samples);
            void publish_graph(Vertices vertices, Edges edges);

    };

}
