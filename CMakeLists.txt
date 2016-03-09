cmake_minimum_required(VERSION 3.3)
project(AssignmentA)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp CellPhone.h CellPhoneHandler.h System.h CellPhone.cpp CellPhoneHandler.cpp System.cpp TestCellPhoneHandler.h TestCellPhoneHandler.cpp )
add_executable(AssignmentA ${SOURCE_FILES})
