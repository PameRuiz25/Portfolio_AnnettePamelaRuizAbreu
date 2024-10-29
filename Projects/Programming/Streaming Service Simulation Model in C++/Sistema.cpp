#include "Sistema.h"
using namespace std;

Sistema::Sistema(){
  listaServicios = {};
}
Sistema::Sistema(vector <Servicio> listaServicios){
  this -> listaServicios = listaServicios;
}
Sistema::~Sistema(){
  
}

vector<Servicio> Sistema::getListaServicios(){
  return listaServicios;
}
Servicio Sistema::getUnServicio(int i){
  return listaServicios[i];
}

void Sistema::setListaServicios(vector<Servicio> listaServicios_){
  listaServicios = listaServicios_;
}
void Sistema::setUnServicio(int i, Servicio servicio){
  listaServicios[i] = servicio;
}

void Sistema::addUnServicio(Servicio servicio){
  listaServicios.push_back(servicio);
}

void Sistema::leerArchivo(string nombreArchivo, int numeroServicio){
  listaServicios[numeroServicio].leerArchivo(nombreArchivo);
}

void Sistema::imprimeServicios(){
  for (int i=0; i<listaServicios.size(); i++) {
    cout << listaServicios[i];
  }
}


void Sistema::crearArchivosSalida() {
  for (int i=0; i<listaServicios.size(); i++) {
    listaServicios[i].crearArchivosSalida();
  }  
}



