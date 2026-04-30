#include <iostream>

using namespace std;

int mover(int disco, char inicio, char destino) {
    cout<<"Mover el disco "<<disco<<" desde "<<inicio<<" hacia "<<destino;
    return 1;
}

bool hanoi(int disco, char inicio,char auxiliar, char destino) {
    int movimientos = 0;
    if (disco == 1) {
        mover(disco, inicio, destino);
    }else {
        hanoi(disco-1,inicio,destino,auxiliar);
        mover(disco, inicio, destino);
        hanoi(disco-1,auxiliar,inicio,destino);
        return true;
    }
}


int main() {
    int discos,movimientos = 0;
    cout <<"Coloque el numero de discos "<<endl;
    // cin >>discos;
    discos = 2;
    // presupuesto = 80;
    movimientos = hanoi(discos,'A','B','C');
    cout<<"Total de movimientos: "<<movimientos<<endl;

    return 0;
}