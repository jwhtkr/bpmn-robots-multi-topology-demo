/**
 * @File: pose_to_odom.hpp
 * @Date: 07 September 2019
 * @Author: Anthony DeVore
 * 
 * @brief
 * This node takes 20 pose messages and calculates the vel and ang_vel for odom
 * then publishes odom msg.
 **/

#ifndef POSE_TO_ODOM_HPP
#define POSE_TO_ODOM_HPP

/* Ros headers */
#include <ros/ros.h>

class PoseToOdom 
{
public:
  // constructor
  PoseToOdom();
  
  // callback for what pose is updated.
  void poseCallback(const geometry_msgs::PoseStamped::ConstPtr &msg);
  void cmd_velCallback(const )
  // publishes new odom message
  void publishOdom();
  // calculates and fills odom message
  void calculateOdom();
  

}

#endif // POSE_TO_ODOM_HPP