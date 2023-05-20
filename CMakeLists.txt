cmake_minimum_required(VERSION 3.24)
project(Lab8)

set(CMAKE_CXX_STANDARD 17)

file(GLOB structures_SRC structures/*.cpp)
file(GLOB tasks_SRC tasks/*.cpp)
file(GLOB etc_SRC etc/*.cpp)


add_executable(DNS ${structures_SRC} ${tasks_SRC} ${etc_SRC} main.cpp)