#include <ros/ros.h>
#include <geometry_msgs/Point.h>
#include <time.h>
#include <stdlib.h>

class Subscribe_And_Publish
{
private:
    ros::Publisher pub;
    ros::Subscriber sub;
    ros::NodeHandle n;
public:


    Subscribe_And_Publish()
    {
       
        sub = n.subscribe("position", 1000, &Subscribe_And_Publish::callback, this);
        pub = n.advertise<geometry_msgs::Point> ("position_delay", 1000);
       
    }

    void callback(const geometry_msgs::Point& pos)
    {
        ros::Time begintime=ros::Time::now();
        ros::Duration messagetime=ros::Duration(1);
        ros::Time endtime= begintime+messagetime;
        while(ros::Time::now()<endtime);
  
        ROS_INFO_STREAM("position delay sent to  the follower:" << "x=" << pos.x << " y=" << pos.y << " z=" << pos.z);
        pub.publish(pos);
    }

};//End of class SubscribeAndPublish

int main(int argc, char **argv)
{
    ros::init(argc, argv, "network");
    Subscribe_And_Publish SAPObject;

    ros::spin();

    return 0;
}

