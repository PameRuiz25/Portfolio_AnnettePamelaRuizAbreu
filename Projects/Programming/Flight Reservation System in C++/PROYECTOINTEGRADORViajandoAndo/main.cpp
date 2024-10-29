/*
Annette Pamela Ruiz Abreu
A01423595

04/06/2022
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Sistema.h"
#include "Aeropuerto.h"
#include "Usuario.h"
#include "login.h"
#include "menu.h"

using namespace std;

int main() {
  Sistema sistema;
  Usuario usuario;
  Sistema *spointer;
  spointer = &sistema;
  string input_s;
  ifstream aeropuerto_text_in;
  Aeropuerto aeropuertoMX;
  aeropuerto_text_in.open("aeropuerto.txt");
  if (!(aeropuerto_text_in.fail())) {
    int paso = 1;
    while (aeropuerto_text_in >> input_s) {
      switch(paso){
        case 1:
          aeropuertoMX.setId(input_s);
          break;
        case 2:
          aeropuertoMX.setCity(input_s);
          break;
        case 3:
          aeropuertoMX.setCountry(input_s);
          paso = 0;
          break;
      }
      paso++;
    }  
  }

  cout << "Bienvenid@ a ViajandoAndo" << endl << endl;
  usuario = login(spointer);
  if (usuario.getUsername()=="") {
    cout << " ---------- ACCESO AL PORTAL NEGADO ---------- " << endl;
    return 0;
  }
  
  aeropuertoMX.startOperations();
  cout << " ¶¶¶¶¶\n  ¶  ¶¶¶\n  ¶¶   ¶¶¶\n   ¶¶    ¶¶\n    ¶¶     ¶¶\n      ¶¶    ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶\n       ¶¶                               ¶¶\n         ¶¶                             ¶¶¶\n          ¶                       ¶¶¶¶¶¶¶\n         ¶                   ¶¶¶¶¶¶¶\n         ¶              ¶¶¶¶¶¶¶\n         ¶           ¶¶¶¶¶\n         ¶            ¶¶\n        ¶¶       ¶¶¶   ¶¶¶\n        ¶        ¶¶¶¶    ¶¶\n        ¶       ¶¶  ¶¶¶   ¶¶¶\n        ¶      ¶¶     ¶¶    ¶¶\n       ¶¶     ¶¶       ¶¶¶   ¶¶¶¶¶¶¶¶¶¶¶¶\n       ¶¶     ¶¶         ¶¶¶   ¶        ¶¶\n       ¶     ¶¶           ¶¶¶            ¶¶¶\n       ¶    ¶¶             ¶¶     ¶¶¶¶¶¶¶¶¶\n      ¶¶    ¶              ¶¶    ¶¶¶¶\n      ¶¶   ¶¶             ¶¶    ¶¶¶¶¶\n      ¶   ¶¶              ¶¶   ¶¶ ¶¶¶¶\n      ¶¶ ¶¶               ¶¶  ¶¶\n       ¶¶¶                 ¶¶ ¶¶\n                            ¶¶¶\n                             ¶" << endl;
  Usuario *pointer_usuario = &usuario;
  cout << "Bienvenido a " << aeropuertoMX.getId();
  startMenu(aeropuertoMX, spointer, pointer_usuario);

  
}



