cmake_minimum_required(VERSION 3.20)
project(DataAlgorithms
DESCRIPTION "Course in datastructures and algorithms"
LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Export compile commands for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Build parallel
set(CMAKE_BUILD_PARALLEL_LEVEL 10)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(7)
add_subdirectory(port)
