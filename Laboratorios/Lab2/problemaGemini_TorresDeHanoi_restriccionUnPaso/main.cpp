#include <iostream>

using namespace std;

int mover(int disco, char inicio, char destino) {
    cout<<"Mover el disco "<<disco<<" desde "<<inicio<<" hacia "<<destino<<endl;
    return 1;
}

int hanoi(int disco, char inicio,char auxiliar, char destino) {
    int movimientos = 0;

    if (disco==0) return 0;

    movimientos += hanoi(disco-1,inicio,auxiliar,destino);
    movimientos += mover(disco, inicio, auxiliar);
    movimientos += hanoi(disco-1,destino,auxiliar,inicio);

    movimientos += mover(disco, auxiliar, destino);
    movimientos += hanoi(disco-1,inicio,auxiliar,destino);

    return movimientos;
}


int main() {
    int discos,movimientos = 0;
    cout <<"Coloque el numero de discos "<<endl;
    // cin >>discos;
    discos = 8;
    movimientos = hanoi(discos,'A','B','C');
    cout<<"Total de movimientos: "<<movimientos<<endl;

    return 0;
}