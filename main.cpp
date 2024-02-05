#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Función para cargar datos desde un archivo
void cargarDatosDesdeArchivo(const string& nombreArchivo, vector<Video*>& vectorVideos) {
    ifstream archivo(nombreArchivo);

    if (!archivo) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        istringstream ss(linea);
        string tipoVideo, genero, nombre;
        int calificacion, anioLanzamiento, duracion, id, episodio, temporada;

        getline(ss, tipoVideo, ',');
        getline(ss, genero, ',');
        ss >> calificacion >> anioLanzamiento >> duracion;
        getline(ss >> ws, nombre, ',');
        ss >> id >> episodio >> temporada;

        if (tipoVideo == "Pelicula") {
            vectorVideos.push_back(new Pelicula(tipoVideo, genero, calificacion, anioLanzamiento, duracion, nombre, id));
        } else if (tipoVideo == "Serie") {
            vectorVideos.push_back(new Serie(tipoVideo, genero, calificacion, anioLanzamiento, duracion, nombre, id, episodio, temporada));
        }
    }

    archivo.close();
}

// Función para calificar un episodio de una serie
void calificarEpisodios(Serie* serie) {
    int temporadaElegida;
    int episodioElegido;
    int calificacionEpisodio;

    cout << "Ingrese la temporada que desea calificar (1-" << serie->getNumTemporadas() << "): ";
    cin >> temporadaElegida;

    if (temporadaElegida < 1 || temporadaElegida > serie->getNumTemporadas()) {
        cout << "Temporada inválida. Regresando al menú principal." << endl;
        return;
    }

    cout << "Ingrese el episodio que desea calificar (1-" << serie->getNumEpisodios(temporadaElegida) << "): ";
    cin >> episodioElegido;

    if (episodioElegido < 1 || episodioElegido > serie->getNumEpisodios(temporadaElegida)) {
        cout << "Episodio inválido. Regresando al menú principal." << endl;
        return;
    }

    cout << "Ingrese la calificación del episodio (1-5): ";
    cin >> calificacionEpisodio;

    serie->calificaEpisodio(temporadaElegida, episodioElegido, calificacionEpisodio);
    cout << "Episodio calificado con éxito." << endl;
}

// Función para mostrar las opciones de series disponibles
void mostrarSeriesDisponibles(const vector<Video*>& vectorVideos) {
    cout << "Series Disponibles:\n";
    for (size_t i = 0; i < vectorVideos.size(); ++i) {
        Serie* serie = dynamic_cast<Serie*>(vectorVideos[i]);
        if (serie) {
            cout << i + 1 << ". " << serie->getNombre() << endl;
        }
    }
}

int main() {
    vector<Video*> vectorVideos;

    // Cargar datos desde el archivo
    cargarDatosDesdeArchivo("datos.txt", vectorVideos);

    // Mostrar datos de cada video en el vector
    for (size_t i = 0; i < vectorVideos.size(); ++i) {
        cout << i + 1 << ". ";
        vectorVideos[i]->muestraDatos();
        cout << "\n";
    }

    // Menú
    int menu;

    do {
        cout << "\nMenu:\n";
        cout << "1. Calificar Película o Serie\n";
        cout << "2. Salir\n";
        cout << "Ingrese la opción elegida: ";
        cin >> menu;

        switch (menu) {
            case 1:
                int indice;
                int calificacion;
                cout << "Ingrese el índice del video a calificar (1-" << vectorVideos.size() << "): ";
                cin >> indice;

                if (indice >= 1 && indice <= vectorVideos.size()) {
                
                    cout << "Ingrese la calificación (1-5): ";
                    cin >> calificacion;
                    vectorVideos[indice - 1]->calificaVideo(calificacion);
                    cout << "Video calificado con éxito.\n";
                } else {
                    cout << "Índice inválido. Inténtelo de nuevo.\n";
                }
                break;

            case 2:
                cout << "Saliendo del programa.\n";
                break;

            case 3:
                // Mostrar series disponibles
                mostrarSeriesDisponibles(vectorVideos);

                // Pedir al usuario que elija una serie
                int opcionSerie;
                cout << "Elija una serie (1-" << vectorVideos.size() << "): ";
                cin >> opcionSerie;

                if (opcionSerie >= 1 && opcionSerie <= vectorVideos.size()) {
                    Serie* serieElegida = dynamic_cast<Serie*>(vectorVideos[opcionSerie - 1]);

                    if (serieElegida) {
                        // Calificar un episodio de la serie
                        calificarEpisodios(serieElegida);
                    } else {
                        cout << "La opción elegida no es una serie.\n";
                    }
                } else {
                    cout << "Opción inválida. Inténtelo de nuevo.\n";
                }
                break;

            default:
                cout << "Opción no válida. Inténtelo de nuevo.\n";
                break;
        }

    } while (menu != 2);

    // Liberar memoria 
    for (Video* video : vectorVideos) {
        delete video;
    }

    return 0;
}

