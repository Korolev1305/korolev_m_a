cmake_minimum_required(VERSION 3.6)
project(stackArr)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES stackarr.cpp stackarr.h test_stackarr.cpp)
add_executable(stackArr ${SOURCE_FILES})