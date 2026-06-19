#include <algorithm>
#include <iostream>

using namespace std;

void llenar(int *arreglo, int *arrDatos,int inicio,int fin) {
    for (int i = inicio; i < fin; ++i) {
        arreglo[i] = arrDatos[i];
    }
}

void merge(int *arrDatos, int inicio, int centro, int fin) {
    int arr1[centro],arr2[centro];
    llenar(arr1,arrDatos,inicio,centro);
    llenar(arr2,arrDatos,centro,fin);

    
}

void merge_sort(int *arrDatos,int inicio,int fin) {
    if (inicio == fin) return;
    int medio = (inicio + fin) / 2;

    merge_sort(arrDatos,inicio,medio); //iquierda
    merge_sort(arrDatos,medio+1,fin);//derecha
    merge(arrDatos,inicio,medio,fin);
}

int main() {
    int arrDatos[] {10,5,48,51,23,32,47,95,74,65,56,14,81,78,30};
    int numDatos = sizeof(arrDatos)/sizeof(arrDatos[0]);

    merge_sort(arrDatos,0,numDatos-1);

    for (int i = 0; i < numDatos; ++i) {
        cout << arrDatos[i] << endl;
    }


    return 0;
}