cmake_minimum_required(VERSION 3.3)
project(AssignmentA)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp test.cpp Gift.cpp Gift.h Container.cpp Container.h)
add_executable(AssignmentA ${SOURCE_FILES})
