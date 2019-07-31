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

/* ROS Headers */
#include<ros/ros.h>

/* C++ Headers */
#include<string>
#include<vector>

MultiTopologyBehaviorManager::MultiTopologyBehaviorManager(const std::string& base_uri,
                                                           const std::string& name,
                                                           const std::string& topic)
 : BehaviorManager<>(base_uri, name, topic, std::vector<std::string>({"timeout_period"})),
   start_time(0),
   period(0)
{}

uint8_t MultiTopologyBehaviorManager::getBehaviorPriority() const noexcept
{
  return BehaviorManager::getBehaviorPriority();
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
