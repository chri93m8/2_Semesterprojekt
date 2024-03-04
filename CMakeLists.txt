cmake_minimum_required(VERSION 3.5)
project(main)

# find_package(ur_rtde REQUIRED)
find_package(ur_rtde REQUIRED)
add_executable(main main.cpp)
target_link_libraries(main PRIVATE ur_rtde::rtde)



