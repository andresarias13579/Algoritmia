#include <iostream>

using namespace std;
#include "ControlesDeSeguridad.h"
#include "FuncionesAuxiliares.h"

void revisamosLosMejoresCasos(int P,int B,int F,struct ControlSeguridad *controles,int numCasos,bool mostrarCasos) {
    int numSoluciones = 0, datosMask[10][3];
    unsigned cumplenMask[10]{};
    unsigned totalCasos = total_combinaciones(numCasos);
    for (unsigned i = 0u; i < totalCasos; ++i) {
        int bestCosto = 0,bestBeneficio = 0, bestFalsosN = 0;
        if (mostrarCasos) imprimirMask(i);
        if (evaluamosMask(P,B,F,controles,bestCosto,bestFalsosN,bestBeneficio,i)) {
            cumplenMask[numSoluciones] = i;
            datosMask[numSoluciones][0] = bestCosto;
            datosMask[numSoluciones][1] = bestBeneficio;
            datosMask[numSoluciones][2] = bestFalsosN;
            numSoluciones++;
        }

    }
    if (numSoluciones == 0) cout <<"No se pueden seleccionar controles de seguridad que cumplan todas las restricciones"<<endl;
    else mostramosSoluciones(cumplenMask,datosMask,numSoluciones,P,B,F);
}
unsigned total_combinaciones(int n) {
    unsigned combinaciones = (1u << n);
    return combinaciones;
}
void imprimirMask(unsigned mask) {
    for (int i = 7; i >= 0; --i) {
        if (mask & (1 << i)) cout << "1";
        else cout << "0";
    }
    cout << endl;
}
bool evaluamosMask(int P,int B,int F,struct ControlSeguridad *controles,int &bestCosto,int &bestFalsosN,int &bestBeneficio,unsigned mask) {
    for (int i = 0; i < 8; ++i) {
        if (mask & (1 << i)) {
            bestCosto += controles[i].costo;
            bestBeneficio += controles[i].beneficio;
            bestFalsosN += controles[i].falsoNegativo;
        }
    }
    if (bestCosto > P or bestBeneficio < B or bestFalsosN > F) return false;
    if (mask == 0u )return false;
    else return true;
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