cmake_minimum_required(VERSION 3.10)

project(MyServer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

enable_testing()
add_subdirectory(tests)

set(SRC_FILES src/SimpleServer.cpp src/main.cpp)
add_executable(MyServer ${SRC_FILES})
