# CMakeのバージョンを設定
cmake_minimum_required(VERSION 2.8)

# プロジェクト名と使用する言語を設定
project(test_cmake C)     # Cの場合
# project(test_cmake CXX) # CPPファイルの場合

# good_morning.cppをコンパイルして静的ライブラリlibgreetings.aを作成
add_library(greetings STATIC good_morning.c)

# hello.c main.cからa.outを作成
add_executable(a.out hello.c main.c)

# a.outを作成するときに、greetingsをリンク
target_link_libraries(a.out greetings)