cmake_minimum_required(VERSION 3.20)
project(Testing
DESCRIPTION "Course in datastructures and algorithms"
LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Export compile commands for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Build parallel
set(CMAKE_BUILD_PARALLEL_LEVEL 10)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_compile_options(-Wall -Wextra -pedantic)

include_directories(../Prioritetskø/)
include_directories(../Binært_søgetræ/)
include_directories(../CriticalPath/)

add_executable(test1 test1.cpp)
add_executable(heap heap.cpp)
add_executable(heap_aktivity heap_aktivity.cpp ../CriticalPath/Aktivitet.cpp)
