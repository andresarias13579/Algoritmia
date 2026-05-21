//Fecha:  sábado 30 Agosto 2025
//Autor: Ana Roncal

#include <cstring>
#include <iostream>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;
#include "MisFunciones.h"

void insertarDatos(const char* codigo,const char *nombre,int ventas,int likes,struct ElementoLista &elemento) {
    strcpy(elemento.nombre,nombre);
    strcpy(elemento.codigo,codigo);
    elemento.ventas = ventas;
    elemento.likes = likes;
}

void ordenarLista(struct Lista &listaLibros) {
    int n,k;
    buscarIndicesVentas(listaLibros,n,k);
    cambiarNodos(listaLibros,n,k);
    buscarIndicesLikes(listaLibros,n,k);
    cambiarNodos(listaLibros,n,k);
}
void cambiarNodos(struct Lista &listaLibros,int n,int k) {
    NodoLista *recorrido,*anterior,*recN,*antN,*recK,*antK;
    recorrido = listaLibros.inicio;
    anterior = nullptr;
    int indice = 1;
    while (recorrido) {
        if (indice == n) {
            recN = recorrido;
            antN = anterior;
        }
        if (indice == k) {
            recK = recorrido;
            antK = anterior;
        }
        anterior = recorrido;
        recorrido = recorrido->siguiente;
        indice++;
    }
    if (antN)antN->siguiente = recK;
    else listaLibros.inicio = recK;
    if (antK)antK->siguiente = recN;
    else listaLibros.inicio = recN;
    antN = recN;
    recN = recN->siguiente;
    antK = recK;
    recK = recK->siguiente;
    antN->siguiente = recK;
    antK->siguiente = recN;
}
void buscarIndicesVentas(struct Lista listaLibros,int &n,int &k) {
    n=1;
    k=1;
    struct NodoLista *recorrido;
    recorrido = listaLibros.inicio;
    int minVentas = 0, maxVentas = 0;
    int indice = 1;
    while(recorrido) {
        if (minVentas == 0) minVentas = recorrido->elemento.ventas;
        if (maxVentas == 0) maxVentas = recorrido->elemento.ventas;
        if (recorrido->elemento.ventas < minVentas) {
            minVentas = recorrido->elemento.ventas;
            n = indice;
        }
        if (recorrido->elemento.ventas > maxVentas) {
            maxVentas = recorrido->elemento.ventas;
            k = indice;
        }
        indice++;
        recorrido = recorrido->siguiente;
    }
}
void buscarIndicesLikes(struct Lista listaLibros,int &n,int &k) {
    n=1;
    k=1;
    struct NodoLista *recorrido;
    recorrido = listaLibros.inicio;
    int minLikes = 0, maxLikes = 0;
    int indice = 1;
    while(recorrido) {
        if (minLikes == 0) minLikes = recorrido->elemento.likes;
        if (maxLikes == 0) maxLikes = recorrido->elemento.likes;
        if (recorrido->elemento.likes < minLikes) {
            minLikes = recorrido->elemento.likes;
            n = indice;
        }
        if (recorrido->elemento.likes > maxLikes) {
            maxLikes = recorrido->elemento.likes;
            k = indice;
        }
        indice++;
        recorrido = recorrido->siguiente;
    }
}