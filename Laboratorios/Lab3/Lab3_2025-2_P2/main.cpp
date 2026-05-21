//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaCola/MisFunciones.h"
using namespace std;

int main(int argc, char **argv) {
    Cola productos[3];
    construir(productos[0]);
    construir(productos[1]);
    construir(productos[2]);
    insercionDeProductos(productos[0],productos[1],productos[2]);
    for (int i=0;i<3;i++) {
        imprimir(productos[i]);
        if (verificamosSiPuedeOrdenarse(productos[i])) cout <<"Si se puede ordenar"<<endl;
        else cout <<"No se puede ordenar"<<endl;
        cout<<"-----------------------------------------"<<endl;
    }
    return 0;
}
