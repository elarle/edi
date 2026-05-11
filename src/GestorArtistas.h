#ifndef GESTOR_ARTISTAS_H_
#define GESTOR_ARTISTAS_H_

#include "Artista.h"
#include "ListaDPI.h"

class GestorArtistas{
	private:
		ListaDPI<Artista*>* artistas;
		int numero_artistas;
		
	public:
		GestorArtistas();
		GestorArtistas(const GestorArtistas & g);
		~GestorArtistas();

		/**
		 * DESC={Devuelve el número de artistas registrados}
		 * COMP={O(1)}
		 */
		int numElementos() const;
		/**
		 * DESC={
		 *		Devuelve true si hay algún artista cuyo nombre coincida
		 *    Devuelve una copia del artista encontrado en el parámetro artista.
		 *    La memoria de artista es responsabilidad del usuario. 
		 *	}
		 * COMP={O(n)}
		 */
		bool buscar(string nombre, Artista* &artista) const;
		
		/**
		 * DESC={Inserta un nuevo artista por órden si no se repite el nombre}
		 * COMP={O(n)}
		 */
		void insertar(string nombre, string country, int seguidores);
		
		/**
		 * DESC={
		 *		Devuelve un puntero al artista con más seguidores
		 *		Si no hay artistas devuelve nullptr. 
		 *	}
		 * COMP={O(n)}
		 */
		Artista* mayorSeguidores() const;

		void mostrar() const;

};


#endif /* GESTOR_ARTISTAS_H_ */
