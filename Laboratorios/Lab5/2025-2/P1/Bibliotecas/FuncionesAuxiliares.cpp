#include <iostream>

using namespace std;
#include "Nodo.h"
#include "Arbol.h"
#include "FuncionesAuxiliares.h"

int ALTURA(Nodo * nodo) {
    if (nodo == nullptr) return 0;
    return nodo->altura;
}
int FACTOR_BALANCE(Nodo *nodo) {
    if (nodo == nullptr) return 0;
    int altura_izq = ALTURA(nodo->izq);
    int altura_der = ALTURA(nodo->der);
    return altura_izq - altura_der;
}
Nodo * rotacionDerecha(Nodo * y) {
    Nodo *x = y->izq;
    Nodo *T2 = x->der;

    x->der = y;
    y->izq = T2;

    y->altura = 1 + max(ALTURA(y->izq), ALTURA(y->der));
    x->altura = 1 + max(ALTURA(x->izq), ALTURA(x->der));
    return x;
}
Nodo * rotacionIzquierda(Nodo * x) {
    Nodo *y = x->der;
    Nodo *T2 = y->izq;

    y->izq = x;
    x->der = T2;

    x->altura = 1 + max(ALTURA(x->izq), ALTURA(x->der));
    y->altura = 1 + max(ALTURA(y->izq), ALTURA(y->der));

    return y;
}
Nodo * insertarAVL(Nodo *nodo, int clave) {
    if (nodo == nullptr) {
        nodo = new Nodo;
        nodo->dni = clave;
        nodo->izq = nullptr;
        nodo->der = nullptr;
        nodo->altura = 1;
        return nodo;
    }
    if (clave < nodo->dni) {
        nodo->izq = insertarAVL(nodo->izq, clave);
    }else if (clave > nodo->dni) {
        nodo->der = insertarAVL(nodo->der, clave);
    } else return nodo;

    nodo->altura = 1 + max(ALTURA(nodo->izq), ALTURA(nodo->der));

    int FB = FACTOR_BALANCE(nodo);

    if (FB > 1 and clave < nodo->izq->dni) {
        nodo = rotacionDerecha(nodo);
    }
    if (FB < -1 and clave > nodo->der->dni) {
        nodo = rotacionIzquierda(nodo);
    }
    if (FB > 1 and clave > nodo->izq->dni) {
        nodo->izq = rotacionIzquierda(nodo->izq);
        return rotacionDerecha(nodo);
    }
    if (FB < -1 and clave < nodo->der->dni) {
        nodo->der = rotacionDerecha(nodo->der);
        return rotacionIzquierda(nodo);
    }
    return nodo;
}
void construir (Arbol &arbol) {
    arbol.raiz = nullptr;
}
void insertar(Arbol &arbol, int clave) {
    // if (arbol.raiz != nullptr) {
    //
    // }
    arbol.raiz = insertarAVL(arbol.raiz, clave);
}
void recorrido_inorden(const Arbol &arbol) {
    recorridoRecursivo(arbol.raiz);
}
void recorridoRecursivo(Nodo *nodo) {
    if (nodo == nullptr) return;
    recorridoRecursivo(nodo->izq);
    cout << nodo->dni<<"(h:"<<nodo->altura<<")   ";
    recorridoRecursivo(nodo->der);
}