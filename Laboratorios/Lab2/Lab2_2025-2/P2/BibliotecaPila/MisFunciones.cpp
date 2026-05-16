
#include <iostream>
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;
#include "MisFunciones.h"

void llenarPilaA(Pila &pilaA) {
    ElementoPila elemento[3];
    elemento[0].peso = 20;
    elemento[1].peso = 15;
    elemento[2].peso = 5;
    for (int i = 0; i < 3; i++) {
        apilar(pilaA, elemento[i]);
    }
}
void llenarPilaB(Pila &pilaB) {
    ElementoPila elemento[4];
    elemento[0].peso = 18;
    elemento[1].peso = 12;
    elemento[2].peso = 10;
    elemento[3].peso = 2;
    for (int i = 0; i < 4; i++) {
        apilar(pilaB, elemento[i]);
    }
}
void fusionarPilas(Pila &pilaA,Pila &pilaB,Pila &pilaC) {
    ElementoPila elementoA,elementoB;
    elementoA = desapilar(pilaA);
    elementoB = desapilar(pilaB);
    if (elementoA.peso > elementoB.peso) {
        apilar(pilaC, elementoA);
        apilar(pilaC, elementoB);
    }else {
        apilar(pilaC, elementoB);
        apilar(pilaC, elementoA);
    }
    while (not esPilaVacia(pilaA) && not esPilaVacia(pilaB)) {
        int cantidadC;
        elementoA = cima(pilaA);
        elementoB = cima(pilaB);
        cantidadC = pilaC.longitud;
        if (elementoA.peso > elementoB.peso) {

            hanoi(cantidadC,pilaC,pilaB,pilaA);
            apilar (pilaC, desapilar(pilaB));
            hanoi(cantidadC,pilaA,pilaB,pilaC);
        }else {
            hanoi(cantidadC,pilaC,pilaA,pilaB);
            apilar (pilaC, desapilar(pilaA));
            hanoi(cantidadC,pilaB,pilaA,pilaC);

        }
    }
    int cantidadC = pilaC.longitud;
    if (not esPilaVacia(pilaA)) {
        hanoi(cantidadC,pilaC,pilaA,pilaB);
        apilar (pilaC, desapilar(pilaA));
        hanoi(cantidadC,pilaB,pilaA,pilaC);
    }
    if (not esPilaVacia(pilaB)) {
        hanoi(cantidadC,pilaC,pilaB,pilaA);
        apilar (pilaC, desapilar(pilaB));
        hanoi(cantidadC,pilaA,pilaB,pilaC);
    }
}
void hanoi(int n, Pila &origen, Pila &auxiliar, Pila &destino) {
    if (n == 1) {
        apilar(destino, desapilar(origen));
        return;
    }
    hanoi(n - 1, origen, destino, auxiliar);
    apilar(destino, desapilar(origen));
    hanoi(n - 1, auxiliar, origen, destino);
}