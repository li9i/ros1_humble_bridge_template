# Why use this repository

Because you are in a situation where ROS 2 humble packages require
communication with ROS 1 packages through custom-made msgs or srvs.

# Summary

This repository hosts dockerfiles, ROS 1 kinetic, and ROS 2 humble packages.
The end result is communication between the two ROS versions with custom
messages.

There are three main components to it:
- A ROS 2 humble listener pkg (lives under `ros2_pkgs_ws/src/cpp_pubsub`)
- A ROS 1 kinetic talker pkg (lives under `ros1_pkgs_docker/ros1_talker`)
- The bridge (`ros1-humble-bridge-builder-base` and `ros1_bridge`)

The bridge is extracted as a ROS 2 workspace from a docker container that
is an instantiation of a builder image (`ros1-humble-bridge-builder`). For
efficiency reasons this image is based on the `ros1-humble-bridge-builder-base`
image. When extracted the bridge must reside under `ros1_bridge`, alongside
all ROS and ROS 2 packages.

# Assumptions / generalisations

It is assumed that ROS 1 packages run through docker and ROS 2 packages run
natively on Ubuntu 22.04. In the general case you would
- place your ROS 1 packages under the `ros1_pkgs_docker` directory
  (e.g. kinetic pkg `ros1_talker`)
- construct a `Dockerfile` for them
- consider using a bash script to launch them (e.g.
  `ros1_pkgs_docker/1.roslaunch.sh`)
- place your ROS 2 packages under `ros2_pkgs_ws/src` (e.g. the humble pkg `cpp_pubsub`)
- create mountpoints for all customly-bridged ROS packages under the directory where the bridge lives (`ros1_bridge/`)


Table of Contents
=================
* [Summary](#summary)
* [Assumptions / generalisations](#assumptions--generalisations)
* [Clone this repository](#clone-this-repository)
* [Build phase](#build-phase)
  * [Build ROS publisher docker image](#terminal-1-build-ros-publisher-docker-image)
  * [`colcon build` ROS 2 listener](#terminal-2-colcon-build-ros-2-listener)
  * [Build the image of the bridge builder's base](#terminal-3-build-the-image-of-the-bridge-builders-base)
    * [Link packages into bridge without duplication](#link-packages-into-bridge-without-duplication)
* [Run phase](#run-phase)
  * [Run ROS publisher](#1-terminal-1-run-ros-publisher)
  * [Run ROS 2 listener](#2-terminal-2-run-ros-2-listener)
  * [Run `ros1_humble_bridge`](#3-terminal-3-run-ros1_humble_bridge)



# Clone this repository

```
mkdir ~/ros1_humble_bridge_test/
cd !:1
git clone git@github.com:li9i/ros1_humble_bridge_template.git
```

# Build phase


## Terminal 1: Build ROS publisher docker image

```
cd ~/ros1_humble_bridge_test/ros1_humble_bridge_template/ros1_pkgs_docker
docker build --progress=plain -t li9i/bridge_ros1_talker:latest .
```


## Terminal 2: `colcon build` ROS 2 listener

```
cd ~/ros1_humble_bridge_test/ros1_humble_bridge_template/ros2_pkgs_ws/
colcon build
```

## Terminal 3: Build the image of the bridge builder's base

```
cd ~/ros1_humble_bridge_test/ros1_humble_bridge_template/ros1-humble-bridge-builder-base
docker build --progress=plain -t li9i/ros1-humble-bridge-builder-base:latest .
```

Now build the bridge builder.

### Link packages into bridge without duplication

Before doing that though there is the problem of package redundancy: For the
bridge to be able to bridge packages using custom msgs/srvs these packages must
reside under the same roof, i.e.  `ros1_bridge/` here.  However they are
launched from other locations: this results in a configuration
where multiple packages must reside under multiple directories at the same
time. In order to avoid this these packages must somehow be linked
here but used in their original locations.
[Symlinks do not work in Docker](https://superuser.com/questions/842642/how-to-make-a-symlinked-folder-appear-as-a-normal-folder),
but mounting the packages as read-only directories within the `ros1_bridge/`
directory works:

```
cd ~/ros1_humble_bridge_test/ros1_humble_bridge_template/ros1_bridge
mkdir ros1_talker
sudo mount -o bind,ro ../ros1_pkgs_docker/ros1_talker/ ros1_talker/
mkdir cpp_pubsub
sudo mount -o bind,ro ../ros2_pkgs_ws/src/cpp_pubsub/ cpp_pubsub/
```

We can now build the bridge builder with

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


# Run phase

## 1. Terminal 1: Run ROS publisher

```
docker run -it --ipc=host --net=host li9i/bridge_ros1_talker:latest
```
```
export ROS_MASTER_URI=http://localhost:11311
export ROS_HOSTNAME=localhost
source /opt/ros/kinetic/setup.bash
source /home/user_r1l/catkin_ws/devel/setup.bash

roslaunch ros1_talker ros1_talker.launch
```

## 2. Terminal 2: Run ROS 2 listener

```
cd ~/ros1_humble_bridge_test/ros1_humble_bridge_template/ros2_pkgs_ws/
source install/local_setup.bash
ros2 run cpp_pubsub listener
```

## 3. Terminal 3: Run `ros1_humble_bridge`

```
cd ~/ros1_humble_bridge_test/ros1_humble_bridge_template/ros1_bridge/ros1_humble_bridge_ws/
source install/local_setup.bash
ros2 run ros1_bridge dynamic_bridge
```
