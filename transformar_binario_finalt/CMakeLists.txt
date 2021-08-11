cmake_minimum_required(VERSION 3.15)
project(transformar_binario C)

set(CMAKE_C_STANDARD 99)

add_executable(transformar_binario main.c funcoes.h funcs.c)