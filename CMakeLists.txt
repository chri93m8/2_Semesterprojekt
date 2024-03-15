cmake_minimum_required(VERSION 3.5)
project(main)
set(DS_LIB_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}")

find_package(ur_rtde REQUIRED)
add_executable(main main.cpp src/robot_control.cpp src/kinematic.cpp src/game_control.cpp)
target_link_libraries(main PRIVATE ur_rtde::rtde)
include_directories(include/ src/ microcontroller/)
