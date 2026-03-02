/*
 * Usuario.cpp
 *
 *  Created on: 9 feb 2026
 *      Author: usuario
 */

#include "Usuario.h"

//Constructores
Usuario::Usuario() {
	// TODO Auto-generated constructor stub
	this->idUsuario = "";
	this->apellidosNombre = "";
	this->contraseña = "";
	this->email = "";

	this->fecha_nacimiento = new Fecha();
}

Usuario::Usuario(string id, string nombre, string email, string contraseña) {
	this->idUsuario = id;
	this->apellidosNombre = nombre;
	this->email = email;
	this->contraseña = contraseña;

	this->fecha_nacimiento = new Fecha();
}

Usuario::Usuario(const Usuario & otro_usuario){
	this->idUsuario = otro_usuario.idUsuario;
	this->apellidosNombre = otro_usuario.apellidosNombre;
	this->email = otro_usuario.email;
	this->contraseña = otro_usuario.contraseña;

	this->fecha_nacimiento = new Fecha(*otro_usuario.fecha_nacimiento);
}

Usuario::~Usuario() {
	delete this->fecha_nacimiento;
}

//Setters
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

void Usuario::setFecha(const Fecha & fecha) {
	this->fecha_nacimiento->asignarFecha(
		fecha.getDia(), 
		fecha.getMes(), 
		fecha.getAño()
	);
}

//Getters
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

void Usuario::getFecha(Fecha & fecha) const{
	fecha.setDia(this->fecha_nacimiento->getDia());
	fecha.setMes(this->fecha_nacimiento->getMes());
	fecha.setAño(this->fecha_nacimiento->getAño());
}
void Usuario::getFecha(int &dia, int &mes, int &año) const{
	dia = (this->fecha_nacimiento->getDia());
	mes = (this->fecha_nacimiento->getMes());
	año = (this->fecha_nacimiento->getAño());
}

//Métodos
void Usuario::mostrar() const {
	cout << "Usuario{" << endl;
	cout << "\tid: " << this->idUsuario << endl;
	cout << "\tnombre: " << this->apellidosNombre << endl;
	cout << "\tfecha: " << this->fecha_nacimiento->pasarACadena() << endl;
	cout << "}" << endl;
}

string Usuario::pasarACadena() const {
	return this->idUsuario + " " + this->apellidosNombre;
}
