cmake_minimum_required(VERSION 3.14)
project(statickPile C)

set(CMAKE_C_STANDARD 11)

add_executable(statickPile main.c)

target_include_directories (statickPile PUBLIC ./includes/statickStack/)