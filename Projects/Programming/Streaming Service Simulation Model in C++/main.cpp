#include <iostream>
#include "menu.h"
#include "Sistema.h"
using namespace std;

int main() {
  Servicio N("Netflix",299), P("Amazon Prime",74.90), D("Disney+",159), H("Hulu", 149.99);
  vector <Servicio> listaServicios = {N, P, D, H};
  Sistema* sistema = new Sistema(listaServicios);
  cout << "BIENVENID@ A REVIEWX " << endl;
  cout << " - El mejor sistema para calificar y encontrar las mejores películas y series - " << endl;
  startMenu(sistema);
  cout << " ------------ CERRANDO OPERACIONES ------------ " << endl;
}