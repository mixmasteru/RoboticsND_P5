#!/bin/sh
DOCKER="docker exec -it xenialros /bin/bash -c"

xterm  -e  "$DOCKER 'gazebo' " &
sleep 5
xterm  -e  "$DOCKER 'source /opt/ros/kinetic/setup.bash; roscore'" &
sleep 5
xterm  -e  "$DOCKER 'source /opt/ros/kinetic/setup.bash; rosrun rviz rviz'"