/*
Annette Pamela Ruiz Abreu
A01423595

04/06/2022
*/

#include "Pasajero.h" //Archivo encabezado
using namespace std;

Pasajero::Pasajero(){ //Constructor vacío
	nombre = "";
	telefono = "";
  kilometro = 0;
	fila = 0;
	columna = 0;
	vendido = false;
}

Pasajero::Pasajero(string name, string phone, int fila_, int columna_, double kilometro_){ //Constructor vacío
	nombre = name;
	telefono = phone;
  kilometro = kilometro_;
	fila = fila_;
	columna = columna_;
	vendido = true;
}


Pasajero::~Pasajero(){ //Destructor

}

//Getters
string Pasajero::getNombre(){
	return nombre;
}
string Pasajero::getTelefono(){
	return telefono;
}
int Pasajero::getFila(){
	return fila;
}
int Pasajero::getColumna(){
	return columna;
}
bool Pasajero::getVendido(){
	return vendido;
}
int Pasajero::getKilometros(){
  return kilometro;
}

//Setters
void Pasajero::setNombre(string nuevo_nombre){
	nombre = nuevo_nombre;
}
void Pasajero::setTelefono(string nueva_telefono){
	telefono = nueva_telefono;
}
void Pasajero::setFila(int nueva_fila){
	fila = nueva_fila;
}
void Pasajero::setColumna(int nueva_columna){
	columna = nueva_columna;
}
void Pasajero::setVendido(bool vendido_){
	vendido = vendido_;
}