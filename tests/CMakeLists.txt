
# Fetch Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)


# Create test executable
add_executable(my_tests mock_test.cpp)
target_link_libraries(my_tests gtest gtest_main gmock gmock_main)

add_test(NAME MyTests COMMAND my_tests)