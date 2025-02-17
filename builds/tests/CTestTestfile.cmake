# CMake generated Testfile for 
# Source directory: /home/nicholas/OperatingSystems/MultithreadWebserver/tests
# Build directory: /home/nicholas/OperatingSystems/MultithreadWebserver/builds/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MyTests "/home/nicholas/OperatingSystems/MultithreadWebserver/builds/tests/my_tests")
set_tests_properties(MyTests PROPERTIES  _BACKTRACE_TRIPLES "/home/nicholas/OperatingSystems/MultithreadWebserver/tests/CMakeLists.txt;15;add_test;/home/nicholas/OperatingSystems/MultithreadWebserver/tests/CMakeLists.txt;0;")
subdirs("../_deps/googletest-build")
