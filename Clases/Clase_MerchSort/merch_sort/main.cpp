#include <algorithm>
#include <iostream>

using namespace std;

void merge(int *arrDatos, int inicio, int centro, int fin) {
    int n1 = centro - inicio+1, n2 = fin - centro;
    int arr1[n1],arr2[n2];
    for (int i = 0; i < n1; ++i) {
        arr1[i] = arrDatos[inicio + i];
    }
    for (int i = 0; i < n2; ++i) {
        arr2[i] = arrDatos[centro + i +1];
    }
    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) arrDatos[k++] = arr1[i++]; //los [i++] significa que primero entra al extrae el dato [i] y luego actualiza i++
        else arrDatos[k++] = arr2[j++];
    }

    while (i < n1) arrDatos[k++] = arr1[i++]; //en caso no haya llenado todo en i
    while (j < n2) arrDatos[k++] = arr2[j++];// en caso no haya llenado todo en j
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
        cout << arrDatos[i] <<"   ";
    }
    return 0;
}