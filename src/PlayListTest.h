#ifndef PLAYLIST_TEST_H_
#define PLAYLIST_TEST_H_

#include "PlayList.h"

/*
 * Ejecuta todas las pruebas de playlist en orden.
 */
void pruebasPlayList();

/*
 * Creamos varias playlists con los distintos constructores.
 * Comprobamos que una nueva playlist empiece vacía, que se pueda
 * cambiar su nombre y que el constructor de copia funcione bien.
 */
void pruebaConstructoresPlayList();

/*
 * Creamos una playlist y varias canciones.
 * Añadimos las canciones a la playlist y comprobamos que el
 * número de canciones y la duración total aumenten correctamente.
 * Mostramos el contenido por pantalla para revisión visual.
 */
void pruebaAgregarCancion();

/*
 * Creamos una playlist con varias canciones y las vamos eliminando
 * una a una. En cada paso comprobamos que la duración y el número
 * de canciones se actualicen correctamente hasta quedar vacía.
 */
void pruebaEliminarCancion();

/*
 * Creamos una playlist con varias canciones y la reproducimos.
 * Comprobamos visualmente que todas las canciones se muestren
 * en el orden correcto sin perderse ninguna.
 */
void pruebaReproducir();

/*
 * Creamos una playlist con varias canciones y probamos la
 * reproducción desde una posición intermedia. Comprobamos
 * visualmente que se salte las primeras canciones y muestre
 * el resto correctamente.
 */
void pruebaReproducirDesde();

#endif /* PLAYLIST_TEST_H_ */
