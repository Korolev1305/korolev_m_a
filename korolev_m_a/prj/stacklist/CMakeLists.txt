cmake_minimum_required(VERSION 3.6)
project(stacklist)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    stacklist.cpp
    stacklist.h
    test_stacklist.cpp)

add_executable(stacklist ${SOURCE_FILES})