#include "ros1_talker.h"


/*******************************************************************************
 * @brief Constructor
 * @param[in] nh [ros::NodeHandle]
 * @param[in] nh_private [ros::NodeHandle]
 */
R1T::R1T(
  ros::NodeHandle nh, ros::NodeHandle nh_private):
  nh_(nh),
  nh_private_(nh_private)
{
  ROS_INFO("[ros1_talker] Creating timer");
  chatter_pub_ = nh_.advertise<std_msgs::String>("chatter", 1000);
  custom_chatter_pub_ = nh_.advertise<ros1_talker::custom_msg>("custom_chatter", 1000);

  timer_ = nh_.createTimer(ros::Duration(1), &R1T::callback, this);
  custom_timer_ = nh_.createTimer(ros::Duration(1), &R1T::customCallback, this);
}


/*******************************************************************************
 * @brief Destructor
 * @params void
 */
R1T::~R1T()
{
  ROS_INFO("[ros1_talker] Destroying ros1_talker");
}


/*******************************************************************************
 * @brief Callback
 * @param[in] msg [const ros::TimerEvent& te]
 * @return void
 */
  void
R1T::callback(const ros::TimerEvent& te)
{
  ROS_INFO("[ros1_talker] ROS1_talker callback. Publishing 'my string is the best'");
  std_msgs::String s;
  s.data = "my string is the best";
  chatter_pub_.publish(s);
}


/*******************************************************************************
 * @brief Custom Callback
 * @param[in] msg [const ros::TimerEvent& te]
 * @return void
 */
  void
R1T::customCallback(const ros::TimerEvent& te)
{
  ROS_INFO("[ros1_talker] ROS1_talker callback. Publishing a bunch of custom stuff");
  ros1_talker::custom_msg msg;

  msg.header.stamp = ros::Time::now();
  msg.child_frame_id = "this is the child frame id yes?";
  msg.custom_bool = true;
  msg.custom_int = 69;
  msg.custom_double = 3.14159;

  geometry_msgs::PoseWithCovarianceStamped::Ptr pose =
    boost::make_shared<geometry_msgs::PoseWithCovarianceStamped>();
  pose->pose.pose.position.x = -14.2;
  msg.pose = *pose;

  custom_chatter_pub_.publish(msg);
}
