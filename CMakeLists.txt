cmake_minimum_required(VERSION 3.10)

project(server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(include)

set(SRC_FILES src/Server.cpp src/TcpServer.cpp)

add_executable(server ${SRC_FILES})