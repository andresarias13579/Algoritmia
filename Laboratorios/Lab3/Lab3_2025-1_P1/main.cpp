//Fecha:  lunes 01 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"

#define N 5
#define M 6
using namespace std;

void asignarPosicion (struct ElementoPila &elemento,int X, int Y) {
    elemento.posicion[0] = X;
    elemento.posicion[1] = Y;
}
void buscamosSalidaDeLaMina(int corX, int corY, int finX, int finY,Pila &camino,char matriz[N][M]) {
    struct ElementoPila cordenada;
    asignarPosicion(cordenada,corX,corY);
    apilar(camino,cordenada);
    matriz[corX][corY] = 'A';
    while (not esPilaVacia(camino)) {
        cordenada = cima(camino);
        corX = cordenada.posicion[0],corY = cordenada.posicion[1];
        if (corX == finX and corY == finY) return; // terminamos
        if ( corX+1 < N and matriz[corX+1][corY] == '.') {
            corX++;
            asignarPosicion(cordenada,corX,corY);
            apilar(camino,cordenada);
            matriz[corX][corY] = 'A';
            continue;
        } else if ( corY+1 < M and matriz[corX][corY+1] == '.' ) {
            corY++;
            asignarPosicion(cordenada,corX,corY);
            apilar(camino,cordenada);
            matriz[corX][corY] = 'A';
            continue;
        }else { // si es '*', 'A'
            desapilar(camino);
        }
    }
    cout <<"No hay una salida disponible"<<endl;
}

int main(int argc, char ** argv) {
    char matriz[N][M] {
        {'.','.','*','.','.','*'},
        {'.','.','.','.','.','.'},
        {'.','*','.','*','.','.'},
        {'.','*','.','.','*','.'},
        {'*','.','.','.','.','.'},
    };
    int posXini = 0,posYini = 0,posXfin = N-1, posYfin = M-1;

    Pila camino;
    construir(camino);
    buscamosSalidaDeLaMina(posXini,posYini,posXfin,posYfin,camino,matriz);
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < M; ++k) {
            cout << matriz[i][k] << " ";
        }
        cout << endl;
    }

    return 0;
}
