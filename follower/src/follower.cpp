#include "ros/ros.h"
#include "geometry_msgs/Point.h"

void chatterCallback(const geometry_msgs::Point& pos)
{
  ROS_INFO_STREAM("position delay receveid from the network  :" << "x=" << pos.x << " y=" << pos.y << " z=" << pos.z);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "follower");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("position_delay", 1000, chatterCallback);
  ros::spin();

  return 0;
}