# Summary

This repository hosts dockerfiles, ROS 1 kinetic, and ROS 2 humble packages.
The end result is communication between the two ROS versions with custom
messages.

There are three main components to it:
- A ROS 2 humble listener pkg (lives under `ros1_pkgs_ws/src/cpp_pubsub` and must also be placed under `ros1_bridge/`)
- A ROS 1 kinetic talker pkg (lives under `ros1_pkgs_docker/ros1_talker` and must also be placed under `ros1_bridge/`)
- The bridge (`ros1-humble-bridge-builder-base` and `ros1_bridge`)

The bridge is extracted as a ROS 2 workspace from a docker container that
is an instantiation of a builder image (`ros1-humble-bridge-builder`). For
efficiency reasons this image is based on the `ros1-humble-bridge-builder-base`
image.  When extracted the bridge must reside under `ros1_bridge`, alongside
with `cpp_pubsub` and `ros1_talker`.


# 0. The basics

Build the image of the bridge builder's base

```
mkdir ~/ros1_humble_bridge_test/
cd !:1
git clone git@github.com:li9i/ros1_humble_bridge_template.git
cd ros1_humble_bridge_template/ros1-humble-bridge-builder-base
docker build --progress=plain -t li9i/ros1-humble-bridge-builder-base:latest .
```

Now build the bridge builder

```
cd ~/ros1_humble_bridge_test/ros1_humble_bridge_template/ros1_bridge
docker build --progress=plain -t li9i/ros1-humble-bridge:latest .
```

The bridge builder is called a builder because if you extract it then you get a
humble bridge workspace:

```
docker run --rm li9i/ros1-humble-bridge:latest | tar xvzf -
```

This will create a `ros1_humble_bridge_ws` directory under
`~/ros1_humble_bridge_test/ros1_humble_bridge_template/ros1_bridge`


# 1. Terminal 1: Build and run ROS publisher

## Build

```
cd ~/ros1_humble_bridge_test/ros1_humble_bridge_template/ros1_pkgs_docker
docker build --progress=plain -t li9i/bridge_ros1_talker:latest .
```

## Run
```
docker run -it --ipc=host --net=host li9i/ros1_talker:latest
```
```
export ROS_MASTER_URI=http://localhost:11311
export ROS_HOSTNAME=localhost
source /opt/ros/kinetic/setup.bash
source /home/user_r1l/catkin_ws/devel/setup.bash

roslaunch ros1_talker ros1_talker.launch
```

# 2. Terminal 2: Run ros1_bridge

```
source /opt/ros/humble/setup.bash
cd ~/ros1_humble_bridge_test/ros1_humble_bridge_template/ros1_bridge/ros1_humble_bridge_ws/
source install/local_setup.bash
ros2 run ros1_bridge dynamic_bridge
```

# 3. Terminal 3: Run ROS 2 listener (natively)

```
source /opt/ros/humble/setup.bash
cd ~/ros1_humble_bridge_test/ros1_humble_bridge_template/ros2_pkgs_ws/
source install/local_setup.bash
ros2 run cpp_pubsub listener
```
