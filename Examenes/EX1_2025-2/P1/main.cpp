#include <iostream>

using namespace std;
#include "Bilbiotecas/Alertas.h"
#include "Bilbiotecas/FuncionesAuxiliares.h"

int main() {
    Alertas alertas[13] {
        {1801, 2,  8, 1},
        {1802, 1,  8, 1},
        {1803, 1,  9, 1},
        {1804, 3,  9, 3},
        {1805, 1, 10, 1},
        {1806, 1, 11, 1},
        {1807, 3, 12, 1},
        {1808, 1, 14, 1},
        {1809, 2, 14, 2},
        {1810, 3, 14, 1},
        {1811, 2, 15, 1},
        {1812, 3, 16, 1},
        {1813, 2, 16, 2}
    };

    int P1=1,P2=1,P3=3,n=13;
    buscarMejorCombinacion(alertas,n,false,P1,P2,P3);

    return 0;
}