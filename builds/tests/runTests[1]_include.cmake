if(EXISTS "/home/nicholas/OperatingSystems/MultithreadWebserver/builds/tests/runTests[1]_tests.cmake")
  include("/home/nicholas/OperatingSystems/MultithreadWebserver/builds/tests/runTests[1]_tests.cmake")
else()
  add_test(runTests_NOT_BUILT runTests_NOT_BUILT)
endif()
