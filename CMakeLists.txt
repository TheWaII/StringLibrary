cmake_minimum_required(VERSION 3.16)
project(StringLibrary)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory (src)
add_subdirectory (tests)
enable_testing ()
add_test (NAME MyTest COMMAND Test)