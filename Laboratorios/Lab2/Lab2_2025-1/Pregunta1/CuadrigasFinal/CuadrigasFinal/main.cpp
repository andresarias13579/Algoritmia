#include <iostream>

#include "BibliotecaLista/funcionesLista.h"
#include "BibliotecaLista/Lista.h"
using namespace std;
void reorganizarLista(Lista &lista) {
    //punteros para gestionar la lista de pares
    NodoLista * pares_inicio=nullptr;
    NodoLista * pares_fin=nullptr;
    //punteros para gestionar la lista de impares
    NodoLista * impares_inicio=nullptr;
    NodoLista * impares_fin=nullptr;

    NodoLista * actual=lista.lista;//al primer nodo de la lista

    //comenzamos a recorrer la lista para evaluar nodo por nodo
    while (actual!=nullptr) {
        NodoLista * siguiente=actual->siguiente;

        actual->siguiente=nullptr;//"desconecto" el nodo de la lista, para reorganizarlo

        if (actual->elemento.codigo%2==0) {
            //Si es PAR
            if (pares_inicio==nullptr) {//que es el primer PAR que encontramos
                pares_inicio=pares_fin=actual;
            }
            else {//si ya hay pares, entao colocamos al final da lista, y actualizamos el nuevo final
                pares_fin->siguiente=actual;
                pares_fin=actual;
            }
        }
        else {//Si es IMPAR
            if (impares_inicio==nullptr) {//que es el primer PAR que encontramos
                impares_inicio=impares_fin=actual;
            }
            else {//Si ya hay impares, colocamos al final de la lista, y actualizamos el nuevo final
                impares_fin->siguiente=actual;
                impares_fin=actual;
            }
        }
        actual=siguiente;//tomamos el siguiente nodo para evaluarlo
    }//Hasta aquí ya se "asignaron" los nodos a las sublistas PAR e IMPAR
    if (pares_inicio==nullptr) {
        lista.lista=impares_inicio;
    }else {
        lista.lista=pares_inicio;
        pares_fin->siguiente=impares_inicio;
    }
}
int main() {
    Lista lista;
    construir(lista);

    insertarAlFinal(lista, {17});
    insertarAlFinal(lista, {4});
    insertarAlFinal(lista, {12});
    insertarAlFinal(lista, {7});

    cout<<"Lista original: ";
    imprimir(lista);

    reorganizarLista(lista);

    cout<<"Lista reorganizada: ";
    imprimir(lista);

    return 0;
}
