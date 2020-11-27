FROM osrf/ros:kinetic-desktop-full-xenial

RUN apt-get update && apt-get upgrade -y && apt-get install -y ros-kinetic-navigation && apt-get install -y ros-kinetic-map-server && apt-get install -y ros-kinetic-move-base && apt-get install -y ros-kinetic-amcl && apt-get install -y ros-kinetic-openslam-gmapping && apt-get install -y ros-kinetic-joy*
RUN apt-get update && apt-get upgrade -y && apt-get install -y libignition-math2-dev protobuf-compiler
RUN apt-get update && apt-get upgrade -y && apt-get install -y ros-kinetic-rtabmap-ros ros-kinetic-rtabmap
COPY install.sh /usr/local/bin/install.sh
RUN chmod +x /usr/local/bin/install.sh
RUN /usr/local/bin/install.sh
RUN apt-get update && apt-get upgrade -y && apt-get install -y ros-kinetic-turtlebot ros-kinetic-turtlebot-apps ros-kinetic-turtlebot-interactions ros-kinetic-turtlebot-simulator ros-kinetic-kobuki-ftdi
RUN apt-get update && apt-get upgrade -y && apt-get install -y libgl1-mesa-glx libgl1-mesa-dri && rm -rf /var/lib/apt/lists/*
RUN apt-get update \
  && apt-get install -y ssh \
      build-essential \
      gcc \
      g++ \
      gdb \
      clang \
      cmake \
      rsync \
      tar \
      python \
  && apt-get clean

RUN ( \
    echo 'LogLevel DEBUG2'; \
    echo 'PermitRootLogin yes'; \
    echo 'PasswordAuthentication yes'; \
    echo 'Subsystem sftp /usr/lib/openssh/sftp-server'; \
  ) > /etc/ssh/sshd_config_test_clion \
  && mkdir /run/sshd

#RUN useradd -m user && yes password | passwd user
RUN echo "root:root" | chpasswd
CMD ["/usr/sbin/sshd", "-D", "-e", "-f", "/etc/ssh/sshd_config_test_clion"]


