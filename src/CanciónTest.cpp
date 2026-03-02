/*
 * CanciónTest.cpp
 *
 *  Created on: 2 mar 2026
 *      Author: estudiante
 */
#include "CanciónTest.h"

#include<iostream>
using namespace std;

void pruebasCanción(){
	pruebasConstrucoresCancion(),
	pruebasOperadoresCancion();
}

void pruebasConstrucoresCancion(){

	cout << "Iniciando pruebas de constructores de Canción" << endl;

	Cancion * c1;
	c1 = new Cancion();

	c1->setTitulo("Pepe");
	if(c1->getTitulo() != "Pepe")
		cerr << " * Error con el getter/setter de Título (Default)" << endl;

	c1->setGenero("Rock");
	if(c1->getGenero() != "Rock")
		cerr << " * Error con el getter/setter de Género (Default)" << endl;

	c1->setDuracion(3);
	if(c1->getDuracion() != 3)
		cerr << " * Error con el getter/setter de Duración (Default)" << endl;

	delete c1;

	Cancion * c2;
	c2 = new Cancion("Jose", "Pop", 5);
	if(c2->getTitulo() != "Jose")
		cerr << " * Error con el Título (Parametrizado)" << endl;

	if(c2->getGenero() != "Pop")
		cerr << " * Error con el Genero (Parametrizado)" << endl;

	if(c2->getDuracion() != 5)
		cerr << " * Error con el Duración (Parametrizado)" << endl;

	Cancion * c3;
	c3 = new Cancion(*c2);

	if(c3->getTitulo() != "Jose")
		cerr << " * Error con el Título (Copia)" << endl;

	if(c3->getGenero() != "Pop")
		cerr << " * Error con el Genero (Copia)" << endl;

	if(c3->getDuracion() != 5)
		cerr << " * Error con el Duració5n (Copia)" << endl;

	cout << "Fin de pruebas de constructores de Canción" << endl;

	delete c2;
	delete c3;

}

void pruebasOperadoresCancion(){
	cout << "Inicio de pruebas de operadores de Canción" << endl;

	Cancion * c1;
	Cancion * c2;
	c1 = new Cancion("Aitana", "Pop-Rock", 67);
	c2 = new Cancion("Pablo", "K-pop", 33);

	if(*c1 == *c2)
		cerr << " * Error con el operador (==). No son iguales." << endl;

	c2->setTitulo("Aitana");
	if(!(*c1 == *c2))
		cerr << " * Error con el operador (==). Son iguales." << endl;

	c1->setTitulo("Pablo");
	if((*c1 < *c2))
		cerr << " * Error con el operador (<). Órden incorrecto. Aitana < Pablo" << endl;

	c2->setTitulo("Xavi");
	if(*c2 < *c1)
		cerr << " * Error con el operador (<). Órden incorrecto. Pablo < Xavi" << endl;

	delete c1;
	delete c2;

	cout << "Fin de pruebas de operadores de Artista" << endl;
}
