/*
 * UsuarioTest.cpp
 *
 *  Created on: 9 feb 2026
 *      Author: usuario
 */

#include "UsuarioTest.h"

void pruebasUsuario(){
	pruebasConstructoresUsuario();
	pruebasCrearBuscarPlayList();
	pruebasAddCancionPlaylist();
	pruebasReproducirPlaylist();
	pruebasCompartirPlaylist();
	pruebasAddPlaylistCompartida();
	pruebasAddArtistaFavorito();
}

void pruebasConstructoresUsuario(){

	cout << "Inicio de pruebas de constructores de Usuario" << endl;

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
	u1->setFecha(fecha);
	Fecha* fecha_test = new Fecha();
	u1->getFecha(*fecha_test);
	if(fecha_test->getAño() != 3 || fecha_test->getMes() != 2 || fecha_test->getDia() != 1)
		cerr << " * Error con la fecha" << endl;

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

	cout << "Fin de pruebas de constructores de Usuario" << endl;

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

	PlayList* p = nullptr;
	
	u1->crearPlayList("Compartida");
	u2->crearPlayList("Conjunta");

	u1->compartirPlaylist("Compartida", p);
	u2->addPlaylistCompartida(p);
	delete p; //Compartir nos devuelve una copia y addPlaylist hace otra copia.
	p = nullptr;

	if(!u2->buscarPlaylist("Compartida", p))
		cerr << " * Error al añadir la primera PlayList compartida" << endl;
	else if(p == nullptr)
		cerr << " * Error al añadir la primera PlayList compartida (nula)" << endl;
	
	u2->compartirPlaylist("Conjunta", p);
	u1->addPlaylistCompartida(p);
	delete p; //Compartir nos devuelve una copia y addPlaylist hace otra copia.
	p = nullptr;

	if(!u1->buscarPlaylist("Conjunta", p))
		cerr << " * Error al añadir la tercera PlayList compartida" << endl;
	else if(p == nullptr)
		cerr << " * Error al añadir la segunda PlayList compartida (nula)" << endl;

	p = nullptr;
	if(u1->buscarPlaylist("No hay", p))
		cerr << " * Error al añadir la tercera búsqueda PlayList" << endl;
	else if(p != nullptr)
		cerr << " * Error al añadir la tercera PlayList compartida (no nula)" << endl;


	cout << "Finalizadas pruebas de AddPlaylistCompartida" << endl;
}

void pruebasAddArtistaFavorito(){
	cout << "Iniciando pruebas de AddArtistaFavorito" << endl;

	Usuario* u = new Usuario();
	Artista* a = new Artista("Leiva", "España", 1000);
	Artista* a2 = new Artista("Melendi", "España", 1000);
	u->addArtistaFavorito(a);
	u->addArtistaFavorito(a2);

	a = nullptr;
	if(!u->buscarArtistaFavorito("Leiva", a))
		cerr << " * Error al añadir el primer ArtistaFavorito" << endl;
	else if(a == nullptr)
		cerr << " * Error al añadir el primer ArtistaFavorito (nulo)" << endl;

	a = nullptr;
	if(!u->buscarArtistaFavorito("Melendi", a))
		cerr << " * Error al añadir el segundo ArtistaFavorito" << endl;
	else if(a == nullptr)
		cerr << " * Error al añadir el segundo ArtistaFavorito (nulo)" << endl;

	a = nullptr;
	if(u->buscarArtistaFavorito("Robe", a))
		cerr << " * Error al añadir el tercer ArtistaFavorito" << endl;
	else if(a != nullptr)
		cerr << " * Error al añadir el tercer ArtistaFavorito (no nulo)" << endl;

	cout << "Finalizadas pruebas de AddArtistaFavorito" << endl;
}

void pruebasAddCancionPlaylist(){
	cout << "Iniciando pruebas de AddCancionPlaylist (Prueba Supervisada)" << endl;

	Usuario* u = new Usuario();
	Cancion* c = new Cancion("Dame", "Veneno", 33);

	u->crearPlayList("test");
	u->addCancionPlaylist("test", c);

	cout << "Debería mostrarse: " << endl
			<< "	- Dame. Veneno. Duración: 33s" << endl
			<< "Valor: " << endl;
	u->reproducirPlayList("test");

	delete u;
	delete c;

	cout << "Finalizadas pruebas de AddCancionPlaylist" << endl;
}

void pruebasReproducirPlaylist(){
	cout << "Iniciando pruebas de ReproducirPlaylist" << endl;

	Usuario* u = new Usuario();
	Cancion* c = new Cancion("Dame", "Veneno", 33);
	Cancion* c2 = new Cancion("Dame2", "Veneno2", 34);
	Cancion* c3 = new Cancion("Dame3", "Veneno3", 35);

	u->crearPlayList("test");
	u->addCancionPlaylist("test", c);
	u->addCancionPlaylist("test", c2);
	u->addCancionPlaylist("test", c3);

	cout << "Debería mostrarse: " <<endl
			<<"	- Dame. Veneno. Duración: 33s" << endl
			<<"	- Dame2. Veneno2. Duración: 34s" << endl
			<<"	- Dame3. Veneno3. Duración: 35s" << endl
			<<"Valor: " << endl;
	if(u->reproducirPlayList("test"));

	else
		cout << "Error al reproducir Playlist" << endl;

	delete u;
	delete c;
	delete c2;
	delete c3;

	cout << "Finalizadas pruebas de ReproducirPlaylist" << endl;
}

void pruebasCompartirPlaylist(){
	cout << "Iniciando pruebas de compartirPlaylist" << endl;

	Usuario* u = new Usuario();
	PlayList* p = nullptr;
	Cancion* c = new Cancion("Dame", "Veneno", 33);
	u->crearPlayList("test");

	u->compartirPlaylist("test", p);
	if(p == nullptr)
		cerr << " * Error con el primer compartido." << endl;
	else if(p->getNombre() != "test")
		cerr << " * Error con el primer compartido (incorrecta)." << endl;

	//Comprobar que sea el puntero exacto a la misma canción
	u->addCancionPlaylist("test", c);
	if(p->getCanciones() != 0)
		cerr << " * Error con el primer compartido (incorrecta 2)." << endl;

	delete p;
	delete u;
	delete c;

	cout << "Finalizadas pruebas de  compartirPlaylist" << endl;
}

