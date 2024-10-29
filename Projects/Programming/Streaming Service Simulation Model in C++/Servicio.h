#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
using namespace std;

class Servicio {
  string nombre;
  double costo;
  int cantidadContenido;
  int cantidadPeliculas;
  int cantidadSeries;
  vector <Video*> todoContenido;
  vector <Pelicula*> listaPeliculas;
  vector <Serie*> listaSeries;

  public:
    Servicio();
    Servicio(string,double);
    virtual ~Servicio();

    string getNombre();
    double getCosto();
    int getCantidadContenido();
    int getCantidadPeliculas();
    int getCantidadSeries();
    vector <Video*> getTodoContenido();
    vector <Pelicula*> getListaPeliculas();
    vector <Serie*> getListaSeries();
    Video* getUnContenido(int);
    Pelicula* getUnaPelicula(int);
    Serie* getUnaSerie(int);

    void setNombre(string);
    void setCosto(double);
    void setCantidadContenido();
    void setCantidadPeliculas();
    void setCantidadSeries();
    void setTodoContenido(vector <Video*>);
    void setListaPeliculas(vector <Pelicula*>);
    void setListaSeries(vector <Serie*>);
    void setUnContenido(int, Video*);
    void setUnaPelicula(int, Pelicula*);
    void setUnaSerie(int, Serie*);

    void addTodoContenido(Video*);
    void addListaPelicula(Pelicula*);
    void addListaSeries(Serie*);

    void leerArchivo(string);
    int menuMostrarVideos();

    void busquedadFiltrada();

    void imprimirGeneros();
    void imprimirRatings();

    void imprimirEpisodios();
    int calificar();

    void crearArchivosSalida();

    friend ostream& operator<<(ostream&, Servicio);


};



