# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/nicholas/OperatingSystems/MultithreadWebserver/builds/_deps/googletest-src"
  "/home/nicholas/OperatingSystems/MultithreadWebserver/builds/_deps/googletest-build"
  "/home/nicholas/OperatingSystems/MultithreadWebserver/builds/_deps/googletest-subbuild/googletest-populate-prefix"
  "/home/nicholas/OperatingSystems/MultithreadWebserver/builds/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/home/nicholas/OperatingSystems/MultithreadWebserver/builds/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/home/nicholas/OperatingSystems/MultithreadWebserver/builds/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/home/nicholas/OperatingSystems/MultithreadWebserver/builds/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/nicholas/OperatingSystems/MultithreadWebserver/builds/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/nicholas/OperatingSystems/MultithreadWebserver/builds/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
