# setting CMake VERSION
cmake_minimum_required(VERSION 2.8)

# setting project name and project langes
project(test_cmake C)     # case c
# project(test_cmake CXX) # case c++

add_library(good_morning ${PROJECT_SOURCE_DIR}/src/good_morning.c)

target_include_directories(good_morning PUBLIC ${PROJECT_SOURCE_DIR}/inc)