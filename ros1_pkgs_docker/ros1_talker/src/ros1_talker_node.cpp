#include "ros1_talker.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "ros1_talker_node");
  ros::NodeHandle nh;
  ros::NodeHandle nh_private("~");

  R1T r1t(nh, nh_private);
  ros::spin();
  return 0;
}
