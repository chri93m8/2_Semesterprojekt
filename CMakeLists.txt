cmake_minimum_required(VERSION 3.5)
project(main)


# find_package(ur_rtde REQUIRED)
find_package(ur_rtde REQUIRED)
add_executable(main main.cpp src/robot_control.cpp)
target_link_libraries(main PRIVATE ur_rtde::rtde)
#target_link_libraries(main PRIVATE /include/robot_control.h)
include_directories(/home/morten/Workspace/2_Semesterprojekt/include)
include_directories(/home/morten/Workspace/2_Semesterprojekt/src)

