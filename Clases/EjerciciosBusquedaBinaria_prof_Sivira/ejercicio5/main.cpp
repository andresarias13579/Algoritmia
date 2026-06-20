#include <iostream>
using namespace std;

int hallarMaxElemento(int *arrDatos,int inicio,int fin) {
    if (inicio == fin) return arrDatos[inicio];
    int medio = (inicio + fin) / 2;

    if (arrDatos[medio] > arrDatos[medio -1 ] and arrDatos[medio] > arrDatos[medio +1 ]) return arrDatos[medio];

    if (medio != 0 and arrDatos[medio] > arrDatos[medio-1] ) return hallarMaxElemento(arrDatos,medio +1 ,fin);
    else return hallarMaxElemento(arrDatos,inicio,medio);
}

int main() {
    int arrDatos[]{8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
    int numDatos = sizeof(arrDatos)/sizeof(arrDatos[0]);
    int maxElemento = hallarMaxElemento(arrDatos, 0,numDatos-1);
    cout << "El elemento maximo es: "<<maxElemento << endl;

    return 0;
}