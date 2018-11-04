cmake_minimum_required(VERSION 3.12)
project(assignment20183_wezpez)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(assignment20183_wezpez
        linkedlist.h
        node.h
        TestListD.cpp)
