cmake_minimum_required(VERSION 3.0.2)
project(service_robot_pkg)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  visualization_msgs
  actionlib
  move_base_msgs
  rospy
)

add_compile_options(-std=c++11)

catkin_package(

)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)


add_executable(servicerobot src/service_robot.cpp)
target_link_libraries(servicerobot ${catkin_LIBRARIES})
