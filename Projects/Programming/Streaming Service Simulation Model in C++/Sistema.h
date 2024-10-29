#pragma once
#include <iostream>
#include "Servicio.h"

class Sistema{
  vector <Servicio> listaServicios;

  public:
    Sistema();
    Sistema(vector <Servicio> listaServicios);
    virtual ~Sistema();

    vector<Servicio> getListaServicios();
    Servicio getUnServicio(int);

    void setListaServicios(vector<Servicio>);
    void setUnServicio(int, Servicio);

    void addUnServicio(Servicio);
    void leerArchivo(string, int);

    void imprimeServicios();
    void crearArchivosSalida();


};

