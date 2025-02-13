set(TEST_FILES ../src/TcpServer.cpp test.cpp)


add_executable(runTests ${TEST_FILES})

target_include_directories(runTests PRIVATE ../include)
target_link_libraries(runTests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(runTests)