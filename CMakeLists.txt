cmake_minimum_required(VERSION 3.5)

project(synchronize_workspace)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(grammar)
add_subdirectory(leetcode)
add_subdirectory(offer2)


# project(test)
# add_executable(test test.cpp)


