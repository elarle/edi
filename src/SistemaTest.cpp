#include "SistemaTest.h"
#include <iostream>

using namespace std;

void pruebasSistema(){
	pruebasConstructoresSistema();
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
	Sistema* s2;
	s1 = new Sistema();
	s2 = new Sistema();
	if (s1 == nullptr || s2 == nullptr)
		cerr << " * Prueba vacía" << endl;

	delete s1;
	delete s2;

	cout << "FinalizadaS pruebas de constructores de Sistema" << endl;
}

void pruebasBuscarUsuarioSistema(){
	cout << "Iniciando pruebas de buscarUsuario de Sistema" << endl;
	
	Sistema* s1;
	s1 = new Sistema();
	
	//DUDA: Debemos devolver una copia o el usuario directo?
	Usuario* busqueda = s1->buscarUsuario("DanielJ");
	if(busqueda == nullptr)
		cerr << " * Error con la primera búsquea." << endl;
	//TODO: Comprobar que el usuario sea el correcto

	delete s1;

	cout << "FinalizadaS pruebas de constructores de Sistema" << endl;
}

void pruebasBuscarArtistaSistema(){
	cout << "Iniciando pruebas de buscarArtista de Sistema" << endl;
	
	Sistema* s1;
	s1 = new Sistema();
	s1->cargarArtistas("artistas.csv");

	Artista* busqueda = nullptr;
	busqueda = s1->buscarArtista("Violadores del Verso");
	if(busqueda == nullptr)
		cerr << " * Error con la primera búsquea." << endl;

	delete s1;

	cout << "FinalizadaS pruebas de constructores de Sistema" << endl;
}

void pruebasReproducirPlaylistUsuarioSistema(){
	cout << "Iniciando pruebas de de ReproducirPlaylistUsuarioSistema" << endl;

	Sistema* s = new Sistema();
	Usuario* u = s->buscarUsuario("Coronado Perez, Pablo");


	if(u == nullptr){
		cerr << " * Prueba vacía" << endl;
	}
	else{
		u->crearPlayList("TestSistema");
		u->reproducirPlayList("TestSistema");
	}
	//NO SE HACE DELETE DEL USUARIO POR QUE ES DE SISTEMA
	//delete s;
	delete u;

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
