#include <iostream>
#include <iomanip>
#define N 6
#define M 11

using namespace std;

bool recorremosMina(int posX, int posY,int limX,int limY, int matriz[][11],int galeria) {
    if (posX<0 or posX>=limX or posY>=limY) return false;
    if (matriz[posX][posY] != 0) {
        if (posY == 0 and matriz[posX][posY] != galeria) {
            return recorremosMina(posX-1,posY,limX,limY,matriz,galeria);
        }
        return false;
    }
    matriz[posX][posY] = galeria;
    if (posY == M-1) {
        recorremosMina(posX,0,limX,limY,matriz,galeria+1);
        return true;
    }
    if (recorremosMina(posX+1,posY,limX,limY,matriz,galeria)) return true;  //baja
    if (recorremosMina(posX,posY+1,limX,limY,matriz,galeria)) return true;  //va a la derecha
    if (recorremosMina(posX-1,posY,limX,limY,matriz,galeria)) return true;  //sube
    matriz[posX][posY] = 0;
    return false;
}

int main() {
    int matriz[N][M] {
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0, 0,-1,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,0,0},
        {0,0,0,0,0, -1,0,0,0,0,0},
        {0,0,0,0,0, -1,0,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,0,0},
    };
    int posX = 5, posY = 0;
    recorremosMina(posX, posY,N,M, matriz,1);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout <<setw(3)<< matriz[i][j];
        }
        cout << endl;
    }

    return 0;
}