#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <iostream>

class Video {
private:
    std::string tipoVideo;
    std::string genero;
    int calificacion;
    int anioLanzamiento; 
    int duracion;

public:
    // Constructor sin parámetros
    Video();

    // Constructor con parámetros
    Video(std::string, std::string, int, int, int);

    virtual void calificaVideo(int _calificacion);
    virtual void muestraDatos() = 0;
};

#endif