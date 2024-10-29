#pragma once
#include <iostream>
#include <string>
using namespace std;

class Episodio{

  int numEpisodio;
  int numTemporada;
  string nombreEpisodio;
  double calificacion;

  public:
    Episodio();
    Episodio(int, int, string, double);
    virtual ~Episodio();

    int getNumEpisodio();
    int getNumTemporada();
    string getNombreEpisodio();
    double getCalificacion();

    void setNumEpisodio(int);
    void setNumTemporada(int);
    void setNombreEpisodio(string);
    void setCalificacion(double);


    friend ostream& operator<<(ostream&, Episodio);



};

