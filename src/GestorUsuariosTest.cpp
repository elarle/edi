#include "GestorUsuariosTest.h"

void pruebasGestorUsuarios(){
	pruebasConstructoresGestorUsuarios();

	pruebasInsertarGestorUsuarios();
	pruebasBuscarGestorUsuarios();
}

void pruebasConstructoresGestorUsuarios(){
	cout << "Iniciando pruebas de constructres de GestorUsuarios" << endl;

	GestorUsuarios * gu1;
	GestorUsuarios * gu2;

	gu1 = new GestorUsuarios();

	if(gu1->numElementos() != 0)
		cerr << "Error con el número de elementos del gestor (default)" << endl;
	
	gu2 = new GestorUsuarios(*gu1);

	if(gu2->numElementos() != 0)
		cerr << "Error con el número de elementos del gestor (copia)" << endl;

	delete gu1;
	delete gu2;

	cout << "Fin de pruebas de constructres de GestorUsuarios" << endl;
}

void pruebasInsertarGestorUsuarios(){
	cout << "Iniciando pruebas de insertar de GestorUsuarios" << endl;
	
	GestorUsuarios* gu1;
	gu1 = new GestorUsuarios();

	gu1->insertar("1", "Paco", "paco@a.com", "1234");
	gu1->insertar("2", "Paco2", "paco@a.com", "1234");
	gu1->insertar("3", "Paco3", "paco@a.com", "1234");
	
	gu1->mostrar();
	if(gu1->numElementos() != 3)
		cerr << " * Error con el número de elementos al insertar usuario" << endl;

	delete gu1;

	cout << "Fin de pruebas de insertar de GestorUsuarios" << endl;
}

void pruebasBuscarGestorUsuarios(){
	cout << "Iniciando pruebas de buscar de GestorUsuarios" << endl;
	
	GestorUsuarios* gu1;
	Usuario* usuario;
	gu1 = new GestorUsuarios();

	gu1->insertar("1", "Paco", "paco@a.com", "1234");
	gu1->insertar("2", "Paco2", "paco@a.com", "1234");
	gu1->insertar("3", "Paco3", "paco@a.com", "1234");

	if(!gu1->buscar("Paco2", usuario))
		cerr << " * Error con buscando usuario (1)" << endl;

	if(gu1->buscar("Paco4", usuario))
		cerr << " * Error con buscando usuario (2)" << endl;

	cout << "Fin de pruebas de buscar de GestorUsuarios" << endl;
}
