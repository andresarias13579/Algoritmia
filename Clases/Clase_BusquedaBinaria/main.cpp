#include <iostream>

using namespace std;

int busquedaBinaria(int *arrNum,int clave,int inicio,int fin) {
    if (inicio > fin) return -1; //si es que pasa esto es porque no encontro el numero
    int medio = (inicio + fin) / 2;
    int mostrar = arrNum[medio];
    if (arrNum[medio] == clave) return medio;
    else if (arrNum[medio] < clave) return busquedaBinaria(arrNum,clave,medio+1,fin);
    else return busquedaBinaria(arrNum,clave,inicio,medio-1);
}

int main() {
    //primero llenamos un arreglo con 11 datos
    //OJO: Para que esto funcione el arreglo tiene que estar ordenado
    int numDatos;
    numDatos = 14;
    int arrNum[numDatos] {1, 5 , 11 , 13,24,26,35,40,41,49,60,67,80,83};
    //ahora trataremos de buscar un numero en especifico
    int k = 83; //elegimos el numero a buscar
    int indice ; //aqui guardamos el indice en el que se encuentra ese numero en el arreglo

    indice = busquedaBinaria(arrNum,k,0,numDatos-1);

    if (indice == -1) cout <<"No se encontro el numero"<<endl;
    else cout << "El numero se encuentra en la posicion "<<indice +1 <<" del arreglo"<<endl;
    //mostramos la posicion +1

    return 0;
}
