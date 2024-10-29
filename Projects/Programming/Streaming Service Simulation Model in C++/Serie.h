#pragma once
#include <iostream>
#include <vector>
#include "Video.h"
#include "Episodio.h"
#include <cstdlib>
#include <fstream>
using namespace std;

class Serie: public Video{
  int cantidadEpisodios;
  vector <Episodio> listaEpisodios;

  public:
    Serie();
    Serie(string, string, int, string, string, string, double, int);
    Serie(string, string, int, string, string, string, double, int, vector<Episodio>, int);
    virtual ~Serie();

    int getCantidadEpisodios();
    vector <Episodio> getListaEpisodios();
    Episodio getUnEpisodio(int);

    void setCantidadEpisodios(int);
    void setListaEpisodios(vector <Episodio>);
    void setUnEpisodio(int, Episodio);

    void imprimeVideo();
    void llenarVectorEpisodios();
    void imprimirEpisodios();

    void calificar(double);
    void calificarEpisodio(double);


};

