cmake_minimum_required(VERSION 3.17)
project(LABO_01_PRG2 C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(LABO_01_PRG2 main.c listes_dynamiques.h listes_dynamiques.c)