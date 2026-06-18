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
		
		//Constructor por copia
		//COMP={O(a*c). a = número de artistas. c = número de canciones de artistas}
		GestorArtistas(const GestorArtistas & g);
		
		//Destructor.
		//COMP={O(a*c). a = número de artistas. c = número de canciones de artistas}
		~GestorArtistas();

		/**
		 * DESC={Devuelve el número de artistas registrados}
		 * COMP={O(1)}
		 */
		int numElementos() const;

		/**
		 * DESC={
		 *		Busca si hay algún artista cuyo nombre coincida.
		 *	}
		 * POST={
		 *		Si se encuentra, copia el puntero a artista y devuelve true.
		 *		Si no se encuentra, no se modifica el puntero artista y devuelve false.
		 * }
		 * COMP={O(n). n = número de artistas}
		 */
		bool buscar(string nombre, Artista* &artista) const;
		
		/**
		 * DESC={Inserta un nuevo artista por orden si no se repite el nombre}
		 * COMP={O(n). n = número de artistas}
		 */
		void insertar(string nombre, string country, int seguidores);
		
		/**
		 * DESC={
		 *		Busca el artista con más seguidores.
		 *	}
		 *	POST={
		 *		Devuelve un puntero al artista con más seguidores si lo encuentra.
		 *		Si no hay artistas devuelve nullptr. 
		 *	}
		 * COMP={O(n). n = número de artistas}
		 */
		Artista* mayorSeguidores() const;

		/**
		 * DESC={Muestra todos los artistas del gestor}
		 * COMP={O(a*c). a = número de artistas. c = número de canciones de los artistas}
		 */
		void mostrar() const;

};

#else /* LISTA_ARTISTAS */
#include "BSTree.h"
#include "KeyValue.h"

class GestorArtistas{
	private:
		BSTree<KeyValue<string, Artista*>>* artistas;
		int numero_artistas;

		//Auxiliares
		
		//COMP={O(log(n)). n = número de artistas}
		bool buscarAux(BSTree<KeyValue<string, Artista*>> *arbol, string nombre, Artista* &artista) const;
		
		//COMP={O(n). n = número de artistas}
		void mostrarAux(BSTree<KeyValue<string, Artista*>> *g) const;

		//COMP={O(n). n = número de artistas}
		Artista* mayorSeguidoresAux(BSTree<KeyValue<string, Artista*>> *a) const;

	public:
		GestorArtistas();
		//Constructor por copia
		//COMP={O(a*c). a = número de artistas. c = número de canciones de artistas}
		GestorArtistas(const GestorArtistas & g);
	
		//Destructor
		//COMP={O(a*c). a = número de artistas. c = número de canciones de artistas}
		~GestorArtistas();

		/**
		 * DESC={Devuelve el número de artistas registrados}
		 * COMP={O(1)}
		 */
		int numElementos() const;

		/**
		 * DESC={
		 *		Busca un artista con el mismo nombre.
		 *	}
		 *	POST={
		 *		Devuelve true y asigna un artista si hay algún alguno cuyo nombre coincida
		 *		En caso de no exsitir no modifica el puntero a artista;
		 *	}
		 * COMP={O(log(n). n = número de artistas)}
		 */
		bool buscar(string nombre, Artista *&a) const;

		/**
		 * DESC={
		 *		Inserta un nuevo artista en órden.
		 *	}
		 *	POST={
		 *		Solo se inserta si no coincide el nombre.
		 *	}
		 * COMP={O(log(n)). n = número de artistas}
		 */
		void insertar(string nombre, string country, int seguidores);

		/**
		 * DESC={
		 *		Busca el artista con más seguidores.
		 *	}
		 *	POST={
		 *		Devuelve un puntero al artista con más seguidores si lo encuentra.
		 *		Si no hay artistas devuelve nullptr. 
		 *	}
		 * COMP={O(n). n = número de artistas}
		 */
		Artista* mayorSeguidores() const;

		/**
		 * DESC={Muestra todos los artistas del gestor.}
		 * COMP={O(n). n = número de artistas del gestor.}
		 */
		void mostrar() const;
};

#endif /* LISTA_ARTISTAS */
#endif /* GESTOR_ARTISTAS_H_ */
