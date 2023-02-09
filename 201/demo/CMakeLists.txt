cmake_minimum_required(VERSION 3.23)
project(demo C)

set(CMAKE_C_STANDARD 99)

add_executable(demo main.c )

add_executable(celsius_scanf "Lecture 2amp3 demos-20230208/celsius_scanf.c")
add_executable(binary_op "Lecture 4 demos-20230208/binary_op.c")