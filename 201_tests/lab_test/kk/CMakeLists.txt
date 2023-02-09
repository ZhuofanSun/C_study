cmake_minimum_required(VERSION 3.23)
project(lab5 C)

set(CMAKE_C_STANDARD 99)



add_executable(check_nesting stack.h stack.c check_nesting.c)