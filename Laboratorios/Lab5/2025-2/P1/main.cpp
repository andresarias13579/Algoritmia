#include <iostream>

#include "Bibliotecas/Arbol.h"

using namespace std;
#include "Bibliotecas/FuncionesAuxiliares.h"

int main() {
    Arbol arbol;

    construir (arbol);
    // insertar(arbol, 72649318);
    // insertar(arbol, 50823147);
    // insertar(arbol, 81234567);
    // insertar(arbol, 40987654);
    // insertar(arbol, 65012345);
    // insertar(arbol, 94561237);
    // insertar(arbol, 30124598);
    int arr[]{72000000, 50000000, 81000000, 40000000, 65000000, 94000000, 30000000, 20000000, 10000000};
    int cantDatos = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < cantDatos; ++i) {
        insertar(arbol, arr[i]);
    }

    recorrido_inorden(arbol);

    return 0;
}