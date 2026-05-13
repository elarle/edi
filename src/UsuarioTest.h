/*
 * UsuarioTest.h
 *
 *  Created on: 9 feb 2026
 *      Author: usuario
 */

#ifndef USUARIOTEST_H_
#define USUARIOTEST_H_

#include "Usuario.h"

/*
 * Ejecuta todas las pruebas de usuario en orden.
 */
void pruebasUsuario();

/*
 * Creamos un usuario por defecto y otro con el constructor parametrizado.
 * Probamos los setters y getters de todos los campos (nombre, ID, email, contraseña).
 * Mostramos los datos por pantalla para revisión visual.
 */
void pruebasConstructoresUsuario();

/*
 * Creamos un usuario y le añadimos dos playlists.
 * Buscamos cada una por nombre y comprobamos que el nombre coincida.
 * Buscamos una playlist que no existe y comprobamos que no la encuentre.
 */
void pruebasCrearBuscarPlayList();

/*
 * Creamos un usuario, creamos una playlist y le añadimos una canción.
 * Reproducimos la playlist para comprobar visualmente que la canción aparece.
 */
void pruebasAddCancionPlaylist();

/*
 * Creamos un usuario, creamos una playlist y le añadimos tres canciones.
 * Reproducimos la playlist para comprobar visualmente que todas aparecen
 * en el orden correcto.
 */
void pruebasReproducirPlaylist();

/*
 * Creamos un usuario con una playlist y la compartimos.
 * Comprobamos que el puntero devuelto no sea nulo y tenga el nombre correcto.
 * Añadimos una canción a la playlist original y comprobamos que la playlist
 * compartida no se modifique (es una copia independiente).
 */
void pruebasCompartirPlaylist();

/*
 * Creamos dos usuarios, cada uno con una playlist.
 * Compartimos la playlist del primero con el segundo y viceversa.
 * Comprobamos que cada uno pueda buscar la playlist que recibió.
 * Buscamos una playlist que no se ha compartido y comprobamos que no la encuentre.
 */
void pruebasAddPlaylistCompartida();

/*
 * Creamos un usuario y le añadimos dos artistas como favoritos.
 * Buscamos cada artista por nombre y comprobamos que los encuentre.
 * Buscamos un artista que no está en favoritos y comprobamos que no lo encuentre.
 */
void pruebasAddArtistaFavorito();

#endif /* USUARIOTEST_H_ */
