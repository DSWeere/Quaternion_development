cmake_minimum_required(VERSION 3.7)
project(Quaternion)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Quaternion.cpp Quaternion.h Unittest.cpp)
add_executable(Quaternion ${SOURCE_FILES})