# setting CMake VERSION
cmake_minimum_required(VERSION 2.8)

# setting project name and project langes
project(test_cmake C)     # case c
# project(test_cmake CXX) # case c++

add_library(hello ${PROJECT_SOURCE_DIR}/src/hello.c)

target_include_directories(hello PUBLIC ${PROJECT_SOURCE_DIR}/inc)