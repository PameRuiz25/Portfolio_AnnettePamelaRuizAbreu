#include "Serie.h"
#include "validacion.h"
using namespace std;

Serie::Serie():Video::Video(){
  cantidadEpisodios = 0;
  listaEpisodios = {};
}
Serie::Serie(string id, string nombre, int duracion, string tipo, string genero, string rating, double calificacion, int votos):Video::Video(id, nombre, duracion, tipo, genero, rating, calificacion, votos){
  cantidadEpisodios = 0;
  listaEpisodios = {};
}
Serie::Serie(string id, string nombre, int duracion, string tipo, string genero, string rating, double calificacion, int cantidadEpisodios_, vector<Episodio> listaEpisodios_, int votos):Video::Video(id, nombre, duracion, tipo, genero, rating, calificacion, votos){
  cantidadEpisodios = cantidadEpisodios_;
  listaEpisodios = listaEpisodios_;
}
Serie::~Serie(){
  
}

int Serie::getCantidadEpisodios(){
  return cantidadEpisodios;
}
vector <Episodio> Serie::getListaEpisodios(){
  return listaEpisodios;
}
Episodio Serie::getUnEpisodio(int i){
  return listaEpisodios[i];
}

void Serie::setCantidadEpisodios(int cantidadEpisodios_){
  cantidadEpisodios = cantidadEpisodios_;
}
void Serie::setListaEpisodios(vector <Episodio> listaEpisodios_){
  listaEpisodios = listaEpisodios_;
}
void Serie::setUnEpisodio(int i, Episodio episodio){
  listaEpisodios[i] = episodio;
}

void Serie::imprimeVideo(){
  cout << "\nDatos de la Serie " << getId() << endl;
  cout << "Nombre: " << getNombre() << endl;
  cout << "Género: " << getGenero()  << endl;
  cout << "Rating: " << getRating() << endl;
  cout << "Núm. Temporadas: " << getDuracion() << endl;
  cout << "Núm. Episodios por Temporada: " << cantidadEpisodios << endl;
  cout << "Calificación Promedio: " << getCalificacion() << endl;
  cout << "Número de votos: " << getVotos() << endl;
}

void Serie::llenarVectorEpisodios() {
  ifstream archivo_episodios;
  vector <string> episode_names;
  int numEps = 1;
  string input_s;
  archivo_episodios.open("episodios.txt");
  try {
    if (archivo_episodios.fail()) {
      throw "ERROR: ¡NO SE ENCONTRÓ EL ARCHVIO DE EPISODIOS!";
    }
    Episodio episodio;
    while (getline(archivo_episodios,input_s) && numEps<=cantidadEpisodios) {
      episode_names.push_back(input_s);
      numEps++;
    }
    for (int i=0; i<getDuracion(); i++) {
      for (int j=0; j<cantidadEpisodios; j++) {
        episodio.setNombreEpisodio(episode_names[j]);
        episodio.setNumEpisodio(j+1);
        episodio.setNumTemporada(i+1);
        listaEpisodios.push_back(episodio); 
      }
    }
    
  } catch(const char* msg) {
    cerr << msg << endl;
  }
  
}


void Serie::imprimirEpisodios() {
  for (int i=0; i<(cantidadEpisodios*getDuracion()); i++) {
    cout << listaEpisodios[i] << endl;
  }
}

void Serie::calificar(double cali){
  setVotos(getVotos()+1);
  if (getCalificacion()==0) {
    setCalificacion(cali);
  }
  else {
    setCalificacion((getCalificacion()*(getVotos()-1)+cali)/getVotos());
  }
  
}


void Serie::calificarEpisodio(double cali){
  int temp, episodio;
  cout << "Ingrese el número de temporada: ";
  temp = validacion(temp,1,getDuracion())-1;
  cout << "Ingrese el número de episodio: ";
  episodio = validacion(episodio,1,cantidadEpisodios);
  listaEpisodios[temp*cantidadEpisodios+episodio-1].setCalificacion(cali);
  cout << listaEpisodios[temp*cantidadEpisodios+episodio-1] << endl;
  
}