cmake_minimum_required(VERSION 3.20)
project(Exam
DESCRIPTION "Exam in datastructures and algorithms"
LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_PARALLEL_LEVEL 10)

add_compile_options(-Wall -Wextra -pedantic)

include_directories(../Prioritetskø/)
include_directories(../Binært_søgetræ/)
include_directories(../CriticalPath/)

add_executable(exam_2 2.cpp)
