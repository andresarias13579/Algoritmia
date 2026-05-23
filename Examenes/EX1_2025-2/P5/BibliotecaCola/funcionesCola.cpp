//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include <fstream>
#include "Cola.h"
#include "funcionesCola.h"
using namespace std;


void construir(struct Cola & colaTAD){
    colaTAD.head = nullptr;
    colaTAD.tail = nullptr;
    colaTAD.last1 = nullptr;
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
        colaTAD.head = nuevo;
        colaTAD.tail = nuevo;
        if (elemento.prioridad=='P') {
            colaTAD.last1 = nuevo;
        }
    }
    else {
        if (elemento.prioridad!='P') {
            colaTAD.tail->siguiente = nuevo;
            colaTAD.tail = nuevo;
        }
        else {
            if (colaTAD.last1 == nullptr) {
                /*Esto significa que no hay ninguno con prioridad V en la cola, por lo que el elemento debe ser el primero de todos*/
                nuevo->siguiente = colaTAD.head;
                colaTAD.head = nuevo;
                colaTAD.last1 = nuevo;
            }
            else {
                if (colaTAD.last1->siguiente == nullptr) {
                    colaTAD.tail = nuevo;
                }
                else {
                    nuevo->siguiente = colaTAD.last1->siguiente;
                }
                colaTAD.last1->siguiente = nuevo;
                colaTAD.last1 = nuevo;
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
        colaTAD.head = nuevo;
        colaTAD.tail = nuevo;
    }
    else {
        colaTAD.tail->siguiente = nuevo;
        colaTAD.tail = nuevo;
    }
    colaTAD.longitud++;
}

struct ElementoCola desencolar(struct Cola & colaTAD){
    struct NodoCola * pSale;
    struct ElementoCola elemento;
    pSale = colaTAD.head;
    colaTAD.head = colaTAD.head->siguiente;
    if (colaTAD.head == nullptr) colaTAD.tail = nullptr;
    if (pSale == colaTAD.last1) colaTAD.last1 = nullptr;
    elemento = pSale->elemento;
    colaTAD.longitud--;
    delete pSale;
    return elemento;
}

bool esColaVacia(const struct Cola & colaTAD){
    return colaTAD.head == nullptr;
}

void imprimir(const struct Cola & colaTAD,ofstream &arch) {
    if (esColaVacia(colaTAD)) {
        arch << "La cola esta vacia no se puede mostrar" << endl;
    } else {
        struct NodoCola * recorrido = colaTAD.head;
        int estaImprimiendoPreferencial = 1,estaImprimiendoRegular=1;
        arch << "[";

        while (recorrido != nullptr) {
            if (recorrido->elemento.prioridad=='R') {
                if (estaImprimiendoPreferencial) {
                    arch<<"P1: ";
                    estaImprimiendoPreferencial=0;
                }
                arch<<recorrido->elemento.codigo;
                if (recorrido->siguiente!=nullptr) arch<<",";
            }
            if (recorrido->elemento.prioridad=='P') {
                if (estaImprimiendoPreferencial) {
                    arch<<"][P2: ";
                    estaImprimiendoRegular=0;
                }
                arch<<recorrido->elemento.codigo;
                if (recorrido->siguiente!=nullptr) arch<<",";
            }

            recorrido = recorrido->siguiente;
        }
        arch << "]" << endl;
    }
}