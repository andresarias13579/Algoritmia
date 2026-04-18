#include <iostream>

using namespace std;
#include "Bilbiotecas/ControlesDeSeguridad.h"
#include "Bilbiotecas/FuncionesAuxiliares.h"

int main() {
   int P,B,F,numCasos = 8;
   ControlesDeSeguridad controles[] {
      {35000,80,1},
      {24000,60,3},
      {30000,70,2},
      {27000,48,1},
      {10000,20,1},
      {7000,35,2},
      {6000,10,1},
      {40000,40,3}
   };
   cout <<"Ingrese el P, B, F: ";
   cin >>P>>B>>F;

   implementamosFuerzaBruta(P,B,F,controles,numCasos,false);

   return 0;
}