//
// Created by Andres on 13/04/2026.
//

#ifndef LAB1_2025_2_FUNCIONESAUXILIARES_H
#define LAB1_2025_2_FUNCIONESAUXILIARES_H

void revisamosLosMejoresCasos(int P,int B,int F,struct ControlSeguridad *controles,int numCasos,bool mostrarCasos);
unsigned total_combinaciones(int n);
void imprimirMask(unsigned mask);
bool evaluamosMask(int P,int B,int F,struct ControlSeguridad *controles,int &bestCosto,int &bestFalsosN,int &bestBeneficio,unsigned mask);
void mostramosSoluciones(unsigned *cumplenMask,int datosMask[][3],int numSoluciones,int P,int B,int F);

#endif //LAB1_2025_2_FUNCIONESAUXILIARES_H
