#include <iostream>

using namespace std;

void imprimirTablero(const int pos[4], ) {

}

int main() {
    int pos[4] = {0,0,0,0}; //estado inicial de las reinas en col = 0
    /**
     *  x   0   0   0
     *  x   0   0   0
     *  x   0   0   0
     *  x   0   0   0
     *
     *  Donde x es la posicion de la reina, cada espacio del arreglo es una reyna e indica su posicion
     *  en las columnas del tablero
     */
    int count = 0;
    bool terminado = false;
    int soluciones[10]{};
    int n_soluciones = 0;
    while (!terminado) {
        imprimirTablero(pos, count);
    }

    return 0;
}