#include "GestorArtistasTest.h"

#include <iostream>

using namespace std;

void pruebasGestorArtistas(){
	pruebaConstructoresGestorArtistas();

	pruebaInsertarGestorArtistas();
	pruebaBuscarGestorArtistas();
	pruebaNumElemenosGestorArtistas();
}

void pruebasConstructoresGestorUsuarios(){

	cout << "Iniciando prueba de constructores de GestorArtistas" << endl;

	GestorArtistas* g1;
	GestorArtistas* g2;
	g1 = new GestorArtistas();

	if(g1->numElementos() != 0)
		cerr << "Error con el número de elementos (default)" << endl;
		
	//¿Deberíamos hacer una prueba aparte para esto?
	g1->insertar("Pepe", "ES", 33);
	if(g1->numElementos() != 1)
		cerr << "Error con el número de elementos (default)" << endl;

	g2 = new GestorArtistas(*g1);
	if(g2->numElementos() != 1)
		cerr << "Error con el número de elementos (copia)" << endl;

	delete g1;
	delete g2;

	cout << "Finalizada prueba de constructores de GestorArtistas" << endl;
}

void pruebaMetodosGestorArtistas(){

}
