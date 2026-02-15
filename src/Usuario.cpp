/*
 * Usuario.cpp
 *
 *  Created on: 9 feb 2026
 *      Author: usuario
 */

#include "Usuario.h"

Usuario::Usuario() {
	// TODO Auto-generated constructor stub
	this->idUsuario = "";
	this->apellidosNombre = "";
	this->contraseña = "";
	this->email = "";
}

Usuario::Usuario(string id, string nombre, string email, string contraseña) {
	this->idUsuario = id;
	this->apellidosNombre = nombre;
	this->email = email;
	this->contraseña = contraseña;
}

Usuario::~Usuario() {
	// TODO Auto-generated destructor stub
}

void Usuario::setApellidosNombre(string apellidos_nombre) {
	this->apellidosNombre = apellidos_nombre;
}

void Usuario::setIdUsuario(string id) {
	this->idUsuario = id;
}

void Usuario::setEmail(string email) {
	this->email = email;
}

void Usuario::setContraseña(string contraseña) {
	this->contraseña = contraseña;
}


string Usuario::getApellidosNombre() const {
	return this->apellidosNombre;
}

string Usuario::getIdUsuario() const {
	return this->idUsuario;
}

string Usuario::getEmail() const {
	return this->email;
}

string Usuario::getContraseña() const {
	return this->contraseña;
}



void Usuario::mostrar() const {
	cout << this->idUsuario << " " << this->apellidosNombre << endl;
}

string Usuario::pasarACadena() const {
	return this->idUsuario + " " + this->apellidosNombre;
}
