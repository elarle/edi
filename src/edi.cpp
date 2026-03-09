//============================================================================
// Name        : edi.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//#include <iostream>
//using namespace std;

#include "UsuarioTest.h"
#include "FechaTest.h"
#include "ArtistaTest.h"
#include "CancionTest.h"
#include "PlayListTest.h"

#include "archivos.h"

int main() {
	leerFicheroSeleccionarAño(2003);
	pruebaFecha();
	cout << endl;
	pruebasUsuario();
	cout << endl;
	pruebasArtista();
	cout << endl;
	pruebasCancion();
	cout << endl;
	pruebasPlayList();

	return 0;
}
