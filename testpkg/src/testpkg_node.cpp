#include <ros/ros.h>
#include "rrt/rrt.h"
#include <ros/console.h>

int main()
{

    // if (ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME, ros::console::levels::Debug))
    // {
    //     ros::console::notifyLoggerLevelsChanged();
    // }


    //Graph Testing
    auto v1 = Vector3(-10.0f,-10.0f,-10.0f);
    auto v2 = Vector3(10.0f,10.0f,10.0f);


    // //RRT Testing
    
    rrt::random_state(v1, v2);
    rrt::init_rrt(v1);
    for (int i = 0; i < 50; i++)
        rrt::step_rrt(v1, v2);
    return 0;
}

