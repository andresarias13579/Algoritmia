//
// Created by Andres on 17/04/2026.
//

#ifndef LAB1_2025_2_T2_FUNCIONESAUXILIARES_H
#define LAB1_2025_2_T2_FUNCIONESAUXILIARES_H

void implementamosFuerzaBruta(int P,int B,int F,ControlesDeSeguridad controles[],int numCasos, bool debug);
unsigned total_casos(int numCasos);
void imprimirMask(unsigned mask);
bool evaluamosMask(int P,int B,int F,struct ControlesDeSeguridad controles[],int &bestCosto,int &bestBeneficio,int &bestFaltas,unsigned mask);
void mostramosSoluciones(unsigned *cumplenMask,int datosMask[][3],int numSoluciones,int P,int B,int F);

#endif //LAB1_2025_2_T2_FUNCIONESAUXILIARES_H
