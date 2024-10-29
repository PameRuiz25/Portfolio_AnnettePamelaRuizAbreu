#pragma once
#include <iostream>
#include "Video.h"
using namespace std;

class Pelicula: public Video{

  public:
      Pelicula();
      Pelicula(string, string, int, string, string, string, double, int);
      ~Pelicula();
  
      void imprimeVideo();
      void calificar(double);

};

