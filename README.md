# Robotics Software Engineer

## Project 5 - Home Service Robot
 
In this project, you will use everything you learned in the Nanodegree Program to build a Home Service Robot in ROS.

- [x] Simulation Setup
- [x] SLAM Testing
- [x] Navigation Testing
- [x] Waypoint Node
- [x] Virtual Objects
- [x] Put it all Together


![Demo](img/home_service.gif "demo")
[webm video](img/home_service.webm)

![Demo my robot](img/my_robot_home_servcie.gif "my robot demo")
[webm video](img/my_robot_home_servcie.webm)

## used packages

* [gmapping](http://wiki.ros.org/gmapping)
* [turtlebot_teleop](http://wiki.ros.org/turtlebot_teleop)
* [turtlebot_rviz_launchers](http://wiki.ros.org/turtlebot_rviz_launchers)
* [turtlebot_gazebo](http://wiki.ros.org/turtlebot_gazebo)
* my_robot from previous projects


## bash scripts
* scrips with "my_robot" prefix run everything in my_robot
* scrips without "my_robot" prefix run everything in turtlebot
* run scripts on ros or use -d option to run it in docker
    ```bash
    ./pick_objects.sh -d
    ```

## Docker

use script to create docker
```bash
./docker/buildrun.sh /absolut/folder
```
use script to get shell in docker
```bash
./docker/docker_exec_it.sh /bin/bash
```
