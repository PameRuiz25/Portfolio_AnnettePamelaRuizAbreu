#include "Video.h"

Video::Video(){
  id = "";
  nombre = "";
  duracion = 0;
  genero = "";
  calificacion = 0;
  type = "";
  rating = "";
  votos = 0;
}
Video::Video(string id_, string nombre_, int duracion_, string type_, string genero_, string rating_, double calificacion_, int votos_){
  id = id_;
  nombre = nombre_;
  duracion = duracion_;
  genero = genero_;
  calificacion = calificacion_;
  type = type_;
  rating = rating_;
  votos = votos_;
}
Video::~Video(){
  
}

int Video::getVotos(){
  return votos;
}

string Video::getId(){
  return id;
}
string Video::getNombre(){
  return nombre;
}
int Video::getDuracion(){
  return duracion;
}
string Video::getGenero(){
  return genero;
}
double Video::getCalificacion(){
  return calificacion;
}
string Video::getType(){
  return type;
}
string Video::getRating() {
  return rating;
}

void Video::setVotos(int votos_){
  votos = votos_;
}

void Video::setId(string id_){
  id = id_;
}
void Video::setNombre(string nombre_){
  nombre = nombre_;
}
void Video::setDuracion(int duracion_){
  duracion = duracion_;
}
void Video::setGenero(string genero_){
  genero = genero_;
}
void Video::setCalificacion(double calificacion_){
  calificacion = calificacion_;
}
void Video::setType(string type_){
  type = type_;
}
void Video::setRating(string rating_){
  rating = rating_;
}