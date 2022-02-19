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

# launch gmapping
xterm -e "source ${root_dir}/devel/setup.bash; 
          rosparam set /slam_gmapping/iterations 10;
          rosparam set /slam_gmapping/linearUpdate 0.05;
          rosparam set /slam_gmapping/angularUpdate 0.1;
          rosparam set /slam_gmapping/map_update_interval 0.2;
          roslaunch turtlebot_gazebo gmapping_demo.launch" &

sleep 5

# launch rviz
xterm -e "source ${root_dir}/devel/setup.bash; 
          roslaunch turtlebot_rviz_launchers view_navigation.launch" &

sleep 5

# launch keyboard teleoperation
xterm -e "source ${root_dir}/devel/setup.bash; 
          roslaunch turtlebot_teleop keyboard_teleop.launch" &

# NOTE: For saving a map do the next command on a terminal on the map folder of the repo
# rosrun map_server map_saver -f <mapname>
