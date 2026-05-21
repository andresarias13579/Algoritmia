#include <iostream>

using namespace std;
#include "Datos.h"
#include "FuncionesAuxiliares.h"

void buscamosLaSolucionMasOptima(int totalCombinar,Caries *dientesCaries,CuracionDiente *curacionDiente,Cita *cita,bool mostrar) {
    int guardarAtenciones[40][2]{};
    int bestBeneficio = 0;
    unsigned numCombinaciones = totalCombinaciones(totalCombinar);
    for (unsigned i = 0u; i < numCombinaciones; ++i) {
        bool cit1,cit2,cit3;
        int dientesAtendidos[3][8]{},beneficioTotal = 0;
        unsigned arrCitas[3];
        separCitas(arrCitas[0],arrCitas[1],arrCitas[2],i,totalCombinar);
        cit1 = obtenerDatosCita(arrCitas[0],dientesCaries,curacionDiente,cita[0].duracion,dientesAtendidos[0],beneficioTotal);
        cit2 = obtenerDatosCita(arrCitas[1],dientesCaries,curacionDiente,cita[1].duracion,dientesAtendidos[1],beneficioTotal);
        cit3 = obtenerDatosCita(arrCitas[2],dientesCaries,curacionDiente,cita[2].duracion,dientesAtendidos[2],beneficioTotal);
        if (cit1 and cit2 and cit3 and sonDientesDistintos(arrCitas)) {
            if (beneficioTotal > bestBeneficio) {
                bestBeneficio = beneficioTotal;
                guardamosLaMejorOpcion(guardarAtenciones,dientesAtendidos);
            }
        }
    }
    mostrarMejorSolucion(guardarAtenciones);
}
unsigned totalCombinaciones(int totalCombinar) {
    unsigned numero = (1u << totalCombinar);
    return numero;
}
void separCitas(unsigned &cita1,unsigned &cita2,unsigned &cita3, unsigned megaCombinacion,unsigned totalCombinar) {
    cita1 = 0,cita2 = 0,cita3 = 0;
    for (unsigned i = 0; i < totalCombinar; ++i) {
        if (8 > i) {
            if (megaCombinacion & (1u<<i)) cita1 += (1u<<(i-0));
        }
        if (8 <= i and i < 16) {
            if (megaCombinacion & (1u<<i)) cita2 += (1u<<(i-8));
        }
        if (i >= 16 ) {
            if (megaCombinacion & (1u<<i)) cita3 += (1u<<(i-16));
        }
    }
}
bool obtenerDatosCita(unsigned citaDientes,Caries *dientesCaries,CuracionDiente *curacionDiente,int limiDuracion,
    int *dientesAtendidos,int &beneficioTotal) {
    int duracion = 0,atendidos = 0;
    for (int i = 0; i < 8; ++i) {
        if (citaDientes & (1u<<i)) {
            duracion += curacionDiente[dientesCaries[i].tipo-1].duracion * dientesCaries[i].caries;
            beneficioTotal += curacionDiente[dientesCaries[i].tipo-1].ganancia * dientesCaries[i].caries;
            dientesAtendidos[atendidos] = i;
            atendidos++;
        }
    }
    if (duracion > limiDuracion) return(false);
    else return(true);
}
bool sonDientesDistintos(unsigned *arrCitas) {
    if ((arrCitas[0] & arrCitas[1]) != 0) return false;
    if ((arrCitas[1] & arrCitas[2]) != 0) return false;
    if ((arrCitas[0] & arrCitas[2]) != 0) return false;
    return true;
}
void guardamosLaMejorOpcion(int guardarAtenciones[40][2],int dientesAtendidos[3][8]) {
    int numAtenciones = 0;
    for (int i = 0; i < 3; ++i) {
        guardarAtenciones[numAtenciones][0] = i;
        int j=0;
        while (true) {
            if (dientesAtendidos[i][j] == 0) break;
            guardarAtenciones[numAtenciones][1] = dientesAtendidos[i][j];
            j++;
            numAtenciones++;
        }
    }
}
void mostrarMejorSolucion(int guardarAtenciones[40][2]) {
    for (int i = 0; i < 40; ++i) {
        cout<<"Cita: "<<guardarAtenciones[i][0]<<"Diente: "<<guardarAtenciones[i][1]<<endl;
    }
}
