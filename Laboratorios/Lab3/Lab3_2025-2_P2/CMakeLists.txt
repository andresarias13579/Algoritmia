cmake_minimum_required(VERSION 4.0)
project(Cola)

set(CMAKE_CXX_STANDARD 20)

add_executable(Cola main.cpp
        BibliotecaCola/funcionesCola.cpp
        BibliotecaCola/funcionesCola.h
        BibliotecaCola/NodoCola.h
        BibliotecaCola/Cola.h
        BibliotecaCola/ElementoCola.h
        BibliotecaCola/funcionesPila.cpp
        BibliotecaCola/ElementoPila.h
        BibliotecaCola/ElementoPila.h
        BibliotecaCola/funcionesPila.h
        BibliotecaCola/funcionesPila.cpp
        BibliotecaCola/funcionesPila.h
        BibliotecaCola/NodoPila.h
        BibliotecaCola/MisFunciones.cpp
        BibliotecaCola/MisFunciones.h
)
