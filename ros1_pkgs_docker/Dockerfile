FROM osrf/ros:kinetic-desktop
MAINTAINER Alexandros Philotheou alefilot@auth.gr

RUN apt-get update
RUN apt-get install -y sudo apt-utils build-essential g++ git libboost-random-dev curl lsb-release python-catkin-tools python-rosdep python-rosinstall python-rosinstall-generator python-wstool build-essential python-rosdep

# Use bash and create user
RUN rm /bin/sh && ln -s /bin/bash /bin/sh
RUN useradd -ms /bin/bash user_r1l
USER user_r1l
WORKDIR /home/user_r1l

RUN echo "source /opt/ros/kinetic/setup.bash" >> /home/user_r1l/.bashrc
RUN echo "source /home/user_r1l/catkin_ws/devel/setup.bash" >> /home/user_r1l/.bashrc

RUN rosdep update
RUN mkdir -p /home/user_r1l/catkin_ws/src && \
    cd /home/user_r1l/catkin_ws/src/

COPY ros1_talker/ /home/user_r1l/catkin_ws/src/ros1_talker/
COPY 1.roslaunch.sh/ /

RUN cd /home/user_r1l/catkin_ws && \
    export CC=gcc && \
    export CXX=g++ && \
    alias g++='g++ -std=c++11' && \
    alias clang++='clang++ -std=c++11' && \
    source /opt/ros/kinetic/setup.bash && \
    catkin build ros1_talker && \
    source /opt/ros/kinetic/setup.bash && \
    source /home/user_r1l/catkin_ws/devel/setup.bash


WORKDIR /
CMD ["/bin/bash"]
