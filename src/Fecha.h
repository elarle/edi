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
	int getDia() const;
	int getMes() const;
	int getAño() const;

	//Setters
	void setDia(int dia);
	void setMes(int mes);
	void setAño(int año);

	void asignarFecha(int dia, int mes, int año);

	//Métodos
	void mostrar() const;
	string pasarACadena() const;

};

#endif /* FECHA_H_ */

