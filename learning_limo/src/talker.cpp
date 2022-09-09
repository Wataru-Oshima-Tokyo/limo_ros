#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");

	ros::NodeHandle n;

	ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 100);

	ros::Rate loop_rate(10);
	
	while(ros::ok())
	{
    geometry_msgs::Twist twist;
    geometry_msgs::Vector3 linear;
    linear.x=0;
    linear.y=0;
    linear.z=0;
    geometry_msgs::Vector3 angular;
    angular.x=0;
    angular.y=0;
    angular.z=1.0;
   
    twist.linear=linear;
    twist.angular=angular;

    chatter_pub.publish(twist);

    ros::spinOnce();

    loop_rate.sleep();
	}

    return 0;
}

