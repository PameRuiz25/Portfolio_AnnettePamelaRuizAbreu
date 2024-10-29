/*
Annette Pamela Ruiz Abreu
A01423595

04/06/2022
*/

#pragma once
#include <iostream>
#include <string>
#include "Pasajero.h"
#include "Vuelo.h"

Vuelo::Vuelo(){
	date = "0/0/0";
	hour = "00:00";
	price = 0;
	airplaneModel = "Desconocido";
	from = "CDMX";
  to = "";
  distance = 0;
	crew = "Desconocido";
  fuel = 0;
	registrado = false;
  airlineNumber = 0;
  cantidadPasajeros = 0;
  duracion = 0;
}

Vuelo::Vuelo(string date_,string hour_,double price_,string airplaneModel_,string from_, string to_,double distance_,string crew_,double fuel_){
  date = date_;
	hour = hour_;
	price = price_;
	airplaneModel = airplaneModel_;
	from = from_;
  to = to_;
  distance = distance_;
	crew = crew_;
  fuel = fuel_;
	registrado = false;
  for (int i = 0; i < FILAS; i++){
		for(int j = 0; i < COLUMNAS; j++){
      seats[i][j].setFila(i);	
			seats[i][j].setFila(j);
		}
	}
}

  // Destructor
	Vuelo::~Vuelo(){
      
    }
	//Getters

    int Vuelo::getAirlineNumber(){
      return airlineNumber;
    }

    string Vuelo::getDate(){
      return date;
    }
    string Vuelo::getHour(){
			return hour;	
		}
    double Vuelo::getPrice(){
			return price;
		}
    string Vuelo::getAirplaneModel(){
			return airplaneModel;
		}
    string Vuelo::getFrom(){
			return from;
		}
    string Vuelo::getTo(){
      return to;
    }
    double Vuelo::getDistance(){
			return distance;
		}
    string Vuelo::getCrew(){
			return crew;
		}
    double Vuelo::getFuel(){
			return fuel;
		}
    Pasajero Vuelo::getPasajero(int fila_, int columna_){
			return seats[fila_][columna_];
		}
		bool Vuelo::getRegistrado(){
			return registrado;
		}
    int Vuelo::getCantidadPasajeros() {
      return cantidadPasajeros;
    }
    double Vuelo::getDuracion() {
      return duracion;
    }
    int Vuelo::getFlightNum() {
      return flight_num;
    }
    
    
	//Setters
    void Vuelo::setFlightNum(int n) {
      flight_num = n;
    }
    void Vuelo::setCantidadPasajeros(int pasajeros){
      cantidadPasajeros = pasajeros;
    }
    void Vuelo::setAirlineNumber(int number_) {
      airlineNumber = number_;
    }
		void Vuelo::setDate(string date_){
      date = date_;
    }
		void Vuelo::setHour(string hour_){
      hour = hour_;
    }
		void Vuelo::setPrice(double price_){
      price = price_;
    }
		void Vuelo::setAirplaneModel(string airplaneModel_){
      airplaneModel = airplaneModel_;      
    }
		void Vuelo::setFrom(string from_){
      from = from_;
    }
    void Vuelo::setTo(string to_) {
      to = to_;
    }
		void Vuelo::setDistance(double distance_){
      distance = distance_;
    }
		void Vuelo::setCrew(string crew_) {
      crew = crew_;
    }
		void Vuelo::setFuel(double fuel_){
			fuel = fuel_;
		}
		void Vuelo::setPasajero(int fila_, int columna_, Pasajero p){
			seats[fila_][columna_] = p;
		}
		void Vuelo::setRegistrado(bool new_registrado){
			registrado = new_registrado;
		}
    void Vuelo::setDuracion(double duracion_){
      duracion = duracion_;
    }

	//Métodos
		void Vuelo::calculateFuel(){
			if (airplaneModel == "A380"){
				fuel = 10 * distance;
			} else if (airplaneModel == "A330"){
				fuel = 8 * distance;
			} else {
				fuel = distance*12;
			}

			cout << "El combustible necesario para viajar de " << from << " a " << to << " es de " << fuel << " Litros" << endl;
		}

		void Vuelo::imprimirVuelo(int n){
			cout << "\nInformación del vuelo " << n+1 << endl << endl;
			cout << "El vuelo parte a las " << hour << endl;
			cout << "El vuelo va de " << from << " a " << to << endl;
			cout << "El combustible necesario para viajar de " << from << " a " << to << " es de " << fuel << " Litros" << endl;
      cout << "La distancia del vuelo es: " << distance << " [km]" << endl;
      cout << "El costo de un boleto de este vuelo es: $"	<< price << endl;
      cout << "FECHA: " << date << endl << endl;
			for (int fila = 0; fila < FILAS; fila ++){
				for (int columna = 0; columna < COLUMNAS; columna ++) {
					if(getPasajero(fila, columna).getVendido()){
						cout << "El asiento [" << fila << ", " << columna << "]" << " está ocupado" << endl;
					}
				}
			}
			
}

void Vuelo::limpiarPasajeros(){
  for (int i=0; i<FILAS; i++) {
    for (int j=0; j<COLUMNAS; j++) {
      seats[i][j].setVendido(false);
    }
  }
}

