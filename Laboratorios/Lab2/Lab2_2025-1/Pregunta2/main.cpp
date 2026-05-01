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
    // if (matriz[posX][posY] == 1) cout<<"Oro: "<<posX<<" "<<posY<<endl;
    int cen1=1,cen2=1;
    for (int i=0;cen1 == 1 or cen2 == 1;i++) {
        if (cen1==1 and matriz[posX+i][posY] == 1) { //busca abajo
            cout<<"Oro: "<<posX+i<<" "<<posY<<endl;
            cen1 = 0;
        } else if (posX+i >=N) cen1 = 0;
        if (cen2==1 and matriz[posX-i][posY] == 1) { //busca arriba
            cout<<"Oro: "<<posX-i<<" "<<posY<<endl;
            cen2 = 0;
        }else if (posX-i <0) cen2 = 0;
        if (matriz[posX][posY-i] == 1) { //busca atras
            cout<<"Oro: "<<posX<<" "<<posY-i<<endl;
        }
        if (matriz[posX][posY+i] == 1) { //busca adelante
            cout<<"Oro: "<<posX<<" "<<posY+i<<endl;
        }
    }
    combustible--;
    if (searchGold(posX,posY+1,limX,limY,combustible,matriz,dir)) return true;
    else {
        int nuevaDir = dir*-1;
        searchGold(posX,posY-1,limX,limY,combustible,matriz,nuevaDir);
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
    posX = 3;
    posY = 2;
    combustible = 6;
    searchGold(posX,posY,limX,limY,combustible,matriz,dir);

    return 0;
}