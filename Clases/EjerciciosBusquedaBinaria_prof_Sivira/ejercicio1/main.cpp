#include <iostream>

using namespace std;
//SOLUCION MIA
/*
 *El problema con mi solucion es que puede existir un desbordamiento de memoria al evaluar el arr[Medio-1]
 *ya que en un arreglo donde el numero solitario sea el primer dato (osea con indice 0) este leeria
 *el arr[-1] (osea basura) por lo que el programa podria fallar (pero por algun motivo no lo hace XD)
 */
int busquedaBinaria(int *arrDatos,int inicio,int fin) {
    if (inicio > fin) return -1;
    int medio = (inicio + fin)/2;
    if (arrDatos[medio] != arrDatos[medio-1] and arrDatos[medio] != arrDatos[medio +1]) return arrDatos[medio];
    if (arrDatos[medio] != arrDatos[medio + 1] ) medio --;
    if (medio % 2 == 0) return busquedaBinaria(arrDatos,medio+2,fin);
    else return busquedaBinaria(arrDatos,inicio,medio);
}
//SOLUCION DE GEMINI ZZZZ
int busquedaBinariaSolitario(int *arrDatos, int inicio, int fin) {
    // 1. Caso base blindado: si el rango se redujo a 1 solo elemento, ¡es el solitario!
    if (inicio == fin) {
        return arrDatos[inicio];
    }

    int medio = (inicio + fin) / 2;

    // 2. Nos aseguramos de que 'medio' siempre apunte al inicio de un supuesto par (índice par)
    if (medio % 2 != 0) {
        medio--;
    }

    // 3. Evaluamos la pareja. Si el par está completo (son iguales),
    // significa que el patrón no se ha roto. El solitario está a la DERECHA.
    if (arrDatos[medio] == arrDatos[medio + 1]) {
        // Saltamos toda la pareja enviando inicio a medio + 2
        return busquedaBinariaSolitario(arrDatos, medio + 2, fin);
    }
    // 4. Si el par NO está completo, el patrón ya se rompió.
    // El solitario está a la IZQUIERDA (y podría ser el mismo 'medio').
    else {
        return busquedaBinariaSolitario(arrDatos, inicio, medio);
    }
}

int main() {
    int arrEntrada[]  {1,3, 3,4,4, 5, 5, 7, 7, 8, 8};
    int numDatos = sizeof(arrEntrada)/sizeof(arrEntrada[0]);
    int numBuscado = busquedaBinaria(arrEntrada, 0,numDatos-1);
    if (numBuscado == -1) cout << "No se encontro el numero solitario"<<endl;
    else cout <<"El numero solitario es: "<<numBuscado<<endl;
    return 0;
}