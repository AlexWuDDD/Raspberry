cmake_minimum_required(VERSION 3.5)
project(someTest)

set(CMAKE_CXX_STANDARD 11)

set(INC_DIR /usr/local/include)
set(LINK_DIR /usr/local/lib)

include_directories(${INC_DIR})
link_directories(${LINK_DIR})


add_executable(someTest main.cpp)
add_executable(FileIOTest FileIO/test.cpp FileIO/test.h)


add_executable(linkTest linkTest.cpp)

add_executable(libuvHelloWorld libuv/helloworld/main.cpp)
target_link_libraries(libuvHelloWorld uv)

add_executable(libuvIdleBasic libuv/idleBasic/main.cpp)
target_link_libraries(libuvIdleBasic uv)

add_executable(libuvUvcat libuv/uvcat/main.cpp)
target_link_libraries(libuvUvcat uv)

add_executable(libuvtee libuv/uvtee/main.cpp)
target_link_libraries(libuvtee uv)

add_executable(libuvonchange libuv/onchange/main.cpp)
target_link_libraries(libuvonchange uv)

add_executable(libuvTcpSever libuv/tcpEchoServer/main.cpp)
target_link_libraries(libuvTcpSever uv)

add_executable(libuvUDP libuv/UDP/main.cpp)
target_link_libraries(libuvUDP uv)

add_executable(libuvDNS libuv/dns/main.cpp)
target_link_libraries(libuvDNS uv)

add_executable(libuvInterface libuv/interfaces/main.cpp)
target_link_libraries(libuvInterface uv)