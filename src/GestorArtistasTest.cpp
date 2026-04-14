/*
 * GestorArtistasTest.cpp
 *
 *  Created on: 13 abr 2026
 *      Author: estudiante
 */

#include "GestorArtistasTest.h"

void pruebasGestorArtistas(){

	 pruebaConstructoresGestorArtistas();

	 pruebaBuscarGestorArtistas();
	 pruebaInsertarGestorArtistas();
}

void pruebaConstructoresGestorArtistas(){
	cout << "Iniciando pruebas de constructres de GestorArtistas" << endl;

	GestorArtistas* ga1;
	GestorArtistas* ga2;

	ga1 = new GestorArtistas();

	if(ga1->numElementos() != 0){
		cerr << "Error con el número de elementos del gestor (default)" << endl;
	}

	ga2 = new GestorArtistas(*ga1);

	if(ga1->numElementos() != 0){
		cerr << "Error con el número de elementos del gestor (default)" << endl;
	}

	delete ga1;
	delete ga2;

	cout << "Fin de pruebas de constructres de GestorArtistas" << endl;
}

void pruebasInsertarGestorArtistas(){
	cout << "Iniciando pruebas de insertar de GestorArtistas" << endl;

	GestorArtistas* ga1;
	ga1 = new GestorArtistas();

	ga1->insertar("Alma", "España", 24);
	ga1->insertar("Pablo", "Marruecos", 3);
	ga1->insertar("Pedro", "Italia", 30);

	ga1->mostrar();
	if(ga1->numElementos() != 3)
		cerr << " * Error con el número de elementos al insertar artistas" << endl;

	delete ga1;

	cout << "Fin de pruebas de insertar de GestorArtistas" << endl;
}

void pruebasBuscarGestorArtistas(){
	cout << "Iniciando pruebas de buscar de GestorArtistas" << endl;

	GestorArtistas* ga1;
	Artista* artista;
	ga1 = new GestorArtistas();

	ga1->insertar("Alma", "España", 24);
	ga1->insertar("Pablo", "Marruecos", 3);
	ga1->insertar("Pedro", "Italia", 30);

	if(!ga1->buscar("Paco2", artista))
		cerr << " * Error con buscando artista (1)" << endl;

	if(ga1->buscar("Paco4", artista))
		cerr << " * Error con buscando artista (2)" << endl;

	cout << "Fin de pruebas de buscar de GestorArtistas" << endl;
}
