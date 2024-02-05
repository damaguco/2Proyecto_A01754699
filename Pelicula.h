#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"  

class Pelicula : public Video {
private:
    std::string nombre;
    int id;

public:
    // Constructor con parámetros
    Pelicula(std::string, std::string, int, int, int, std::string, int);

    // Constructor sin parámetros
    Pelicula();

    // Calificar videos y se debe especificar que es de la clase Video
    void calificaVideo(int _calificacion);

    // Muestra de Datos
    void muestraDatos();
};

#endif