/**
 * @File: multi_topology_behavior_manager_node.cpp
 * @Date: 30 June 2019
 * @Author: James Swedeen
 *
 * @brief
 * This is the behavior manager for this demo.
 **/

/* Local Headers */
#include"multi_topology_demo/multi_topology_behavior_manager.hpp"

/* Behavior Manager Headers */
#include<behavior_pool/behavior_pool.hpp>

/* ROS Headers */
#include<ros/ros.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "multi_topology_behavior_manager_node");
  ros::NodeHandle m_nh;
  ros::NodeHandle p_nh("~");

  std::string listening_topic;

  p_nh.getParam("listening_topic", listening_topic);

  BehaviorPool<MultiTopologyBehaviorManager> behavior(listening_topic, "Run_Topology", "http://localhost:8080/");

  ros::Rate loop_rate(30);

  while(m_nh.ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }

  exit(EXIT_SUCCESS);
}

/* multi_topology_behavior_manager_node.cpp */
