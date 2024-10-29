#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Vuelo.h"

using namespace std;

class Usuario {
  string nombre;
  string telefono;
  int edad;
  string username;
  double kilometros;
  vector <string> vuelos;
  
  public:
    Usuario();
    Usuario(string, string, int, string, double, vector<string>);
    virtual ~Usuario();

    string getNombre();
    string getTelefono();
    int getEdad();
    string getUsername();
    double getKilometros();
    vector <string> getVuelos();
    string getUnVuelo(int);

    void setNombre(string);
    void setTelefono(string);
    void setEdad(int);
    void setUsername(string);
    void setKilometros(double);
    void setVuelos(vector <string>);
    void setUnVuelo(int, string);

    void addVuelo(string);
    void mostrarVuelos();
    bool cancelarVuelo(int);

    void imprimeUsuario();
    int getCantidadVuelosRes();

};

