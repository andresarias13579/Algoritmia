#include <iostream>

using namespace std;

int buscarMinimaSumaCentro(int *arr1,int inicio,int medio,int fin) {
    int suma = 0;
    int sumaIzq = 999999, sumaDer = 999999;
    for (int i = medio; i >= inicio; i--) {
        suma += arr1[i];
        if (suma < sumaIzq) sumaIzq = suma;
    }
    suma = 0;
    for (int i = medio+1; i <= fin; i++) {
        suma += arr1[i];
        if (suma < sumaDer) sumaDer = suma;
    }
    return min(min(sumaIzq,sumaDer),sumaDer+sumaIzq);
}

int buscarMinimaSuma(int *arr1,int inicio,int fin) {
    if (inicio == fin) return arr1[inicio];
    int medio =(fin+inicio)/2;
    int sumIzq = buscarMinimaSuma(arr1,inicio,medio);
    int sumDer = buscarMinimaSuma(arr1,medio+1,fin);
    int sumaCentro = buscarMinimaSumaCentro(arr1,inicio,medio,fin);
    return min(min(sumIzq,sumDer),sumaCentro);
}

int main() {
    int arr1[]{2, 5, -6, 2, 3, -1, -5, 6};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[]{2, -3, 4, -5, -7};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int arr3[]{-4, 5, 6, -4, 3, -1, -5, 6};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);

    int min = buscarMinimaSuma(arr1,0,n1-1);
    cout<<"La suma minima es : "<<min<<endl;

    min = buscarMinimaSuma(arr2,0,n2-1);
    cout<<"La suma minima es : "<<min<<endl;

    min = buscarMinimaSuma(arr3,0,n3-1);
    cout<<"La suma minima es : "<<min<<endl;

    return 0;
}