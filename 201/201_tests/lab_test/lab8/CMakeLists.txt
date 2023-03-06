cmake_minimum_required(VERSION 3.24)
project(lab8 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab8 language_greeting.c)

add_executable(qsort quicksort.c qsort.c)