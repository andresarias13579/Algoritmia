//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "Cola.h"
#include "funcionesCola.h"
using namespace std;

void construir(struct Cola & colaTAD){
    colaTAD.inicio = nullptr;
    colaTAD.fin = nullptr;
    colaTAD.longitud = 0;
}

/*devuelve la longitud de la cola*/
int longitud(const struct Cola & colaTAD) {
    return colaTAD.longitud;
}

void encolarPrioridad(struct Cola & colaTAD, const struct ElementoCola & elemento) {
    struct NodoCola *nuevo;
    nuevo = new NodoCola{};
    nuevo->elemento = elemento;
    if(esColaVacia(colaTAD)) {
        colaTAD.inicio = nuevo;
        colaTAD.fin = nuevo;
        if (elemento.prioridad=='V') {
            colaTAD.prioridadV = nuevo;
        }
    }
    else {
        if (elemento.prioridad!='V') {
            colaTAD.fin->siguiente = nuevo;
            colaTAD.fin = nuevo;
        }
        else {
            if (colaTAD.prioridadV == nullptr) {
                /*Esto significa que no hay ninguno con prioridad V en la cola, por lo que el elemento debe ser el primero de todos*/
                nuevo->siguiente = colaTAD.inicio;
                colaTAD.inicio = nuevo;
                colaTAD.prioridadV = nuevo;
            }
            else {
                if (colaTAD.prioridadV->siguiente == nullptr) {
                    colaTAD.fin = nuevo;
                }
                else {
                    nuevo->siguiente = colaTAD.prioridadV->siguiente;
                }
                colaTAD.prioridadV->siguiente = nuevo;
                colaTAD.prioridadV = nuevo;
            }
        }
    }
    colaTAD.longitud++;
}

void encolar(struct Cola &colaTAD, const struct ElementoCola & elemento){
    struct NodoCola *nuevo;
    nuevo = new NodoCola{};
    nuevo->elemento = elemento;
    if(esColaVacia(colaTAD)){
        colaTAD.inicio = nuevo;
        colaTAD.fin = nuevo;
    }
    else {
        colaTAD.fin->siguiente = nuevo;
        colaTAD.fin = nuevo;
    }
    colaTAD.longitud++;
}

struct ElementoCola desencolar(struct Cola & colaTAD){
    struct NodoCola * pSale;
    struct ElementoCola elemento;
    pSale = colaTAD.inicio;
    colaTAD.inicio = colaTAD.inicio->siguiente;
    elemento = pSale->elemento;
    colaTAD.longitud--;
    delete pSale;
    return elemento;
}

bool esColaVacia(const struct Cola & colaTAD){
    return colaTAD.inicio == nullptr;
}

void imprimir(const struct Cola & colaTAD) {
    if (esColaVacia(colaTAD)) {
        cout << "La cola esta vacia no se puede mostrar" << endl;
    } else {
        struct NodoCola * recorrido = colaTAD.inicio;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca las comas despues del inicio*/
            if ( not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento.codigo << "-" << recorrido->elemento.prioridad;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}