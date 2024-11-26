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

add_executable(port2_1 port_1.cpp)
target_compile_options(port2_1 PRIVATE -Wall -Wextra -pedantic)

add_executable(port2_2 port_2.cpp BinarySearchTree.cpp)
target_compile_options(port2_2 PRIVATE -Wall -Wextra -pedantic)
