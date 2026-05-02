//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
using namespace std;
#include "misFunciones/FuncionesAuxiliares.h"

/*
 * IMPLEMENTACION DE UNA LISTA SIMPLEMENTE ENLAZADA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2025-2
 */
int main(int argc, char **argv) {
    //creamos los elementos;
    struct ElementoLista elementos[4]{};
    insertamosElementos(elementos[0],17,"Messala","Rojo");
    insertamosElementos(elementos[1],4,"Ben-Hur","Azul");
    insertamosElementos(elementos[2],12,"Artax","Verde");
    insertamosElementos(elementos[3],7,"Drusus","Negro");

    //creamos la lista
    struct Lista listaInicial;
    construir(listaInicial);
    for(int i=0;i<4;i++) {
        insertarAlFinal(listaInicial,elementos[i]);
    }
    imprimir(listaInicial);

    //reordenamos la lista
    ordenarLista(listaInicial);
    //mostramos la lista
    imprimir(listaInicial);

    return 0;
}
