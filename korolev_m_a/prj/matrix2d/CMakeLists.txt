cmake_minimum_required(VERSION 3.6)
project(matrix2d)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES matrix2d.cpp matrix2d.h test_matrix.cpp)
add_executable(matrix2d ${SOURCE_FILES})