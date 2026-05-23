#include <iostream>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;
#include "MisFunciones.h"

void ordenarLista(Lista &listaRobot) {
    NodoLista *recorrido = listaRobot.inicio, *anterior = nullptr,*siguiente;
    NodoLista *nuevoOrdenIni = nullptr,*nuevoOrdenFin = nullptr;
    char buscar = 'A';
    while (recorrido) {
        siguiente = recorrido->siguiente;
        if (recorrido->elemento.tipo == buscar) {
            if (anterior==nullptr) listaRobot.inicio = recorrido->siguiente;
            else anterior->siguiente = recorrido->siguiente;
            recorrido->siguiente = nullptr;
            if (nuevoOrdenIni == nullptr) nuevoOrdenIni = recorrido;
            if (nuevoOrdenFin) nuevoOrdenFin->siguiente = recorrido;
            nuevoOrdenFin = recorrido;
            if (buscar!='C')buscar ++;
            else buscar = 'A';
            recorrido = listaRobot.inicio;
            anterior = nullptr;
        }
        else {
            anterior = recorrido;
            recorrido = siguiente;
            if (recorrido == nullptr) {
                if (buscar == 'A') {
                    buscar = 'B';
                    recorrido = listaRobot.inicio;
                    anterior = nullptr;
                }else if (buscar == 'B') {
                    buscar = 'C';
                    recorrido = listaRobot.inicio;
                    anterior = nullptr;
                }else if (buscar == 'C') {
                    buscar = 'A';
                    recorrido = listaRobot.inicio;
                    anterior = nullptr;
                }
            }
        }
    }
    listaRobot.inicio = nuevoOrdenIni;
}

// ESTO LO HICE PENSANDO QUE ERA PRIMERO PURO A, LUEGO PURO B Y AL FINAL PURO C XDDDD

// void ordenarLista(Lista &listaRobot) {
//     NodoLista *recorrido = listaRobot.inicio,*anterior=nullptr,*siguiente;
//     NodoLista *tipoAini = nullptr,*tipoAfin = nullptr;
//     NodoLista *tipoBini = nullptr,*tipoBfin = nullptr;
//     NodoLista *tipoCini = nullptr,*tipoCfin = nullptr;
//     while (recorrido != nullptr) {
//         siguiente = recorrido->siguiente;
//         if (recorrido->elemento.tipo == 'A') {
//             if (anterior) anterior->siguiente = recorrido->siguiente;
//             else listaRobot.inicio = recorrido->siguiente;
//             if (tipoAini == nullptr) tipoAini = recorrido;
//             if (tipoAfin) tipoAfin->siguiente = recorrido;
//             tipoAfin = recorrido;
//             recorrido->siguiente = nullptr;
//         }
//         else if (recorrido->elemento.tipo == 'B') {
//             if (anterior) anterior->siguiente = recorrido->siguiente;
//             else listaRobot.inicio = recorrido->siguiente;
//             if (tipoBini == nullptr) tipoBini = recorrido;
//             if (tipoBfin) tipoBfin->siguiente = recorrido;
//             tipoBfin = recorrido;
//             recorrido->siguiente = nullptr;
//         }
//         else if (recorrido->elemento.tipo == 'C') {
//             if (anterior) anterior->siguiente = recorrido->siguiente;
//             else listaRobot.inicio = recorrido->siguiente;
//             if (tipoCini == nullptr) tipoCini = recorrido;
//             if (tipoCfin) tipoCfin->siguiente = recorrido;
//             tipoCfin = recorrido;
//             recorrido->siguiente = nullptr;
//         }
//         else anterior = recorrido;
//         recorrido = siguiente;
//     }
//     if (tipoAini) tipoAfin->siguiente = tipoBini;
//     else listaRobot.inicio = tipoBini;
//     if (tipoBini) tipoBfin->siguiente = tipoCini;
//     else if (tipoAini) tipoAfin->siguiente = tipoCini;
//     else listaRobot.inicio = tipoCini;
//     if (tipoAini) listaRobot.inicio = tipoAini;
// }