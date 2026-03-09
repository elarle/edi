#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include <iostream>
using namespace std;

#include "Cola.h"
#include "Cancion.h"

class PlayList{
private:
	string nombre;
	int canciones;
	int duracion;
	Cola<Cancion*>* cola;

public:
	//Constructores
	PlayList(); //Sería mejor poner el nombre inicial a Untitled
	PlayList(string nombre); //Tiempo y canciones son siempre 0 al principio
	PlayList(const PlayList & playlist);
	~PlayList();

	//Getters
	string getNombre() const;
	int getDuracion() const;
	int getCanciones() const;

	//Setters
	void setNombre(string nombre);

	//Métodos
	//DESC={Añade una canción al final de la playlist y modifica los atributos}
	//COMP={O(1)}
	void agregarCancion(Cancion * cancion);

	//DESC={Elimina la primera canción de la playlist y modifica los atributos}
	//COMP={O(1)}
	void eliminarCancion();
	
	//DESC={
	//		Muestra la información de la playlist y de cada canción.
	//}
	//COMP={O(n)}
	void mostrar() const;

	//DESC={
	//		Este método va desencolando canciones desde la primera
	//		hasta que se quede vacía. Reproducir no modifica la playlist.
	//}
	//COMP={O(n)}
	void reproducir(); //No puede ser const

	//DESC={
	//		Este método va desencolando canciones de la misma manera que reproducir()
	//		pero empezando desde una canción concreta
	//}
	//COMP={O(n)}
	void reproducirDesde(int indice); //No puede ser const
};

#endif /* PLAYLIST_H_ */
