cmake_minimum_required(VERSION 3.24)
project(ass2_test C)

set(CMAKE_C_STANDARD 99)

add_executable(ass2_test find_substring.c error_checking.c error_checking.h)

add_executable(puzzle2D puzzle2D.c)
add_executable(wordSearch2D wordSearch2D.c)
add_executable(error_checking error_checking.c)