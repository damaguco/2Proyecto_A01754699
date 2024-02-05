#include "Serie.h"
#include <iostream>

Serie::Serie(std::string _tipoVideo, std::string _genero, int _calificacion, int _anoLanzamiento, int _duracion, std::string _nombre, int _id, int _episodio, int _temporada)
    : Video(_tipoVideo, _genero, _calificacion, _anoLanzamiento, _duracion), nombre(_nombre), id(_id), episodio(_episodio), temporada(_temporada) {
    numEpisodiosPorTemporada.resize(_temporada);
}

Serie::Serie() : Video(), nombre("Desconocido"), id(0), episodio(0), temporada(0) {
    numEpisodiosPorTemporada.resize(temporada);
}


void Serie::calificaVideo(int _calificacion) {
    Video::calificaVideo(_calificacion);
}

void Serie::calificaEpisodio(int temporada, int episodio, int calificacion) {
    if (temporada >= 1 && temporada <= numEpisodiosPorTemporada.size() && episodio >= 1) {
        numEpisodiosPorTemporada[temporada - 1] = std::max(numEpisodiosPorTemporada[temporada - 1], episodio);

    } else {
        std::cout << "Temporada o episodio inválido." << std::endl;
    }
}

void Serie::muestraDatos() {
    Video::muestraDatos();
    std::cout << "El nombre: " << nombre << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Episodio: " << episodio << std::endl;
    std::cout << "Temporada: " << temporada << std::endl;
}

std::string Serie::getNombre() const {
    return nombre;
}

int Serie::getId() const {
    return id;
}

int Serie::getNumTemporadas() const {
    return numEpisodiosPorTemporada.size();
}

int Serie::getNumEpisodios(int temporada) const {
    if (temporada >= 1 && temporada <= numEpisodiosPorTemporada.size()) {
        return numEpisodiosPorTemporada[temporada - 1];
    } else {
        return 0; 
    }
}

