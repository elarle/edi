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
		 */void pruebaInsertarCancion(){
	cout << "Inicio de pruebas de operadores de insetarCanción" << endl;

	Artista * a1;
	Artista * a2;
	a1 = new Artista("Andrés", "Marruecos", 67);
	a2 = new Artista("Pablo", "España", 33);


	delete a1;
	delete a2;

	cout << "Fin de pruebas de operadores de insertarCanción" << endl;
}
		bool operator<(const Artista &artista) const;

		//Métodos
		bool buscarCancion(string titulo) const;
		void insertarCancion(string titulo, string genero, int duracion);

		void mostrar() const;

};

#endif /* ARTISTA_H_ */
