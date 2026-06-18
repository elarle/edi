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
	//PRE={cancion debe estar inicializado correctamente}
	//DESC={Añade una canción al final de la playlist y modifica los atributos}
	//COMP={O(1)}
	void agregarCancion(Cancion * cancion);

	//DESC={Elimina la primera canción de la playlist y modifica los atributos}
	//COMP={O(1)}
	void eliminarCancion();
	
	//DESC={
	//		Muestra cada canción de la playlist.
	//}
	//COMP={O(n)}
	void mostrar() const;

	//DESC={
	//		Este método muestra las canciones de la playlist. 
	//		Reproducir no modifica la playlist.
	//}
	//COMP={O(n)}
	void reproducir(); //No puede ser const

	//PRE={indice < número de canciones. indice >= 0}
	//DESC={
	//		Muestra las canciones desde la canción con el índice indicado
	//}
	//COMP={O(n)}
	void reproducirDesde(int indice); //No puede ser const
};

#endif /* PLAYLIST_H_ */
