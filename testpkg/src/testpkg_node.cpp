#include <ros/ros.h>
#include "rrt/rrt.h"


int main()
{
    
    //Graph Testing
    auto v1 = Vector3(-10.0f,-10.0f,-10.0f);
    auto v2 = Vector3(10.0f,10.0f,10.0f);


    // //RRT Testing
    
    std::cout<<rrt::random_state(v1, v2)<<"\n";
    rrt::init_rrt(v1);
    return 0;
}

