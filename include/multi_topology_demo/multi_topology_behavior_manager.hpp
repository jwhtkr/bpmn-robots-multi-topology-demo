/**
 * @File: multi_topology_behavior_manager.hpp
 * @Date: 30 June 2019
 * @Author: James Swedeen
 *
 * @brief
 * This is the behavior manager for this demo.
 **/

#ifndef MULTI_TOPOLOGY_BEHAVIOR_MANAGER_HPP
#define MULTI_TOPOLOGY_BEHAVIOR_MANAGER_HPP

/* Behavior Manager Headers */
#include<behavior_manager/behavior_manager.hpp>

/* C++ Headers */
#include<string>

/* Ros Headers */
#include<ros/ros.h>

class MultiTopologyBehaviorManager : public BehaviorManager<>
{
public:
  /**
   * @Default Constructor
   **/
  MultiTopologyBehaviorManager() = delete;
  /**
   * @Copy Constructor
   **/
  MultiTopologyBehaviorManager(const MultiTopologyBehaviorManager&) = delete;
  /**
   * @Move Constructor
   **/
  MultiTopologyBehaviorManager(MultiTopologyBehaviorManager&&) = delete;
  /**
   * @Constructor
   **/
  MultiTopologyBehaviorManager(const std::string& base_uri,
                               const std::string& name,
                               const std::string& topic);
  /**
   * @Deconstructor
   **/
  ~MultiTopologyBehaviorManager() override = default;
  /**
   * @Assignment Operators
   **/
  MultiTopologyBehaviorManager& operator=(const MultiTopologyBehaviorManager&) = delete;
  MultiTopologyBehaviorManager& operator=(MultiTopologyBehaviorManager&&)      = delete;
  /**
   * @get
   **/
  uint8_t getBehaviorPriority() const noexcept override;
protected:
  /**
   * @runBehavior
   **/
  void runBehavior() override;
private:
  ros::Duration start_time;
  ros::Duration period;
};

#endif
/* multi_topology_behavior_manager.hpp */
