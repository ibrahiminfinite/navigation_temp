#include <ros/ros.h>
#include "sampler/sampler_node.h"
#include "graph/graph_node.h"


int main()
{
    
    // Sampler Testing
    sampler::sample_state(Vector3(0.0f,0.0f,0.0f), Vector3(0.0f,0.0f,0.0f));
    sampler::sample_state_n(Vector3(-10.0f,-10.0f,-10.0f), Vector3(10.0f,10.0f,10.0f), 2);


    //Graph Testing
    auto g = graph::Graph();
    g.addVertex(Vector3(0.0f,0.0f,0.0f));

    return 0;
}