cmake_minimum_required(VERSION 3.10)

project(server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SRC_FILES src/Server.cpp src/TcpServer.cpp)

add_executable(server ${SRC_FILES})

# Enable GTEST
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)
add_subdirectory(tests)