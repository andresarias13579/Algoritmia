#include <iostream>
#include <iomanip>

using namespace std;
#include "Alertas.h"
#include "FuncionesAuxiliares.h"

void buscarMejorCombinacion(Alertas alertas[],int numOpciones,bool mostrar,int P1,int P2,int P3) {
    unsigned totalCombinaciones = total_combinadas(numOpciones);
    int bestSoluciones[10][10]{},cantBestSolution = 0,numeroAlertas[10]{};
    for (unsigned i = 0; i < totalCombinaciones; i++) {
        if (mostrar) mostrarCombinaciones(i);
        if (combinacionesQueCumplen(alertas,i,P1,P2,P3)) {
            llenarSoluciones(alertas,i,bestSoluciones,cantBestSolution,numeroAlertas);
            cantBestSolution++;
        }
    }
    if (cantBestSolution == 0) cout << "No solution found";
    else mostrarSoluciones(bestSoluciones,cantBestSolution,alertas,numeroAlertas);
}
bool combinacionesQueCumplen(Alertas alertas[],unsigned mask,int P1,int P2,int P3) {
    int hora=8,cantP1=0,cantP2=0,cantP3=0;
    for (int i = 0; i < 13; ++i) {
        if (mask & (1u << i)) {
            if (hora <= alertas[i].horaInicio) {
                int horaFin = alertas[i].horaInicio + alertas[i].duracion;
                if (alertas[i].prioridad == 1) horaFin++;
                if (horaFin>17) return false;
                if (alertas[i].horaInicio < 14 and horaFin > 13) return false;
                if (alertas[i].prioridad == 1) cantP1++;
                if (alertas[i].prioridad == 2) cantP2++;
                if (alertas[i].prioridad == 3) cantP3++;
                hora = horaFin;
                // if (alertas[i].prioridad == 1) hora = alertas[i].horaInicio+alertas[i].duracion+1;
                // else hora = alertas[i].horaInicio+alertas[i].duracion;
            }else return false;
        }
    }

    if (cantP1 == P1 and cantP2 == P2 and cantP3 == P3) return true;
    else return false;
}
void llenarSoluciones(Alertas alertas[],int mask,int bestSoluciones[10][10],int cantBest,
    int *numAlertas) {
    int soluciones=0;
    for (int i = 0; i < 13; ++i) {
        if (mask & (1u << i)) {
            bestSoluciones[cantBest][soluciones]=i;
            soluciones++;
        }
    }
    numAlertas[cantBest]=soluciones;
}
void mostrarSoluciones(int bestSoluciones[][10],int cantBestSolution,Alertas alertas[],
    int *numAlertas) {
    for (int i = 0; i < cantBestSolution; ++i) {
        for (int j = 0; j < numAlertas[i]; ++j) {
            int indice = bestSoluciones[i][j];
            cout << setw(6)<<alertas[indice].codigo<<" P"<<alertas[indice].prioridad<<" |";
        }
        cout << endl;
    }
}
unsigned total_combinadas(int numOpciones) {
    unsigned total = (1u << numOpciones);
    return total;
}
void mostrarCombinaciones(unsigned mask) {
    for (int i = 12; i >= 0; i--) {
        if (mask & (1 << i)) cout << "1";
        else cout << "0";
    }
    cout << endl;
}
