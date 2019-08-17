/**
 * @File: multi_topology_behavior_manager.cpp
 * @Date: 30 June 2019
 * @Author: James Swedeen
 *
 * @brief
 * This is the behavior manager for this demo.
 **/

/* Local Headers */
#include"multi_topology_demo/multi_topology_behavior_manager.hpp"

/* Behavior Manager Headers */
#include<behavior_manager/behavior_manager.hpp>

/* Architecture Messages */
#include<architecture_msgs/BehaviorStatus.h>

/* ROS Headers */
#include<ros/ros.h>

/* C++ Headers */
#include<string>
#include<vector>

MultiTopologyBehaviorManager::MultiTopologyBehaviorManager(const std::string& base_uri,
                                                           const std::string& name,
                                                           const std::string& camunda_topic,
                                                           const std::string& status_topic,
                                                           const std::string& get_resources_topic,
                                                           const std::string& give_resources_topic,
                                                           const std::string& give_up_resources_topic,
                                                           const std::string& modify_robots_topic,
                                                           const std::string& config_file_path)
 : behavior_manager::BehaviorManager<>(base_uri,
                                       name,
                                       camunda_topic,
                                       status_topic,
                                       get_resources_topic,
                                       give_resources_topic,
                                       give_up_resources_topic,
                                       modify_robots_topic,
                                       config_file_path,
                                       std::vector<std::string>({"timeout_period"})),
   start_time(0),
   period(0)
{}

architecture_msgs::BehaviorStatus::Response::Ptr MultiTopologyBehaviorManager::getStatus() const noexcept
{
  architecture_msgs::BehaviorStatus::Response::Ptr output(this->::behavior_manager::BehaviorManager<>::getStatus());

  output->description = "This behavior is used to make simulated turtlebots go to random goals.";

  return output;
}


void MultiTopologyBehaviorManager::runBehavior()
{
  if(this->start_time.isZero() && this->period.isZero())
  {
    this->period.fromSec(std::atoi(this->task_lock.getResponsVars().at("timeout_period").at("value").as_string().c_str()));
    this->start_time.fromSec(ros::Time::now().toSec());
  }

  if(ros::Time::now().toSec() > (this->start_time + this->period).toSec())
  {
    this->task_lock.complete();
  }
}

/* multi_topology_behavior_manager.cpp */
