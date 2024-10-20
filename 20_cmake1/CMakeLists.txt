# setting CMake VERSION
cmake_minimum_required(VERSION 2.8)

# setting project name and project langes
project(test_cmake C)     # case c
# project(test_cmake CXX) # case c++

# Compile good_morning.cpp and create static library libgreetings.a
add_library(greetings STATIC good_morning.c)

# create a.out by hello.c, main.c
add_executable(a.out hello.c main.c)

# link "greetings" to a.out
target_link_libraries(a.out greetings)