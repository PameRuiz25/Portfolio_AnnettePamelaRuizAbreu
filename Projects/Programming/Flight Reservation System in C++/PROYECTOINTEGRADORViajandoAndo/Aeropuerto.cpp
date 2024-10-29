/*
Annette Pamela Ruiz Abreu
A01423595

04/06/2022
*/

#include "Aeropuerto.h"

Aeropuerto::Aeropuerto(){
	id = "";
	date = "";
  city = "";
	country = "";
	totalTransactions = 0;
	totalDailyIncomes = 0;
} 


Aeropuerto::~Aeropuerto(){
	
}

//Getters
string Aeropuerto::getId(){
	return id;
}
string Aeropuerto::getDate(){
	return date;
}
string Aeropuerto::getCity(){
	return city;
}
string Aeropuerto::getCountry(){
	return country;
}
int Aeropuerto::getTotalTransactions(){
	return totalTransactions;
}
double Aeropuerto::getTotalDailyIncomes(){
	return totalDailyIncomes;
}
Aerolinea Aeropuerto::getAirlines(int airline_num){
  return airlines[airline_num];
}



//Setters
void Aeropuerto::setId(string id_){
	id = id_;
}
void Aeropuerto::setDate(string date_){
	date = date_;
}
void Aeropuerto::setCity(string city_){
	city = city_;
}
void Aeropuerto::setCountry(string country_){
	country = country_;
}
void Aeropuerto::setTotalTransactions(int total_){
	totalTransactions = total_;
}
void Aeropuerto::setTotalDailyIncomes(double totalD_){
	totalDailyIncomes = totalD_;
}

void Aeropuerto::setAirline(int airline_num, Aerolinea new_airline){
  airlines[airline_num] = new_airline;
}

//Métodos

void Aeropuerto::startOperations(){
  cout << "Por favor ingrese la fecha de hoy en formato [dd/mm/aa]: ";
	date = validacion(date,8,8);
	cout << "\n Iniciando operaciones" << endl << endl;
  if (id=="") {
    cout << "Identificador del Aeropuerto: ";
	  id = validacion(id,3,20);
	  cout << "Ciudad de Operación: ";
	  city = validacion(city,3,30);
	  cout << "País: ";
	  country = validacion(country,3,30);
  }
  setVuelos();
  
}

void Aeropuerto::registrarVuelo(int n_aerolinea, int n_vuelo){
  airlines[n_aerolinea].getFlight(n_vuelo).setAirlineNumber(n_aerolinea);
	airlines[n_aerolinea].scheduleFlight(n_vuelo);
	totalTransactions ++;
}

void Aeropuerto::registrarPasajeros(int n_aerolinea, int n_vuelo, Usuario *usuario){
	airlines[n_aerolinea].registrarPasajeros(n_vuelo, usuario);
}

void Aeropuerto::printAllFlights(){
	cout << "Los vuelos programados para " << date << " son: " << endl;
	for (int i = 0; i < NUM_AEREOLINEAS ; i++){
		airlines[i].imprimeAerolinea();
	}
}


void Aeropuerto::closeOperations(int cancelation_fee){
	double suma_incomes = 0;
	for (int i = 0; i < NUM_AEREOLINEAS; i++){
		suma_incomes += airlines[i].getIncomes();
	}
	cout << "\nEl total de vuelos registrados del día " << date << " fue de: " << totalTransactions << endl;
	cout << "El total de ingresos de este día en el aeropuerto " << id << " fue de: $" << suma_incomes - cancelation_fee << endl;
}

void Aeropuerto::setVuelos(){
  ifstream vuelos_text_in;
  vuelos_text_in.open("vuelos.txt");
  if (vuelos_text_in.fail()) {
    for (int i = 0; i<NUM_AEREOLINEAS; i++) {
      airlines[i].setBoardingCity(city);
      airlines[i].setNumber(i);
  		airlines[i].updateAirline();
  		
      for (int j = 0; j<NUM_FLIGHTS; j++) {
        Vuelo v;
  			v = airlines[i].getFlight(j);
        v.setAirlineNumber(i);
        v.setFrom(getCity());
  			airlines[i].setFlight(j,v);
      }
    }
  }
  else {
    for (int i = 0; i<NUM_AEREOLINEAS; i++) {
      airlines[i].setBoardingCity(city);
      airlines[i].setNumber(i);
    	airlines[i].updateAirline();
    }
    int paso = 1;
    Vuelo vuelo;
    string input_s;
    int f=0, c=0, x;
    while (vuelos_text_in >> input_s) {
      cout << input_s << endl;
      switch(paso){
        case 1:
          vuelo.setAirlineNumber(stoi(input_s));
          break;
        case 2:
          vuelo.setDate(input_s);
          break;
        case 3:
          vuelo.setHour(input_s);
          break;
        case 4:
          vuelo.setPrice(stod(input_s));
          break;
        case 5:
          vuelo.setFuel(stod(input_s));
          break;
        case 6:
          vuelo.setAirplaneModel(input_s);
          break;
        case 7:
          vuelo.setFrom(input_s);
          break;
        case 8:
          vuelo.setTo(input_s);
          break;
        case 9:
          vuelo.setDuracion(stod(input_s));
          break;
        case 10:
          vuelo.setDistance(stod(input_s));
          break;
        case 11:
          vuelo.setCrew(input_s);
          break;
        case 12:
          vuelo.setFlightNum(stoi(input_s));
          vuelo.setRegistrado(true);
            airlines[vuelo.getAirlineNumber()].setFlight(vuelo.getFlightNum(),vuelo);
          totalTransactions++;
          paso = 0;
          Vuelo vuelo;
          
          break;
        }
  
        paso ++;    
  }
  
}
}


void Aeropuerto::crearArchivoAeropuerto() {
  ofstream aeropuerto_text_out;
  aeropuerto_text_out.open("aeropuerto.txt");
  if (aeropuerto_text_out.fail()) {
      cout << "ERROR DE SISTEMA" << endl;
      exit(1);
  }
  aeropuerto_text_out << id << endl;
  aeropuerto_text_out << city << endl;
  aeropuerto_text_out << country << endl;
  aeropuerto_text_out.close();
}

void Aeropuerto::clearAllFlights() {
  for (int i=0; i<NUM_AEREOLINEAS; i++) {
    airlines[i].clearAllFlights();
  }
  cout << "SE HAN BORRADO TODOS LOS VUELOS DE TODAS LAS AEROLÍNEAS" << endl;
}

void Aeropuerto::crearArchivoVuelos() {
  ofstream vuelos_text_out;
  Vuelo v;
  vuelos_text_out.open("vuelos.txt");
  if (vuelos_text_out.fail()) {
      cout << "ERROR DE SISTEMA" << endl;
      exit(1);
  }
  for (int i=0; i<NUM_AEREOLINEAS; i++) {
    for (int j=0; j<NUM_FLIGHTS; j++) {
      v = airlines[i].getFlight(j);
      if (v.getRegistrado()) {
        vuelos_text_out << v.getAirlineNumber() << endl;
        vuelos_text_out << v.getDate() << endl;
        vuelos_text_out << v.getHour() << endl;
        vuelos_text_out << v.getPrice() << endl;
        vuelos_text_out << v.getFuel() << endl;
        vuelos_text_out << v.getAirplaneModel() << endl;
        vuelos_text_out << v.getFrom() << endl;
        vuelos_text_out << v.getTo() << endl;
        vuelos_text_out << v.getDuracion() << endl;
        vuelos_text_out << v.getDistance() << endl;
        vuelos_text_out << v.getCrew() << endl;
        vuelos_text_out << v.getFlightNum() << endl;
      }
    }
  }

  
  vuelos_text_out.close();
}

void Aeropuerto::limpiarPasajeros(int a, int f) {
  airlines[a].limpiarPasajeros(f);

  
}
