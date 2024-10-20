# setting CMake VERSION
cmake_minimum_required(VERSION 2.8)

# setting project name and project langes
project(test_cmake C)     # case c
# project(test_cmake CXX) # case c++

# add subdirectory
add_subdirectory(hello)
add_subdirectory(good_morning)
add_subdirectory(main)