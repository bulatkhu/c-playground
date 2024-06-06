cmake_minimum_required(VERSION 3.28)
project(playground C)

set(CMAKE_C_STANDARD 11)

add_executable(playground examples/hello_world/main.c
        examples/filo/filo.c
)
