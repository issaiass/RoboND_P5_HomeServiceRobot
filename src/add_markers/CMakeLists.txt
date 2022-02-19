cmake_minimum_required(VERSION 3.0.2)
project(add_markers)


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


add_executable(addmarkers src/add_markers.cpp)
target_link_libraries(addmarkers ${catkin_LIBRARIES})
