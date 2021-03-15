#include "sampler/sampler_node.h"

Vector3 sampler::sample_state(Vector3 minvals, Vector3 maxvals)
{
    std::mt19937 generator(device());
    std::vector<std::uniform_real_distribution<float>> uniform_pds;
    
    for(int i = 0; i < current_pos.size(); i++)
    {
        sample(i)=std::uniform_real_distribution<float>(minvals(i),maxvals(i))(generator);
    }
    std::cout<<"Sample State Pass\n";
    return sample;
}


Vector3 sampler::sample_state_n(Vector3 minvals, Vector3 maxvals, int num_samples)
{
    Vector3Array samples;
    for (int i = 0; i < num_samples; i++)
    {
        samples.push_back(sampler::sample_state(minvals, maxvals));
    }
    std::cout<<"Sample State N Pass\n";
}