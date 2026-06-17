#include <iostream>
using namespace std;
int BusquedaBinaria(int A[], int k, int inicial, int final) {
    //CASO BASE: cuando se cruzan las posiciones inicial y final: es decir, que no se encontró K en el arreglo A[]
    if (inicial>final)
        return -1;
    //PARTE RECURSIVA
    int medio=(inicial+final)/2;
    if (A[medio]==k)
        return medio;
    else //analizamos qué mitad del arreglo A[] descartamos
        if (A[medio]<k)
            return BusquedaBinaria(A, k, medio+1, final);//subarreglo de la derecha
        else
            return BusquedaBinaria(A, final, inicial, medio-1);//subarreglo de la izquierda
}
int main() {
    int A[]={1,5,7,9,12,15,16,20};//Arreglo está ORDENADO
    int n=8;    int k=16;
    int posicion=BusquedaBinaria(A, k, 0, n-1);
    if (posicion==-1)
        cout<<"El elemento no se encuentra en el arreglo."<<endl;
    else
        cout<<"El elemento se encuentra en la posicion "<<posicion+1<<endl;
    return 0;
}