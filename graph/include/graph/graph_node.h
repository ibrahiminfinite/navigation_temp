#include <ros/ros.h>
#include <vector>
#include <algorithm>
#include <Eigen/Dense>


typedef Eigen::Vector3f Vertex;
typedef std::vector<Vertex> VertexList;

typedef std::pair<Vertex, Vertex> Edge;
typedef std::vector<Edge> EdgeList;


namespace graph
{

class Graph
{
  
  public:
    Graph() {ROS_INFO("Graph Created");}
    VertexList vertices;
    EdgeList edges;

    void addVertex(Vertex v)
    {
      vertices.push_back(v);
      ROS_INFO("Vertex added ");
    }

    void addEdge(Vertex src, Vertex dst)
    {
      edges.push_back(Edge(src,dst));
      ROS_INFO("Edge added ");
    }

    bool hasVertex(Vertex v)
    {
      return std::find(vertices.begin(), vertices.end(), v) != vertices.end();
    }

    //returns the number of vertices
    int getNumVertices()
    {
      return vertices.size();
    }

    void clearGraph()
    {
      vertices.clear();
      edges.clear();
    }

};

}