#!/bin/sh

cd $(pwd)/../..
root_dir=$(pwd)

#rm -rf build devel
#catkin_make;

# launch gazebo world
xterm -e "export GAZEBO_MODEL_PATH=${GAZEBO_MODEL_PATH}:${root_dir}/src/service_robot_pkg/models; 
          source /opt/ros/kinetic/setup.bash;
          source ${root_dir}/devel/setup.bash;
          roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=${root_dir}/src/service_robot_pkg/worlds/minimaze.world" &
sleep 5

# launch localization
xterm -e "source ${root_dir}/devel/setup.bash; 
          roslaunch turtlebot_gazebo amcl_demo.launch map_file:=${root_dir}/src/map/map.yaml" &

sleep 5

# launch rviz
xterm -e "source ${root_dir}/devel/setup.bash; 
          roslaunch turtlebot_rviz_launchers view_navigation.launch" &

sleep 5

# set initial pose
xterm -e "source ${root_dir}/devel/setup.bash;
          rosrun pick_objects initial_pose.py;" &
