#include "GestorArtistasTest.h"

#include <iostream>

using namespace std;

void pruebasGestorArtistas(){
	pruebaConstructoresGestorArtistas();

	pruebaInsertarGestorArtistas();
	pruebaBuscarGestorArtistas();
	pruebaNumElementosGestorArtistas();
}

void pruebaConstructoresGestorArtistas(){

	cout << "Iniciando prueba de constructores de GestorArtistas" << endl;

	GestorArtistas* g1;
	GestorArtistas* g2;
	g1 = new GestorArtistas();

	if(g1->numElementos() != 0)
		cerr << " * Error con el número de elementos (default)" << endl;
		
	//¿Deberíamos hacer una prueba aparte para esto?
	g1->insertar("Pepe", "ES", 33);
	if(g1->numElementos() != 1)
		cerr << " * Error con el número de elementos (default)" << endl;

	g2 = new GestorArtistas(*g1);
	if(g2->numElementos() != 1)
		cerr << " * Error con el número de elementos (copia)" << endl;

	delete g1;
	delete g2;

	cout << "Finalizada prueba de constructores de GestorArtistas" << endl;

}

void pruebaBuscarGestorArtistas(){
	cout << "Iniciando prueba de constructores de GestorArtistas" << endl;

	GestorArtistas* g1;
	Artista* busqueda = nullptr;
	
	g1 = new GestorArtistas();

	g1->insertar("Pepe", "ES", 33);
	g1->insertar("Andrés", "Marruecos", 1);
	g1->insertar("Diego", "India", 6767);

	if(!g1->buscar("Pepe", busqueda) || busqueda == nullptr)
		cerr << " * Error con la primera búsqueda" << endl;
	if(busqueda != nullptr)
		delete busqueda;

	if(!g1->buscar("Diego", busqueda) || busqueda == nullptr)
		cerr << " * Error con la segunda búsqueda" << endl;
	if(busqueda != nullptr)
		delete busqueda;

	busqueda = nullptr;
	if(!g1->buscar("Felipe", busqueda) || busqueda == nullptr)
		cerr << " * Error con la tercera búsqueda" << endl;

	delete g1;

	cout << "Finalizada prueba de constructores de GestorArtistas" << endl;
}

void pruebaNumElementosGestorArtistas(){
	cout << "Iniciando prueba de numElementos de GestorArtistas" << endl;

	GestorArtistas* g1;
	g1 = new GestorArtistas();
	if(g1->numElementos() != 0)
		cerr << " * Error con el número de elementos en gestor vacío" << endl;

	g1->insertar("Pepe", "ES", 33);
	g1->insertar("Andrés", "Marruecos", 1);
	g1->insertar("Diego", "India", 6767);

	if(g1->numElementos() != 3)
		cerr << " * Error con el número de elementos en gestor con 3 artistas" << endl;

	g1->insertar("Diego", "India", 6767);

	if(g1->numElementos() != 4)
		cerr << " * Error con el número de elementos en gestor con 4 artistas" << endl;

	delete g1;

	cout << "Finalizada prueba de numElementos de GestorArtistas" << endl;
}

void pruebaInsertarGestorArtistas(){
	cout << "Iniciando prueba de insertar de GestorArtistas" << endl;

	GestorArtistas* g1;
	Artista* busqueda = nullptr;
	g1 = new GestorArtistas();

	g1->insertar("Pepe", "ES", 33);
	g1->insertar("Andrés", "Marruecos", 1);	
	g1->insertar("Diego", "India", 6767);
	
	if(!g1->buscar("Pepe", busqueda)){
		cerr << " * Error con la primera inserción" << endl;
	}

	if(busqueda != nullptr){
		if(busqueda->getCountry() != "ES")
			cerr << " * Error con el país de la primera inserción" << endl;
		if(busqueda->getSeguidores() != 33)
			cerr << " * Error con el país de la primera inserción" << endl;
	}

	if(!g1->buscar("Andrés", busqueda))
		cerr << " * Error con la segunda inserción" << endl;
	if(!g1->buscar("Diego", busqueda))
		cerr << " * Error con la tercera inserción" << endl;

	delete g1;

	cout << "Finalizada prueba de insertar de GestorArtistas" << endl;
}
