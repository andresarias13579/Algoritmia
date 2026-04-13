cmake_minimum_required(VERSION 4.2)
project(ejercicioMochila)

set(CMAKE_CXX_STANDARD 20)

add_executable(ejercicioMochila main.cpp
        Bibliotecas/Item.h
        Bibliotecas/KnapSackBruteForce.cpp
        Bibliotecas/KnapSackBruteForce.h)
