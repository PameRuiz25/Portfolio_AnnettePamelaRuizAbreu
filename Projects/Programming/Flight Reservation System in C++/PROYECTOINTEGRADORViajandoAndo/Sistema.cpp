#include <iostream>
#include "Sistema.h"


Sistema::Sistema(){
  usuarios = {};
}
Sistema::Sistema(Aeropuerto aeropuerto, vector<string> usuarios){
  this -> aeropuerto = aeropuerto;
  this -> usuarios = usuarios;
}
Sistema::~Sistema(){
  
}

Aeropuerto Sistema::getAeropuerto(){
  return aeropuerto;
}

vector<string> Sistema::getUsuarios(){
  return usuarios;
}

string Sistema::getUnUsuario(int i){
  return usuarios[i];
}


    
void Sistema::setAeropuerto(Aeropuerto aeropuerto){
  this -> aeropuerto = aeropuerto;
}

void Sistema::setUsuarios(vector<string> usuarios){
  this -> usuarios = usuarios;
}

void Sistema::setUnUsuario(int i, string usuario){
  usuarios[i] = usuario;
}


void Sistema::addUsuario(string usuario){
  usuarios.push_back(usuario);
}


