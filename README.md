# Robotics Software Engineer

## Project 5 - Home Service Robot
 
In this project, you will use everything you learned in the Nanodegree Program to build a Home Service Robot in ROS.

- [x] Simulation Setup
- [x] SLAM Testing
- [x] Wall Follower Node
- [x] Navigation Testing
- [x] Waypoint Node
- [x] Virtual Objects
- [x] Put it all Together


![Demo](screen.gif)


## used packages

### amcl
amcl is a probabilistic localization system for a robot moving in 2D. 
It implements the adaptive (or KLD-sampling) Monte Carlo localization 
approach (as described by Dieter Fox), which uses a particle filter 
to track the pose of a robot against a known map.
### my_robot




## Docker

use script to create docker
```bash
./docker/buildrun.sh /absolut/folder
```
use script to get shell in docker
```bash
./docker/docker_exec_it.sh /bin/bash
```

## bash scripts

use -d option to run it in docker
```bash
./pick_objects.sh -d
```
