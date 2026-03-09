#include "PlayListTest.h"

#include<iostream>
using namespace std;

void pruebasPlayList(){
	pruebaConstructoresPlayList();
	pruebaAgregarCancion();
	pruebaEliminarCancion();
	pruebaReproducir();
	pruebaReproducirDesde();
}

void pruebaConstructoresPlayList(){
	cout << "Inicio de pruebas constructores de PlayList" << endl;

	PlayList * p1;
	PlayList * p2;
	PlayList * p3;
	p1 = new PlayList();

	if(p1->getNombre() != "")
		cerr << " * Error con el nombre inicial (Default)" << endl;
	if(p1->getCanciones() != 0)
		cerr << " * Error con el número inicial de canciones (Default)" << endl;
	if(p1->getDuracion() != 0)
		cerr << " * Error con el tiempo inicial de la playlist (Default)" << endl;

	p1->setNombre("Los Chichos playlist");
	if(p1->getNombre() != "Los Chichos playlist")
		cerr << " * Error con el getter/setter de Nombre (Default)" << endl;
	
	p2 = new PlayList("Los Chichos playlist");
	if(p2->getNombre() != "Los Chichos playlist")
		cerr << " * Error con el nombre inicial (Parametrizado)" << endl;
	if(p2->getCanciones() != 0)
		cerr << " * Error con el número inicial de canciones (Parametrizado)" << endl;
	if(p2->getDuracion() != 0)
		cerr << " * Error con el tiempo inicial de la playlist (Parametrizado)" << endl;

	p3 = new PlayList(*p2);
	if(p3->getNombre() != "Los Chichos playlist")
		cerr << " * Error con el nombre inicial (Copia)" << endl;
	if(p3->getCanciones() != 0)
		cerr << " * Error con el número inicial de canciones (Copia)" << endl;
	if(p3->getDuracion() != 0)
		cerr << " * Error con el tiempo inicial de la playlist (Copia)" << endl;

	delete p1;
	delete p2;
	delete p3;

	cout << "Fin de pruebas de constructores de PlayList" << endl;
}

void pruebaAgregarCancion(){
	cout << "Inicio de pruebas de agregarCancion" << endl;

	Cancion * c1;
	Cancion * c2;
	Cancion * c3;
	c1 = new Cancion("Ni mas ni menos", "Gitaneo", 67);
	c2 = new Cancion("Son ilusiones", "Gitaneo", 33);
	c3 = new Cancion("Sangre gitana", "Payada clásica", 69);

	PlayList * p1;
	p1 = new PlayList();

	p1->agregarCancion(c1);
	p1->agregarCancion(c2);
	p1->agregarCancion(c3);

	if(p1->getDuracion() != 169)
		cerr << " * Error con el cálculo de la duración (Default)" << endl;
	if(p1->getCanciones() != 3)
		cerr << " * Error con el número de canciones (Default)" << endl;

	cout << "# Prueba supervisada:" << endl;
	p1->mostrar();

	delete p1;

	delete c1;
	delete c2;
	delete c3;

	cout << "Fin de pruebas de agregarCancion" << endl;
}

void pruebaEliminarCancion(){
	cout << "Inicio de pruebas de eliminarCancion" << endl;

	Cancion * c1;
	Cancion * c2;
	Cancion * c3;
	c1 = new Cancion("Ni mas ni menos", "Gitaneo", 67);
	c2 = new Cancion("Son ilusiones", "Gitaneo", 33);
	c3 = new Cancion("Sangre gitana", "Payada clásica", 69);

	PlayList * p1;
	p1 = new PlayList();

	p1->agregarCancion(c1);
	p1->agregarCancion(c2);
	p1->agregarCancion(c3);

	p1->eliminarCancion();
	if(p1->getDuracion() != 102)
		cerr << " * Error con el cálculo de la duración (1º)" << endl;
	if(p1->getCanciones() != 2)
		cerr << " * Error con el número de canciones (1º)" << endl;
	cout << "# Prueba supervisada (2):" << endl;
	p1->mostrar();

	p1->eliminarCancion();
	if(p1->getDuracion() != 69)
		cerr << " * Error con el cálculo de la duración (2º)" << endl;
	if(p1->getCanciones() != 1)
		cerr << " * Error con el número de canciones (2º)" << endl;
	cout << "# Prueba supervisada (1):" << endl;
	p1->mostrar();

	p1->eliminarCancion();
	if(p1->getDuracion() != 0)
		cerr << " * Error con el cálculo de la duración (3º)" << endl;
	if(p1->getCanciones() != 0)
		cerr << " * Error con el número de canciones (3º)" << endl;
	cout << "# Prueba supervisada (0):" << endl;
	p1->mostrar();

	delete p1;

	delete c1;
	delete c2;
	delete c3;

	cout << "Fin de pruebas de eliminarCancion" << endl;
}

void pruebaReproducir(){
	cout << "Inicio de pruebas de reproducir" << endl;

	Cancion * c1;
	Cancion * c2;
	Cancion * c3;
	Cancion * c4;
	Cancion * c5;
	c1 = new Cancion("Canción 0", "clásica", 0);
	c2 = new Cancion("Canción 1", "clásica", 1);
	c3 = new Cancion("Canción 2", "clásica", 2);
	c4 = new Cancion("Canción 3", "clásica", 3);
	c5 = new Cancion("Canción 4", "clásica", 4);

	PlayList * p1;
	p1 = new PlayList();

	p1->agregarCancion(c1);
	p1->agregarCancion(c2);
	p1->agregarCancion(c3);
	p1->agregarCancion(c4);
	p1->agregarCancion(c5);

	cout << "# Prueba supervisada (0..4):" << endl;
	p1->reproducir();

	delete p1;

	delete c1;
	delete c2;
	delete c3;
	delete c4;
	delete c5;

	cout << "Fin de pruebas de reproducir" << endl;
}

void pruebaReproducirDesde(){
	cout << "Inicio de pruebas de reproducirDesde" << endl;

	Cancion * c1;
	Cancion * c2;
	Cancion * c3;
	Cancion * c4;
	Cancion * c5;
	c1 = new Cancion("Canción 0", "clásica", 0);
	c2 = new Cancion("Canción 1", "clásica", 1);
	c3 = new Cancion("Canción 2", "clásica", 2);
	c4 = new Cancion("Canción 3", "clásica", 3);
	c5 = new Cancion("Canción 4", "clásica", 4);

	PlayList * p1;
	p1 = new PlayList();

	p1->agregarCancion(c1);
	p1->agregarCancion(c2);
	p1->agregarCancion(c3);
	p1->agregarCancion(c4);
	p1->agregarCancion(c5);

	cout << "# Prueba supervisada (2..4):" << endl;
	p1->reproducirDesde(2);

	delete p1;

	delete c1;
	delete c2;
	delete c3;
	delete c4;
	delete c5;

	cout << "Fin de pruebas de reproducir" << endl;
	cout << "Fin de pruebas de reproducir" << endl;
}
