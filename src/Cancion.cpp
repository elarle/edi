/*
 * Cancion.cpp
 *
 *  Created on: 2 mar 2026
 *      Author: estudiante
 */
#include "Cancion.h"

//Constructores
Cancion::Cancion(){
	this->titulo = " ";
	this->genero = " ";
	this->duracion = 0;
};

Cancion::Cancion(string titulo, string genero, int duracion){
	this->titulo = titulo;
	this->genero = genero;
	this->duracion = duracion;
}

Cancion::Cancion(const Cancion & cancion){
	this->titulo = cancion.titulo;
	this->genero = cancion.genero;
	this->duracion = cancion.duracion;
}

Cancion::~Cancion(){
	//En principio no se reserva memoria por lo que el destructor da igual.
}

//Getters
string Cancion::getTitulo() const{
	return this->titulo;
}

string Cancion::getGenero() const{
	return this->genero;
}

int Cancion::getDuracion() const{
	return this->duracion;
}

void Cancion::setTitulo(string titulo){
	this->titulo = titulo;
}

void Cancion::setGenero(string genero){
	this->genero = genero;
}

void Cancion::setDuracion(int duracion){
	this->duracion = duracion;
}

bool Cancion::operator==(const Cancion &cancion) const{
	return  this->titulo == cancion.titulo;
}

bool Cancion::operator<(const Cancion &cancion) const{
	return  this->titulo < cancion.titulo;
}

