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
		case 1:
			//Mostrar todos los usuarios
			break;
		case 2:
			//Buscar y mostrar un usuario
			break;
		case 3:
			//Mostrar artistas y sus canciones
			break;
		case 4:
			//Buscar y mostrar un artista
			break;
		case 5:
			//Reproducir una playlist de un usuario
			break;
		case 6:
			//Compartir playlist entre dos usuarios
			break;
		case 7:
			//Eliminar playlist de un usuario
			break;
		case 8:
			//Añadir artista a favoritos de un usuario
			break;
		case 9:
			//Eliminar artista de favoritos de un usuario
			break;
		case 10:
			//Artista con más seguidores
			break;
		case 0:
			salir = true;
			break;
		default:
			break;
		}
	}
	// TODO no olvidar el delete al puntero al sistema
	return 0;
}



