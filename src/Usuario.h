/*
 * Usuario.h
 *
 *  Created on: 9 feb 2026
 *      Author: usuario
 */

#ifndef USUARIO_H_
#define USUARIO_H_

#include <iostream>
using namespace std;

#include "Fecha.h"

class Usuario {
private:
	string idUsuario;
	string apellidosNombre;
	string email;
	string contraseña;

	Fecha* fecha_nacimiento;

public:
	Usuario();
	Usuario(string id, string nombre, string email, string contraseña);
	Usuario(const Usuario & otro_usuario);
	~Usuario();

	//Setters
	//Todos los setters tienen complejidad O(1).
	void setApellidosNombre(string apellidos_nombre);
	void setIdUsuario(string id);
	void setEmail(string email);
	void setContraseña(string contraseña);

	//TODO: implementar pruebas de esto
	void setFecha(const Fecha & fecha);

	//Getters
	//Todos los getters tienen complejidad O(1).
	string getApellidosNombre() const;
	string getIdUsuario() const;
	string getEmail() const;
	string getContraseña() const;

	void getFecha(Fecha & fecha) const;
	void getFecha(int &dia, int &mes, int &año) const;

	/**
	 * DESC={Muestra a cout el usuario}
	 * COMP={O(?)}
	 */
	void mostrar() const;
	/**
	 * DESC={Pasa el usuario a cadena.}
	 * COMP={O(?)}
	 */
	string pasarACadena() const;

};

#endif /* USUARIO_H_ */
