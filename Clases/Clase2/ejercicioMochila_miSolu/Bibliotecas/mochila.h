//
// Created by Andres on 12/04/2026.
//

#ifndef EJERCICIOMOCHILA_MISOLU_MOCHILA_H
#define EJERCICIOMOCHILA_MISOLU_MOCHILA_H

void mochilaFuerzaBruta(struct Item *items,int n,int capacity,bool debug);
unsigned totalCombinations(int n);
void impresorMaskBinario(unsigned mask);
bool evaluarMascara(struct Item *items,int n,unsigned mask,int capacity,int &peso,int &valor);
void actualizarMejorBestMask(unsigned mask, int valor, int peso, int &bestValue,int &bestWeight,unsigned &bestMask);
void imprimirBestSolution(int bestValue,int bestWeight,unsigned bestMask);

#endif //EJERCICIOMOCHILA_MISOLU_MOCHILA_H
