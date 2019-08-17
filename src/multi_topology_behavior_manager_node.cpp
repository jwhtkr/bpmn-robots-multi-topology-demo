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
#include<behavior_manager/behavior_pool.hpp>

/* ROS Headers */
#include<ros/ros.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "multi_topology_behavior_manager_node");
  ros::NodeHandle m_nh;
  ros::NodeHandle p_nh("~");

  std::string listening_topic,
              status_topic,
              get_resources_topic,
              give_resources_topic,
              give_up_resources_topic,
              modify_robots_topic,
              config_file_path;

  if(!p_nh.getParam("listening_topic",         listening_topic)         ||
     !p_nh.getParam("status_topic",            status_topic)            ||
     !p_nh.getParam("get_resources_topic",     get_resources_topic)     ||
     !p_nh.getParam("give_resources_topic",    give_resources_topic)    ||
     !p_nh.getParam("give_up_resources_topic", give_up_resources_topic) ||
     !p_nh.getParam("modify_robots_topic",     modify_robots_topic)     ||
     !p_nh.getParam("config_file_path",        config_file_path))
  {
    throw std::runtime_error(std::string("Parameters aren't set right;") +
                              "\nlistening_topic: "         + listening_topic +
                              "\nstatus_topic: "            + status_topic +
                              "\nget_resources_topic: "     + get_resources_topic +
                              "\ngive_resources_topic: "    + give_resources_topic +
                              "\ngive_up_resources_topic: " + give_up_resources_topic +
                              "\nmodify_robots_topic: "     + modify_robots_topic +
                              "\nconfig_file_path: "        + config_file_path);
  }

  behavior_manager::BehaviorPool<MultiTopologyBehaviorManager> behavior("Run_Topology",
                                                                        "http://localhost:8080/",
                                                                        listening_topic,
                                                                        status_topic,
                                                                        get_resources_topic,
                                                                        give_resources_topic,
                                                                        give_up_resources_topic,
                                                                        modify_robots_topic,
                                                                        config_file_path);
  ros::Rate loop_rate(30);

  while(m_nh.ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }

  exit(EXIT_SUCCESS);
}

/* multi_topology_behavior_manager_node.cpp */
