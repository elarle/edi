/*
 * Fecha.cpp
 *
 *  Created on: Feb 16, 2026
 *      Author: arbol
 */

#include "Fecha.h"

Fecha::Fecha() {
	this->dia = 0;
	this->mes = 0;
	this->año = 0;
}

Fecha::Fecha(int dia, int mes, int año){
	this->dia = dia;
	this->mes = mes;
	this->año = año;
}

Fecha::Fecha(const Fecha &otra_fecha){
	this->dia = otra_fecha.dia;
	this->mes = otra_fecha.mes;
	this->año = otra_fecha.año;
}

Fecha::~Fecha() {
	// TODO Auto-generated destructor stub
}

//Getters
int Fecha::getDia() const{
	return this->dia;
}

int Fecha::getMes() const{
	return this->mes;
}

int Fecha::getAño() const{
	return this->año;
}

//Setters
void Fecha::setDia(int dia){
	this->dia = dia;
};

void Fecha::setMes(int mes){
	this->mes = mes;
}

void Fecha::setAño(int año){
	this->año = año;
}

void Fecha::asignarFecha(int dia, int mes, int año){
	this->dia = dia;
	this->mes = mes;
	this->año = año;
}

//Métodos
void Fecha::mostrar() const{
	cout << this->pasarACadena() << endl;
}

string Fecha::pasarACadena() const{
	return to_string(this->dia) + "/" + 
			 to_string(this->mes) + "/" + 
			 to_string(this->año);
}


