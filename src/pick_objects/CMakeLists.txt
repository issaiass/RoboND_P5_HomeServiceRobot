cmake_minimum_required(VERSION 3.0.2)
project(pick_objects)

find_package(catkin REQUIRED COMPONENTS
  actionlib
  move_base_msgs
  roscpp
  rospy
)

add_compile_options(-std=c++11)

catkin_package(

)


include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(pickobjects src/pick_objects.cpp)
target_link_libraries(pickobjects ${catkin_LIBRARIES})
