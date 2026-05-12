#include "SistemaTest.h"
#include <iostream>

using namespace std;

void pruebasSistema(){
	pruebasConstructoresSistema();

	pruebasCargarDatosSistema();

	pruebasBuscarArtistaSistema();
	pruebasReproducirPlaylistUsuarioSistema();
	pruebasCompartirPlaylistSistema();
	pruebasEliminarPlaylistUsuarioSistema();
	pruebasAddFavoritoSistema();
	pruebasBorrarFavoritoSistema();
	pruebasMayorArtistaSistema();
}

void pruebasConstructoresSistema(){
	cout << "Iniciando pruebas de constructores de Sistema" << endl;

	Sistema* s1;
	Sistema* s2;
	Usuario* u;
	Artista* a;

	s1 = new Sistema();
	s2 = new Sistema(*s1);

	if(s1 == nullptr || s2 == nullptr)
		cerr << " * Error creando sistemas" << endl;

	u = s2->buscarUsuario("Sanchez Mancera, Andres");
	if(u == nullptr)
		cerr << " * Error copiando usuarios en Sistema" << endl;

	a = s2->buscarArtista("Dua Lipa");
	if(a == nullptr)
		cerr << " * Error copiando artistas en Sistema" << endl;

	delete s1;
	delete s2;

	cout << "Finalizadas pruebas de constructores de Sistema" << endl;
}

void pruebasCargarDatosSistema(){
cout << "Iniciando pruebas de carga de datos de Sistema" << endl;

	Sistema* s;
	Usuario* u;
	Artista* a;
	Cancion* c;
	PlayList* p;

	s = new Sistema();
	u = s->buscarUsuario("Madruga Maraver, Angel");
	if(u == nullptr)
		cerr << " * Error cargando usuario desde fichero" << endl;
	else{
		p = nullptr;
		if(!u->buscarPlaylist("Verano", p) || p == nullptr)
			cerr << " * Error cargando playlists desde fichero" << endl;
		else{
			if(p->getCanciones() == 0)
				cerr << " * Error cargando canciones en playlist desde fichero" << endl;
		}
	}

	a = s->buscarArtista("Harry Styles");
	if(a == nullptr)
		cerr << " * Error cargando artista desde fichero" << endl;
	else{
		c = nullptr;
		if(!a->buscarCancion("Adore You", c) || c == nullptr)
			cerr << " * Error cargando canciones desde fichero" << endl;
	}

	delete s;

	cout << "Finalizadas pruebas de carga de datos de Sistema" << endl;
}

void pruebasBuscarUsuarioSistema(){
	cout << "Iniciando pruebas de buscarUsuario de Sistema" << endl;
	
	Sistema* s1;
	s1 = new Sistema();
	
	//DUDA: Debemos devolver una copia o el usuario directo?
	Usuario* busqueda = s1->buscarUsuario("Coronado Perez, Pablo");
	if(busqueda == nullptr)
		cerr << " * Error con la primera búsquea." << endl;
	else if(busqueda->getIdUsuario() != "PabloCa")
		cerr << " * Error con la primera búsqueda. Usuario incorrecto." << endl;

	busqueda = s1->buscarUsuario("Sanchez Mancera, Andres");
	if(busqueda == nullptr)
		cerr << " * Error con la segunda búsquea." << endl;
	else if(busqueda->getIdUsuario() != "AndresS")
		cerr << " * Error con la segunda búsqueda. Usuario incorrecto." << endl;

	busqueda = nullptr;
	busqueda = s1->buscarUsuario("Perikillo");

	if(busqueda != nullptr)
		cerr << " * Error con la tercera búsqueda." << endl;

	delete s1;

	cout << "FinalizadaS pruebas de constructores de Sistema" << endl;
}

//TODO: Añadir más casos
void pruebasBuscarArtistaSistema(){
	cout << "Iniciando pruebas buscarArtista Sistema" << endl;

	Sistema* s = new Sistema();

	Artista* a1 = s->buscarArtista("Rosalía");
	if(a1 == nullptr)
		cerr << "ERROR: Rosalía no encontrada" << endl;

	Artista* a2 = s->buscarArtista("The Beatles");
	if(a2 == nullptr)
		cerr << "ERROR: The Beatles no encontrados" << endl;

	Artista* a3 = s->buscarArtista("FakeArtist");
	if(a3 != nullptr)
		cerr << "ERROR: artista inexistente encontrado" << endl;

	delete s;

	cout << "Finalizadas pruebas buscarArtista Sistema" << endl;
}

//TODO: Esta prueba está mal hecha, esto se va para usuario
void pruebasReproducirPlaylistUsuarioSistema(){
	cout << "Iniciando pruebas de reproducirPlaylistUsuario de Sistema" << endl;

		Sistema* s;
		Usuario* u;
		PlayList* p;
		Cancion* c1;
		Cancion* c2;
		Cancion* c3;

		s = new Sistema();
		u = s->buscarUsuario("Coronado Perez, Pablo");

		if(u == nullptr){
			cerr << " * Error preparando usuario para reproducir playlist" << endl;
			delete s;
			return;
		}

		c1 = new Cancion("Cancion sistema 1", "Pop", 170);
		c2 = new Cancion("Cancion sistema 2", "Rock", 193);
		c3 = new Cancion("Cancion sistema 3", "Trap", 153);

		u->crearPlayList("TestSistema");
		u->addCancionPlaylist("TestSistema", c1);
		u->addCancionPlaylist("TestSistema", c2);
		u->addCancionPlaylist("TestSistema", c3);

		p = nullptr;
		if(!u->buscarPlaylist("TestSistema", p) || p == nullptr)
			cerr << " * Error creando playlist para reproducir" << endl;
		else{
			if(p->getCanciones() != 3)
				cerr << " * Error con el numero de canciones antes de reproducir" << endl;
		}

		cout << "# Prueba supervisada" << endl;

		cout << "# Debería verse:" << endl
				<< "	- Cancion sistema 1. Pop. Duración 170s" << endl
				<< "	- Cancion sistema 2. Pop. Duración 193s" << endl
				<< "	- Cancion sistema 3. Pop. Duración 153s" << endl;

		cout << "Valor: " << endl;
	
		if(!s->reproducirPlaylistUsuario("Coronado Perez, Pablo", "TestSistema"))
			cerr << " * Error reproduciendo una playlist existente" << endl;
	
		if(p != nullptr){
			if(p->getCanciones() != 3)
				cerr << " * Error reproducir modifica la playlist" << endl;
		}

		if(s->reproducirPlaylistUsuario("Usuario Inexistente", "TestSistema"))
			cerr << " * Error reproduciendo una playlist inexistente" << endl;

		delete c1;
		delete c2;
		delete c3;
		delete s;

		cout << "Finalizadas pruebas de reproducirPlaylistUsuario de Sistema" << endl;
	}

void pruebasCompartirPlaylistSistema(){
cout << "Iniciando pruebas de compartirPlaylist de Sistema" << endl;

	Sistema* s;
	Usuario* origen;
	Usuario* destino;
	PlayList* p;
	Cancion* c1;
	Cancion* c2;

	s = new Sistema();
	origen = s->buscarUsuario("Coronado Perez, Pablo");
	destino = s->buscarUsuario("Sanchez Mancera, Andres");

	if(origen == nullptr || destino == nullptr){
		cerr << " * Error preparando usuarios para compartir playlist" << endl;
		delete s;
		return;
	}

	c1 = new Cancion("Compartida 1", "Pop", 100);
	c2 = new Cancion("Compartida 2", "Rock", 200);

	origen->crearPlayList("CompartidaSistema");
	origen->addCancionPlaylist("CompartidaSistema", c1);
	origen->addCancionPlaylist("CompartidaSistema", c2);

	if(!s->compartirPlaylist("Coronado Perez, Pablo", "Sanchez Mancera, Andres", "CompartidaSistema"))
		cerr << " * Error compartiendo una playlist que sí existe" << endl;

	p = nullptr;
	if(!destino->buscarPlaylist("CompartidaSistema", p) || p == nullptr)
		cerr << " * Error compartiendo playlist (1)" << endl;
	else{
		if(p->getCanciones() != 2)
			cerr << " * Error con canciones de playlist compartida" << endl;
		if(p->getDuracion() != 300)
			cerr << " * Error con duracion de playlist compartida" << endl;
	}

	if(s->compartirPlaylist("Usuario Inexistente", "Sanchez Mancera, Andres", "CompartidaSistema"))
		cerr << " * Error compariendo una playlist que no existe (2)" << endl;
	if(s->compartirPlaylist("Coronado Perez, Pablo", "Usuario Inexistente", "CompartidaSistema"))
		cerr << " * Error compariendo una playlist que no existe (3)" << endl;
	if(s->compartirPlaylist("Coronado Perez, Pablo", "Sanchez Mancera, Andres", "Playlist Inexistente"))
		cerr << " * Error compariendo una playlist que no existe (4)" << endl;

	delete c1;
	delete c2;
	delete s;

	cout << "Finalizadas pruebas de compartirPlaylist de Sistema" << endl;
}

void pruebasEliminarPlaylistUsuarioSistema(){
cout << "Iniciando pruebas de eliminarPlaylistUsuario de Sistema" << endl;

	Sistema* s;
	Usuario* u;
	PlayList* p;
	Cancion* c;

	s = new Sistema();
	u = s->buscarUsuario("Coronado Perez, Pablo");

	if(u == nullptr){
		cerr << " * Error preparando usuario para eliminar playlist" << endl;
		delete s;
		return;
	}

	c = new Cancion("Para borrar", "Pop", 50);
	u->crearPlayList("BorrarSistema");
	u->addCancionPlaylist("BorrarSistema", c);

	if(!s->eliminarPlaylistUsuario("Coronado Perez, Pablo", "BorrarSistema"))
		cerr << " * Error elimnando la playlist (1)" << endl;
	else if(u->buscarPlaylist("BorrarSistema", p))
		cerr << " * Error eliminando la playlist (1 persiste)" << endl;

	if(s->eliminarPlaylistUsuario("Usuario Inexistente", "BorrarSistema"))
		cerr << " * Error elimnando la playlist (usuario inexistente)" << endl;

	if(s->eliminarPlaylistUsuario("Coronado Perez, Pablo", "Playlist Inexistente"))
		cerr << " * Error elimnando la playlist (usuario inexistente 2)" << endl;

	delete c;
	delete s;

	cout << "Finalizadas pruebas de eliminarPlaylistUsuario de Sistema" << endl;
}


void pruebasAddFavoritoSistema(){
cout << "Iniciando pruebas de addFavorito de Sistema" << endl;

	Sistema* s;
	Usuario* u;
	Artista* a = nullptr;

	s = new Sistema();
	u = s->buscarUsuario("Coronado Perez, Pablo");

	if(u == nullptr){
		cerr << " * Error preparando usuario para favoritos" << endl;
		delete s;
		return;
	}

	if(!s->addFavorito("Coronado Perez, Pablo", "Dua Lipa"))
		cerr << " * Error añadiendo artista favorito (1)" << endl;
	else if(!u->buscarArtistaFavorito("Dua Lipa", a) || a == nullptr)
		cerr << " * Error anadiendo artista favorito (1 incorrecto)" << endl;

	if(s->addFavorito("Coronado Perez, Pablo", "Artista Inexistente"))
		cerr << " * Error añadiendo artista favorito (inexistente 1)" << endl;

	if(s->addFavorito("Usuario Inexistente", "Dua Lipa"))
		cerr << " * Error añadiendo artista favorito (inexistente 1)" << endl;

	delete s;

	cout << "Finalizadas pruebas de addFavorito de Sistema" << endl;
}



void pruebasBorrarFavoritoSistema(){
cout << "Iniciando pruebas de borrarFavorito de Sistema" << endl;

	Sistema* s;
	Usuario* u;
	Artista* a;

	s = new Sistema();
	u = s->buscarUsuario("Coronado Perez, Pablo");

	if(u == nullptr){
		cerr << " * Error preparando usuario para borrar favorito" << endl;
		delete s;
		return;
	}

	s->addFavorito("Coronado Perez, Pablo", "Dua Lipa");

	if(!s->borrarFavorito("Coronado Perez, Pablo", "Dua Lipa"))
		cerr << " * Error borrando el artista favorito (1)" << endl;

	a = nullptr;
	if(u->buscarArtistaFavorito("Dua Lipa", a) || a != nullptr)
		cerr << " * Error borrando artista favorito" << endl;

	if(s->borrarFavorito("Usuario Inexistente", "Dua Lipa"))
		cerr << " * Error borrando artista favorito (inexistente)" << endl;
	
	if(s->borrarFavorito("Coronado Perez, Pablo", "Artista Inexistente"))
		cerr << " * Error borrando artista favorito (inexistente 2)" << endl;
	
	delete s;

	cout << "Finalizadas pruebas de borrarFavorito de Sistema" << endl;
}

void pruebasMayorArtistaSistema(){
	cout << "Iniciando pruebas de mayorSeguidores de Sistema" << endl;

	Sistema* s;
	s = new Sistema();

	//Caso de prueba con usuarios y artistas del csv
	s->addFavorito("Sanchez Mancera, Andres", "Rosalía");

	Artista* mayor = nullptr;
	mayor = s->buscarMayorArtista();
	if(mayor->getNombre() != "Rosalía")
		cerr << " * Error con el primer mayor" << endl;

	delete s;

	cout << "Finalizadas pruebas de mayorSeguidores de Sistema" << endl;
}


