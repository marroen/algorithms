cmake_minimum_required(VERSION 3.27)
project(algo LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

add_executable(algo src/main.cpp src/graph.cpp src/dfs/dfs.cpp)
target_compile_features(algo PUBLIC cxx_std_20)
