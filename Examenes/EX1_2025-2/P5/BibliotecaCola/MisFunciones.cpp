#include <iostream>
#include <cstring>
#include <fstream>

#include "Cola.h"
#include "funcionesCola.h"

using namespace std;
#include "MisFunciones.h"

void lecturaArchivos(Cola &cola,const char*nombArchLec,const char*nombreArchOut) {
    ifstream input(nombArchLec,ios::in);
    if (not input.is_open()) {
        cout <<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<nombArchLec<<endl;
        exit(1);
    }
    ofstream output(nombreArchOut,ios::out);
    if (not output.is_open()) {
        cout <<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<nombArchLec<<endl;
        exit(1);
    }
    while (true) {
        char tipoOperacion[20];
        input >> tipoOperacion;
        if (input.eof()) break;
        if (strcmp(tipoOperacion,"llegada")==0) {
            int codigo;
            char prioridad[20];
            input>>codigo>>prioridad;
            operacionLlegada(cola,codigo,prioridad);
        } else if (strcmp(tipoOperacion,"atender")==0) {
            int cantidad;
            input>>cantidad;
            operacionAtender(cola,cantidad,output);
        }else if (strcmp(tipoOperacion,"imprimir")==0) {
            operacionImprimir(cola,output);
        }
    }

}

void operacionLlegada(Cola &cola,int codigo,const char *prioridad) {
    char prioEncolar;
    if (strcmp(prioridad,"regular")==0) prioEncolar='R';
    else if (strcmp(prioridad,"preferente")==0) prioEncolar='P';
    encolarPrioridad(cola,{codigo,prioEncolar});
}
void operacionAtender(Cola &cola,int cantidad,ofstream &arch) {
    for (int i = 0; i < cantidad; ++i) {
        ElementoCola elemento;
        char prioridad[3];
        elemento = desencolar(cola);
        if (elemento.prioridad == 'P') strcpy(prioridad,"P1");
        else if (elemento.prioridad == 'R') strcpy(prioridad,"P2");
        arch<<"Atendido: "<<elemento.codigo<<" ("<<prioridad<<")"<<endl;
    }
}
void operacionImprimir(Cola &cola,ofstream &arch) {
    arch<<"Estado: ";
    if (esColaVacia(cola)) arch<<"[P1:][P2:]"<<endl;
    else imprimir(cola,arch);
}