#include "Episodio.h"

Episodio::Episodio(){
  numEpisodio = 0;
  numTemporada = 0;
  nombreEpisodio = "";
  calificacion = 0;
}
Episodio::Episodio(int numEpisodio_, int numTemporada_, string nombreEpisodio_, double calificacion_){
  numEpisodio = numEpisodio_;
  numTemporada = numTemporada_;
  nombreEpisodio = nombreEpisodio_;
  calificacion = calificacion_;
}
Episodio::~Episodio(){
  
}

int Episodio::getNumEpisodio(){
  return numEpisodio;
}
int Episodio::getNumTemporada(){
  return numTemporada;
}
string Episodio::getNombreEpisodio(){
  return nombreEpisodio;
}
double Episodio::getCalificacion(){
  return calificacion;
}

void Episodio::setNumEpisodio(int numEpisodio_){
  numEpisodio = numEpisodio_;
}
void Episodio::setNumTemporada(int numTemporada_){
  numTemporada = numTemporada_;
}
void Episodio::setNombreEpisodio(string nombreEpisodio_){
  nombreEpisodio = nombreEpisodio_;
}
void Episodio::setCalificacion(double calificacion_){
  calificacion = calificacion_;
}

ostream& operator<<(ostream& salida, Episodio e){
  cout << "DATOS EPISODIO " << e.getNumEpisodio() << endl;
  cout << "Nombre: " << e.getNombreEpisodio() << endl;
  cout << "Temporada: " << e.getNumTemporada() << endl;
  cout << "Calificación: " << e.getCalificacion() << endl;
  return salida;
}

