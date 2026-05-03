/*
 * UsuarioTest.h
 *
 *  Created on: 9 feb 2026
 *      Author: usuario
 */

#ifndef USUARIOTEST_H_
#define USUARIOTEST_H_

#include "Usuario.h"

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

//TODO: Mezclar con buscar
void pruebasCrearPlayList();

void pruebasAddCancionPlaylist();

void pruebasReproducirPlaylist();

void pruebasCompartirPlaylist();

void pruebasAddPlaylistCompartida();

void pruebasAddArtistaFavorito();

void pruebasBuscarPlaylist();

#endif /* USUARIOTEST_H_ */
