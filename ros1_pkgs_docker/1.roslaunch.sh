#!/bin/bash
export ROS_MASTER_URI=http://localhost:11311
export ROS_HOSTNAME=localhost

source /opt/ros/kinetic/setup.bash
source /home/user_r1l/catkin_ws/devel/setup.bash

roslaunch ros1_talker ros1_talker.launch
