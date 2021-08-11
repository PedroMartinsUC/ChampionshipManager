cmake_minimum_required(VERSION 3.15)
project(projeto_final C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Wextra")

add_executable(projeto_final main.c funcoes.h funcs.c)