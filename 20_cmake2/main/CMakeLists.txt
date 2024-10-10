# CMakeのバージョンを設定
cmake_minimum_required(VERSION 2.8)

# プロジェクト名と使用する言語を設定
project(test_cmake C)     # Cの場合
# project(test_cmake CXX) # CPPファイルの場合

add_executable(a.out ${PROJECT_SOURCE_DIR}/src/main.c)
# a.outをコンパイルする際にhelloをリンクする
target_link_libraries(a.out hello)
target_link_libraries(a.out good_morning)
