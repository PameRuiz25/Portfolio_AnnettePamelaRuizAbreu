#pragma once
#include <iostream>
#include <string>
using namespace std;

class Video{
  string id;
  string nombre;
  int duracion;
  string genero;
  string rating;
  double calificacion;
  string type;
  int votos;

  public:
    Video();
    Video(string, string, int, string, string, string, double, int);
    virtual ~Video();

    string getId();
    string getNombre();
    int getDuracion();
    string getGenero();
    double getCalificacion();
    string getType();
    string getRating();
    int getVotos();

    void setId(string);
    void setNombre(string);
    void setDuracion(int);
    void setGenero(string);
    void setCalificacion(double);
    void setType(string);
    void setRating(string);
    void setVotos(int);

    virtual void imprimeVideo()=0;
    virtual void calificar(double)=0;
    


};

