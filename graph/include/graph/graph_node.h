#include <ros/ros.h>
#include <vector>
#include <algorithm>
#include <Eigen/Dense>


typedef Eigen::Vector3f Vertex;
typedef std::vector<Vertex> VertexList;

typedef std::pair<Vertex, Vertex> Edge;
typedef std::vector<Edge> EdgeList;


namespace rrgraph
{

class Graph
{
  
  public:
    Graph();
    VertexList vertices;
    EdgeList edges;

    void addVertex(Vertex v);

    void addEdge(Vertex src, Vertex dst);

    bool hasVertex(Vertex v);

    //returns the number of vertices
    int getNumVertices();

    void clearGraph();

};

}