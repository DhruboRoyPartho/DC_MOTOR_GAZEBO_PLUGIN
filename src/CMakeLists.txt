cmake_minimum_required(VERSION 3.10)
project(dc_motor_plugin)

find_package(gazebo REQUIRED)

include_directories(${GAZEBO_INCLUDE_DIRS})

add_library(dc_motor_plugin SHARED dc_motor_plugin.cpp)
target_link_libraries(dc_motor_plugin ${GAZEBO_LIBRARIES})
