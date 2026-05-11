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

void pruebasCrearPlayList(){
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

void pruebasAddCancionPlaylist(){
	cout << "Iniciando pruebas de AddCancionPlaylist" << endl;
	cout << "Finalizadas pruebas de AddCancionPlaylist" << endl;
}

void pruebasTemplate(){
	cout << "Iniciando pruebas de Template" << endl;
	cout << "Finalizadas pruebas de Template" << endl;
}
