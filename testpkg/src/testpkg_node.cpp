#include <ros/ros.h>
#include "sampler/sampler_node.h"
// #include "graph/graph_node.h"
#include "rrt/rrt.h"
#include "kdtree/kdtree.h"

int main()
{
    
    // Sampler Testing
    sampler::sample_state(Vector3(0.0f,0.0f,0.0f), Vector3(0.0f,0.0f,0.0f));
    sampler::sample_state_n(Vector3(-10.0f,-10.0f,-10.0f), Vector3(10.0f,10.0f,10.0f), 2);


    //Graph Testing
    // auto g = graph::Graph();
    // auto v1 = Vector3(0.0f,0.0f,0.0f);
    // auto v2 = Vector3(3.0f,3.0f,3.0f);
    // g.addVertex(v1);
    // g.addVertex(v2);
    // g.addEdge(v1, v2);
    // std::cout<<g.hasVertex(v1)<<"\n";


    //RRT Testing
    // rrt::init_rrt(v1);

    return 0;
}

