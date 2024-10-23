cmake_minimum_required(VERSION 3.29)
project(matrix_multiply)

set(CMAKE_CXX_STANDARD 20)

add_executable(matrix_multiply main.cpp
        Matrix.cpp
        Matrix.h)
