/*
 * UsuarioTest.h
 *
 *  Created on: 9 feb 2026
 *      Author: usuario
 */

#ifndef USUARIOTEST_H_
#define USUARIOTEST_H_

#include "Usuario.h"

//TODO: Mejorar precondiciones
void pruebasUsuario();

/**
 * DESC={Crea punteros de Usuario para comprobar que la clase guarda bien la información.
 * Primero usa el constructor por defecto y los métodos set y get para los datos básicos
 * como nombre, ID, email y contraseña. Luego prueba el constructor con parámetros
 * usando también un objeto Fecha. Al final muestra los datos por pantalla para
 * revisarlos y borra todos los objetos creados.}
 *
 * COMP={O(1)}
 *
 * PRE={La clase Usuario debe tener sus constructores, métodos get/set y la función mostrar.}
 *
 * POST={Informa si alguno de los datos del usuario no se ha guardado o recuperado
 * correctamente durante las pruebas.}
 */
void pruebasConstructoresUsuario();

//TODO: Mejorar precondiciones
//También mezclar con buscar
void pruebasCrearPlayList();

//TODO: Implementar
//TODO: Mejorar precondiciones
void pruebasAddCancionPlaylist();

//TODO: Implementar
//TODO: Mejorar precondiciones
void pruebasReproducirPlaylist();

//TODO: Implementar
//TODO: Mejorar precondiciones
void pruebasCompartirPlaylist();

//TODO: Implementar
//TODO: Mejorar precondiciones
void pruebasAddPlaylistCompartida();

//TODO: Implementar
//TODO: Mejorar precondiciones
void pruebasAddArtistaFavorito();

//TODO: Implementar
//TODO: Mejorar precondiciones
void pruebasBuscarPlaylist();

#endif /* USUARIOTEST_H_ */
