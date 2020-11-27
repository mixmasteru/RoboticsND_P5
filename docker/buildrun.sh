#!/bin/bash
FOLDER=${1}

docker build --tag myros:xenial .
docker run -d \
    --name xenialros \
    --rm \
    --device=/dev/dri:/dev/dri \
    --env="DISPLAY" \
    --env="QT_X11_NO_MITSHM=1" \
    --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" \
    --volume="~/development/udacity/ros/$FOLDER:/root/ros:rw" \
    -p 127.0.0.1:2222:22 \
    myros:xenial

#export containerId=$(docker ps -l -q)
#xhost +local:`docker inspect --format='' $containerId`
#docker start $containerId
