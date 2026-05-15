#include <iostream>
#include <cstring>
#include "Lista.h"
#include "funcionesLista.h"
#include "NodoLista.h"
using namespace std;
#include "MisFunciones.h"

void insertarJugador(int numero,const char *apellido,const char* posicion, ElementoLista &elemento) {
    strcpy(elemento.apellido,apellido);
    strcpy(elemento.posicion,posicion);
    elemento.numero = numero;
}

void reordenaFormacion(struct Lista &listaJugadores,const char *primero,const char*segundo,const char*tercero,const char*cuarto) {
    struct NodoLista *recorrido = listaJugadores.inicio,*anterior = nullptr;
    struct NodoLista *primeroIni = nullptr,*primeroFin = nullptr,
                    *segundoIni = nullptr,*segundoFin = nullptr,
                    *terceroIni = nullptr,*terceroFin = nullptr,
                    *cuartoIni = nullptr,*cuartoFin = nullptr;
    while(recorrido) {
        struct NodoLista *siguienteNodo = recorrido->siguiente;
        recorrido->siguiente = nullptr;
        if (strcmp(recorrido->elemento.posicion,primero) == 0) { // puntero primero
            if (anterior) anterior->siguiente = recorrido->siguiente;
            else listaJugadores.inicio = recorrido->siguiente;
            recorrido->siguiente = primeroIni;
            primeroIni = recorrido;
            if (primeroFin == nullptr) primeroFin = primeroIni;
        }
        if (strcmp(recorrido->elemento.posicion,segundo) == 0) { // puntero segundo
            if (anterior) anterior->siguiente = recorrido->siguiente;
            else listaJugadores.inicio = recorrido->siguiente;
            recorrido->siguiente = segundoIni;
            segundoIni = recorrido;
            if (segundoFin == nullptr) segundoFin = segundoIni;
        }
        if (strcmp(recorrido->elemento.posicion,tercero) == 0) { // puntero tercero
            if (anterior) anterior->siguiente = recorrido->siguiente;
            else listaJugadores.inicio = recorrido->siguiente;
            recorrido->siguiente = terceroIni;
            terceroIni = recorrido;
            if (terceroFin == nullptr) terceroFin = terceroIni;
        }
        if (strcmp(recorrido->elemento.posicion,cuarto) == 0) { // puntero cuarto
            if (anterior) anterior->siguiente = recorrido->siguiente;
            else listaJugadores.inicio = recorrido->siguiente;
            recorrido->siguiente = cuartoIni;
            cuartoIni = recorrido;
            if (cuartoFin == nullptr) cuartoFin = cuartoIni;
        }
        recorrido = siguienteNodo;
    }

    listaJugadores.inicio = primeroIni;
    primeroFin->siguiente = segundoIni;
    segundoFin->siguiente = terceroIni;
    terceroFin->siguiente = cuartoIni;

    //SOLUCION DE GEMINI ZZZZ
    // struct NodoLista *ultimoConectado = nullptr;

    // Conectamos la Posición 1
    // if (primeroIni != nullptr) {
    //     listaJugadores.inicio = primeroIni;
    //     ultimoConectado = primeroFin;
    // }
    // // Conectamos la Posición 2
    // if (segundoIni != nullptr) {
    //     if (listaJugadores.inicio == nullptr) listaJugadores.inicio = segundoIni;
    //     else ultimoConectado->siguiente = segundoIni;
    //     ultimoConectado = segundoFin;
    // }
    // // Conectamos la Posición 3
    // if (terceroIni != nullptr) {
    //     if (listaJugadores.inicio == nullptr) listaJugadores.inicio = terceroIni;
    //     else ultimoConectado->siguiente = terceroIni;
    //     ultimoConectado = terceroFin;
    // }
    // // Conectamos la Posición 4
    // if (cuartoIni != nullptr) {
    //     if (listaJugadores.inicio == nullptr) listaJugadores.inicio = cuartoIni;
    //     else ultimoConectado->siguiente = cuartoIni;
    //     // No necesitamos actualizar 'ultimoConectado' aquí porque es la última lista.
    //     // Además, al insertar como pila, el último nodo naturalmente tiene su 'siguiente' en nullptr.
    // }
}

