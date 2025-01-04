cmake_minimum_required(VERSION 3.5.0)
project(flecstest1 VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB_RECURSE SOURCES
    src/*.h
    src/*.c
    src/*.cpp
)

add_executable(flecstest1 ${SOURCES})

