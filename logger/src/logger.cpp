#include <ros/ros.h>
#include <geometry_msgs/Point.h>
#include <matlogger2/matlogger2.h>
#include <Eigen/Dense>

class S_And_S
{
private:
  ros::Subscriber sub;
  ros::Subscriber sub1;
  ros::NodeHandle n;
public:
  S_And_S(){
    sub = n.subscribe("position",1000,&S_And_S::callback,this);
    sub1 = n.subscribe("position_delay",1000,&S_And_S::callback1,this);

  }
  void callback(const geometry_msgs::Point& pos){
    auto logger = XBot::MatLogger2::MakeLogger("/home/giovanni/log/position"); // date-time automatically appended  
    logger->set_buffer_mode(XBot::VariableBuffer::Mode::circular_buffer);  
    Eigen::VectorXd vec(3);
    vec(0)=pos.x;
    vec(1)=pos.y;
    vec(2)=pos.z;
    logger->add("position", vec);
    
  }
  void callback1(const geometry_msgs::Point& pos){
    auto logger = XBot::MatLogger2::MakeLogger("/home/giovanni/log/pos_delay"); // date-time automatically appended  
    logger->set_buffer_mode(XBot::VariableBuffer::Mode::circular_buffer);  
    Eigen::VectorXd vec(3);
    vec(0)=pos.x;
    vec(1)=pos.y;
    vec(2)=pos.z;
    logger->add("pos_delay", vec);
    
  }

};
int main(int argc, char **argv)
{
    ros::init(argc, argv, "logger");
    S_And_S SASObject;

    ros::spin();

    return 0;
}