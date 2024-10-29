#include <iostream>
#include <vector>
#include "Usuario.h"

using namespace std;

Usuario::Usuario(){
  username = "";
  nombre = "";
  edad = 0;
  telefono = "";
  kilometros = 0;
  vuelos = {};
}
Usuario::Usuario(string username_, string nombre_, int edad_, string telefono_, double kilometros_, vector<string> vuelos_){
  username = username_;
  nombre = nombre_;
  edad = edad_;
  telefono = telefono_;
  kilometros = kilometros_;
  vuelos = vuelos_;
}
Usuario::~Usuario(){
  
}


string Usuario::getNombre() {
  return nombre;
}
string Usuario::getTelefono() {
  return telefono;
}
int Usuario::getEdad() {
  return edad;
}
string Usuario::getUsername(){
  return username;
}
double Usuario::getKilometros(){
  return kilometros;
}
vector <string> Usuario::getVuelos(){
  return vuelos;
}
string Usuario::getUnVuelo(int i){
  return vuelos[i];
}

void Usuario::setEdad(int edad_) {
  edad = edad_;
}
void Usuario::setNombre(string nombre_){
  nombre = nombre_;
}
void Usuario::setTelefono(string telefono_) {
  telefono = telefono_;
}
void Usuario::setUsername(string username_){
  username = username_;
}

void Usuario::setKilometros(double kilometros_){
  kilometros = kilometros_;
}
void Usuario::setVuelos(vector<string> vuelos_){
  vuelos = vuelos_;
}
void Usuario::setUnVuelo(int i, string vuelo){
  vuelos[i] = vuelo;
}


int Usuario::getCantidadVuelosRes(){
  return vuelos.size();
}

void Usuario::imprimeUsuario() {
  cout << "INFORMACIÓN DEL USUARIO: " << username << endl;
  cout << "NOMBRE: " << nombre << endl;
  cout << "EDAD: " << edad << endl;
  cout << "TELÉFONO: " << telefono << endl;
  cout << "NÚM. VUELOS RESERVADOS: " << getCantidadVuelosRes() << endl;
  cout << "KILÓMETROS: " << kilometros << endl;
  cout << "VUELOS: " << endl;
  for (int i=0; i<vuelos.size(); i++) {
    cout << "Aerolínea: " << vuelos[i][0] << " Vuelo: " << vuelos[i][1] << endl;
  }
}

void Usuario::addVuelo(string vuelo){
  vuelos.push_back(vuelo);
}

void Usuario::mostrarVuelos() {
  cout << "VUELOS: " << endl;
  for (int i=0; i<vuelos.size(); i++) {
    cout << "Aerolínea: " << vuelos[i][0] << " Vuelo: " << vuelos[i][1] << endl;
  }
}


bool Usuario::cancelarVuelo(int input_i){
  vector <string> vuelos_n;
  bool cancelacion = false;
  for (int i=0; i<vuelos.size(); i++) {
    if (stoi(vuelos[i])==input_i) {
      cout << "Se canceló existosamente su vuelo " << endl;
      cancelacion = true;
    }
    else {
      vuelos_n.push_back(vuelos[i]);
    }
  }
  vuelos = vuelos_n;
  return cancelacion;
}

