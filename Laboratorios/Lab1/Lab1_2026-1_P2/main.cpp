#include <iostream>

using namespace std;
#include "Bibliotecas/Datos.h"
#include "Bibliotecas/FuncionesAuxiliares.h"

int main() {
    Caries dientesCaries[8]{
        {1,1,3},
        {1,1,1},
        {1,2,0},
        {1,3,1},
        {1,3,2},
        {1,4,1},
        {1,4,2},
        {1,4,3}
    };
    CuracionDiente curacionDiente[4] {
        {5,20},
        {7,30},
        {10,35},
        {12,42}
    };
    Cita cita[3] {60,45,50};

    buscamosLaSolucionMasOptima(24,dientesCaries,curacionDiente,cita,true);

    return 0;
}