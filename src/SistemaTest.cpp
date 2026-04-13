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

	cout << "FinalizadaS pruebas de constructores de Sistema" << endl;
}
