/*
Annette Pamela Ruiz Abreu
A01423595

04/06/2022
*/

#pragma once
#include <iostream>
#include <string>
#include <string>
#include <sstream>
using namespace std;


class Pasajero{
	//Privados para el encapsulamiento
	string nombre;
  string telefono;
	int fila;
	int columna;
	bool vendido;
  double kilometro;

	public:
	Pasajero(); //Constructor vacío
	Pasajero(string, string, int, int, double);
	~Pasajero(); //Destructor

	//Getters
	string getNombre();
	string getTelefono();
	int getFila();
	int getColumna();
	bool getVendido();
  int getKilometros();
	//Setters
	void setNombre(string);
	void setTelefono(string);
	void setFila(int);
	void setColumna(int);
	void setVendido(bool);
};
