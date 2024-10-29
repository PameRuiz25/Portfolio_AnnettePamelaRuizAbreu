/*
Annette Pamela Ruiz Abreu
A01423595

04/06/2022
*/

#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Vuelo.h"
#include "validacion.h"
#include "Usuario.h"
using namespace std;


const int NUM_FLIGHTS = 5;

class Aerolinea{
	//Privados para el encapsulamiento
	string boardingCity;
	string name;
  string shortName;
	double incomes;
  int number;
	Vuelo flights[NUM_FLIGHTS];
	
	public:
	Aerolinea(); //Constructor vacío
	~Aerolinea(); //Destructor

	//Getters
	string getBoardingCity();
	string getShortName();
	double getIncomes();
	string getName();
	Vuelo getFlight(int);
  int getNumber();

	//Setters
	void setBoardingCity(string);
	void setShortName(string);
	void setIncomes(double);
	void setName(string);
	void setFlight(int, Vuelo);
  void setNumber(int);

	//Métodos
	void updateAirline();
	void scheduleFlight(int);
	void currentIncome(double);
	void closeOperation();
	void registrarPasajeros(int, Usuario*);
	void imprimeAerolinea();
  void clearAllFlights();

  void limpiarPasajeros(int);

};