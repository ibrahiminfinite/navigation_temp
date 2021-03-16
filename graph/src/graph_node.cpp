#include "graph/graph_node.h"

  rrgraph::Graph::Graph()
  {
    ROS_INFO("Graph Created");
  }


  void rrgraph::Graph::addVertex(Vertex v)
  {
    vertices.push_back(v);
    ROS_INFO("Vertex added ");
  }


  void rrgraph::Graph::addEdge(Vertex src, Vertex dst)
  {
    edges.push_back(Edge(src,dst));
    ROS_INFO("Edge added ");
  }

  bool rrgraph::Graph::hasVertex(Vertex v)
  {
    return std::find(vertices.begin(), vertices.end(), v) != vertices.end();
  }

  //returns the number of vertices
  int rrgraph::Graph::getNumVertices()
  {
    return vertices.size();
  }

  void rrgraph::Graph::clearGraph()
  {
    vertices.clear();
    edges.clear();
  }