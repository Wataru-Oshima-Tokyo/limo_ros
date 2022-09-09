#include "ros/ros.h"
#include "std_msgs/String.h"
#include <geometry_msgs/Twist.h>

void chatterCallback(const geometry_msgs::TwistConstPtr& msg )
{
    double x = msg->linear.x;
    double y = msg->linear.y;
    double z = msg->angular.z;
    
    ROS_INFO("angular_z:%f]", z);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "listener");

    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("cmd_vel", 100, chatterCallback);

    ros::spin();

    return 0;

}
