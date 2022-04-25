if(APPLE)
include_directories("/usr/local/include/eigen3")
else()
include_directories("/usr/include/eigen3")
endif()

add_executable(coordinateTransform coordinateTransform.cpp)