#include <iostream>
using namespace std;

#define N 6

void obtenerCanariosFaltantes(int faltantes[],int iniFila,int finFila,int  fila,int matriz[][N],int inicio, int fin);
void ordenarCanarios(int matriz[],int inicio,int fin);
void ordenar(int matriz[], int inicio, int medio, int fin);
int buscarCanario(int matriz[],int inicio,int fin);
void mostrarCanarios(int faltantes[],int numFilas);

int main() {
    int canarios[7];
    canarios[0] = 1; //Amarillo
    canarios[1] = 2; //Rojo
    canarios[2] = 3; //Blanco
    canarios[3] = 4; //Negro
    canarios[4] = 5; //Bruno
    canarios[5] = 6; //Agata
    canarios[6] = 7; //Isabel
    int numFilas;
    int matriz[N][N] {
        {0,3,7,2,2,7},
        {5,0,3,1,5,3},
        {7,7,3,6,6,3},
        {7,4,0,7,2,4},
        {5,1,2,5,1,2},
        {6,0,7,4,7,4}
    };
    numFilas = sizeof(matriz)/sizeof(matriz[0]);

    int faltantes[N], fila = 0;
    obtenerCanariosFaltantes(faltantes,0, N-1, fila, matriz,0, numFilas-1);

    mostrarCanarios(faltantes,N);

    return 0;
}

void obtenerCanariosFaltantes(int faltantes[],int iniFila,int finFila,int  fila,int matriz[][N],int inicio, int fin) {
    if (iniFila == finFila) {
        ordenarCanarios(matriz[iniFila],inicio,fin);
        faltantes[iniFila] = buscarCanario(matriz[iniFila],1,fin);
        return;
    }
    int medio = (iniFila+finFila)/2;
    obtenerCanariosFaltantes(faltantes,iniFila,medio,fila,matriz,inicio,fin);
    obtenerCanariosFaltantes(faltantes,medio+1,finFila,fila,matriz,inicio,fin);
}
void ordenarCanarios(int matriz[], int inicio, int fin) {
    if (inicio == fin) return;
    int medio = (inicio+fin)/2;
    ordenarCanarios(matriz,inicio,medio);
    ordenarCanarios(matriz,medio+1,fin);
    ordenar(matriz,inicio,medio,fin);
}
void ordenar(int matriz[], int inicio, int medio, int fin) {
    int i = inicio;
    int j = medio + 1;
    int k = 0;
    int buffer[fin - inicio + 1];

    while (i<=medio and j<=fin) {
        if (matriz[i] < matriz[j]) buffer[k++] = matriz[i++];
        else buffer[k++] = matriz[j++];
    }

    while (i<=medio) buffer[k++] = matriz[i++];
    while (j<=fin) buffer[k++] = matriz[j++];

    for (int i = inicio,j = 0; i<=fin; i++,j++) matriz[i] = buffer[j];
}
int buscarCanario(int matriz[],int inicio,int fin) {
    if (matriz[0]!=0) return -1;
    else {
        if (inicio > fin) return -1; //si es que no hay canario faltante

        int medio = (inicio+fin)/2;
        // if (medio == 0 and matriz[medio] != matriz[medio+1]) return matriz[medio]; //esto es en caso se halle al inicio
        if (matriz[medio] != matriz[medio-1] and matriz[medio] != matriz[medio+1]) return matriz[medio]; //esto si es que lo encontro
        if (medio % 2 == 0) medio--;
        if (matriz[medio] == matriz[medio +1]) return buscarCanario(matriz,medio+2,fin); //busca a la derecha
        else return buscarCanario(matriz,inicio,medio); //busca a la izquierda
    }
}
void mostrarCanarios(int faltantes[], int numFilas) {
    for (int i = 0; i < numFilas; i++) {
        if (faltantes[i] == -1) cout<<"Fila "<<i+1<<": No hay canario faltante"<<endl;
        if (faltantes[i] == 1) cout<<"Fila "<<i+1<<": Falta Amarillo"<<endl;
        if (faltantes[i] == 2) cout<<"Fila "<<i+1<<": Falta Rojo"<<endl;
        if (faltantes[i] == 3) cout<<"Fila "<<i+1<<": Falta Blanco"<<endl;
        if (faltantes[i] == 4) cout<<"Fila "<<i+1<<": Falta Negro"<<endl;
        if (faltantes[i] == 5) cout<<"Fila "<<i+1<<": Falta Bruno"<<endl;
        if (faltantes[i] == 6) cout<<"Fila "<<i+1<<": Falta Agata"<<endl;
        if (faltantes[i] == 7) cout<<"Fila "<<i+1<<": Falta Isabel"<<endl;
    }
}