cmake_minimum_required(VERSION 3.28)
project(playground C)

set(CMAKE_C_STANDARD 11)

add_executable(hello_world examples/hello_world/main.c)
add_executable(filo examples/filo/filo.c)
add_executable(pointers examples/pointers.c)
add_executable(sieve examples/sieve.c)
add_executable(lilo examples/lilo.c
        examples/lilo.c)
add_executable(rsort examples/rsort.c)
add_executable(clash_plist examples/clash/plist.c
        examples/clash/plist.c)
add_executable(halde examples/halde/halde.c)
add_executable(halde_test examples/halde/test.c
        examples/halde/halde.c)
