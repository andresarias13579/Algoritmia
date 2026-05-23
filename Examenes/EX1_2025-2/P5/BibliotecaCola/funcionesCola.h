//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal 

#ifndef COLA_FUNCIONESCOLA_H
#define COLA_FUNCIONESCOLA_H
#include <fstream>
using namespace std;

void construir(struct Cola & colaTAD);
void encolarPrioridad(struct Cola &cola, const struct ElementoCola &colaTAD);
void encolar(struct Cola &cola, const struct ElementoCola &colaTAD);
struct ElementoCola desencolar(struct Cola & colaTAD);
bool esColaVacia(const struct Cola & colaTAD);
void imprimir(const struct Cola & colaTAD,ofstream &arch);
int longitud(const struct Cola & colaTAD) ;

#endif //COLA_FUNCIONESCOLA_H
