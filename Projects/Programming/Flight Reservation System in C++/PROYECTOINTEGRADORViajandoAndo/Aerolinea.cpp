/*
Annette Pamela Ruiz Abreu
A01423595

04/06/2022
*/

#include "Aerolinea.h"


Aerolinea::Aerolinea(){
	boardingCity = "";
  name = "";
  shortName = "";
	incomes = 0;
  number = 0;
}

Aerolinea::~Aerolinea(){
		
} //Destructor

	//Getters
	string Aerolinea::getBoardingCity(){
		return boardingCity;	
	}
	string Aerolinea::getShortName(){
		return shortName;
	}
	double Aerolinea::getIncomes(){
		return incomes;	
	}
	string Aerolinea::getName(){
		return name;
	}

	Vuelo Aerolinea::getFlight(int n_flight){
		return flights[n_flight];
	}

  int Aerolinea::getNumber() {
    return number;
  }

	//Setters
	void Aerolinea::setBoardingCity(string new_bC){
		boardingCity = new_bC;
	}
	void Aerolinea::setShortName(string shortName_){
		shortName = shortName_;
	}
	void Aerolinea::setIncomes(double incomes_){
		incomes = incomes_;
	}
	void Aerolinea::setName(string name_){
		name = name_;
	}
	void Aerolinea::setFlight(int n_fligth, Vuelo new_flight){
		flights[n_fligth] = new_flight;
	}
  void Aerolinea::setNumber(int num) {
    number = num;
  }


	//Métodos
	void Aerolinea::updateAirline(){
  	cout << "\nActualización de la aerolínea "<< number+1 << ":" << endl;
  	cout << "Nombre de la aerolínea: ";
  	getline(cin, name);
  	cout << "Abreviatura: ";
  	getline(cin, shortName);
  	cout << "Los datos han sido guardados correctamente" << endl << endl;
	}

void Aerolinea::scheduleFlight(int flight_num){
  flights[flight_num].setAirlineNumber(getNumber());
  flights[flight_num].setFlightNum(flight_num);
  flights[flight_num].setTo(getBoardingCity());
  string input_s = "";
  double input_d = 0;
  cout << "\nProgramación de vuelo " << flight_num+1 << " de la aerolínea " << getName() << ":" << endl << endl;
  cin.ignore();
  cout << "Modelo del Avión [B747/A380/A330]: ";
  input_s = validacion(input_s,4,6);
  flights[flight_num].setAirplaneModel(input_s);
  cout << "Ciudad destino: ";
  input_s = validacion(input_s,3,20);
  flights[flight_num].setTo(input_s);
  cout << "Fecha de partida [dd/mm/aa]: ";
  input_s = validacion(input_s,8,8);
  flights[flight_num].setDate(input_s);
  cout << "Distancia de vuelo en kilometros: ";
  input_d = validacion(input_d,1.0,50000.0);
  flights[flight_num].setDistance(input_d);
  flights[flight_num].calculateFuel();
  cin.ignore();
  cout << "Clave de la tripulación: ";
  input_s = validacion(input_s,3,20);
  flights[flight_num].setCrew(input_s);
  cout << "Duración del vuelo en horas: ";
  input_d = validacion(input_d,1.0,30.0);
  flights[flight_num].setDuracion(input_d);
  cin.ignore();
  cout << "Horario del vuelo [hh:mm]: ";
  input_s = validacion(input_s,5,5);
  flights[flight_num].setHour(input_s);
  cout << "Precio del boleto: ";
  input_d = validacion(input_d,1.0,100000.0);
  flights[flight_num].setPrice(input_d);
  cout << "El vuelo ha sido programado correctamente" << endl << endl;
 	flights[flight_num].setRegistrado(true);
}

	void Aerolinea::registrarPasajeros(int flight_num, Usuario *usuario){
      string v_string;
      v_string = to_string(flights[flight_num].getAirlineNumber()+1) + to_string(flight_num+1);
    
      usuario -> addVuelo(v_string);
    
      int vendidos = 0;
      for (int i = 0; i < FILAS; i++){
  		  for(int j = 0; j < COLUMNAS; j++){
          if (flights[flight_num].getPasajero(i, j).getVendido()) {
            vendidos ++;
          }
  		  }
  	  }
			string dato;
			string nombre_pasajero = usuario -> getNombre();
  		string tel_pasajero = usuario -> getTelefono();
      double kilometros_pasajeros = usuario -> getKilometros();
  		cin.ignore (); 

      cout << "Quedan " << ASIENTOS-vendidos << " asientos en este vuelo"  << endl;
  		cout << "\nIngrese el número de asientos que necesita: ";
      getline(cin, dato);
      while (stoi(dato)>(ASIENTOS-vendidos) || stoi(dato)<=0) {
        cout << "Número de asientos inválido. Inténtelo de nuevo" << endl;
        getline(cin, dato);
      }
      double kilometros_n = flights[flight_num].getDistance();
      usuario -> setKilometros(kilometros_pasajeros+kilometros_n);
      int updateNumPasajeros = flights[flight_num].getCantidadPasajeros() + stoi(dato);
      flights[flight_num].setCantidadPasajeros(updateNumPasajeros);


      double desc = 1;
      if (kilometros_pasajeros>=50000) {
        desc = 0.6;
      }
			double current_income = stod(dato) * flights[flight_num].getPrice() * desc;
			currentIncome(current_income);
  		incomes += current_income;
    
  		
  		for (int i = 0; i < stoi(dato); i++){
  			int fila_p, columna_p;
  			
  			cout << "Ingrese el número de fila: ";
  			while  (!(cin >> fila_p) || fila_p <= 0 || fila_p > FILAS) {
  			cin.clear(); //Limpia el input anterior 
  			cin.ignore(123, '\n'); //Ignora caracteres anteriores
  			cout << "Ingresa un número válido para la fila: ";
  			}
  			cout << "Ingrese el número de columna: ";
  			while  (!(cin >> columna_p) || columna_p <= 0 || columna_p > COLUMNAS) {
  			cin.clear(); //Limpia el input anterior 
  			cin.ignore(123, '\n'); //Ignora caracteres anteriores
  			cout << "Ingresa un número válido para la columna: ";
  			}
  
  			
  			while (flights[flight_num].getPasajero(fila_p, columna_p).getVendido() ){
  				cout << "Ese asiento está ocupado. Por favor ingrese un asiento válido nuevamente." << endl;
  				cout << "Ingrese el número de fila: ";
  				while  (!(cin >> fila_p) || fila_p <= 0 || fila_p > FILAS) {
  				cin.clear(); //Limpia el input anterior 
  				cin.ignore(123, '\n'); //Ignora caracteres anteriores
  				cout << "Ingresa un número válido para la fila: ";
  				}
  				cout << "Ingrese el número de columna: ";
  				while  (!(cin >> columna_p) || columna_p <= 0 || columna_p > 4) {
  				cin.clear(); //Limpia el input anterior 
  				cin.ignore(123, '\n'); //Ignora caracteres anteriores
  				cout << "Ingresa un número válido para la columna: ";
  				}
  			}
  			Pasajero pasajero_p = Pasajero(nombre_pasajero,tel_pasajero,fila_p,columna_p, kilometros_pasajeros);
  			pasajero_p.setVendido(true);
  			flights[flight_num].setPasajero(fila_p,columna_p, pasajero_p);
  			cout << "Se ha registrado correctamente el asiento " << i+1 << " con fila: " << fila_p << " y columna: " << columna_p << endl << endl;
  		}
	}

	void Aerolinea::currentIncome(double curr){
		cout << "El ingreso ganado por los boletos vendidos hasta ahora es de: $" << curr << endl;
	}

	void Aerolinea::closeOperation(){
		cout << "El ingreso total del día es: $" << incomes << endl;
	}

	void Aerolinea::imprimeAerolinea(){
		cout << "\n\nLos vuelos de la Aerolínea " << name << " son: " << endl << endl;
		for (int i = 0; i < NUM_FLIGHTS; i++){
			if(flights[i].getRegistrado()){
				flights[i].imprimirVuelo(i);
			}
		}
	}


void Aerolinea::clearAllFlights() {
  for (int i=0; i<NUM_FLIGHTS; i++) {
    flights[i] = Vuelo();
  }
}


void Aerolinea::limpiarPasajeros(int f) {
  flights[f].limpiarPasajeros();
}
