cmake_minimum_required(VERSION 3.23)
project(class_2_3 C)

set(CMAKE_C_STANDARD 99)

add_executable(class_2_3 main.c)

add_executable(static static.c)
add_executable(stack stack.c)