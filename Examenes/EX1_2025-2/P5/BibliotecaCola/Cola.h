//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal 

#ifndef COLA_COLA_H
#define COLA_COLA_H
#include "NodoCola.h"
struct Cola {
    struct NodoCola * head;
    struct NodoCola * tail;
    struct NodoCola * last1;
    int longitud;
};
#endif //COLA_COLA_H