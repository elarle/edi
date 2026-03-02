#ifndef ARTISTA_H_
#define ARTISTA_H_

#include <iostream>
using namespace std;

class Artista {
	private:
		string nombre;
		string country;
		int seguidores;
	public:
		Artista();
		Artista(string nombre, string country, int seguidores);
		Artista(const Artista & artista);

		//Getters
		string getNombre() const;
		string getCountry() const;
		int getSeguidores() const;

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

};

#endif /* ARTISTA_H_ */
