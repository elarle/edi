//============================================================================
// Name        : progPrincipal.cpp
// Author      : Profesores de la asignatura EDI
// Version     : Curso 25/26
// Copyright   :
// Description : Programa principal proyecto EDI
//============================================================================


#include <iostream>
using namespace std;

#include "Sistema.h"
#include "Usuario.h"

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

		case 5: {
			//Reproducir una playlist de un usuario
			string linea;
			cout << "Introduzca un usuario: ";
			getline(cin, linea);
			
			Usuario* usuario = nullptr;
			PlayList* playlist = nullptr;
			
			usuario = sistema->buscarUsuario(linea);
			if(usuario == nullptr)
				cout << "Usuario no encontrado." << endl;
			else {

				cout << "Introduzca el nombre de la playlist: ";
				getline(cin, linea);
				if(usuario->buscarPlaylist(linea, playlist)){
					cout << "Reproduciendo playlist: " << endl;
					playlist->reproducir();
				} else {
					cout << "Playlist no encontrada" << endl;
				};
			}

			break;
		}
			
		//Compartir playlist entre dos usuarios
		case 6: {
			string linea;
			cout << "Introduzca un usuario: ";
			getline(cin, linea);
			
			Usuario* src = nullptr;
			Usuario* dst = nullptr;
			PlayList* playlist = nullptr;
			
			src = sistema->buscarUsuario(linea);
			if(src== nullptr)
				cout << "Usuario no encontrado." << endl;
			else {
				cout << "Introduzca otro usuario: ";
				getline(cin, linea);
				dst = sistema->buscarUsuario(linea);
				if(dst==nullptr)
					cout << "Usuario no encontrado." << endl;
				else {
					cout << "Introduzca el nombre de la playlist: ";
					getline(cin, linea);
					if(src->buscarPlaylist(linea, playlist)){
						dst->addPlaylistCompartida(playlist);
						cout << "Playlist copiada" << endl;
					} else {
						cout << "Playlist no encontrada" << endl;
					};

				}
			}
			break;
		}

			//Eliminar playlist de un usuario
		case 7: {
			string linea;
			cout << "Introduzca un usuario: ";
			getline(cin, linea);
			
			Usuario* usr = nullptr;
			PlayList* playlist = nullptr;
			
			usr = sistema->buscarUsuario(linea);
			if(usr== nullptr)
				cout << "Usuario no encontrado." << endl;
			else {
				cout << "Introduzca el nombre de la playlist: ";
				getline(cin, linea);
				if(usr->buscarPlaylist(linea, playlist)){
					usr->eliminarPlayList(linea);
					cout << "Playlist eliminada" << endl;
				} else {
					cout << "Playlist no encontrada" << endl;
				};
			}
			break;
		}

		case 8: {
			//Añadir artista a favoritos de un usuario
			string linea;
			cout << "Introduzca un usuario: ";
			getline(cin, linea);
			
			Usuario* usr = nullptr;
			Artista* artista = nullptr;
			
			usr = sistema->buscarUsuario(linea);
			if(usr== nullptr)
				cout << "Usuario no encontrado." << endl;
			else {
				cout << "Introduzca el nombre del artista: ";
				getline(cin, linea);
				artista = sistema->buscarArtista(linea);
				if(artista == nullptr){
					cout << "Artista no encontrado" << endl;
				} else {
					usr->addArtistaFavorito(artista);
					cout << "Artista añadido a favoritos" << endl;
				};
			}
			break;
		}

			//Eliminar artista de favoritos de un usuario
		case 9:{
			//Añadir artista a favoritos de un usuario
			string linea;
			cout << "Introduzca un usuario: ";
			getline(cin, linea);
			
			Usuario* usr = nullptr;
			Artista* artista = nullptr;
			
			usr = sistema->buscarUsuario(linea);
			if(usr== nullptr)
				cout << "Usuario no encontrado." << endl;
			else {
				cout << "Introduzca el nombre del artista: ";
				getline(cin, linea);
				artista = sistema->buscarArtista(linea);
				if(artista == nullptr){
					cout << "Artista no encontrado" << endl;
				} else {
					usr->borrarArtistaFavorito(linea);
					cout << "Artista eliminado" << endl;
				};
			}
			break;
		}

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


