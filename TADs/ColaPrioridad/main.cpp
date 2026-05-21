#include <iostream>

#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"

int main() {
    Cola cola;
    construir(cola);
    ElementoCola elemento;
    elemento.codigo = 10;
    elemento.prioridad = 'V';
    encolarPrioridad(cola,elemento);
    elemento.codigo = 20;
    elemento.prioridad = 'U';
    encolarPrioridad(cola,elemento);
    elemento.codigo = 30;
    elemento.prioridad = 'V';
    encolarPrioridad(cola,elemento);
    imprimir(cola);
    return 0;
}
