# cmake_minimum_required(VERSION <specify CMake version here>)
project(someTest)

set(CMAKE_CXX_STANDARD 11)

add_executable(someTest main.cpp)
add_executable(FileIOTest FileIO/test.cpp FileIO/test.h)