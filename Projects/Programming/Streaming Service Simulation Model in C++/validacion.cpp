#include "validacion.h"

using namespace std;

int validacion(int input,int inferior,int superior){
  while (!(cin >> input) || input>superior || input<inferior) {
    cout << "Input inválido. Intételo de nuevo." << endl;
    cin.clear();
		cin.ignore(123, '\n');
  }
  return input;
}

double validacion(double input,double inferior,double superior){
  while (!(cin >> input) || input>superior || input<inferior) {
    cout << "Input inválido. Intételo de nuevo." << endl;
    cin.clear();
		cin.ignore(123, '\n');
  }
  return input;
}

string validacion(string input, int inferior, int superior) {
  getline(cin,input);
  while (input.size()>superior || input.size()<inferior) {
    cout << "Input inválido. Caracteres aceptados:\n  - Máximo - " << superior << "\n  - Mínimo - " << inferior << endl;
    cout << "Intételo de nuevo." << endl;
    getline(cin,input);
  }
  
  return input;
}


