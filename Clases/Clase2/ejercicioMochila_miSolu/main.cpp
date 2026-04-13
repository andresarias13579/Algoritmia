#include <iostream>

using namespace std;
#include "Bibliotecas/Item.h"
#include "Bibliotecas/mochila.h"

int main() {
    struct Item items[] {
        {10,60},
        {20,100},
        {30,120},
        {15,80}
    };
    int n=4;
    int capacity = 50;
    mochilaFuerzaBruta(items,n,capacity,true);

    return 0;
}