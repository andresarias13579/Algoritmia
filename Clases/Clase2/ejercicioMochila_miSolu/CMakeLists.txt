cmake_minimum_required(VERSION 4.2)
project(ejercicioMochila_miSolu)

set(CMAKE_CXX_STANDARD 20)

add_executable(ejercicioMochila_miSolu main.cpp
        Bibliotecas/Item.h
        Bibliotecas/mochila.cpp
        Bibliotecas/mochila.h)
