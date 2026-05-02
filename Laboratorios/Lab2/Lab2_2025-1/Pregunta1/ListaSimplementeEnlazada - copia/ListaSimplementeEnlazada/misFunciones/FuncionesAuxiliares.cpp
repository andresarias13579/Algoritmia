#include <cstring>
#include <iostream>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;
#include "FuncionesAuxiliares.h"

void insertamosElementos(struct ElementoLista &elemento, int id,char *nombre, char *equipo) {
    elemento.id = id;
    strcpy(elemento.nombre, nombre);
    strcpy(elemento.equipo, equipo);
}
/*
 * FORMA DE SOLUCIÓN:
 * 1. Se recorre la lista original nodo por nodo utilizando un puntero auxiliar 'siguienteNodo'
 * para no perder la referencia del resto de la lista al modificar los enlaces.
 * 2. Cada nodo actual se "desconecta" de la lista y se evalúa su ID.
 * 3. Si el ID es par, se enlaza al final de la sublista de pares utilizando 'iniPares' y 'finPares'.
 * 4. Si el ID es impar, se enlaza al final de la sublista de impares usando 'iniImpares' y 'finImpares'.
 * 5. Al terminar el recorrido, se unen ambas sublistas (pares apuntando a impares) gestionando
 * los casos borde (ej. que la lista solo tenga pares o solo impares).
 */
void ordenarLista(struct Lista &lista) {

    // Si la lista está vacía, no hay nada que ordenar
    if (lista.inicio == nullptr) return;

    struct NodoLista *recorrido = lista.inicio;
    struct NodoLista *siguienteNodo = nullptr;

    while (recorrido != nullptr) {
        // PASO CLAVE: Guardar el resto de la lista antes de modificar el nodo actual
        siguienteNodo = recorrido->siguiente;

        // Desconectar el nodo actual para aislarlo
        recorrido->siguiente = nullptr;

        // Clasificar el nodo
        if (recorrido->elemento.id % 2 == 0) { // Es PAR
            if (lista.iniPares == nullptr) {
                lista.iniPares = recorrido;
                lista.finPares = recorrido;
            } else {
                lista.finPares->siguiente = recorrido;
                lista.finPares = recorrido; // Actualizamos el fin de pares
            }
        } else { // Es IMPAR
            if (lista.iniImpares == nullptr) {
                lista.iniImpares = recorrido;
                lista.finImpares = recorrido;
            } else {
                lista.finImpares->siguiente = recorrido;
                lista.finImpares = recorrido; // Actualizamos el fin de impares
            }
        }

        // Avanzar al siguiente nodo de la lista original usando nuestra variable segura
        recorrido = siguienteNodo;
    }

    // Unir las dos sublistas formadas
    if (lista.iniPares != nullptr) {
        lista.inicio = lista.iniPares; // La lista general arranca con los pares

        if (lista.iniImpares != nullptr) {
            // Si hay impares, los conectamos al final de los pares
            lista.finPares->siguiente = lista.iniImpares;
        }
    } else {
        // Caso borde: Si no hubo ningún par, la lista arranca directamente con los impares
        lista.inicio = lista.iniImpares;
    }
}
