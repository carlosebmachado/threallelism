cmake_minimum_required(VERSION 3.17)
project(threallelism)

# added -fopenmp
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

set(CMAKE_CXX_STANDARD 14)

add_executable(threallelism main.cpp watch.hpp matrix.hpp vector.hpp)