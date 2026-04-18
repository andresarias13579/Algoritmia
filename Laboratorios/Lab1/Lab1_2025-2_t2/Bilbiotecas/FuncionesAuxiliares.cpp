#include <iostream>

using namespace std;
#include "ControlesDeSeguridad.h"
#include "FuncionesAuxiliares.h"

void implementamosFuerzaBruta(int P,int B,int F,ControlesDeSeguridad controles[],int numCasos,bool debug) {
    int numSoluciones = 0,datosMask[10][3];
    unsigned maskCumplen[10]{};
    unsigned totalDeCasos = total_casos(numCasos);
    for (unsigned i = 0; i < totalDeCasos; ++i) {
        int bestCosto = 0,bestBeneficio = 0, bestFaltas = 0;
        if (debug) imprimirMask(i);
        if (evaluamosMask(P,B,F,controles,bestCosto,bestBeneficio,bestFaltas,i)) {
            maskCumplen[numSoluciones] = i;
            datosMask[numSoluciones][0] = bestCosto;
            datosMask[numSoluciones][1] = bestBeneficio;
            datosMask[numSoluciones][2] = bestFaltas;
            numSoluciones++;
        }
    }
    if (numSoluciones == 0) cout <<"No se pueden seleccionar controles de seguridad que cumplan todas las restricciones"<<endl;
    else mostramosSoluciones(maskCumplen,datosMask,numSoluciones,P,B,F);
}
unsigned total_casos(int numCasos) {
    unsigned combinaciones = (1u << numCasos);
    return combinaciones;
}
void imprimirMask(unsigned mask) {
    for (int i = 7; i >=0 ; --i) {
        if (mask & (1u << i)) cout << "1";
        else cout << "0";
    }
    cout << endl;
}
bool evaluamosMask(int P,int B,int F,struct ControlesDeSeguridad controles[],int &bestCosto,int &bestBeneficio,int &bestFaltas,unsigned mask) {
    for (int i = 7; i>=0 ; --i) {
        if (mask & (1u << i)) {
            bestCosto += controles[i].costo;
            bestBeneficio += controles[i].beneficio;
            bestFaltas += controles[i].falsosNegativos;
        }
    }
    if (bestCosto<=P and bestBeneficio>=B and bestFaltas<=F) return true;
    else return false;
}
void mostramosSoluciones(unsigned *cumplenMask,int datosMask[][3],int numSoluciones,int P,int B,int F) {
    cout << "P: "<<P<<", B: "<<B<<", F: "<<F<<endl;
    for (int k = 0; k < numSoluciones; ++k) {
        int bandera = 1;
        cout<<"Recursos: ";
        for (int i = 0; i < 8; ++i) if (cumplenMask[k] & (1u<<i)) {
            if (bandera) {
                cout<<"{"<<i+1;
                bandera = 0;
            }
            else cout <<","<< i+1;
        }
        cout<<"}"<<",Costo total: "<<datosMask[k][0]<<",Beneficio: "<<datosMask[k][1]<<",Falsos Negativos: "<<datosMask[k][2]<<endl;
    }

}