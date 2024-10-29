#include <iostream>
#include "validacion.h"
#include "funciones.h"
#include "Sistema.h"
#include <unistd.h>
using namespace std;

void startMenu(Sistema *sistema){
  sleep(1);
  cout << " _______________\n| /~~~~~~~~\\ ||||\n||          |...|\n||          |   |\n| \\________/  O |\n ~~~~~~~~~~~~~~~" << endl;
  int input_i;
  string input_s;
  Servicio servicio;
  bool operando = true;
  while (operando) {
    sleep(1);
    cout << "\n -------------------- MENÚ -------------------- " << endl;
    cout << "<1> Cargar archivo de datos\n<2> Ver datos de los servicios de streaming\n<3> Mostrar todos los videos\n<4> Buscar videos \n<5> Ver episodios de una serie\n<6> Calificar un video\n<0> Salir" << endl;
  input_i = validacion(input_i,0,6);
    switch (input_i) {
      case 0:
        operando = false;
        sistema -> crearArchivosSalida();
        break;
      case 1:
        mostrarServicios();
        input_i = validacion(input_i,0,4)-1;
        if (input_i==-1) {
          break;
        }
        if (sistema->getUnServicio(input_i).getCantidadContenido()!=0) {
          cout << "Este servicio ya tiene videos precargados." << endl;
          break;
        }
        cin.clear();
		    cin.ignore(123, '\n');
        cout << "Ingrese el path al archivo: " << endl;
        input_s = validacion(input_s,1,10000);
        sistema -> leerArchivo(input_s,input_i);
        
        break;
      case 2:
        sistema -> imprimeServicios();
        break;
      case 3:
        mostrarServicios();
        input_i = validacion(input_i,0,4)-1;
        servicio = sistema->getUnServicio(input_i);
        if (input_i==-1) {
          break;
        }
        servicio.menuMostrarVideos();
        
        break;
      case 4:
        mostrarServicios();
        input_i = validacion(input_i,0,4)-1;
        if (input_i==-1) {
          break;
        }
        servicio = sistema->getUnServicio(input_i);

        servicio.busquedadFiltrada();
        
        break;
      case 5:
        mostrarServicios();
        input_i = validacion(input_i,0,4)-1;
        servicio = sistema->getUnServicio(input_i);

        servicio.imprimirEpisodios();
        break;
      case 6:
        mostrarServicios();
        input_i = validacion(input_i,0,4)-1;
        if (input_i==-1) {
          break;
        }
        servicio = sistema->getUnServicio(input_i);
        servicio.calificar();
        
        break;
    }

    
  }
}
