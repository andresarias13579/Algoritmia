#include <iostream>

using namespace std;
//SOLUCION GEMINI ZZZZ
int busquedaBinariaMinimo(int *arrDatos, int inicio, int fin) {
    // CASO BASE DE SEGURIDAD: Si el sub-arreglo se redujo a 1 solo elemento
    if (inicio == fin) return arrDatos[inicio];

    // REGLA 1: "Ya está ordenado" (O(1))
    // Si el primero es menor al último, este bloque ya no tiene rotación.
    if (arrDatos[inicio] < arrDatos[fin]) {
        return arrDatos[inicio];
    }

    int medio = (inicio + fin) / 2;

    // REGLA 2: El Abismo (Detección segura del quiebre)
    // Verificamos si el quiebre está justo después del medio
    if (medio < fin && arrDatos[medio] > arrDatos[medio + 1]) {
        return arrDatos[medio + 1];
    }
    // Verificamos si el quiebre está justo en el medio
    if (medio > inicio && arrDatos[medio - 1] > arrDatos[medio]) {
        return arrDatos[medio];
    }

    // REGLA 3: Decidir a qué mitad ir
    // Si el número del medio es mayor que el del final, el abismo está a la derecha
    if (arrDatos[medio] > arrDatos[fin]) {
        return busquedaBinariaMinimo(arrDatos, medio + 1, fin);
    }
    // Si no, obligatoriamente el abismo está en la mitad izquierda
    else {
        return busquedaBinariaMinimo(arrDatos, inicio, medio - 1);
    }
}
//SOLUCION MIA
int busquedaBinaria(int *arrDatos,int inicio,int fin,int ultimoNum) {
    if (inicio > fin) return -1;
    int medio = (fin + inicio) / 2;
    if (ultimoNum == 0) return arrDatos[medio];
    if (medio == 0 and arrDatos[medio]<arrDatos[medio+1]) return arrDatos[medio];
    if (medio+1 == ultimoNum and arrDatos[medio]>arrDatos[medio+1]) return arrDatos[medio];
    if (arrDatos[medio] < arrDatos[medio+1] and arrDatos[medio] < arrDatos[medio-1]) return arrDatos[medio];
    if (arrDatos[medio] > arrDatos[medio-1] and arrDatos[medio] <arrDatos[ultimoNum])
        return busquedaBinaria(arrDatos,inicio,medio-1,ultimoNum);
    else return busquedaBinaria(arrDatos,medio+1,fin,ultimoNum);
}

int main() {
    int arrDatos[]{8,9,10,2,3,4,5,6,7};
    int numDatos = sizeof(arrDatos) / sizeof(arrDatos[0]);
    // int numMenor = busquedaBinaria(arrDatos,0,numDatos-1,numDatos-1);
    int numMenor = busquedaBinariaMinimo(arrDatos,0,numDatos-1);
    if (numMenor == -1) cout << "No se encontro el menor elemento" << endl;
    else cout <<"El numero menor es: "<< numMenor << endl;
    return 0;
}