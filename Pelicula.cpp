#include "Pelicula.h"
#include <iostream>

using namespace std;

// Constructor con parámetros
Pelicula::Pelicula(string _tipoVideo, string _genero, int _calificacion, int _anoLanzamiento, int _duracion, string _nombre, int _id)
    : Video(_tipoVideo, _genero, _calificacion, _anoLanzamiento, _duracion), nombre(_nombre), id(_id) {}

// Constructor sin parámetros
Pelicula::Pelicula() : Video(), nombre("Desconocido"), id(0) {}


// Calificar videos y se debe especificar que es de la clase Video
void Pelicula::calificaVideo(int _calificacion) {
    Video::calificaVideo(_calificacion);
}

// Muestra de Datos
void Pelicula::muestraDatos() {
    Video::muestraDatos();
    cout << "Nombre: " << nombre << endl;
    cout << "ID: " << id << endl;
}
