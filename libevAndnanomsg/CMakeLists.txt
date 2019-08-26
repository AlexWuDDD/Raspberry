# cmake_minimum_required(VERSION <specify CMake version here>)
project(libevAndnanomsg)

set(CMAKE_CXX_STANDARD 11)


SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")


set(CMAKE_CXX_STANDARD 11)

set(INC_DIR /usr/local/include)
set(LINK_DIR /usr/local/lib)


include_directories(${INC_DIR})
link_directories(${LINK_DIR})



add_executable(libevAndnanomsg main.cpp worker.cpp)
target_link_libraries(libevAndnanomsg pthread nanomsg ev pthread)