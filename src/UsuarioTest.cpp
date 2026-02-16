/*
 * UsuarioTest.cpp
 *
 *  Created on: 9 feb 2026
 *      Author: usuario
 */

#include "UsuarioTest.h"

void pruebasUsuario(){

	cout << "Inicio de pruebas de Usuario" << endl;

	Usuario u1;
	u1.setApellidosNombre("Muriel, Pepe");
	if(u1.getApellidosNombre() != "Muriel, Pepe")
		cout << " * Error con apellidosNombre defecto" << endl;

	u1.setIdUsuario("abcdefghijk");
	if(u1.getIdUsuario() != "abcdefghijk")
		cout << " * Error con idUsuario defecto" << endl;

	u1.setEmail("muriel@pepe.com");
	if(u1.getEmail() != "muriel@pepe.com")
		cout << " * Error con email defecto" << endl;

	u1.setContraseña("1234");
	if(u1.getContraseña() != "1234")
		cout << " * Error con contraseña defecto" << endl;

	Usuario u2 = Usuario("1", "pepe", "hola@a.c", "1234");
	
	if(u2.getApellidosNombre() != "pepe")
		cout << " * Error con apellidosNombre" << endl;

	if(u2.getIdUsuario() != "1")
		cout << " * Error con idUsuario" << endl;

	if(u2.getEmail() != "hola@a.c")
		cout << " * Error con email" << endl;

	if(u2.getContraseña() != "1234")
		cout << " * Error con contraseña" << endl;

	cout << "Prueba supervisada:" << endl;
	u2.mostrar();

	cout << "Fin de pruebas de Usuario" << endl;

}


