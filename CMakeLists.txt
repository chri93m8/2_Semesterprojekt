cmake_minimum_required(VERSION 3.5)
project(main LANGUAGES C CXX)
set(DS_LIB_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

find_package(ur_rtde REQUIRED)
add_executable(main main.cpp  src/robot_control.cpp src/kinematic.cpp src/game_control.cpp src/mic_control.cpp)
target_link_libraries(main PRIVATE ur_rtde::rtde ${CURSES_LIBRARIES})

include_directories(include/ src/ microcontroller/)


