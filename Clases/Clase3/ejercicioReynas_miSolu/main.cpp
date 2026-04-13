#include <iostream>

using namespace std;

void mostramosTablero(int *posQueen,int &numSolu);
bool termino(int *posQueen);
bool validamosSoluciones(int *posQueen,int *soluciones,int numSolu);

int main() {
    int posQueen[4]{}, numSolu = 1,soluciones[10],numValidos = 0;
    while (true) {
        if (validamosSoluciones(posQueen,soluciones,numSolu)) {
            soluciones[numValidos] = numSolu;

            numValidos++;
        }
        mostramosTablero(posQueen,numSolu);
        if (termino(posQueen)) break;
        int reyna = 0;
        while (true) {
            if (posQueen[reyna] +1 < 4) {
                posQueen[reyna] ++;
                break;
            }
            posQueen[reyna] = 0;
            reyna++;
        }
    }
    cout <<"Las unicas soluciones posibles son: "<< endl;
    for (int i = 0; i < numValidos; ++i) {
        cout << soluciones[i]<<endl;
    }
    return 0;
}
void mostramosTablero(int *posQueen, int &numSolu) {
    cout <<"Solucion No. "<<numSolu<<endl;
    for (int i = 0; i < 4; ++i) {
        char tablero[4]{'*','*','*','*'};
        tablero[posQueen[i]] = 'Q';
        for (int j = 0; j < 4; ++j) cout <<tablero[j];
        cout << endl;
    }
    cout<<"--------------------"<<endl;
    numSolu++;
}
bool termino(int *posQueen) {
    int count = 0;
    for (int i = 0; i < 4; ++i) if (posQueen[i]==3) count++;
    if (count==4) return true;
    else return false;
}
bool validamosSoluciones(int *posQueen,int *soluciones,int numSolu) {
    //entre columnas
    for (int i = 0; i < 4; ++i) {
        for (int j = i+1; j < 4; ++j) if (posQueen[i] == posQueen[j]) return false;
    }
    //entre diagonales
    for (int i = 0; i < 4; ++i) {
        for (int j = i+1; j < 4; ++j) {
            if (abs(i - j) == abs(posQueen[i] - posQueen[j])) return false;
        }
    }
    return true;
}