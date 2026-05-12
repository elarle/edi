//============================================================================
// Name        : progPrincipal.cpp
// Author      : Profesores de la asignatura EDI
// Version     : Curso 25/26
// Copyright   :
// Description : Programa principal proyecto EDI
//============================================================================


#include <iostream>
using namespace std;

int menu(string nombreSistema) {
	int opcion;
	do {
		cout << endl<<endl;
		cout << " -------- " << nombreSistema << " --------" << endl <<endl;
		cout << " 1. Mostrar todos los usuarios             " << endl;
		cout << " 2. Buscar y mostrar un usuario            " << endl;
		cout << " 3. Mostrar artistas y sus canciones       " << endl;
		cout << " 4. Buscar y mostrar un artista            " << endl;
		cout << " 5. Reproducir una playlist de un usuario  " << endl;
		cout << " 6. Compartir playlist entre dos usuarios  " << endl;
		cout << " 7. Eliminar playlist de un usuario        " << endl;
		cout << " 8. Añadir artista a favoritos de un usuario" << endl;
		cout << " 9. Eliminar artista de favoritos de un usuario" << endl;
		cout << " 10. Artista con mas seguidores          " << endl;

		cout << " 0. Finalizar. " << endl;
		cout << " Opción: ";
		cout<<"_";
		cin>>opcion;
		cin.ignore();
		cout<<endl;

	} while ((opcion < 0) || (opcion > 11));
	return opcion;
}

#define TESTS
#ifndef TESTS

#include "Sistema.h"
#include "Usuario.h"

int main() {
	// TODO Crear un objeto dinámico de la clase Sistema
	// los datos se cargan automáticamente.
	// TODO no olvidar hacer new al puntero al Sistema
	
	Sistema* sistema = new Sistema(); 

	bool salir = false;
	int opcion;

	while (!salir) {

		opcion = menu("Simulador Spotify");
		switch (opcion) {
		
			//Mostrar todos los usuarios
		case 1:
			sistema->mostrarUsuarios();
			break;

			//Buscar y mostrar un usuario
		case 2:{
			string nombre;
			getline(cin, nombre);
			
			Usuario* usuario = nullptr;
			usuario = sistema->buscarUsuario(nombre);
			if(usuario == nullptr)
				cout << "Usuario no encontrado." << endl;
			else {
				usuario->mostrar();
			}
			break;
		}

		case 3:
			sistema->mostrarArtistas();
			//Mostrar artistas y sus canciones
			break;

			//Buscar y mostrar un artista
		case 4: {
			string nombre;
			getline(cin, nombre);
			
			Artista* artista = nullptr;
			artista = sistema->buscarArtista(nombre);
			if(artista == nullptr)
				cout << "Artista no encontrado." << endl;
			else 
				artista->mostrar();
			
			break;
		}

			//Reproducir una playlist de un usuario
		case 5: {
			string usuario;
			string playlist;

			cout << "Introduzca un usuario: ";
			getline(cin, usuario);
			
			cout << "Introduzca el nombre de la playlist: ";
			getline(cin, playlist);
			
			if(sistema->reproducirPlaylistUsuario(usuario, playlist))
				cout << "Reproduciendo playlist" << endl;
			else 
				cout << "Error al reproducir playlist" << endl;

			break;
		}
			
			//Compartir playlist entre dos usuarios
		case 6: {
			string src;
			string dst;
			string playlist;

			cout << "Introduzca un usuario: ";
			getline(cin, src);
			
			cout << "Introduzca otro usuario: ";
			getline(cin, dst);

			cout << "Introduzca el nombre de la playlist: ";
			getline(cin, playlist);

			sistema->compartirPlaylist(src, dst, playlist);

			break;
		}

			//Eliminar playlist de un usuario
		case 7: {
			string usr;
			string playlist;

			cout << "Introduzca un usuario: ";
			getline(cin, usr);

			cout << "Introduzca el nombre de la playlist: ";
			getline(cin, playlist);

			sistema->eliminarPlaylistUsuario(usr, playlist);
			
			break;
		}

		case 8: {
			//Añadir artista a favoritos de un usuario
			string usuario;
			cout << "Introduzca un usuario: ";
			getline(cin, usuario);
			
			string artista;
			cout << "Introduzca un artista: ";
			getline(cin, artista);
			
			if(sistema->addFavorito(usuario, artista))
				cout << "Añadido artista a favortos" << endl;
			else 
				cout << "No se ha podido añadir";

			break;
		}

			//Eliminar artista de favoritos de un usuario
		case 9:{
			string usuario;
			string artista;

			cout << "Introduzca un usuario: ";
			getline(cin, usuario);
			
			cout << "Introduzca un artista: ";
			getline(cin,artista);

			if(sistema->borrarFavorito(usuario, artista))
				cout << "Artista favorito eliminado" << endl;
			else
				cout << "No se pudo eliminar de favoritos" << endl;

		}
			//Mostrar artista con más seguidores
		case 10: {
			Artista* a = sistema->buscarMayorArtista();
			if(a != nullptr)
				a->mostrar();
			else
				cout << "No hay artistas en el sistema";
			break;
		}
		case 0:
			salir = true;
			break;
		default:
			break;
		}
	}
	// TODO no olvidar el delete al puntero al sistema
	delete sistema;
	return 0;
}

#endif /* TESTS */


