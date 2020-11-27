#!/bin/bash
#PROG=${1:-rqt}
PROG="$@"
#PROG="'"$PROG"'"
#echo $PROG
#exit

export containerId=$(docker ps -l -q)
xhost +local:`docker inspect --format='' $containerId`
#docker exec -it xenialros /bin/bash -c "'"$PROG"'"
docker exec -it xenialros /bin/bash
#docker start $containerId


# 1 Pipe from a file
#sudo docker exec --interactive CONTAINER_NAME /bin/bash < the_beginning.sh | tee the_beginning_output.txt`

#2a Pipe by piping
#echo "echo This is how we pipe to docker exec" | sudo docker exec --interactive CONTAINER_NAME /bin/bash -