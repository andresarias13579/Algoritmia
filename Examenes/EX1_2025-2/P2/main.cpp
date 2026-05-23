#include <iostream>

using namespace std;

void mover(int paquete,char origen,char destino) {
    cout<<"Mover el paquete "<<paquete<<" del almacen "<<origen<<" hacia el almacen "<<destino<<endl;
}

void hanoi(int paquetes, char inicio,char auxiliar,char destino) {
    if (paquetes == 0) return;
    hanoi(paquetes-1,inicio,auxiliar,destino);
    mover(paquetes, inicio, auxiliar);
    hanoi(paquetes-1,destino,auxiliar,inicio);

    mover(paquetes, auxiliar, destino);
    hanoi(paquetes-1,inicio,auxiliar,destino);
}

int main() {
    int n;
    cout<<"Ingrese el numero de paquetes:"<<endl;
    cin >> n;
    hanoi(n, 'A','B','C');

    return 0;
}