#include "ros/ros.h"
#include "std_msgs/Int32.h" 
#include <iostream>
int main(int argc, char **argv)
 {
    //初始化一个叫“demo_topic_publisher”的ROS节点
    ros::init(argc, argv,"demo_topic_publisher"); 
    //创建一个Nodehandle对象，用来与ROS进行通信
    ros::NodeHandle node_obj; 
    //创建一个topic发布节点，节点是number_publisher，发布的topic的名称是"/numbers",发布的数据类型是Int32。第二项是buffer size参数。
    ros::Publisher number_publisher =node_obj.advertise<std_msgs::Int32>("/numbers",10); 
    //定义发送数据频率，如果频率高的话注意同时调高上一个buffer size
    ros::Rate loop_rate(10); 
    int number_count = 0; 
    while (ros::ok()) 
    {
        std_msgs::Int32 msg; 
        //将整数变量值赋给Message的data。data是msg对象的一个field
        msg.data = number_count; 
        ROS_INFO("%d",msg.data); 
	//节点发布message数据到topic，注意这里是msg
	number_publisher.publish(msg); 
	//读取和更新ROS topics，如果没有spinonce()或spin()，节点不会发布消息
	ros::spinOnce(); 
	//为了达到之前定义的发送频率，需要一个delay时间
	loop_rate.sleep(); 
	++number_count;
    } 
    return 0; 
} 
