//
// Created by aml on 22/05/2026.
//

#ifndef P1_FUNCIONESAUXILIARES_H
#define P1_FUNCIONESAUXILIARES_H

void buscarMejorCombinacion(Alertas alertas[],int numOpciones,bool mostrar,int P1,int P2,int P3);
bool combinacionesQueCumplen(Alertas alertas[],unsigned mask,int P1,int P2,int P3);
void llenarSoluciones(Alertas alertas[],int mask,int bestSoluciones[10][10],int cantBest,
    int *numAlertas);
void mostrarSoluciones(int bestSoluciones[][10],int cantBestSolution,Alertas alertas[],
    int *numAlertas);
unsigned total_combinadas(int numOpciones);
void mostrarCombinaciones(unsigned mask);

#endif //P1_FUNCIONESAUXILIARES_H