/*
 * UsuarioTest.cpp
 *
 *  Created on: 9 feb 2026
 *      Author: usuario
 */

#include "UsuarioTest.h"

void pruebasUsuario(){
	pruebasConstructoresUsuario();
	pruebasCrearPlayList();
	pruebasAddCancionPlaylist();
	pruebasReproducirPlaylist();
	pruebasCompartirPlaylist();
	pruebasAddPlaylistCompartida();
	pruebasAddArtistaFavorito();
	pruebasBuscarPlaylist();
}

void pruebasConstructoresUsuario(){

	cout << "Inicio de pruebas de Usuario" << endl;

	Usuario* u1;
	u1 = new Usuario();
	u1->setApellidosNombre("Muriel, Pepe");
	if(u1->getApellidosNombre() != "Muriel, Pepe")
		cerr << " * Error con apellidosNombre defecto" << endl;

	u1->setIdUsuario("abcdefghijk");
	if(u1->getIdUsuario() != "abcdefghijk")
		cerr << " * Error con idUsuario defecto" << endl;

	u1->setEmail("muriel@pepe.com");
	if(u1->getEmail() != "muriel@pepe.com")
		cerr << " * Error con email defecto" << endl;

	u1->setContraseña("1234");
	if(u1->getContraseña() != "1234")
		cerr << " * Error con contraseña defecto" << endl;

	Fecha* fecha = new Fecha(1, 2, 3);
	Usuario* u2 = new Usuario("1", "pepe", "hola@a.c", "1234", fecha);
	
	if(u2->getApellidosNombre() != "pepe")
		cerr << " * Error con apellidosNombre" << endl;

	if(u2->getIdUsuario() != "1")
		cerr << " * Error con idUsuario" << endl;

	if(u2->getEmail() != "hola@a.c")
		cerr << " * Error con email" << endl;

	if(u2->getContraseña() != "1234")
		cerr << " * Error con contraseña" << endl;

	cout << "Prueba supervisada:" << endl;
	u2->mostrar();

	delete u1;
	delete u2;
	delete fecha;

	cout << "Fin de pruebas de Usuario" << endl;

}

void pruebasCrearBuscarPlayList(){
	cout << "Iniciando pruebas de CrearPlaylist" << endl;
	
	Usuario* u1 = new Usuario();
	PlayList* p = nullptr;
	u1->crearPlayList("Test1");
	u1->crearPlayList("AndresCoran");
	
	if(!u1->buscarPlaylist("Test1", p))
		cerr << " * Error con la primera playlist" << endl;
	else if(p == nullptr)
		cerr << " * Error con la primera playlist (nula)" << endl;		
	else if(p->getNombre() != "Test1")
		cerr << " * Error con la primera playlist (incorrecta)" << endl;

	p = nullptr;
	if(!u1->buscarPlaylist("AndresCoran", p))
		cerr << " * Error con la segunda playlist" << endl;
	else if(p == nullptr)
		cerr << " * Error con la segunda playlist (nula)" << endl;		
	else if(p->getNombre() != "AndresCoran")
		cerr << " * Error con la segunda playlist (incorrecta)" << endl;

	p = nullptr;
	if(u1->buscarPlaylist("PEPE", p))
		cerr << " * Error con la tercera búsqueda" << endl;
	else if(p != nullptr)
		cerr << " * Error en la tercera búsqueda (no nula)" << endl; 


	cout << "Finalizadas pruebas de CrearPlaylist" << endl;
}

void pruebasAddPlaylistCompartida(){
	cout << "Iniciando pruebas de AddPlaylistCompartida" << endl;

	Usuario* u1 = new Usuario();
	Usuario* u2 = new Usuario();
	PlayList* p1 = nullptr;
	PlayList* p2 = nullptr;
	u1->crearPlayList("Conjunta");
	u2->crearPlayList("Compartida");
	u1->compartirPlaylist("Conjunta", p1);
	u2->compartirPlaylist("Compartida", p2);

	u1->addPlaylistCompartida(p2);
	u2->addPlaylistCompartida(p1);

	if(!u2->buscarPlaylist("Conjunta", p1))
		cerr << " * Error al añadir la primera PlayList compartida" << endl;
	else if(p1 == nullptr)
		cerr << " * Error al añadir la primera PlayList compartida (nula)" << endl;
	cout << "Finalizadas pruebas de AddPlaylistCompartida" << endl;

	if(!u1->buscarPlaylist("Conjunta", p2))
		cerr << " * Error al añadir la tercera PlayList compartida" << endl;
	else if(p2 == nullptr)
		cerr << " * Error al añadir la segunda PlayList compartida (nula)" << endl;
	cout << "Finalizadas pruebas de AddPlaylistCompartida" << endl;

	if(u1->buscarPlaylist("No hay", p2))
		cerr << " * Error al añadir la tercera búsqueda PlayList" << endl;
	else if(p2 != nullptr)
		cerr << " * Error al añadir la tercera PlayList compartida (no nula)" << endl;


	cout << "Finalizadas pruebas de AddPlaylistCompartida" << endl;
}

void pruebasAddArtistaFavorito(){
	cout << "Iniciando pruebas de AddArtistaFavorito" << endl;

	Usuario* u = new Usuario();
	Artista* a1 = new Artista("Leiva", "España", 1000);
	Artista* a2 = new Artista("Melendi", "España", 1000);
	u->addArtistaFavorito(a1);
	u->addArtistaFavorito(a2);

	if(!u->buscarArtistaFavorito("Leiva", a1))
		cerr << " * Error al añadir el primer ArtistaFavorito" << endl;
	else if(a1 == nullptr)
		cerr << " * Error al añadir el primer ArtistaFavorito (nulo)" << endl;

	if(!u->buscarArtistaFavorito("Melendi", a2))
		cerr << " * Error al añadir el segundo ArtistaFavorito" << endl;
	else if(a1 == nullptr)
		cerr << " * Error al añadir el segundo ArtistaFavorito (nulo)" << endl;

	if(u->buscarArtistaFavorito("Robe", a1))
		cerr << " * Error al añadir el tercer ArtistaFavorito" << endl;
	else if(a1 == nullptr)
		cerr << " * Error al añadir el tercer ArtistaFavorito (no nulo)" << endl;

	cout << "Finalizadas pruebas de AddArtistaFavorito" << endl;
}

void pruebasTemplate(){
	cout << "Iniciando pruebas de Template" << endl;
	cout << "Finalizadas pruebas de Template" << endl;
}
