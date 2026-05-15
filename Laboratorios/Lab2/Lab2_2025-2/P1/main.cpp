#include <iostream>
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
using namespace std;
#include "BibliotecaLista/MisFunciones.h"

int main(int argc, char **argv) {
    struct ElementoLista elemento[20]{};
    insertarJugador(7,"Martinez","Delantero",elemento[0]);
    insertarJugador(1,"Ramirez","Portero",elemento[1]);
    insertarJugador(5,"Perez","Defensa",elemento[2]);
    insertarJugador(8,"Torres","Mediocampo",elemento[3]);
    insertarJugador(9,"Lopez","Delantero",elemento[4]);
    insertarJugador(3,"Gomez","Defensa",elemento[5]);
    struct Lista listaJugadores;
    construir(listaJugadores);
    for(int i=0;i<6;i++) {
        insertarAlFinal(listaJugadores,elemento[i]);
    }
    cout<<"JUGADORES"<<endl;
    imprimir(listaJugadores);
    cout<<endl;
    reordenaFormacion(listaJugadores,"Portero","Defensa","Mediocampo","Delantero");
    cout<<"JUGADORES ORDENADOS"<<endl;
    imprimir(listaJugadores);

    return 0;
}
