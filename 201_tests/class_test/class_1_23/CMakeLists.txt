cmake_minimum_required(VERSION 3.23)
project(class_1_23 C)

set(CMAKE_C_STANDARD 99)

add_executable(class_1_23 main.c)

add_executable(bounds bounds.c)
add_executable(array array.c)
add_executable(deal_hand deal_hand.c)
add_executable(find_repeated find_repeated.c)
add_executable(read_char read_char.c)
add_executable(two-d-array two-d-array.c)
add_executable(two-d-var-length two-d-var-length.c)
add_executable(var-length-array var-length-array.c)