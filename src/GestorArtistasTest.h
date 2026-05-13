#ifndef GESTOR_ARTISTAS_TEST_H_
#define GESTOR_ARTISTAS_TEST_H_

#include "GestorArtistas.h"

/*
 * Ejecuta todas las pruebas del gestor de artistas en orden.
 */
void pruebasGestorArtistas();

/*
 * Creamos un gestor vacío y comprobamos que tenga 0 elementos.
 * Insertamos un artista y comprobamos que tenga 1 elemento.
 * Creamos un gestor con el constructor de copia y comprobamos
 * que tenga los mismos elementos.
 */
void pruebaConstructoresGestorArtistas();

/*
 * Creamos un gestor con varios artistas.
 * Buscamos los artistas existentes por nombre y comprobamos
 * que los encuentre. Buscamos un artista inexistente y
 * comprobamos que no lo encuentre.
 */
void pruebaBuscarGestorArtistas();

/*
 * Creamos un gestor vacío y comprobamos que numElementos sea 0.
 * Insertamos varios artistas y comprobamos que numElementos aumente.
 * Insertamos un artista duplicado y comprobamos que numElementos
 * no se incremente.
 */
void pruebaNumElementosGestorArtistas();

/*
 * Creamos un gestor e insertamos varios artistas.
 * Buscamos cada artista por nombre y comprobamos que sus datos
 * (país, seguidores) sean los esperados.
 */
void pruebaInsertarGestorArtistas();

/*
 * Creamos un gestor vacío y comprobamos que mayorSeguidores
 * devuelva nullptr. Insertamos varios artistas con distinto
 * número de seguidores y comprobamos que mayorSeguidores
 * devuelva el artista con más seguidores.
 */
void pruebaMayorSeguidores();

#endif /* GESTOR_ARTISTAS_TEST_H_ */
