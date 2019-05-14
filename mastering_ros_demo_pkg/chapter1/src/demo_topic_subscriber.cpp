#include "ros/ros.h" 
#include "std_msgs/Int32.h"
#include <iostream>
//创建一个callback函数，当有新数据在topic更新时执行该函数，抽取新数据并print到console
void number_callback(const std_msgs::Int32::ConstPtr& msg) 
{
    ROS_INFO("Received [%d]",msg->data); 
}
int main(int argc, char **argv)
{
    ros::init(argc, argv,"demo_topic_subscriber"); 
    ros::NodeHandle node_obj;
    //创建一个ROS订阅节点number_subscriber，订阅主题是"/numbers",第三项是callback函数。
    ros::Subscriber number_subscriber = node_obj.subscribe("/numbers",10,number_callback); 
    //写入spin()，相当于一个无限循环，订阅节点会等待topic更新数据，只有当按Ctrl+C才会退出。
    ros::spin(); 
    return 0;
}

