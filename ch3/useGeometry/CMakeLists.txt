cmake_minimum_required(VERSION 2.8)
project(useGeometry)

if(APPLE)
include_directories("/usr/local/include/eigen3")
else()
include_directories("/usr/include/eigen3")
endif()

add_executable(useGeometry useGeometry.cpp)