cmake_minimum_required(VERSION 3.24)
project(lab6 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab6 split_time.c reverse_half.c)

add_executable(average average.c)

add_executable(reverse_half reverse_half.c)