#include <iostream>
using namespace std;

int contadorInversionesMerge(int *arrDatos,int inicio,int medio,int fin) {
    int izq = inicio;
    int der = medio +1 ;
    int buffer[fin - inicio + 1];
    int totalInversions = 0;
    int k= 0;
    while (izq <= medio and der <= fin) {
        if (arrDatos[izq] <= arrDatos[der]) {
            buffer[k++] = arrDatos[izq++];
        }
        else {
            buffer[k++] = arrDatos[der++];
            totalInversions += medio - izq +1;
        }
    }
    while (izq <= medio) {
        buffer[k++] = arrDatos[izq++];
    }
    while (der <= fin) {
        buffer[k++] = arrDatos[der++];
    }
    for (int k = inicio,j=0; k <= fin; k++,j++) {
        arrDatos[k] = buffer[j];
    }
    return totalInversions;
}

int contadorInversiones(int *arrDatos,int inicio,int fin) {
    if (inicio == fin) return 0;
    int totalInversions = 0;
    int medio = (fin + inicio) / 2;
    totalInversions += contadorInversiones(arrDatos,inicio,medio);
    totalInversions += contadorInversiones(arrDatos,medio+1,fin);
    totalInversions += contadorInversionesMerge(arrDatos,inicio,medio,fin);
    return totalInversions;
}

int main() {
    int arrDatos[]{1, 20, 6, 4, 5};
    int numDatos = sizeof(arrDatos)/sizeof(arrDatos[0]);
    int cantInversiones = contadorInversiones(arrDatos, 0,numDatos-1);

    cout << "El numero de inversiones es: "<<cantInversiones << endl;

    return 0;
}