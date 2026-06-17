#include <iostream>

using namespace std;

int busquedaBinariaCeros(int *arrDatos,int inicio,int fin) {
    if (inicio > fin) return 0;
    int medio = (inicio + fin) / 2;
    if (arrDatos[medio] == 0 and arrDatos[medio-1] == 1) return medio;
    if (arrDatos[medio] == 1) return busquedaBinariaCeros(arrDatos,medio+1,fin);
    else return busquedaBinariaCeros(arrDatos,inicio,medio-1);
}

int main() {
    int arrEntrada[]{0,0,0,0};  //solo para el caso de puros ceros falla, pero se soluciona altoq
    int numDatos = sizeof(arrEntrada)/sizeof(arrEntrada[0]);
    int cantCeros = 0;

    cantCeros = numDatos - busquedaBinariaCeros(arrEntrada,0,numDatos-1);

    if (cantCeros != numDatos) cout << "Ceros encontrados: " << cantCeros << endl;
    else cout << "No se encontraron ceros" << endl;

    return 0;
}