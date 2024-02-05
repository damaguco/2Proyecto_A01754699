#include "Video.h"
#include <iostream>

using namespace std;

// Constructor con parámetros
Video::Video(string _tipoVideo, string _genero, int _calificacion, int _anioLanzamiento, int _duracion) : tipoVideo(_tipoVideo), genero(_genero), calificacion(_calificacion), anioLanzamiento(_anioLanzamiento), duracion(_duracion) {}

// Constructor sin parámetros
Video::Video() : tipoVideo("Desconocido"), genero("Desconocido"), calificacion(0), anioLanzamiento(0), duracion(0) {}

// Función virtual pura
void Video::calificaVideo(int _calificacion) {
    calificacion = _calificacion;
}


void Video::muestraDatos() {
    cout << "Tipo de Video: " << tipoVideo << endl;
    cout << "Género: " << genero << endl;
    cout << "Calificación: " << calificacion << endl;
    cout << "Año de Lanzamiento: " << anioLanzamiento << endl;
    cout << "Duración: " << duracion << " minutos" << endl;
}