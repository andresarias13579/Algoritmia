//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
using namespace std;
#include "BibliotecaLista/MisFunciones.h"

int main(int argc, char **argv) {
    Lista listaRobot;
    construir(listaRobot);
    // insertarAlInicio(listaRobot,{6,'B'});
    // insertarAlInicio(listaRobot,{5,'A'});
    // insertarAlInicio(listaRobot,{9,'C'});
    // insertarAlInicio(listaRobot,{2,'A'});
    // insertarAlInicio(listaRobot,{7,'B'});
    insertarAlInicio(listaRobot,{4,'A'});
    insertarAlInicio(listaRobot,{8,'C'});
    insertarAlInicio(listaRobot,{9,'A'});
    insertarAlInicio(listaRobot,{3,'C'});

    imprimir(listaRobot);
    ordenarLista(listaRobot);
    imprimir(listaRobot);

    return 0;
}
