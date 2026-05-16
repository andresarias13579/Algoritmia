//Fecha:  lunes 01 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
using namespace std;
#include "BibliotecaPila/MisFunciones.h"

int main(int argc, char ** argv) {
    Pila pilaA, pilaB, pilaC;
    construir(pilaA);
    construir(pilaB);
    construir(pilaC);
    llenarPilaA(pilaA);
    llenarPilaB(pilaB);
    imprimir(pilaA);
    imprimir(pilaB);
    fusionarPilas(pilaA,pilaB,pilaC);
    imprimir(pilaC);
    return 0;
}
