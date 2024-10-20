# setting CMake VERSION
cmake_minimum_required(VERSION 2.8)

# setting project name and project langes
project(test_cmake C)     # case c
# project(test_cmake CXX) # case c++

add_executable(a.out ${PROJECT_SOURCE_DIR}/src/main.c)
# link "greetings" to a.out
target_link_libraries(a.out hello)
target_link_libraries(a.out good_morning)
