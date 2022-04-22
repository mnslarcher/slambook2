cmake_minimum_required(VERSION 2.8)
project(useEigen)

set(CMAKE_BUILD_TYPE "Release")
# CMAKE_BUILD_TYPE 
# Specifies the build type on single-configuration generators (e.g. Makefile 
# Generators or Ninja). 
# 1. Release: high optimization level, no debug info, code or asserts.
# 2. Debug: No optimization, asserts enabled, [custom debug (output) code 
#    enabled], debug info included in executable (so you can step through the 
#    code with a debugger and have address to source-file:line-number 
#    translation).
# 3. RelWithDebInfo: optimized, *with* debug info, but no debug (output) code or 
#    asserts.
# 4. MinSizeRel: same as Release but optimizing for size rather than speed.

set(CMAKE_CXX_FLAGS "-O3")
# CMAKE_CXX_FLAGS initialize the CXXFLAGS CMake Environment Variable.
# Turning on optimization flags makes the compiler attempt to improve the 
# performance and/or code size at the expense of compilation time and possibly 
# the ability to debug the program.

# 03 Optimize yet more.
# -O3 turns on all optimizations specified by -O2 and also turns on the 
# -finline-functions, -funswitch-loops, -fpredictive-commoning, 
# -fgcse-after-reload, -ftree-vectorize, -fvect-cost-model, -ftree-partial-pre 
# and -fipa-cp-clone options. 

include_directories("/usr/include/eigen3")
add_executable(eigenMatrix eigenMatrix.cpp)