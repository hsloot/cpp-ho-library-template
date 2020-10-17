# CMake generated Testfile for 
# Source directory: /home/runner/work/cpp-ho-library-template/cpp-ho-library-template/test
# Build directory: /home/runner/work/cpp-ho-library-template/build/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_all "/home/runner/work/cpp-ho-library-template/build/test/testlib")
set_tests_properties(test_all PROPERTIES  _BACKTRACE_TRIPLES "/home/runner/work/cpp-ho-library-template/cpp-ho-library-template/test/CMakeLists.txt;17;add_test;/home/runner/work/cpp-ho-library-template/cpp-ho-library-template/test/CMakeLists.txt;0;")
subdirs("../_deps/catch-build")
