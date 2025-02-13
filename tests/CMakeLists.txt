

set(TEST_FILES test.cpp)

add_executable(tests ${TEST_FILES})
target_link_libraries(tests PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)