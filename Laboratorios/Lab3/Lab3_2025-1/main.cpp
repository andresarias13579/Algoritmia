//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
using namespace std;
#include "BibliotecaLista/MisFunciones.h"

/*
 * IMPLEMENTACION DE UNA LISTA SIMPLEMENTE ENLAZADA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2025-2
 */
int main(int argc, char **argv) {

    struct ElementoLista elemento[8]{};
    struct Lista listaLibros;
    construir(listaLibros);
    insertarDatos("L001","Cien años de soledad",200,400,elemento[0]);
    insertarDatos("L002","1984",600,5000,elemento[1]);
    insertarDatos("L003","El principito",120,7500,elemento[2]);
    insertarDatos("L004","Harry Potter",1200,12000,elemento[3]);
    insertarDatos("L005","Sapiens",350,1000,elemento[4]);
    insertarDatos("L006","Don Quijote",400,780,elemento[5]);
    insertarDatos("L007","Farenheit 451",250,4500,elemento[6]);
    insertarDatos("L008","Orgullo y Prejuicio",678,23000,elemento[7]);
    for (int i = 0; i < 8; ++i) {
        insertarAlFinal(listaLibros, elemento[i]);
    }
    cout<<"DATOS INICIALES"<<endl;
    imprimir(listaLibros);
    cout<<endl;
    ordenarLista(listaLibros);
    cout<<"DATOS ORDENADOS"<<endl;
    imprimir(listaLibros);

    return 0;
}