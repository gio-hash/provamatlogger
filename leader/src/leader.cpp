#include <ros/ros.h>
#include<geometry_msgs/Point.h>
int main(int argc, char **argv){
    ros::init(argc,argv,"leader");
    ros::NodeHandle n;
    ros::Publisher chatter_pub =n.advertise<geometry_msgs::Point>("position",1000);
    ros::Rate loop_rate(1.0);
    while (ros::ok()){
        geometry_msgs::Point pos;
        pos.x = 1;
        pos.y = 2;
        pos.z =  3;
        ROS_INFO_STREAM("sending position:"<< " x=" << pos.x << " y=" << pos.y << " z=" << pos.z);
        chatter_pub.publish(pos);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return  0;

}