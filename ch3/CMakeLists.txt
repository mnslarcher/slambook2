cmake_minimum_required(VERSION 2.8)
project(chapter3)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(useEigen)
add_subdirectory(useGeometry)
# add_subdirectory(visualizeGeometry)
add_subdirectory(examples)