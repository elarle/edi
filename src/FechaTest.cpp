#include<iostream>
using namespace std;

#include"Fecha.h"

void pruebaFecha(){
	cout << "Inicio de las pruebas de Fecha" << endl;

	Fecha * f1;
	f1 = new Fecha();
	f1->setDia(10);

	if(f1->getDia() != 10)
		cout << "Error en el getter/setter de día" << endl;

	delete f1;

	Fecha * f2;
	f2 = new Fecha(1,1,1970);

	if(f2->getDia() != 1)
		cout << "Error en el getter/setter de día (parametrizado)" << endl;
	if(f2->getMes() != 1)
		cout << "Error en el getter/setter de mes (parametrizado)" << endl;
	if(f2->getAño() != 1970)
		cout << "Error en el getter/setter de año (parametrizado)" << endl;
	
	cout << "Prueba supervisada. Debería verse: 1/1/1970. Valor: " << 
		f2->pasarACadena() << endl;

	Fecha * f3;
	f3 = new Fecha(*f2);
	if(f2->getDia() != f3->getDia())
		cout << "Error en la copia de día" << endl;
	if(f2->getMes() != f3->getMes())
		cout << "Error en la copia de mes" << endl;
	if(f2->getAño() != f3->getAño())
		cout << "Error en la copia de año" << endl;

	delete f2;
	delete f3;

	cout << "Fin de las pruebas de Fecha" << endl;
}
