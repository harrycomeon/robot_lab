/* 
* Copyright (C) 2015, Lentin Joseph and Qbotics Labs Inc.

 * Email id : qboticslabs@gmail.com

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the names of Stanford University or Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.


* This code is the ROS service server code which will receive the integer from service client

*/


#include "ros/ros.h"
#include "mastering_ros_demo_pkg/demo_srv.h"
#include <iostream>
#include <sstream>


//Defining namespace using in this code
using namespace std;
//using namespace ros;
//using namespace std_msgs;
//using namespace mastering_ros_demo_pkg;

//当在服务器上收到请求后，这一回调函数执行操作，且收到的类型为mastering_ros_demo_pkg::demo_srv::Request，
//回应的类型为mastering_ros_demo_pkg::demo_srv::Response
bool demo_service_callback(mastering_ros_demo_pkg::demo_srv::Request  &req,
         mastering_ros_demo_pkg::demo_srv::Response &res)
{


//  ROS_INFO("From Client  [%s], Server says [%s]",req.in.c_str(),ss.c_str());


  std::stringstream ss;
  ss << "Received  Here";
//out为回应下demo_srv.srv的field name，这一回应将进入到服务客户端节点
  res.out = ss.str();

  ROS_INFO("From Client  [%s], Server says [%s]",req.in.c_str(),res.out.c_str());

  return true;


}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "demo_service_server");
  ros::NodeHandle n;
  //创建服务服务器，并通过回调函数实例化
  ros::ServiceServer service = n.advertiseService("demo_service", demo_service_callback);
  ROS_INFO("Ready to receive from client.");
  ros::spin();

  return 0;
}



