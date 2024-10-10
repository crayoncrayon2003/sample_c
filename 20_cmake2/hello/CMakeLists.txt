# CMakeのバージョンを設定
cmake_minimum_required(VERSION 2.8)

# プロジェクト名と使用する言語を設定
project(test_cmake C)     # Cの場合
# project(test_cmake CXX) # CPPファイルの場合

add_library(hello ${PROJECT_SOURCE_DIR}/src/hello.c)

target_include_directories(hello PUBLIC ${PROJECT_SOURCE_DIR}/inc)