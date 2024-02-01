# 0. The basics

Build the image of the bridge builder's base

```
mkdir ~/Desktop/humble_bridge_test_2024_01/
cd !:1
git clone git@github.com:li9i/ros1_humble_bridge_template.git
cd ros1-humble-bridge-builder-base
reset; docker build --progress=plain -t li9i/ros1-humble-bridge-builder-base:latest .
```

Now build the bridge builder

```
cd ros1_bridge
docker build --progress=plain -t li9i/ros1-humble-bridge:latest .
```

The bridge builder is called a builder because if you extract it then you get a
humble bridge workspace

```
cd ros1_bridge
docker run --rm li9i/ros1-humble-bridge:latest | tar xvzf -
```

This will create a `ros1_humble_bridge_ws` directory under
`~/Desktop/humble_bridge_test_2024_01/ros1_bridge`


# 1. Terminal 1: Build and run ROS publisher

## Build

```
cd ~/Desktop/humble_bridge_test_2024_01/ros1_pkgs_docker
docker build --progress=plain -t li9i/bridge_ros1_talker:latest .
```

## Run
```
docker run -it --ipc=host --net=host li9i/ros1_talker:latest

export ROS_MASTER_URI=http://localhost:11311
export ROS_HOSTNAME=localhost
source /opt/ros/kinetic/setup.bash
source /home/user_r1l/catkin_ws/devel/setup.bash

roslaunch ros1_talker ros1_talker.launch
```

# 2. Terminal 2: Run ros1_bridge

```
source /opt/ros/humble/setup.bash
cd ~/Desktop/humble_bridge_test_2024_01/ros1_bridge/ros1_humble_bridge_ws/
source install/local_setup.bash
ros2 run ros1_bridge dynamic_bridge
```

# 3. Terminal 3: Run ROS 2 listener (natively)

```
source /opt/ros/humble/setup.bash
cd ~/Desktop/humble_bridge_test_2024_01/ros2_pkgs_ws/
source install/local_setup.bash
ros2 run cpp_pubsub listener
```
