#pragma once
#include <iostream>
#include <vector>
#include "Aeropuerto.h"

using namespace std;

class Sistema {
  Aeropuerto aeropuerto;
  vector <string> usuarios;

  public:
    Sistema();
    Sistema(Aeropuerto, vector<string>);
    virtual ~Sistema();

    Aeropuerto getAeropuerto();
    vector<string> getUsuarios();
    string getUnUsuario(int);
    
    void setAeropuerto(Aeropuerto);
    void setUsuarios(vector<string>);
    void setUnUsuario(int, string);

    void addUsuario(string);


};

