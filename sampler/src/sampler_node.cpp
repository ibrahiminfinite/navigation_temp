#include "sampler/sampler_node.h"

Vector3 sampler::sample_state(Vector3 minvals, Vector3 maxvals)
{
    
    for(int i = 0; i < current_pos.size(); i++)
    {
        // does this create a new distribution object every time ?
        sample(i)=std::uniform_real_distribution<float>(minvals(i),maxvals(i))(generator);
    }
    //ROS_INFO("Sampler : Samping random state");
    return sample;
}


Vector3 sampler::sample_state_n(Vector3 minvals, Vector3 maxvals, int num_samples)
{
    Vector3Array samples;
    for (int i = 0; i < num_samples; i++)
    {
        samples.push_back(sampler::sample_state(minvals, maxvals));
    }
    //ROS_INFO("Sampler : Sample N random states");
}