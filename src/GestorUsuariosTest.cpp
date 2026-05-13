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

	Fecha * fecha = new Fecha(1,2,3);

	gu1->insertar("1", "Paco", "paco@a.com", "1234", fecha);
	gu1->insertar("2", "Paco2", "paco@a.com", "1234", fecha);
	gu1->insertar("3", "Paco3", "paco@a.com", "1234", fecha);
	
	cout << "# Pruebas supervisada" << endl;

	cout << "Debería mostrarse:" << endl
			<< "Usuario{" << endl
			<< "	id: 1" << endl
			<< "	nombre: Paco" << endl
			<< "	fecha: 1/2/3" << endl
			<< "}" << endl
			<< "Usuario{" << endl
			<< "	id: 2" << endl
			<< "	nombre: Paco2" << endl
			<< "	fecha: 1/2/3" << endl
			<< "}" << endl
			<< "Usuario{" << endl
			<< "	id: 3" << endl
			<< "	nombre: Paco3" << endl
			<< "	fecha: 1/2/3" << endl
			<< "}" << endl;

	cout << "Valor:" << endl;

	gu1->mostrar();
	if(gu1->numElementos() != 3)
		cerr << " * Error con el número de elementos al insertar usuario" << endl;

	delete fecha;
	delete gu1;

	cout << "Fin de pruebas de insertar de GestorUsuarios" << endl;
}

void pruebasBuscarGestorUsuarios(){
	cout << "Iniciando pruebas de buscar de GestorUsuarios" << endl;
	
	GestorUsuarios* gu1;
	Usuario* usuario;
	gu1 = new GestorUsuarios();
	

	Fecha * fecha = new Fecha(4,5,6);

	gu1->insertar("1", "Paco", "paco@a.com", "1234", fecha);
	gu1->insertar("2", "Paco2", "paco@a.com", "1234", fecha);
	gu1->insertar("3", "Paco3", "paco@a.com", "1234", fecha);

	if(!gu1->buscar("Paco2", usuario))
		cerr << " * Error con buscando usuario (1)" << endl;

	if(gu1->buscar("Paco4", usuario))
		cerr << " * Error con buscando usuario (2)" << endl;

	delete fecha;

	cout << "Fin de pruebas de buscar de GestorUsuarios" << endl;
}
