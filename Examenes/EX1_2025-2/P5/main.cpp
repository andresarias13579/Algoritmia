#include <iostream>
#include <cstring>

#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"

using namespace std;
#include "BibliotecaCola/MisFunciones.h"

int main() {
    Cola cola;
    construir(cola);
    lecturaArchivos(cola,"eventos.txt","salida.txt");

    return 0;
}
