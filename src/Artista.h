#ifndef ARTISTA_H_
#define ARTISTA_H_

#include <iostream>
using namespace std;

#include "ListaDPI.h"
#include "Cancion.h"

class Artista {
	private:
		string nombre;
		string country;
		int seguidores;

		ListaDPI<Cancion*>* canciones; 
		int numero_canciones;

	public:
		Artista();
		Artista(string nombre, string country, int seguidores);
		Artista(const Artista & artista);
		~Artista();

		//Getters
		string getNombre() const;
		string getCountry() const;
		int getSeguidores() const;
		int getNumCanciones() const;

		//Setters
		void setNombre(string nombre);
		void setCountry(string country);
		void setSeguidores(int seguidores);

		//Operadores
		/**
		 * DESC={Compara el nombre de los artistas} 
		 * COMP={O(1)}
		 */
		bool operator==(const Artista &artista) const;

		/**
		 * DESC={
		 *		Compara los nombres de los artistas según el órden alfabético.
		 *		Devuelve true si el primero estaría antes afabéticamente.
		 *		Si devuelve false el segundo operando estaría primero.
		 * }
		 * COMP={O(1)}
		 */
		bool operator<(const Artista &artista) const;

		//Métodos
		/**
		 * DESC={Busca una canción por título en la lista del artista}
		 * POST={Si se encuentra, se devuelve true y se asigna el puntero. Si no, no se modifica.}
		 * COMP={O(n)}
		 */
		bool buscarCancion(string titulo, Cancion* &cancion) const;
		/**
		 * DESC={Inserta una canción en el artista si no existe ya una con ese título}
		 * COMP={O(n)}
		 */
		void insertarCancion(string titulo, string genero, int duracion);

		/**
		 * DESC={Incrementa el número de seguidores}
		 * COMP={O(1)}
		 */
		void addSeguidor();
		/**
		 * DESC={Decrementa el número de seguidores si es mayor que 0}
		 * COMP={O(1)}
		 */
		void delSeguidor();

		/**
		 * DESC={Muestra la información del artista y sus canciones}
		 * COMP={O(n)}
		 */
		void mostrar() const;

};

#endif /* ARTISTA_H_ */
