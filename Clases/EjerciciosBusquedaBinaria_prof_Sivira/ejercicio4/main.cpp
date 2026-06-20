#include <iostream>

using namespace std;

int sumaMaxinaCentro(int *arrDatos, int inicio,int  medio,int fin) {
    int suma = 0;
    int sumaIzquierda = -99999,sumaDerecha = -99999;
    for (int i = medio; i >= inicio; i--) {
        suma += arrDatos[i];
        if (suma > sumaIzquierda) sumaIzquierda = suma;
    }
    suma = 0;
    for (int i = medio+1; i <= fin; i++) {
        suma += arrDatos[i];
        if (suma > sumaDerecha) sumaDerecha = suma;
    }

    return sumaDerecha + sumaIzquierda;
}

int sumaMaxima(int *arrDatos, int inicio,int fin) {
    if (inicio == fin) return arrDatos[inicio];

    int medio = (inicio + fin) / 2;
    int sumaIzq = sumaMaxima(arrDatos, inicio, medio);
    int sumaDer = sumaMaxima(arrDatos, medio + 1, fin);
    int sumaCentro = sumaMaxinaCentro(arrDatos, inicio, medio,fin);

    return max(max(sumaIzq, sumaDer), sumaCentro);
}

int main() {
    int arrDatos[]{-2, -5, 6, -2, -3, 1, 5, -6};
    int numDatos = sizeof(arrDatos) / sizeof(arrDatos[0]);
    int sumaMax = sumaMaxima(arrDatos, 0,numDatos-1);
    cout<<"La suma maxima de contiguos es: "<<sumaMax<<endl;

    return 0;
}