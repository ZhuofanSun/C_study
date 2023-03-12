cmake_minimum_required(VERSION 3.24)
project(lab9 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab9 main.c)

add_executable(closest_flight closest_flight.c)
add_executable(sort_words sort_words.c str_quicksort.c str_quicksort.h)
add_executable(str_quicksort str_quicksort.c)