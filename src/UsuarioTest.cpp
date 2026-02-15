/*
 * UsuarioTest.cpp
 *
 *  Created on: 9 feb 2026
 *      Author: usuario
 */

#include "UsuarioTest.h"

void pruebasUsuario(){

	Usuario u1;
	u1.setApellidosNombre("Muriel, Pepe");
	if(u1.getApellidosNombre() != "Muriel, Pepe")
		cout << "Error con apellidosNombre" << endl;

	Usuario u2 = Usuario("1", "pepe", "hola@a.c", "1234");

}


