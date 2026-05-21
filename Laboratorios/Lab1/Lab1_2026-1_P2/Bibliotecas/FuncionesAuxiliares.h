//
// Created by Andres on 20/05/2026.
//

#ifndef LAB1_2026_1_P2_FUNCIONESAUXILIARES_H
#define LAB1_2026_1_P2_FUNCIONESAUXILIARES_H

void buscamosLaSolucionMasOptima(int totalCombinar,Caries *dientesCaries,CuracionDiente *curacionDiente,Cita *cita,bool mostrar);
unsigned totalCombinaciones(int totalCombinar);
void separCitas(unsigned &cita1,unsigned &cita2,unsigned &cita3, unsigned megaCombinacion,unsigned totalCombinar);
bool obtenerDatosCita(unsigned citaDientes,Caries *dientesCaries,CuracionDiente *curacionDiente,int limiDuracion,
    int *dientesAtendidos,int &beneficioTotal);
bool sonDientesDistintos(unsigned *arrCitas);
void guardamosLaMejorOpcion(int guardarAtenciones[40][2],int dientesAtendidos[3][8]);
void mostrarMejorSolucion(int guardarAtenciones[40][2]);

#endif //LAB1_2026_1_P2_FUNCIONESAUXILIARES_H
