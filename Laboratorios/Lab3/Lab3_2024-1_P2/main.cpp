#include <iostream>
using namespace std;

int buscaInicioRadicion(int *arrDatos,int inicio,int fin) {
    if (inicio>fin) return -1;
    int medio = (fin+inicio)/2;
    if (medio != 0 and arrDatos[medio-1] <=0 and arrDatos[medio] >0) return medio;
    if (arrDatos[medio] > 0) return buscaInicioRadicion(arrDatos,inicio,medio-1);
    else return buscaInicioRadicion(arrDatos,medio+1,fin);
}
int buscaRadiacionMax(int *arrDatos1,int inicio,int fin) {
    if (inicio>fin) return -1;
    int medio = (fin+inicio)/2;
    if (arrDatos1[medio]!=arrDatos1[medio-1] and arrDatos1[medio]!=arrDatos1[medio+1])
        return arrDatos1[medio] ;
    if (medio % 2 != 0) medio--;
    if (arrDatos1[medio] == arrDatos1[medio+1])
        return buscaRadiacionMax(arrDatos1,medio+2,fin);
    else return buscaRadiacionMax(arrDatos1,inicio,medio);
}
void mostrarDatos(int potenciaMax, int inicioRadiacion) {
    if (inicioRadiacion != -1 and potenciaMax != -1) {
        cout<<"La radiacion empieza a "<<inicioRadiacion<<" km. Potencia maxima "
            <<potenciaMax<<" megatones"<<endl;
    } else if (inicioRadiacion == -1) cout<<"El inicio de radiacion no se encontro"<<endl;
    else cout<<"La potencia maxima no se encontro"<<endl;
}
int main() {
    int arrDatos1[]{0,-1,0,-1,0,1,1,2,2,3,2,2,1,1};
    int numDatos1 = sizeof(arrDatos1) / sizeof(arrDatos1[0]);
    int inicioRadiacion = buscaInicioRadicion(arrDatos1, 0,numDatos1-1);
    int potenciaMax = buscaRadiacionMax(arrDatos1,inicioRadiacion,numDatos1-1);
    mostrarDatos(potenciaMax,inicioRadiacion);

    int arrDatos2[]{-1,0,-1,0,1,1,2,2,3,3,4,3,3,2,2,1,1};
    int numDatos2 = sizeof(arrDatos2) / sizeof(arrDatos2[0]);
    int inicioRadiacion2 = buscaInicioRadicion(arrDatos2, 0,numDatos2-1);
    int potenciaMax2 = buscaRadiacionMax(arrDatos2,inicioRadiacion2,numDatos2-1);
    mostrarDatos(potenciaMax2,inicioRadiacion2);

    return 0;
}