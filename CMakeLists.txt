cmake_minimum_required(VERSION 3.29)
project(math_graph_cpp)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(libs/StoneMath)

find_package(raylib CONFIG REQUIRED)

add_executable(math_graph_cpp main.cpp
        CoordinateSystem.cpp
        CoordinateSystem.h
        Point.cpp
        Point.h)

target_link_libraries(math_graph_cpp PRIVATE raylib StoneMath)
