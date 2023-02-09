cmake_minimum_required(VERSION 3.23)
project(class_1_16 C)

set(CMAKE_C_STANDARD 99)

add_executable(class_1_16 main.c)

add_executable(canopen canopen.c)
add_executable(file_modes file_modes.c)
add_executable(read_file read_file.c)
add_executable(stream stream.c)