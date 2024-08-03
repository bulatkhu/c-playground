cmake_minimum_required(VERSION 3.28)
project(playground C)

set(CMAKE_C_STANDARD 11)

add_executable(hello_world examples/hello_world/main.c)
add_executable(filo examples/filo/filo.c)
add_executable(pointers examples/pointers.c)

