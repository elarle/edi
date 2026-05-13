#ifndef SISTEMA_TEST_H_
#define SISTEMA_TEST_H_

#include "Sistema.h"

/*
 * Ejecuta todas las pruebas del sistema en orden.
 */
void pruebasSistema();

/*
 * Creamos un sistema por defecto y otro con el constructor de copia.
 * Comprobamos que ninguno sea nullptr y que el sistema copiado contenga
 * los mismos usuarios y artistas que el original.
 */
void pruebasConstructoresSistema();

/*
 * Creamos un sistema (carga datos desde CSV).
 * Buscamos un usuario existente y comprobamos que tenga su playlist con canciones.
 * Buscamos un artista existente y comprobamos que tenga sus canciones.
 */
void pruebasCargarDatosSistema();

/*
 * Creamos un sistema y buscamos dos usuarios existentes por nombre.
 * Comprobamos que el ID del usuario devuelto sea el esperado.
 * Buscamos un usuario inexistente y comprobamos que devuelva nullptr.
 */
void pruebasBuscarUsuarioSistema();

/*
 * Creamos un sistema y buscamos dos artistas existentes por nombre.
 * Buscamos un artista inexistente y comprobamos que devuelva nullptr.
 */
void pruebasBuscarArtistaSistema();

/*
 * Creamos un sistema, creamos una playlist con 3 canciones en un usuario
 * y la reproducimos desde el sistema. Comprobamos visualmente que se
 * muestren todas las canciones. Verificamos que la reproducción no modifique
 * el número de canciones de la playlist. Probamos con un usuario inexistente
 * y comprobamos que devuelva false.
 */
void pruebasReproducirPlaylistUsuarioSistema();

/*
 * Creamos un sistema, creamos una playlist con 2 canciones en un usuario
 * y la compartimos con otro usuario. Comprobamos que el destino tenga una
 * copia con el mismo número de canciones y la misma duración. Probamos
 * compartir con usuario origen inexistente, usuario destino inexistente y
 * playlist inexistente; en todos los casos debe devolver false.
 */
void pruebasCompartirPlaylistSistema();

/*
 * Creamos un sistema, creamos una playlist en un usuario y la eliminamos.
 * Comprobamos que ya no exista al buscarla. Probamos eliminar con usuario
 * inexistente y con playlist inexistente; en ambos casos debe devolver false.
 */
void pruebasEliminarPlaylistUsuarioSistema();

/*
 * Creamos un sistema y añadimos un artista existente como favorito de un usuario.
 * Comprobamos que aparezca en su lista de artistas favoritos. Probamos añadir
 * un artista inexistente y usar un usuario inexistente; ambos deben devolver false.
 */
void pruebasAddFavoritoSistema();

/*
 * Creamos un sistema, añadimos un artista favorito a un usuario y luego lo borramos.
 * Comprobamos que ya no aparezca en su lista. Probamos borrar con usuario
 * inexistente y con un artista que no está en favoritos; ambos deben devolver false.
 */
void pruebasBorrarFavoritoSistema();

/*
 * Creamos un sistema, añadimos un artista como favorito de un usuario
 * y comprobamos que buscarMayorArtista devuelva ese artista.
 */
void pruebasMayorArtistaSistema();

#endif /* SISTEMA_TEST_H_ */
