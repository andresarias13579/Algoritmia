//
// Created by aml on 22/05/2026.
//

#ifndef COLAPRIORIDAD_MISFUNCIONES_H
#define COLAPRIORIDAD_MISFUNCIONES_H

void lecturaArchivos(Cola &cola,const char*nombArchLec,const char*nombreArchOut);

void operacionLlegada(Cola &cola,int codigo,const char *prioridad);

void operacionAtender(Cola &cola,int cantidad,ofstream &arch);

void operacionImprimir(Cola &cola,ofstream &arch);

#endif //COLAPRIORIDAD_MISFUNCIONES_H