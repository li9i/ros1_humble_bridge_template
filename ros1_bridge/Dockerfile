FROM li9i/ros1-humble-bridge-builder-base:latest

# ------------------------------------------------------------------------------
# 2,3,4
# Place ROS 1 packages into /ros1_ws workspace and colcon build
# ------------------------------------------------------------------------------
RUN mkdir -p /ros1_ws/src
COPY ros1_talker /ros1_ws/src/ros1_talker/
RUN  cd ros1_ws &&                                                                      \
     unset ROS_DISTRO &&                                                                \
     grep -r c++11 | grep CMakeLists | cut -f 1 -d ':' |                                \
       xargs sed -i -e 's|std=c++11|std=c++17|g' &&                                     \
     time colcon build --cmake-args -DCMAKE_BUILD_TYPE=Release

# ------------------------------------------------------------------------------
# 5,6,7
# Place ROS 2 packages into /ros2_ws workspace and colcon build
# ------------------------------------------------------------------------------
RUN mkdir -p /ros2_ws/src
COPY cpp_pubsub /ros2_ws/src/cpp_pubsub/
RUN  cd /ros2_ws &&                                                                     \
     source /opt/ros/humble/setup.bash  &&                                              \
     time colcon build --cmake-args -DCMAKE_BUILD_TYPE=Release

# ------------------------------------------------------------------------------
# 8
# Source ROS 1 and ROS 2 workspaces before /opt/ros/humble
# Then compile ros1_bridge
# ref: https://github.com/ros2/ros1_bridge/issues/391
# ------------------------------------------------------------------------------
RUN  source /ros1_ws/install/setup.bash  &&                                             \
     source /ros2_ws/install/setup.bash  &&                                             \
     source /opt/ros/humble/setup.bash  &&                                              \
     mkdir -p /ros1_humble_bridge_ws/src &&                                             \
     cd /ros1_humble_bridge_ws/src &&                                                   \
     git clone https://github.com/ros2/ros1_bridge &&                                   \
     cd ros1_bridge/ &&                                                                 \
     git checkout b9f1739 &&                                                            \
     cd ../.. &&                                                                        \
     MEMG=$(printf "%.0f" $(free -g | awk '/^Mem:/{print $2}'));                        \
     NPROC=$(nproc);  MIN=$((MEMG<NPROC ? MEMG : NPROC));                               \
     time MAKEFLAGS="-j $MIN" colcon build --event-handlers console_direct+             \
       --cmake-args -DCMAKE_BUILD_TYPE=Release

# ------------------------------------------------------------------------------
# 9: Clean up
# ------------------------------------------------------------------------------
RUN apt-get -y clean all; apt-get -y update

# ------------------------------------------------------------------------------
# 10: Pack all ROS 1 dependent libraries
# ------------------------------------------------------------------------------
RUN  ROS1_LIBS="libxmlrpcpp.so";                                                        \
     ROS1_LIBS="$ROS1_LIBS librostime.so";                                              \
     ROS1_LIBS="$ROS1_LIBS libroscpp.so";                                               \
     ROS1_LIBS="$ROS1_LIBS libroscpp_serialization.so";                                 \
     ROS1_LIBS="$ROS1_LIBS librosconsole.so";                                           \
     ROS1_LIBS="$ROS1_LIBS librosconsole_log4cxx.so";                                   \
     ROS1_LIBS="$ROS1_LIBS librosconsole_backend_interface.so";                         \
     ROS1_LIBS="$ROS1_LIBS liblog4cxx.so";                                              \
     ROS1_LIBS="$ROS1_LIBS libcpp_common.so";                                           \
     ROS1_LIBS="$ROS1_LIBS libb64.so";                                                  \
     ROS1_LIBS="$ROS1_LIBS libaprutil-1.so";                                            \
     ROS1_LIBS="$ROS1_LIBS libapr-1.so";                                                \
     cd /ros1_humble_bridge_ws/install/ros1_bridge/lib;                                 \
     for soFile in $ROS1_LIBS; do                                                       \
         soFilePath=$(ldd libros1_bridge.so | grep $soFile | awk '{print $3;}');        \
         cp $soFilePath ./;                                                             \
     done

# ------------------------------------------------------------------------------
# 11: Spit out ros1-humble-bridge tarball by default when no command is given
# ------------------------------------------------------------------------------
RUN tar czf /ros1_humble_bridge_ws.tgz                                 \
     --exclude '*/build/*' --exclude '*/src/*' /ros1_humble_bridge_ws
ENTRYPOINT []
CMD cat /ros1_humble_bridge_ws.tgz; sync
