/*
Annette Pamela Ruiz Abreu
A01423595

04/06/2022
*/

#include "Pasajero.h"

#ifndef VUELO_H
#define VUELO_H

const int FILAS = 30;
const int COLUMNAS = 4;
const int ASIENTOS = FILAS*COLUMNAS;

using namespace std;

class Vuelo {
  string date;
  string hour;
  double price;
  string airplaneModel;
  string from;
  string to;
  double distance;
  string crew;
  double fuel;
  Pasajero seats[FILAS][COLUMNAS];
	bool registrado;
  int airlineNumber;
  double duracion;
  int cantidadPasajeros;
  int flight_num;

  public:
  // Constructores
    Vuelo();
    Vuelo(string,string,double,string,string,string,double,string,double);
  // Destructor
		~Vuelo();
	//Getters
    int getFlightNum();
    string getDate();
    string getHour();
    double getPrice();
    string getAirplaneModel();
    string getFrom();
    string getTo();
    double getDistance();
    string getCrew();
    double getFuel();
    Pasajero getPasajero(int, int);
		bool getRegistrado();
    int getAirlineNumber();
    int getCantidadPasajeros();
    double getDuracion();
    
	//Setters
    void setFlightNum(int);
		void setDate(string);
		void setHour(string);
		void setPrice(double);
		void setAirplaneModel(string);
		void setFrom(string);
    void setTo(string);
		void setDistance(double);
		void setCrew(string);
		void setFuel(double);
		void setPasajero(int, int, Pasajero);
		void setRegistrado(bool);
    void setAirlineNumber(int);
    void setDuracion(double);
    void setCantidadPasajeros(int);

	//Métodos
		void calculateFuel();
		void imprimirVuelo(int);
    void limpiarPasajeros();

};
#endif
