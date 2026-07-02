//
// Created by Andres on 1/07/2026.
//

#ifndef P1_FUNCIONESAUXILIARES_H
#define P1_FUNCIONESAUXILIARES_H

int ALTURA(Nodo * nodo);
int FACTOR_BALANCE(Nodo * nodo);
Nodo * rotacionDerecha(Nodo * y);
Nodo * rotacionIzquierda(Nodo * x);
Nodo * insertarAVL(Nodo *nodo, int clave);
void construir (Arbol &arbol);
void insertar(Arbol &arbol, int clave);
void recorrido_inorden(const Arbol &arbol);
void recorridoRecursivo(Nodo *nodo);

#endif //P1_FUNCIONESAUXILIARES_H
