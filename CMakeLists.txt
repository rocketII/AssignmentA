cmake_minimum_required(VERSION 3.3)
project(AssignmentA)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp  House.cpp House.h  HousingRegister.cpp HousingRegister.h)#test.cpp  system.h system.cpp
add_executable(AssignmentA ${SOURCE_FILES})
