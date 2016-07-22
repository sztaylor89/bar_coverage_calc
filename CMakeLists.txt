cmake_minimum_required(VERSION 3.5)
project(bar_coverage_calc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    bar_coverage_calc.cpp)

add_executable(bar_coverage_calc ${SOURCE_FILES})