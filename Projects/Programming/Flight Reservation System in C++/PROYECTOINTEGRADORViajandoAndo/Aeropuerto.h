/*
Annette Pamela Ruiz Abreu
A01423595

04/06/2022
*/

#pragma once
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Aerolinea.h"
#include "validacion.h"
#include "Vuelo.h"
#include "Usuario.h"
using namespace std;

const int NUM_AEREOLINEAS = 3;

class Aeropuerto{
	//Privados para el encapsulamiento
	string id;
	string date;
  string city;
	string country;
	int totalTransactions;
	double totalDailyIncomes;
	Aerolinea airlines[NUM_AEREOLINEAS];
	
	public:
	Aeropuerto(); //Constructor vacío
	~Aeropuerto(); //Destructor

	//Getters
	string getId();
	string getDate();
	string getCity();
	string getCountry();
	int getTotalTransactions();
	double getTotalDailyIncomes();
  Aerolinea getAirlines(int);

	
	//Setters
	void setId(string);
	void setDate(string);
	void setCity(string);
	void setCountry(string);
	void setTotalTransactions(int);
	void setTotalDailyIncomes(double);
  void setAirline(int, Aerolinea);

	//Métodos
	void startOperations();
	void printAllFlights();
	void closeOperations(int);
	void registrarVuelo(int, int);
	void registrarPasajeros(int, int, Usuario*);
  void setVuelos();

  void crearArchivoAeropuerto();
  void clearAllFlights();
  void crearArchivoVuelos();

  void limpiarPasajeros(int, int);

};
