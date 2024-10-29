/*
Annette Pamela Ruiz Abreu
A01423595

04/06/2022
*/

#include "menu.h"
using namespace std;

void startMenu(Aeropuerto aeropuertoMX, Sistema *sistema, Usuario *usuario){
  double cancelation_fee = 0;
  Vuelo v;
  Aerolinea airline;
  vector<int> numeros_vuelos = {};
  vector<int> numeros_airlines = {};
  int input_i, airline_num, flight_num;
  string input_s;
  double input_d;
  string fecha_o = "", hora_o = "", destino_o = "", fecha, hora, destino;
  double preciomin_o = 0.0, preciomax_o = 0.0, preciomin, preciomax;
  bool operando_main = true, vuelo_invalido = true, airline_invalido = true;
  bool operando_admin = true, continua;
  string CONTRASENA_ADMIN = "P4m3Ru1z";
  while (operando_main) {
    cout << "\n\n ----------------- MENÚ ----------------- " << endl;
    cout << "<1> Menú de Administrador" << endl;
    cout << "<2> Buscar vuelos" << endl;
    cout << "<3> Cancelar vuelo" << endl;
    cout << "<4> Ver información de usuario" << endl;
    cout << "<0> Salir" << endl;
    cout << " ------------------------------------------- " << endl;
    input_i = validacion(input_i,0,4);
    operando_admin = true;
    
    switch (input_i) {
      case 0:
        aeropuertoMX.crearArchivoAeropuerto();
        aeropuertoMX.crearArchivoVuelos();
        aeropuertoMX.closeOperations(cancelation_fee);
        sistema -> setAeropuerto(aeropuertoMX);
        operando_main = false;
        break;
      case 1:
        cin.ignore();
        cout << "Ingrese la contraseña de administrador: ";
        getline(cin,input_s);
        if (input_s!=CONTRASENA_ADMIN) {
          cout << "Contraseña incorrecta" << endl;
          break;
        }
        while (operando_admin) {
          cout << "\n\n --------- MENÚ DE ADMINISTRADOR --------- "<< endl;
          cout << "<1> Programar un vuelo" << endl;
          cout << "<2> Imprimir todos los vuelos" << endl;
          cout << "<3> Borrar todos los vuelos" << endl;
          cout << "<0> Regresar al menú principal" << endl;
          cout << " --------------------------------------- " << endl;
          input_i = validacion(input_i,0,3);

          switch(input_i) {
            case 0:
              operando_admin = false;
              break;
            case 1:
              airline_num = seleccionarAerolinea(input_i, aeropuertoMX);
              flight_num = seleccionarVueloNoRegistrado(input_i, aeropuertoMX, airline_num);
              if (flight_num==-1) {
                break;
              }
              aeropuertoMX.registrarVuelo(airline_num,flight_num);
              break;
            case 2:
              aeropuertoMX.printAllFlights();
              break;
            case 3:
              aeropuertoMX.clearAllFlights();
              break;
          } 
        }

        break;
      case 2:
        for (int i=0; i<NUM_AEREOLINEAS; i++) {
          for (int j=0; j<NUM_FLIGHTS; j++) {
            if (aeropuertoMX.getAirlines(i).getFlight(j).getRegistrado()) {
              continua = true;
              break;
            }
          }
        }
        if (!continua) {
          cout << "NO HAY VUELOS PROGRAMADOS" << endl;
        }
        while (continua) {
          cout << " --------------- FILTROS --------------- " << endl;
          cout << "<0> Buscar vuelos" << endl;
          cout << "<1> Borrar filtros" << endl;
          cout << "<2> Fecha" << endl;
          cout << "<3> Hora" << endl;
          cout << "<4> Destino" << endl;
          cout << "<5> Precio" << endl;
          cout << "<6> Salir" << endl;
          input_i = validacion(input_i,0,6);
          cin.ignore();
          switch(input_i) {
            case 0:
              vuelo_invalido = true;
              airline_invalido = true;
              numeros_vuelos.clear();
              numeros_airlines.clear();
              for (int i=0; i<NUM_AEREOLINEAS; i++) {
                cout << "VUELOS DE LA AEROLÍNEA " << aeropuertoMX.getAirlines(i).getName() << endl;
                for (int j=0; j<NUM_FLIGHTS; j++) {
                  v = aeropuertoMX.getAirlines(i).getFlight(j);
                  fecha = fecha_o;
                  hora = hora_o;
                  destino = destino_o;
                  preciomin = preciomin_o;
                  preciomax = preciomax_o;
                  if (fecha=="") {
                    fecha = v.getDate();
                  }
                  if (hora=="") {
                    hora = v.getHour();
                  }
                  if (destino=="") {
                    destino = mayusculas(v.getTo());
                  }
                  if (preciomin==0) {
                    preciomin = v.getPrice();
                  }
                  if (preciomax==0) {
                    preciomax = v.getPrice();
                  }
                  if (fecha==v.getDate() && hora==v.getHour() && destino==mayusculas(v.getTo()) && v.getPrice()>=preciomin && v.getPrice()<=preciomax && v.getRegistrado()) {
                  v.imprimirVuelo(j);
                  numeros_vuelos.push_back(j);
                  numeros_airlines.push_back(i);
                }
                v = Vuelo();
              }
            }
            
            if (numeros_vuelos.size()==0) {
              cout << "No hay ningún vuelo que cumpla con los filtros" << endl;
            }
            else {
              cout << "\n<1> Reservar vuelo" << endl;
              cout << "<0> Salir" << endl;
              input_i = validacion(input_i, 0,1);
              switch(input_i) {
                case 0:
                  break;
                case 1:
                  airline_num = seleccionarAerolinea(input_i, aeropuertoMX);
                  for (int i=0; i<numeros_airlines.size(); i++) {
                    if (numeros_airlines[i]==airline_num) {
                      airline_invalido = false;
                    };
                  }
                  if (airline_invalido) {
                    cout << "La aerolinea seleccionada no tiene vuelos que cumplan con los filtros especificados" << endl;
                    break;
                  }
                  cout << "<0> Salir" << endl;
                  cout << "Ingresar número de vuelo: ";
                  while (vuelo_invalido) {
                    flight_num = validacion(input_i, 0, NUM_FLIGHTS) - 1;
                    if (flight_num == -1) {
                      vuelo_invalido = false;
                      break;
                    }
                    else {
                      for (int i=0; i<numeros_vuelos.size(); i++) {
                      if (numeros_vuelos[i] == flight_num) {
                        aeropuertoMX.registrarPasajeros(airline_num,flight_num, usuario);
                        vuelo_invalido = false;
                        break;
                      }
                    }
                      if (vuelo_invalido) {
                        cout << "Ingresar un número de vuelo válido: ";
                      }
                    }
                  }
                       
                  break;
              }
            }
             
              break;
            case 1:
              fecha_o = "";
              hora_o = "";
              destino_o = "";
              preciomin_o = 0.0;
              preciomax_o = 0.0;
              cout << "Se han borrado todos los filtros" << endl;
              break;
            case 2:
              cout << "FECHA: ";
              input_s = validacion(input_s,8,8);
              fecha_o = input_s;
              break;
            case 3:
              cout << "HORA: ";
              input_s = validacion(input_s,5,5);
              hora_o = input_s;
              break;
            case 4:
              cout << "DESTINO: ";
              input_s = validacion(input_s,2,20);
              destino_o = mayusculas(input_s);
              break;
            case 5:
              cout << "PRECIO MÍNIMO: ";
              input_d = validacion(input_d,1.0,100000.0);
              preciomin_o = input_d;
              cout << "PRECIO MÁXIMO: ";
              input_d = validacion(input_d,preciomin,1000000.0);
              preciomax_o = input_d;
              break;
            case 6:
              fecha_o = "";
              hora_o = "";
              destino_o = "";
              preciomin_o = 0.0;
              preciomax_o = 0.0;
              continua = false;
              break;
          }
        }
        break;
      case 3:
        usuario -> mostrarVuelos();
        cout << "NOTA: SI CANCELA EL VUELO SOLO SE LE REEMBOLSARÁ LA MITAD DEL COSTO DE 1 BOLETO" << endl << endl;
        cout << "Ingrese el número de la aerolínea y el número de vuelo (juntos y sin espacios) para cancelar el vuelo. Si desea salir ingrese 0" << endl;
        input_i = validacion(input_i,0,35);
        if (usuario -> cancelarVuelo(input_i)) {
          int a, f;
          if (input_i>=30) {
            a = 2;
            f = input_i - 31;
          }
          else if (input_i>=20) {
            a = 1;
            f = input_i - 21;
          }
          else {
            a = 0;
            f = input_i - 11;
          }
          aeropuertoMX.limpiarPasajeros(a,f);
          usuario -> setKilometros(usuario -> getKilometros() - aeropuertoMX.getAirlines(a).getFlight(f).getDistance());
          cancelation_fee += aeropuertoMX.getAirlines(a).getFlight(f).getPrice()/2;
        }
        else {
          cout << "No tenía boletos para el vuelo que seleccionó. No se hizo ninguna cancelación" << endl;
        }
        break;
      case 4:
        usuario -> imprimeUsuario();
        break;
    }
  }
}
