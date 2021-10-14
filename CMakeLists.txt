cmake_minimum_required(VERSION 3.16)
project(StringLibrary)

set(CMAKE_CXX_STANDARD 14)

add_executable(StringLibrary main.cpp Library/myString.cpp Library/myString.h)
