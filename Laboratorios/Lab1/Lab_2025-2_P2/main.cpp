//esta solucion lo hizo gemini
#include <iostream>
#include <iomanip>

using namespace std;

#define N 6
#define M 11

// Representación de la mina: 0 = vacío, -1 = roca.
// Las galerías se marcarán con 1, 2, 3, etc.
int mina[N][M] = {
    {0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0}
};

// n y m son los topes de la matriz. x, y son la posición actual. id es el número de galería.
bool perforar(int x, int y, int id, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;

    // 1. MANEJO DE CHOQUES Y ASCENSOR CORREGIDO
    if (mina[x][y] != 0) {
        // Solo subimos en la col 0 si chocamos con algo distinto a nosotros mismos.
        // Esto evita que el robot salga volando hacia arriba al intentar ir hacia "Abajo".
        if (y == 0 && mina[x][y] != id) {
            return perforar(x - 1, 0, id, n, m);
        }
        return false;
    }

    mina[x][y] = id;

    if (y == m - 1) {
        perforar(n - 1, 0, id + 1, n, m);
        return true;
    }

    // 2. MOVIMIENTO (Tu prioridad original Abajo, Derecha, Arriba era perfecta)
    if (perforar(x + 1, y, id, n, m)) return true; // Abajo
    if (perforar(x, y + 1, id, n, m)) return true; // Derecha
    if (perforar(x - 1, y, id, n, m)) return true; // Arriba

    mina[x][y] = 0;

    if (y == 0) {
        return perforar(x - 1, 0, id, n, m);
    }

    return false;
}

// Única función donde se permiten bucles según el documento (para imprimir)
void imprimirMina() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mina[i][j] == -1) cout << setw(2) << "*";
            else if (mina[i][j] == 0) cout << "  ";
            else cout << setw(2) << mina[i][j];
        }
        cout << endl;
    }
}

int main() {
    // Lanzamos el robot de la Galería 1 desde la esquina inferior izquierda.
    perforar(N - 1, 0, 1, N, M);
    imprimirMina();
    return 0;
}