#include <iostream>

using namespace std;
#include "funcionesCola.h"
#include "MisFunciones.h"
#include "funcionesPila.h"
#include "ElementoCola.h"
#include "Cola.h"
#include "Pila.h"

void insercionDeProductos(Cola &productos1,Cola &productos2,Cola &productos3) {
    //productos 1
    encolar(productos1,{7});
    encolar(productos1,{6});
    encolar(productos1,{5});
    encolar(productos1,{4});
    encolar(productos1,{1});
    encolar(productos1,{2});
    encolar(productos1,{3});
    //productos 2
    encolar(productos2,{4});
    encolar(productos2,{5});
    encolar(productos2,{6});
    encolar(productos2,{7});
    encolar(productos2,{1});
    encolar(productos2,{2});
    encolar(productos2,{3});
    //productos 3
    encolar(productos3,{1});
    encolar(productos3,{5});
    encolar(productos3,{6});
    encolar(productos3,{2});
    encolar(productos3,{4});
    encolar(productos3,{7});
    encolar(productos3,{3});
}
bool verificamosSiPuedeOrdenarse(Cola productos) {
    Pila pilaAux;
    Cola colaFinal;
    int productoSolicitado = 1,cantElementos = productos.longitud;
    struct ElementoCola elemento;
    construir(pilaAux);
    construir(colaFinal);
    // elemento = desencolar(productos);
    // apilar(pilaAux,{elemento.codigo});
    while (productoSolicitado <= cantElementos) {
        if (esPilaVacia(pilaAux)) {
            elemento = desencolar(productos);
            apilar(pilaAux,{elemento.codigo});
        }
        ElementoPila ultimoApilado = cima(pilaAux);
        if (ultimoApilado.numero == productoSolicitado) {
            ultimoApilado = desapilar(pilaAux);
            encolar(colaFinal,{ultimoApilado.numero});
            productoSolicitado++;
        }else {
            if (not esColaVacia(productos)) {
                elemento = desencolar(productos);
                apilar(pilaAux,{elemento.codigo});
            }
            else return false;
        }
    }
    return true;
}
