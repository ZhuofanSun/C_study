cmake_minimum_required(VERSION 3.24)
project(ass2_test C)

set(CMAKE_C_STANDARD 99)


add_executable(find_substring find_substring.c)
add_executable(error_checking error_checking.c)
add_executable(puzzle2D puzzle2D.c error_checking.c)
add_executable(wordSearch2D wordSearch2D.c error_checking.c puzzle2D.c)
add_executable(generate_matrix generate_matrix.c)