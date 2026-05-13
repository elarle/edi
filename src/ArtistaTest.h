#ifndef ARTISTA_TEST_H_
#define ARTISTA_TEST_H_

#include "Artista.h"

/*
 * Ejecuta todas las pruebas de artista en orden.
 */
void pruebasArtista();

/*
 * Creamos un artista por defecto y probamos sus setters y getters.
 * Creamos un artista con el constructor parametrizado y comprobamos
 * que los datos sean correctos. Creamos un artista con el constructor
 * de copia y verificamos que los datos se dupliquen bien.
 */
void pruebasConstructoresArtista();

/*
 * Creamos dos artistas con nombres distintos y comprobamos que
 * el operador == detecte que son diferentes. Cambiamos un nombre
 * para que coincidan y comprobamos que ahora sean iguales.
 * Probamos el operador < con distintos nombres para verificar
 * el orden alfabético.
 */
void pruebasOperadoresArtista();

/*
 * Creamos un artista e insertamos varias canciones.
 * Las buscamos una a una por título para comprobar que se encuentren.
 * Probamos el constructor de copia del artista y verificamos que
 * las canciones también se copien correctamente.
 */
void pruebasInsertarBuscarCancion();

/*
 * Creamos un artista con un número inicial de seguidores.
 * Añadimos seguidores y comprobamos que el contador se incremente
 * correctamente en cada paso.
 */
void pruebasAddSeguidor();

/*
 * Creamos un artista con un número inicial de seguidores.
 * Eliminamos seguidores y comprobamos que el contador se decremente
 * correctamente en cada paso.
 */
void pruebasDelSeguidor();

#endif /* ARTISTA_TEST_H_ */
