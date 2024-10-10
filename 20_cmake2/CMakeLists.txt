# CMakeのバージョンを設定
cmake_minimum_required(VERSION 2.8)

# プロジェクト名と使用する言語を設定
project(test_cmake C)     # Cの場合
# project(test_cmake CXX) # CPPファイルの場合

# サブディレクトリを登録
add_subdirectory(hello)
add_subdirectory(good_morning)
add_subdirectory(main)