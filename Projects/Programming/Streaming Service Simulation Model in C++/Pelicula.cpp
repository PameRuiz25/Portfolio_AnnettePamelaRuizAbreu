#include "Pelicula.h"

Pelicula::Pelicula():Video::Video(){
  
}
Pelicula::Pelicula(string id, string nombre, int duracion, string tipo, string genero, string rating, double calificacion, int votos):Video::Video(id, nombre, duracion, tipo, genero, rating, calificacion, votos){
  
}
Pelicula::~Pelicula(){
  
}

void Pelicula::imprimeVideo() {
  cout << "\nDatos de la Película " << getId() << endl;
  cout <<  "Nombre: " << getNombre() << endl;
  cout << "Género: " << getGenero()  << endl;
  cout << "Rating: " << getRating() << endl;
  cout << "Minutos: " << getDuracion() << endl;
  cout << "Calificación Promedio: " << getCalificacion() << endl;
  cout << "Número de votos: " << getVotos() << endl;
}


void Pelicula::calificar(double cali){
  setVotos(getVotos()+1);
  if (getCalificacion()==0) {
    setCalificacion(cali);
  }
  else {
    setCalificacion((getCalificacion()*(getVotos()-1)+cali)/getVotos());
  }
}


