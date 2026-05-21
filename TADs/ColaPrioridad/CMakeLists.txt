cmake_minimum_required(VERSION 4.0)
project(ColaPrioridad)

set(CMAKE_CXX_STANDARD 20)

add_executable(ColaPrioridad main.cpp
        BibliotecaCola/Cola.h
        BibliotecaCola/funcionesCola.cpp)
