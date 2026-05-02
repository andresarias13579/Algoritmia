cmake_minimum_required(VERSION 4.2)
project(ListaSimplementeEnlazada)

set(CMAKE_CXX_STANDARD 14)

include_directories(ListaSimplementeEnlazada/BibliotecaLista)

add_executable(ListaSimplementeEnlazada
        ListaSimplementeEnlazada/BibliotecaLista/ElementoLista.h
        ListaSimplementeEnlazada/BibliotecaLista/funcionesLista.cpp
        ListaSimplementeEnlazada/BibliotecaLista/funcionesLista.h
        ListaSimplementeEnlazada/BibliotecaLista/Lista.h
        ListaSimplementeEnlazada/BibliotecaLista/NodoLista.h
        ListaSimplementeEnlazada/main.cpp
        ListaSimplementeEnlazada/misFunciones/FuncionesAuxiliares.cpp
        ListaSimplementeEnlazada/misFunciones/FuncionesAuxiliares.h)
