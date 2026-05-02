#include <iostream>
#define N 6
#define M 7
using namespace std;

bool searchGold(int posX,int posY,int limX,int limY,int &combustible,int matriz[][M],int dir) {
    if (posX < 0 or posX >= limX or posY <0 or posY >= limY) return false;
    if (matriz[posX][posY] == 2) {
        combustible--;
        return false;
    }
    if (combustible == 0) return true;
    // --- ESCÁNER SEGURO ---
    // Revisar la celda actual
    if (matriz[posX][posY] == 1) {
        cout << "Oro: " << posX << " " << posY << endl;
    }
    // Busca hacia Abajo
    for (int i = 1; posX + i < limX; i++) {
        if (matriz[posX + i][posY] == 1) {
            cout << "Oro: " << posX + i << " " << posY << endl;
            break; // Detiene la búsqueda al encontrar la veta
        }
    }
    // Busca hacia Arriba
    for (int i = 1; posX - i >= 0; i++) {
        if (matriz[posX - i][posY] == 1) {
            cout << "Oro: " << posX - i << " " << posY << endl;
            break;
        }
    }
    // Busca hacia Adelante (Derecha)
    for (int i = 1; posY + i < limY; i++) {
        if (matriz[posX][posY + i] == 1) {
            cout << "Oro: " << posX << " " << posY + i << endl;
            break;
        }
    }
    // Busca hacia Atrás (Izquierda)
    for (int i = 1; posY - i >= 0; i++) {
        if (matriz[posX][posY - i] == 1) {
            cout << "Oro: " << posX << " " << posY - i << endl;
            break;
        }
    }
    combustible--;
    if (searchGold(posX,posY+dir,limX,limY,combustible,matriz,dir)) return true;
    else {
        int nuevaDir = dir*-1;
        searchGold(posX,posY-dir,limX,limY,combustible,matriz,nuevaDir);
        return false;
    }
    return true;
}

int main() {
    int matriz[N][M] {
        { 0, 1, 1, 1, 1, 1, 1},
        { 0, 1, 1, 0, 0, 0, 0},
        { 0, 1, 0, 0, 0, 0, 0},
        { 1, 0, 0, 0, 2, 0, 0},
        { 1, 1, 0, 0, 0, 0, 0},
        { 1, 1, 0, 1, 1, 0, 0}
    };
    int posX,posY,limX = N,limY = M,combustible,dir = 1;
    posX = 4;
    posY = 2;
    combustible = 6;
    searchGold(posX,posY,limX,limY,combustible,matriz,dir);

    return 0;
}