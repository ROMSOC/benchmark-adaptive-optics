cmake_minimum_required(VERSION 3.6)
project(benchmarks)
set(CMAKE_CXX_STANDARD 14)

include_directories(Eigen)
add_executable(benchmarks main.cpp)
