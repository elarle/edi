#include "SistemaTest.h"
#include <iostream>

using namespace std;

void pruebasSistema(){
	pruebasConstructoresSistema();
	pruebasMostrarUsuariosSistema();
	pruebasMostrarArtistasSistema();
	pruebasBuscarUsuarioSistema();
	pruebasBuscarArtistaSistema();
	pruebasReproducirPlaylistUsuarioSistema();
	pruebasCompartirPlaylistSistema();
	pruebasEliminarPlaylistUsuarioSistema();
	pruebasAddFavoritoSistema();
	pruebasBorrarFavoritoSistema();
}

void pruebasConstructoresSistema(){
	cout << "Iniciando pruebas de constructores de Sistema" << endl;
	
	Sistema* s1;
	s1 = new Sistema();
	//Ni idea de qué cookeamos aquí
	delete s1;

	cerr << " * Prueba vacía" << endl;

	cout << "FinalizadaS pruebas de constructores de Sistema" << endl;
}

void pruebasBuscarUsuarioSistema(){
	cout << "Iniciando pruebas de constructores de Sistema" << endl;
	
	Sistema* s1;
	s1 = new Sistema();
	//Ni idea de qué cookeamos aquí
	delete s1;
	cerr << " * Prueba vacía" << endl;

	cout << "FinalizadaS pruebas de constructores de Sistema" << endl;
}

void pruebasBuscarArtistaSistema(){
	cout << "Iniciando pruebas de constructores de Sistema" << endl;
	
	Sistema* s1;
	s1 = new Sistema();
	//Ni idea de qué cookeamos aquí
	delete s1;
	cerr << " * Prueba vacía" << endl;

	cout << "FinalizadaS pruebas de constructores de Sistema" << endl;
}

void pruebasMostrarArtistasSistema(){
	cout << "Iniciando pruebas de de MostrarArtistasSistema" << endl;

	cerr << " * Prueba vacía" << endl;

	cout << "Finalizadas pruebas de de MostrarArtistasSistema" << endl;
}

void pruebasMostrarUsuariosSistema(){
	cout << "Iniciando pruebas de de MostrarUsuariosSistema" << endl;

	cerr << " * Prueba vacía" << endl;

	cout << "Finalizadas pruebas de de MostrarUsuariosSistema" << endl;
}

void pruebasReproducirPlaylistUsuarioSistema(){
	cout << "Iniciando pruebas de de ReproducirPlaylistUsuarioSistema" << endl;

	cerr << " * Prueba vacía" << endl;

	cout << "Finalizadas pruebas de de ReproducirPlaylistUsuarioSistema" << endl;
}

void pruebasCompartirPlaylistSistema(){
	cout << "Iniciando pruebas de de CompartirPlaylistSistema" << endl;

	cerr << " * Prueba vacía" << endl;

	cout << "Finalizadas pruebas de de CompartirPlaylistSistema" << endl;
}

void pruebasEliminarPlaylistUsuarioSistema(){
	cout << "Iniciando pruebas de de EliminarPlaylistUsuarioSistema" << endl;

	cerr << " * Prueba vacía" << endl;

	cout << "Finalizadas pruebas de de EliminarPlaylistUsuarioSistema" << endl;
}

void pruebasAddFavoritoSistema(){
	cout << "Iniciando pruebas de de AddFavoritoSistema" << endl;

	cerr << " * Prueba vacía" << endl;

	cout << "Finalizadas pruebas de de AddFavoritoSistema" << endl;
}

void pruebasBorrarFavoritoSistema(){
	cout << "Iniciando pruebas de de BorrarFavoritoSistema" << endl;

	cerr << " * Prueba vacía" << endl;

	cout << "Finalizadas pruebas de de BorrarFavoritoSistema" << endl;
}
