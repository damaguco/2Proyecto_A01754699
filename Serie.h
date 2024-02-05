#ifndef SERIE_H
#define SERIE_H

#include "Video.h"
#include <vector>
#include <string>

class Serie : public Video {
public:


    Serie(std::string _tipoVideo, std::string _genero, int _calificacion, int _anoLanzamiento, int _duracion, std::string _nombre, int _id, int _episodio, int _temporada);
    Serie();  


    void calificaEpisodio(int temporada, int episodio, int calificacion);
    void muestraDatos();
    std::string getNombre() const;
    int getId() const;
    void calificaVideo(int _calificacion);
    int getNumTemporadas() const;
    int getNumEpisodios(int temporada) const;



private:
    std::string nombre;
    int id;
    int episodio;
    int temporada;
    std::vector<int> numEpisodiosPorTemporada;
};

#endif
