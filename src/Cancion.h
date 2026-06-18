/*
 * Canción.h
 *
 *  Created on: 2 mar 2026
 *      Author: estudiante
 */

#ifndef CANCIÓN_H_
#define CANCIÓN_H_

#include <iostream>
using namespace std;

class Cancion {
	private:
		string titulo;
		string genero;
		int duracion;
	public:
		Cancion();
		Cancion(string titulo, string genero, int duracion);
		Cancion(const Cancion & cancion);
		~Cancion();

		//Getters
		string getTitulo() const;
		string getGenero() const;
		int getDuracion() const;

		//Setters
		void setTitulo(string titulo);
		void setGenero(string genero);
		void setDuracion(int duracion);

		//Operadores
		/**
		 * DESC={
		 *		Compara el titulo de las canciones.
		 *		Devuelve true si los nombres coinciden.
		 *		Del caso contrario devuelve false.
		 *	}
		 * COMP={O(1)}
		 */
		bool operator==(const Cancion &cancion) const;

		/**
		 * DESC={
		 *		Compara los titulos de las canciones según el órden alfabético.
		 *		Devuelve true si el primero estaría antes afabéticamente.
		 *		Si devuelve false el segundo operando estaría primero.
		 * }
		 * COMP={O(1)}
		 */
		bool operator<(const Cancion &cancion) const;
		
		/**
		 * DESC={Muestra la canción}
		 * COMP={O(1)}
		 */
		void mostrar() const;
};

#endif /* CANCIÓN_H_ */
