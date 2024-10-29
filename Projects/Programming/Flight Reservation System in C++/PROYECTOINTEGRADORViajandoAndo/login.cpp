#include <iostream>
#include "login.h"
using namespace std;

Usuario login(Sistema *sistema){
  string input, telefono;
  int edad;
  Usuario usuario;
  cout << " ---------------- LOGIN ---------------- " << endl;
  ifstream existing_users;
  ofstream output_users;
  existing_users.open("usuarios.txt");
  if (existing_users.fail()) {
    cout << "No hay usuarios en nuestro sistema" << endl << endl;
    output_users.open("usuarios.txt");
    if (output_users.fail()) {
      cout << "Lo sentimos. Hubo un error.\n";
      exit(1);
    }
    cout << " ---------- CREAR UN NUEVO USUARIO ---------- " << endl;
    cout << "¡IMPORTANTE! - Ingresar todo sin espacios" << endl;
    cout << "USUARIO: ";
    input = validacion(input,4,20);
    usuario.setUsername(input);
    output_users << "USERNAME: " << input << endl;
    cout << "CONTRASEÑA: ";
    input = validacion(input,6,20);
    output_users << "CONTRASEÑA: " << input << endl;
    cout << "INGRESAR INFORMACIÓN DE USUARIO" << endl;
    cout << "NOMBRE: ";
    input = validacion(input,1,30);
    usuario.setNombre(input);
    output_users << "NOMBRE: " << input << endl;
    cout << "EDAD: ";
    edad = validacion(edad, 18, 110);
    usuario.setEdad(edad);
    cin.ignore();
    output_users << "EDAD: " << edad << endl;
    cout << "TELÉFONO: ";
    telefono = validacion(telefono,10,10);
    usuario.setTelefono(telefono);
    output_users << "TELEFONO: " << telefono << endl;
    output_users << "KILÓMETROS: " << 0 << endl;
    
    output_users.close();
    
    return usuario;
  }
  else {
    int paso = 1;
    vector <string> usuarios, contrasenas, nombres, telefonos;
    vector <int> edades;
    vector <string> usuarios_viejos;
    string username = "";
    string contrasena = "";
    string nombre = "";
    string telefono = "";
    while (existing_users >> input) {
      usuarios_viejos.push_back(input);
      if (paso==2) {
        username = input;
        usuarios.push_back(username);
      }
      else if (paso==4) {
        contrasena = input;
        contrasenas.push_back(contrasena);
      }
      else if (paso==6){
        nombre = input;
        nombres.push_back(nombre);
      }
      else if (paso==8) {
        edad = stoi(input);
        edades.push_back(edad);
      }
      else if (paso==10) {
        telefono = input;
        telefonos.push_back(telefono);
        paso = 0;
      }
      paso = paso + 1;
    }
    sistema -> setUsuarios(usuarios);
    bool exists = false;
    int choice = 2;
    bool correcto;
    int j;
    while (!exists && choice==2) {
      cout << "USUARIO: ";
      getline(cin,username);
      for (int i=0; i<usuarios.size();i++) {
        if (usuarios[i]==username) {
          j = i;
          exists = true;
          break;
        }
      }
      if (!exists) {
        cout << "Ese usuario no existe. Escoja una acción.\n<1> Crear usuario nuevo\n<2> Intentar de nuevo\n<0> Salir" << endl;
        choice = validacion(choice,0,2);
        cin.ignore();
      }
    }
    if (choice==0) {
      return usuario;
    }
    
    if (!exists) {
      output_users.open("usuarios.txt");
      for (int i=0; i<usuarios_viejos.size(); i++) {
        if (i%2==0) {
          output_users << usuarios_viejos[i]+" "+usuarios_viejos[i+1]+"\n";
        }
      }
      cout << " ---------- CREAR UN NUEVO USUARIO ---------- " << endl;
    cout << "¡IMPORTANTE! - Ingresar todo sin espacios" << endl;

    bool invalido = false;
    do {
      cout << "USUARIO: ";
      input = validacion(input,4,20);
      for (int i=0; i<sistema -> getUsuarios().size(); i++) {
        if (sistema -> getUnUsuario(i)==input) {
          invalido = true;
          cout << "Ese usuario ya existe. Inténtelo de nuevo." << endl;
          break;
        }
        else {
          invalido = false;
        }
      }
      
    } while (invalido);
   
    
    usuario.setUsername(input);
    output_users << "USERNAME: " << input << endl;
    cout << "CONTRASEÑA: ";
    input = validacion(input,6,20);
    output_users << "CONTRASEÑA: " << input << endl;
    cout << "INGRESAR INFORMACIÓN DE USUARIO" << endl;
    cout << "NOMBRE: ";
    input = validacion(input,1,30);
    usuario.setNombre(input);
    output_users << "NOMBRE: " << input << endl;
    cout << "EDAD: ";
    edad = validacion(edad, 18, 110);
    usuario.setEdad(edad);
    cin.ignore();
    output_users << "EDAD: " << edad << endl;
    cout << "TELÉFONO: ";
    telefono = validacion(telefono,10,10);
    usuario.setTelefono(telefono);
    output_users << "TELEFONO: " << telefono << endl;
    output_users << "KILÓMETROS: " << 0 << endl;
    return usuario;
    }
    
    cout << "CONTRASEÑA: ";
    getline(cin,contrasena);
    int intentos = 4;

    while (contrasenas[j]!=contrasena && intentos>1) {
      intentos = intentos - 1;
      cout << "Constraseña incorrecta. Tiene " << intentos << " intentos más\nInténtelo otra vez" << endl;
      cout << "CONTRASEÑA: ";
      getline(cin,contrasena);
    }
    if (contrasenas[j]==contrasena) {
      usuario.setUsername(username);
      usuario.setEdad(edades[j]);
      usuario.setTelefono(telefonos[j]);
      usuario.setNombre(nombres[j]);
      cout << "Usuario y contraseña correctos." << endl;
      return usuario;
    }
    else {
      cout << "Se usaron todos los intentos. Constraseña incorrecta." << endl;
      return usuario;
    }
    
    existing_users.close();
    output_users.close();
  }
    
}


