#include "Servicio.h"
#include "validacion.h"
#include "funciones.h"
using namespace std;

string nombre;
double costo;
int cantidadContenido;
int cantidadPeliculas;
int cantidadSeries;
vector <Video> todoContenido;
vector <Pelicula> listaPeliculas;
vector <Serie> listaSeries;

Servicio::Servicio(){
  nombre = "";
  costo = 0;
  cantidadContenido = 0;
  cantidadPeliculas = 0;
  cantidadSeries = 0;
  todoContenido = {};
  listaPeliculas = {};
  listaSeries = {};  
}
Servicio::Servicio(string nombre_,double costo_){
  nombre = nombre_;
  costo = costo_;
  cantidadContenido = 0;
  cantidadPeliculas = 0;
  cantidadSeries = 0;
  todoContenido = {};
  listaPeliculas = {};
  listaSeries = {};
}
Servicio::~Servicio(){
  
}

string Servicio::getNombre(){
  return nombre;
}
double Servicio::getCosto(){
  return costo;
}
int Servicio::getCantidadContenido(){
  return cantidadContenido;
}
int Servicio::getCantidadPeliculas(){
  return cantidadPeliculas;
}
int Servicio::getCantidadSeries(){
  return cantidadSeries;
}
vector <Video*> Servicio::getTodoContenido(){
  return todoContenido;
}
vector <Pelicula*> Servicio::getListaPeliculas(){
  return listaPeliculas;
}
vector <Serie*> Servicio::getListaSeries(){
  return listaSeries;
}
Video* Servicio::getUnContenido(int i){
  return todoContenido[i];
}
Pelicula* Servicio::getUnaPelicula(int i){
  return listaPeliculas[i];
}
Serie* Servicio::getUnaSerie(int i){
  return listaSeries[i];
}

void Servicio::setNombre(string nombre_){
  nombre = nombre_;
}
void Servicio::setCosto(double costo_){
  costo = costo_;
}
void Servicio::setCantidadContenido(){
  cantidadContenido = todoContenido.size();
}
void Servicio::setCantidadPeliculas(){
  cantidadPeliculas = listaPeliculas.size();
}
void Servicio::setCantidadSeries(){
  cantidadSeries = listaSeries.size();
}
void Servicio::setTodoContenido(vector <Video*> todoContenido_){
  todoContenido = todoContenido_;
}
void Servicio::setListaPeliculas(vector <Pelicula*> listaPeliculas_){
  listaPeliculas = listaPeliculas_;
}
void Servicio::setListaSeries(vector <Serie*> listaSeries_){
  listaSeries = listaSeries_;
}
void Servicio::setUnContenido(int i, Video* video){
  todoContenido[i] = video;
}
void Servicio::setUnaPelicula(int i, Pelicula* pelicula){
  listaPeliculas[i] = pelicula;
}
void Servicio::setUnaSerie(int i, Serie* serie){
  listaSeries[i] = serie;
}

void Servicio::addTodoContenido(Video* video){
  todoContenido.push_back(video);
}
void Servicio::addListaPelicula(Pelicula* pelicula){
  listaPeliculas.push_back(pelicula);
}
void Servicio::addListaSeries(Serie* serie){
  listaSeries.push_back(serie);
}

void Servicio::leerArchivo(string nombreArchivo){
  string input_s;
  int paso = 0, r;
  char delimitador = ',';
  ifstream archivo;
  archivo.open(nombreArchivo);
  if (archivo.fail()) {
    cout << "ARCHIVO NO EXISTE" << endl;
    cout << "NO SE HAN GUARDADO LOS DATOS" << endl;
  }
  else {
    string id, tipo, nombre, genero, rating;
    int duracion, votos;
    double calificacion;
    while(getline(archivo,input_s,delimitador)){
      paso++;
      switch(paso){
        case 1:
          id = input_s;
          break;
        case 2:
          tipo = input_s;
          break;
        case 3:
          nombre = input_s;
          break;
        case 4:
          duracion = stoi(input_s);
        case 5:
          genero = input_s;
          break;
        case 6:
          rating = input_s;
          break;
        case 7:
          calificacion = stod(input_s);
          break;
        case 8:
          votos = stoi(input_s);
          if (tipo=="Movie") {
            Pelicula *p_video = new Pelicula (id,nombre,duracion,tipo,genero,rating,calificacion,votos);
            addListaPelicula(p_video);
            addTodoContenido(p_video);
          }
          else {
            Serie *p_video = new Serie(id,nombre,duracion,tipo,genero,rating,calificacion,votos);
            r = (rand()%25)+6;
            p_video->setCantidadEpisodios(r);
            p_video->llenarVectorEpisodios();

            
            addListaSeries(p_video);
            addTodoContenido(p_video);
          }
          
          paso = 0;
          break;
      }
      
    }
    cout << "Se han cargado los datos del archivo correctamente" << endl;
    setCantidadContenido();
    setCantidadPeliculas();
    setCantidadSeries();
    
  }
  
}


ostream& operator<<(ostream &salida, Servicio s){
  salida << endl << s.getNombre() << endl;
  salida << "Costo: $" << s.getCosto() << endl;
  salida << "Cantidad de Videos: " << s.getCantidadContenido() << endl;
  salida << "Cantidad de Películas: " << s.getCantidadPeliculas() << endl;
  salida << "Cantidad de Series: " << s.getCantidadSeries() << endl << endl;
  return salida;
}

int Servicio::menuMostrarVideos(){
  if (getTodoContenido().size()==0) {
    cout << "ESTE SERVICIO NO TIENE VIDEOS" << endl;
    return 0;
  }
  bool notcontinous = true;
  int input_i;
  string input_s;
  cout << "<1> Mostrar todo" << endl;
  cout << "<2> Mostrar películas" << endl;
  cout << "<3> Mostrar series" << endl;
  cout << "<0> Salir" << endl;
  input_i = validacion(input_i,0,3)-1;
  if (input_i==-1) {
    return 0;
  }
  else if (input_i==0) {
    for (int i=0; i<getCantidadContenido(); i++) {
      getTodoContenido()[i]->imprimeVideo();
      cin.clear();
      if (i!=0 && i%100==0 && notcontinous) {
        cout << "Para ver los siguientes 100 videos presione <Enter>. Para imprimir todo de una vez presione <T> Para salir presione <S>." << endl;
        input_s = mayusculas(validacion(input_s,0,1));
      }
      if (input_s=="S") {
        break;
      }
      else if (input_s=="T") {
        notcontinous = false;
      }
    }
  }
  else if (input_i==1) {
    for (int i=0; i<getCantidadPeliculas(); i++) {
      getListaPeliculas()[i]->imprimeVideo();
      cin.clear();
      if (i!=0 && i%100==0 && notcontinous) {
        cout << "Para ver las siguientes 100 películas presione <Enter>. Para imprimir todo de una vez presione <T> Para salir presione <S>." << endl;
        input_s = mayusculas(validacion(input_s,0,1));
      }
      if (input_s=="S") {
        break;
      }
      else if (input_s=="T") {
        notcontinous = false;
      }
    }
  }
  else if (input_i==2) {
    for (int i=0; i<getCantidadSeries(); i++) {
      getListaSeries()[i]->imprimeVideo();
      cin.clear();
      if (i!=0 && i%100==0 && notcontinous) {
        cout << "Para ver los siguientes 100 videos presione <Enter>. Para imprimir todo de una vez presione <T> Para salir presione <S>." << endl;
        input_s = mayusculas(validacion(input_s,0,1));
      }
      if (input_s=="S") {
        break;
      }
      else if (input_s=="T") {
        notcontinous = false;
      }
    }
  }
  return 0;
}

void Servicio::imprimirGeneros() {
  bool yaEsta;
  vector <string> generos={todoContenido[0]->getGenero()};
  for (int i=1; i<cantidadContenido; i++) {
    yaEsta = false;
    for (int j=0; j<generos.size();j++) {
      if (generos[j]==todoContenido[i]->getGenero()) {
        yaEsta = true;
        break;
      }
    }
    if (!yaEsta) {
      generos.push_back(todoContenido[i]->getGenero());
    }
  }
  cout << "GÉNEROS" << endl;
  for (int i=0; i<generos.size(); i++) {
    cout << generos[i] << endl;
  }
}

void Servicio::imprimirRatings() {
  bool yaEsta;
  vector <string> ratings={todoContenido[0]->getRating()};
  for (int i=0; i<cantidadContenido; i++) {
    yaEsta = false;
    for (int j=0; j<ratings.size();j++) {
      if (ratings[j]==todoContenido[i]->getRating()) {
        yaEsta = true;
        break;
      }
    }
    if (!yaEsta) {
      ratings.push_back(todoContenido[i]->getRating());
    }
  }
  cout << "RATINGS" << endl;
  for (int i=0; i<ratings.size(); i++) {
    cout << ratings[i] << endl;
  }
}

void Servicio::busquedadFiltrada() {
  bool operando_filtros = true, notcontinuo=true;
  int input_i, duracion_min=0, duracion_max=0, duracion_max_c, duracion_min_c, paso;
  string tipo="", genero="", rating="", tipo_c, genero_c, rating_c, input_s, genero_espacio, nombre="", nombre_c;
  double calificacion=0, calificacion_c, input_d;
  while (operando_filtros) {
    cout << "\n<1> Buscar" << endl;
    cout << " ------------ FILTROS ------------ " << endl;
    cout << "<2> Tipo            <3> Género " << endl;
    cout << "<4> Rating          <5> Duracion " << endl;
    cout << "<6> Calificación    <7> Nombre " << endl;
    cout << "<8> Borrar Filtros" << endl;
    cout << " --------------------------------- " << endl;
    cout << "<9> Calificar       <0> Salir" << endl;
    
    input_i = validacion(input_i,0,9);
    switch(input_i) {
      case 0:
        operando_filtros = false;
        break;
      case 1:
        notcontinuo = true;
        paso = 1;
        if (tipo=="Movie") {
          for (int i=0; i<cantidadPeliculas; i++) {
            genero_c = genero;
            rating_c = rating;
            duracion_min_c = duracion_min;
            duracion_max_c = duracion_max;
            calificacion_c = calificacion;
            nombre_c = nombre;
            if (nombre_c=="") {
              nombre_c = listaPeliculas[i]->getNombre();
            }
            if (genero_c=="") {
              genero_c = listaPeliculas[i]->getGenero();
            }
            if (rating_c=="") {
              rating_c = listaPeliculas[i]->getRating();
            }
            if (duracion_min_c==0) {
              duracion_min_c = listaPeliculas[i]->getDuracion();
            }
            if (duracion_max_c==0) {
              duracion_max_c = listaPeliculas[i]->getDuracion();
            }
            if (calificacion_c==0) {
              calificacion_c = listaPeliculas[i]->getCalificacion();
            }

            if ((mayusculas(genero_c)==mayusculas(listaPeliculas[i]->getGenero())||mayusculas(genero_espacio)==mayusculas(listaPeliculas[i]->getGenero())) && mayusculas(rating_c)==mayusculas(listaPeliculas[i]->getRating()) && duracion_min_c<=listaPeliculas[i]->getDuracion() && duracion_max_c>=listaPeliculas[i]->getDuracion() && calificacion_c<=listaPeliculas[i]->getCalificacion() && nombre_c==listaPeliculas[i]->getNombre()) {
              listaPeliculas[i]->imprimeVideo();
              paso++;
              
            }
            if (paso%100==0 && notcontinuo) {
              cout << "Presione <Enter> para ver las siguientes 100 películas. Presione <T> para imprimir todas corridas." << endl;
              input_s = mayusculas(validacion(input_s,0,1));
              if (input_s=="T") {
                notcontinuo = false;
              }
            }
            
          }
          if (paso==1) {
            cout << "NO HAY NINGUNA PELÍCULA QUE CUMPLA CON LAS ESPECIFICACIONES " << endl;
          }
        }
        else if (tipo=="TV Show") {
          for (int i=0; i<cantidadSeries; i++) {
            genero_c = genero;
            rating_c = rating;
            duracion_min_c = duracion_min;
            duracion_max_c = duracion_max;
            calificacion_c = calificacion;
            nombre_c = nombre;
            if (nombre_c=="") {
              nombre_c = listaSeries[i]->getNombre();
            }
            if (genero_c=="") {
              genero_c = listaSeries[i]->getGenero();
            }
            if (rating_c=="") {
              rating_c = listaSeries[i]->getRating();
            }
            if (duracion_min_c==0) {
              duracion_min_c = listaSeries[i]->getDuracion();
            }
            if (duracion_max_c==0) {
              duracion_max_c = listaSeries[i]->getDuracion();
            }
            if (calificacion_c==0) {
              calificacion_c = listaSeries[i]->getCalificacion();
            }

            if ((mayusculas(genero_c)==mayusculas(listaSeries[i]->getGenero())||mayusculas(genero_espacio)==mayusculas(listaSeries[i]->getGenero())) && mayusculas(rating_c)==mayusculas(listaSeries[i]->getRating()) && duracion_min_c<=listaSeries[i]->getDuracion() && duracion_max_c>=listaSeries[i]->getDuracion() && calificacion_c<=listaSeries[i]->getCalificacion() && nombre_c==listaSeries[i]->getNombre()) {
              listaSeries[i]->imprimeVideo();
              paso++;
              
            }
            if (paso%100==0 && notcontinuo) {
              cout << "Presione <Enter> para ver las siguientes 100 películas. Presione <T> para imprimir todas corridas." << endl;
              input_s = mayusculas(validacion(input_s,0,1));
              if (input_s=="T") {
                notcontinuo = false;
              }
            }
            
          }
          if (paso==1) {
            cout << "NO HAY NINGUNA SERIE QUE CUMPLA CON LAS ESPECIFICACIONES " << endl;
          }
        }
        else {
          for (int i=0; i<cantidadContenido; i++) {
            genero_c = genero;
            rating_c = rating;
            duracion_min_c = duracion_min;
            duracion_max_c = duracion_max;
            calificacion_c = calificacion;
            nombre_c = nombre;
            if (nombre_c=="") {
              nombre_c = todoContenido[i]->getNombre();
            }
            if (genero_c=="") {
              genero_c = todoContenido[i]->getGenero();
            }
            if (rating_c=="") {
              rating_c = todoContenido[i]->getRating();
            }
            if (duracion_min_c==0) {
              duracion_min_c = todoContenido[i]->getDuracion();
            }
            if (duracion_max_c==0) {
              duracion_max_c = todoContenido[i]->getDuracion();
            }
            if (calificacion_c==0) {
              calificacion_c = todoContenido[i]->getCalificacion();
            }

            if ((mayusculas(genero_c)==mayusculas(todoContenido[i]->getGenero())||(mayusculas(genero_espacio)==mayusculas(todoContenido[i]->getGenero()))) && mayusculas(rating_c)==mayusculas(todoContenido[i]->getRating()) && duracion_min_c<=todoContenido[i]->getDuracion() && duracion_max_c>=todoContenido[i]->getDuracion() && calificacion_c<=todoContenido[i]->getCalificacion() && nombre_c==todoContenido[i]->getNombre()) {
              todoContenido[i]->imprimeVideo();
              paso++;
              
            }
            if (paso%100==0 && notcontinuo) {
              cout << "Presione <Enter> para ver las siguientes 100 películas. Presione <T> para imprimir todas corridas." << endl;
              input_s = mayusculas(validacion(input_s,0,1));
              if (input_s=="T") {
                notcontinuo = false;
              }
            }
            
          }
          if (paso==1) {
            cout << "NO HAY NINGÚN VIDEO QUE CUMPLA CON LAS ESPECIFICACIONES " << endl;
          }
        }
        break;
      case 2:
        cout << "<1> Película\n<2> Serie" << endl;
        input_i = validacion(input_i,1,2);
        if (input_i==1) {
          tipo = "Movie";
        }
        else {
          tipo = "TV Show";
        }
        break;
      case 3:
        imprimirGeneros();
        cin.ignore();
        cout << "\nGénero: ";
        genero = validacion(input_s,1,40);
        genero_espacio = genero + " ";
        break;
      case 4:
        imprimirRatings();
        cin.ignore();
        cout << "\nRating: ";
        rating = validacion(input_s,1,15);
        break;
      case 5:
        cout << "NOTA: La duración de películas está en minutos, la duración de series está en temporadas";
        cin.ignore();
        cout << "\nDuracion Mínima: ";
        duracion_min = validacion(input_i,1,300);
        cin.ignore();
        cout << "\nDuracion Máxima: ";
        duracion_max = validacion(input_i,duracion_min,300);
        break;
      case 6:
        cin.ignore();
        cout << "Calificación Mínima: ";
        calificacion = validacion(input_d,1.0,5.0);
        break;
      case 7:
        cin.ignore();
        cout << "Nombre: ";
        nombre = validacion(input_s,1,300);
        break;
      case 8:
        duracion_min=0;
        duracion_max = 0;
        tipo="";
        genero="";
        rating="";
        calificacion=0;
        nombre = "";
        cout << "Se han borrado todos los filtros" << endl;
        break;
      case 9:
          calificar();
        break;
    }
          
  }
}

void Servicio::imprimirEpisodios() {
  string input_s;
  bool existe=false;
  cin.ignore();
  cout << "Nombre de la serie: ";
  input_s = validacion(input_s,1,60);
  for (int i=0; i<cantidadSeries; i++) {
    if (input_s == listaSeries[i]->getNombre()) {
      listaSeries[i]->imprimirEpisodios();
      existe = true;
      break;
    }
  }
  if (!existe) {
    cout << "ESA SERIE NO EXISTE" << endl;
  }
}


int Servicio::calificar() {
  int input_i;
  double input_d;
  string input_s;
  cout << "- Seleccionar tipo de video a calificar -" << endl;
  cout << "<1> Película" << endl;
  cout << "<2> Serie" << endl;
  cout << "<3> Episodio de una serie" << endl;
  cout << "<0> Salir" << endl;

  input_i = validacion(input_i,0,3);

  if (input_i==0) {
    return 0;
  }
  cin.ignore();
  cout << "Ingrese nombre: ";
  input_s = validacion(input_s,1,60);
  cout << "Ingrese calificación (1-5): ";
  input_d = validacion(input_d,1.0,5.0);
  if (input_i==1) {
    vector <Pelicula*> listaCalificar;
    listaCalificar = getListaPeliculas();

    for (int i=0; i<listaCalificar.size() ; i++) {
      if (listaCalificar[i]->getNombre() == input_s) {
        listaCalificar[i]->calificar(input_d);
        cout << "Se ha calificado exitosamente el título" << endl;
        return 0;
      }
    }
    
  }
  else {
    vector <Serie*> listaCalificar;
    listaCalificar = getListaSeries();
    
    for (int i=0; i<listaCalificar.size() ; i++) {
      if (listaCalificar[i]->getNombre() == input_s) {
        if (input_i==2) {
          listaCalificar[i]->calificar(input_d);
        }
        else if (input_i==3) {
          listaCalificar[i]->calificarEpisodio(input_d);
        }
        
        cout << "Se ha calificado exitosamente el título" << endl;
        return 0;
      }
    }
  }
  
  cout << "El título que buscó no existe. No se ha calificado nada" << endl;
  
  return 0;
}


void Servicio::crearArchivosSalida() {
  ofstream salida;
  string name;
  cin.clear();
  cin.ignore(123,'\n');
  cout << "Ingrese el nombre (solo en nombre, no la extensión) del archivo de salida para los videos de " << getNombre() << endl;
  name = validacion(name,0,20)+".txt";
  salida.open(name);
  try {
    if (salida.fail()) {
      throw "ERROR AL CREAR AR1CHIVO DE SALIDA";
    }
  }
  catch(const char* msg) {
    cerr << msg << endl;
  }
  for (int i=0; i<cantidadPeliculas; i++) {
    salida << listaPeliculas[i]->getId() << ",";
    salida << listaPeliculas[i]->getType() << ",";
    salida << listaPeliculas[i]->getNombre() << ",";
    salida << listaPeliculas[i]->getDuracion() << ",";
    salida << listaPeliculas[i]->getGenero() << ",";
    salida << listaPeliculas[i]->getRating() << ",";
    salida << listaPeliculas[i]->getCalificacion() << ",";
    salida << listaPeliculas[i]->getVotos() << ",";
  }
  for (int i=0; i<cantidadSeries; i++) {
    salida << listaSeries[i]->getId() << ",";
    salida << listaSeries[i]->getType() << ",";
    salida << listaSeries[i]->getNombre() << ",";
    salida << listaSeries[i]->getDuracion() << ",";
    salida << listaSeries[i]->getGenero() << ",";
    salida << listaSeries[i]->getRating() << ",";
    salida << listaSeries[i]->getCalificacion() << ",";
    salida << listaSeries[i]->getVotos() << ",";
  }
  salida.close();
}


