#include <iostream>
#include <iomanip>

#define N 10
#define M 10
using namespace std;

int buscarArtefacto(int posX,int posY,int limX,int limY,int alcArriba,int alcAbajo,int artefactos,int matriz[][10]) {
    if (posX < 0 or posX >= limX or posY<0 or posY >= limY) return 0;
    if (posX < alcArriba or posX>alcAbajo) return 0;
    if (matriz[posX][posY] == 1) artefactos++; //si encuentra un artefacto lo aumenta
    if (matriz[posX][posY] == 2) return 0;// esto es para que no redunde al momento de buscar XD
    matriz[posX][posY] = 2;// si es que ya paso por ahi
    if (abs(posX-alcAbajo) <= abs (posX-alcArriba)) { //va hacia abajo
        artefactos += buscarArtefacto(posX+1,posY,limX,limY,alcArriba,alcAbajo,0,matriz); //baja uno
        artefactos += buscarArtefacto(posX+1,posY-1,limX,limY,alcArriba,alcAbajo,0,matriz); //baja uno diagonal izquierda
        artefactos += buscarArtefacto(posX+1,posY+1,limX,limY,alcArriba,alcAbajo,0,matriz); //baja uno diagonal derecha
    }
    if (abs(posX-alcAbajo) >= abs (posX-alcArriba)) { //va hacia arriba
        artefactos += buscarArtefacto(posX-1,posY,limX,limY,alcArriba,alcAbajo,0,matriz); //sube uno
        artefactos += buscarArtefacto(posX-1,posY-1,limX,limY,alcArriba,alcAbajo,0,matriz); //sube uno diagonal izquierda
        artefactos += buscarArtefacto(posX-1,posY+1,limX,limY,alcArriba,alcAbajo,0,matriz); //sube uno diagonal derecha
    }
    return artefactos;
}

int main() {
    int matriz[N][M] {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    int alcance,posX,posY,limX = N,limY = M,artefactos;
    cin >> alcance >>posX >>posY;
    // alcance = 3;
    //
    // posX = 5;
    // posY = 5;
    artefactos = 0;
    artefactos = buscarArtefacto(posX,posY,limX,limY,posX-alcance,posX+alcance,artefactos,matriz);
    cout<<"El robot encontro "<<artefactos<<" artefactos"<<endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (matriz[i][j] == 2)cout <<setw(3)<< "*";
            else if (matriz[i][j] == 1)cout <<setw(3)<< "A";
            else cout <<setw(3)<< ".";
        }
        cout << endl;
    }

    return 0;
}