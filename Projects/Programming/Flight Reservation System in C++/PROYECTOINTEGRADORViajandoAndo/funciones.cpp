#include "funciones.h"

int seleccionarAerolinea(int input_i, Aeropuerto aeropuertoMX){
  cout << "Seleccione la aerolinea deseada" << endl;
  for (int i = 0; i<NUM_AEREOLINEAS; i++) {
    cout << "<" << i+1 << "> " << aeropuertoMX.getAirlines(i).getName() << endl;
  }
  input_i = validacion(input_i,1,NUM_AEREOLINEAS) - 1;
  return input_i;
}


int seleccionarVueloNoRegistrado(int input_i, Aeropuerto aeropuertoMX, int airline_num){
  int total_registrados = NUM_FLIGHTS;
  cout << "Seleccione el vuelo que quiere programar" << endl;
  for (int i = 0; i<NUM_FLIGHTS; i++) {
    if (!(aeropuertoMX.getAirlines(airline_num).getFlight(i).getRegistrado())) {
      cout << "<" << i+1 << "> " << "Vuelo " << i+1 << endl;
      total_registrados --;
    }
  }
  cout << "Presione <0> si desea regresar al menu principal" << endl;
  if (total_registrados == NUM_FLIGHTS) {
    cout << "TODOS LOS VUELOS DE ESTA AEROLÍNEA YA ESTÁN REGISTRADOS" << endl;
    return -1;
  }
  while (true) {
    input_i = validacion(input_i,0,NUM_FLIGHTS) - 1;
    if (input_i == -1) {
      break;
    }
    else if (!(aeropuertoMX.getAirlines(airline_num).getFlight(input_i).getRegistrado())) {
      break;
    }
    cout << "El vuelo ya está registrado. Inténtelo de nuevo." << endl;
  }
  return input_i;
}



int seleccionarVueloRegistrado(int input_i, Aeropuerto aeropuertoMX, int airline_num){
  int total_registrados = 0;
  cout << "Seleccione el vuelo" << endl;
  for (int i = 0; i<NUM_FLIGHTS; i++) {
    if (aeropuertoMX.getAirlines(airline_num).getFlight(i).getRegistrado()) {
      cout << "<" << i+1 << "> " << "Vuelo " << i+1 << endl;
      total_registrados ++;
    }
  }
  cout << "Presione <0> si desea regresar al menu principal" << endl;
  if (total_registrados == 0) {
    cout << "NO HAY NINGÚN VUELO REGISTRADO" << endl;
    return -1;
  }
  while (true) {
    input_i = validacion(input_i,0,NUM_FLIGHTS) - 1;
    if (input_i == -1) {
      break;
    }
    else if (!(aeropuertoMX.getAirlines(airline_num).getFlight(input_i).getRegistrado())) {
      break;
    }
    cout << "Vuelo inexistente. Inténtelo de nuevo" << endl;
  }
  return input_i;
}

string mayusculas(string palabra) {
  string palabra_n = "";
  for (int i=0; i<palabra.size(); i++) {
    palabra_n += toupper(palabra[i]);
  }
  return palabra_n;
}



