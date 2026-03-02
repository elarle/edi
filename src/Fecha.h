/*
 * Fecha.h
 *
 *  Created on: Feb 16, 2026
 *      Author: arbol
 */

#ifndef FECHA_H_
#define FECHA_H_

#include<iostream>
using namespace std;

class Fecha {
private:
	int dia;
	int mes;
	int año;

public:

	//Constructores
	Fecha();
	Fecha(int dia, int mes, int año);
	Fecha(const Fecha &otra_fecha);

	~Fecha();

	//Getters
	//Todos los getters tienen complejidad O(1).
	int getDia() const;
	int getMes() const;
	int getAño() const;

	//Setters
	//Todos los setters tienen complejidad O(1);
	void setDia(int dia);
	void setMes(int mes);
	void setAño(int año);
	
	/**
	 * DESC={Asigna la fecha exacta introducida}
	 * COMP={O(1)}
	 */
	void asignarFecha(int dia, int mes, int año);

	//Métodos
	/**
	 * DESC={Muestra a cout la fecha}
	 * COMP={O(?)}
	 */
	void mostrar() const;
	/**
	 * DESC={Pasa la fecha a cadena.}
	 * COMP={O(?)}
	 */
	string pasarACadena() const;

};

#endif /* FECHA_H_ */

