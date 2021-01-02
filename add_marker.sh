#!/bin/bash
SOURCE="source /root/ros/devel/setup.bash; "
DOCKER="docker exec -it xenialros /bin/bash -c '#CMD#'"
CMDS=('roslaunch my_robot world.launch'
'roslaunch my_robot amcl.launch'
'roslaunch my_robot view_navigation.launch'
'roslaunch add_markers add_markers.launch'
)

USE_DOCKER=false
while :; do
    case $1 in
        -d|--docker) USE_DOCKER=true
        ;;
        *) break
    esac
    shift
done

for i in "${CMDS[@]}"
do
    i="$SOURCE$i  "
    if [ "$USE_DOCKER" = true ] ; then
      i=${DOCKER/"#CMD#"/$i}
    fi
    echo $i
    xterm  -e "$i" & sleep 5
done