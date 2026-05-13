#ifndef GESTOR_ARTISTAS_H_
#define GESTOR_ARTISTAS_H_

#include "Artista.h"

//#define LISTA_ARTISTAS
#if defined LISTA_ARTISTAS

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
		 *		Busca si hay algún artista cuyo nombre coincida.
		 *		Devuelve un puntero al artista original.
		 *	}
		 * POST={
		 *		Si se encuentra, copia el puntero a artista y devuelve true.
		 *		Si no se encuentra, no se modifica el puntero artista y devuelve false.
		 * }
		 * COMP={O(n)}
		 */
		bool buscar(string nombre, Artista* &artista) const;
		
		/**
		 * DESC={Inserta un nuevo artista por orden si no se repite el nombre}
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

		/**
		 * DESC={Muestra todos los artistas del gestor}
		 * COMP={O(n)}
		 */
		void mostrar() const;

};

#else /* LISTA_ARTISTAS */
#include "BSTree.h"

class GestorArtistas{
	private:
		BSTree<Artista*>* artistas;
		int numero_artistas;

		//Auxiliares
		bool buscarAux(BSTree<Artista*> *arbol, string nombre, Artista* &artista) const;
		void mostrarAux(BSTree<Artista*> *g) const;
		Artista* mayorSeguidoresAux(BSTree<Artista*> *a) const;

	public:
		GestorArtistas();
		GestorArtistas(const GestorArtistas & g);
		~GestorArtistas();

		void destruirArtistas(BSTree<Artista*> *g);

		/**
		 * DESC={Devuelve el número de artistas registrados}
		 * COMP={O(1)}
		 */
		int numElementos() const;

		/**
		 * DESC={Devuelve true si hay algún artista cuyo nombre coincida}
		 * COMP={O(log(n))}
		 */
		bool buscar(string nombre, Artista *&a) const;

		/**
		 * DESC={Inserta un nuevo usuario en órden si no se repite ni el id, nombre ni email}
		 * COMP={O(log(n))}
		 */
		void insertar(string nombre, string country, int seguidores);

		/**
		 * DESC={
		 *		Devuelve un puntero al artista con más seguidores
		 *		Si no hay artistas devuelve nullptr. 
		 *	}
		 * COMP={O(log(n))}
		 */
		Artista* mayorSeguidores() const;

		void mostrar() const;
};

#endif /* LISTA_ARTISTAS */
#endif /* GESTOR_ARTISTAS_H_ */
