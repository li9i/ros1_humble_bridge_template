cmake_minimum_required(VERSION 2.8.3)
project(ros1_talker)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  geometry_msgs
  message_generation
)

add_message_files(
  FILES
  custom_msg.msg
)
generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs
)

catkin_package(
  CATKIN_DEPENDS
  roscpp
  std_msgs
  INCLUDE_DIRS include
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)



add_library(ros1_talker_lib src/ros1_talker.cpp)
add_dependencies(ros1_talker_lib
  ${catkin_EXPORTED_TARGETS})


add_executable(ros1_talker_node
  src/ros1_talker_node.cpp)

target_link_libraries(ros1_talker_node
  ros1_talker_lib
  ${catkin_LIBRARIES}
)

add_dependencies(ros1_talker_node
  ${catkin_EXPORTED_TARGETS}
)
