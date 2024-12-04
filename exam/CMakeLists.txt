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

add_executable(exam_1 exam_1.cpp)
add_executable(exam_2 exam_2.cpp)
add_executable(exam_3 exam_3.cpp)
add_executable(exam_4 exam_4.cpp)
add_executable(exam_5 exam_5.cpp)
add_executable(exam_6 exam_6.cpp)
add_executable(exam_7 exam_7.cpp)
add_executable(exam_8 exam_8.cpp)
add_executable(exam_9 exam_9.cpp)
