cmake_minimum_required(VERSION 3.2.2)

project(AVLTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp AVLTree/AVLTree.cpp AVLTree/AVLTree.h)
add_executable(Main ${SOURCE_FILES})