#include "funciones.h"

void mostrarServicios(){
  cout << "----- SERVICIO -----" << endl;
  cout << "<1> Netflix" << endl;
  cout << "<2> Amazon Prime" << endl;
  cout << "<3> Disney+" << endl; 
  cout << "<4> Hulu" << endl;
  cout << "<0> Salir" << endl;
}

string mayusculas(string palabra){
  string palabra_n = "";
  for (int i=0; i<palabra.size(); i++){
    palabra_n+=toupper(palabra[i]);
  }
  return palabra_n;
}
