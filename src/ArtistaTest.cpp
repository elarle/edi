#include "ArtistaTest.h"

#include<iostream>
using namespace std;

void pruebasArtista(){
	pruebasConstrucoresArtista(),
	pruebasOperadoresArtista();
}

void pruebasConstrucoresArtista(){

	cout << "Iniciando pruebas de constructores de Artista" << endl;

	Artista * a1;
	a1 = new Artista();

	a1->setNombre("Pepe");
	if(a1->getNombre() != "Pepe")
		cout << " * Error con el getter/setter de Nombre (Default)" << endl;
	
	a1->setCountry("España");
	if(a1->getCountry() != "Pepe")
		cout << " * Error con el getter/setter de Country (Default)" << endl;

	a1->setSeguidores(33);
	if(a1->getSeguidores() != 33)
		cout << " * Error con el getter/setter de Seguidores (Default)" << endl;
	
	delete a1;

	Artista * a2;
	a2 = new Artista("Jose", "Portugal", 1);
	if(a2->getNombre() != "Jose")
		cout << " * Error con el Nombre (Parametrizado)" << endl;
	
	if(a2->getCountry() != "Portugal")
		cout << " * Error con el Country (Parametrizado)" << endl;

	if(a2->getSeguidores() != 1)
		cout << " * Error con el Seguidores (Parametrizado)" << endl;

	Artista * a3;
	a3 = new Artista(*a2);

	if(a3->getNombre() != "Jose")
		cout << " * Error con el Nombre (Copia)" << endl;
	
	if(a3->getCountry() != "Portugal")
		cout << " * Error con el Country (Copia)" << endl;

	if(a3->getSeguidores() != 1)
		cout << " * Error con el Seguidores (Copia)" << endl;

	cout << "Fin de pruebas de constructores de Artista" << endl;

	delete a2;
	delete a3;

}

void pruebasOperadoresArtista(){
	cout << "Inicio de pruebas de operadores de Artista" << endl;

	Artista * a1;
	Artista * a2;
	a1 = new Artista("Andrés", "Marruecos", 67);
	a2 = new Artista("Pablo", "España", 33);

	if(*a1 == *a2)
		cout << " * Error con el operador (==). No son iguales." << endl;

	a2->setNombre("Andrés");
	if(!(*a1 == *a2))
		cout << " * Error con el operador (==). Son iguales." << endl;

	a1->setNombre("Pablo");
	if((*a1 < *a2))
		cout << " * Error con el operador (<). Órden incorrecto. Andrés < Pablo" << endl;

	a2->setNombre("Xavi");
	if(*a2 < *a1)
		cout << " * Error con el operador (<). Órden incorrecto. Pablo < Xavi" << endl;

	delete a1;
	delete a2;

	cout << "Fin de pruebas de operadores de Artista" << endl;
}
