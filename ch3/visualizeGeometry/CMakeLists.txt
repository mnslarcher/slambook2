cmake_minimum_required(VERSION 2.8)
project(visualizeGeometry)

set(CMAKE_CXX_FLAGS "-std=c++11")

if(APPLE)
include_directories("/usr/local/include/eigen3")
else()
include_directories("/usr/include/eigen3")
endif()

find_package(Pangolin)
include_directories(${Pangolin_INCLUDE_DIRS})

add_executable(visualizeGeometry visualizeGeometry.cpp)
target_link_libraries(visualizeGeometry, ${Pangolin_LIBRARIES})