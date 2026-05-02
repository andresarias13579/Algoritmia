cmake_minimum_required(VERSION 4.2)
project(CuadrigasFinal)

set(CMAKE_CXX_STANDARD 14)

include_directories(CuadrigasFinal/BibliotecaLista)

add_executable(CuadrigasFinal
        CuadrigasFinal/BibliotecaLista/ElementoLista.h
        CuadrigasFinal/BibliotecaLista/funcionesLista.cpp
        CuadrigasFinal/BibliotecaLista/funcionesLista.h
        CuadrigasFinal/BibliotecaLista/Lista.h
        CuadrigasFinal/BibliotecaLista/NodoLista.h
        CuadrigasFinal/main.cpp)
