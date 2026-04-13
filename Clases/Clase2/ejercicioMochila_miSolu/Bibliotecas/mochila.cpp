#include <iostream>

using namespace std;
#include "Item.h"
#include "mochila.h"

void mochilaFuerzaBruta(struct Item *items,int n,int capacity,bool debug) {
    int bestValue = 0;
    unsigned bestMask = 0u;
    int bestWeight = 0;

    const unsigned totalComb = totalCombinations(n);
    if (debug) cout <<"Cantidad de combinaciones posibles: "<<totalComb<<endl;
    for (unsigned mask = 0; mask < totalComb; ++mask) {
        if (debug) {
            cout <<"Combinacion "<<mask<<" ";
            impresorMaskBinario(mask);
            cout <<endl;
        }
        int peso, valor;
        if (!evaluarMascara(items,n,mask,capacity,peso,valor)) continue;
        actualizarMejorBestMask(mask,valor,peso,bestValue,bestWeight,bestMask);
    }
    imprimirBestSolution(bestValue,bestWeight,bestMask);
}
unsigned totalCombinations(int n) {
    const unsigned totalComb = (1u << n);
    return totalComb;
}
void impresorMaskBinario(unsigned mask) {
    for (int i = 3; i >= 0; --i) {
        if (mask & (1u << i)) {
            cout <<"1";
        }else {
            cout <<"0";
        }
    }
}
bool evaluarMascara(struct Item *items,int n,unsigned mask,int capacity,int &peso,int &valor) {
    peso = 0;
    valor = 0;
    for (int i = 0; i < n; ++i) {
        if (mask & (1u << i)) {
            peso += items[i].weight;
            if (peso > capacity) {
                valor = -1;
                return false;
            }
            valor += items[i].value;
        }
    }
    return true;
}
void actualizarMejorBestMask(unsigned mask, int valor, int peso, int &bestValue,int &bestWeight,unsigned &bestMask) {
    if (bestValue == 0 and bestWeight == 0 and bestMask == 0) {
        bestValue = valor;
        bestWeight = peso;
        bestMask = mask;
    }else {
        if (valor > bestValue or bestValue == valor and peso < bestWeight) {
            bestValue = valor;
            bestWeight = peso;
            bestMask = mask;
        }
    }
}
void imprimirBestSolution(int bestValue,int bestWeight,unsigned bestMask) {
    cout <<"La mejor solucion es : ";
    impresorMaskBinario(bestMask);
    cout <<endl;
    cout <<"Peso: "<<bestWeight<<endl;
    cout <<"Valor: "<<bestValue<<endl;

}