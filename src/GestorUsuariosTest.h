#ifndef GESTOR_USUARIOS_TEST_H_
#define GESTOR_USUARIOS_TEST_H_

#include "GestorUsuarios.h"

/*
 * Ejecuta todas las pruebas del gestor de usuarios en orden.
 */
void pruebasGestorUsuarios();

/*
 * Creamos un gestor vacío y comprobamos que tenga 0 elementos.
 * Creamos un gestor con el constructor de copia y comprobamos
 * que tenga los mismos elementos.
 */
void pruebasConstructoresGestorUsuarios();

/*
 * Creamos un gestor e insertamos varios usuarios con sus datos.
 * Comprobamos que el número de elementos aumente con cada inserción.
 * Mostramos los usuarios por pantalla para revisión visual.
 */
void pruebasInsertarGestorUsuarios();

/*
 * Creamos un gestor con varios usuarios.
 * Buscamos un usuario existente por nombre y comprobamos que lo encuentre.
 * Buscamos un usuario inexistente y comprobamos que no lo encuentre.
 */
void pruebasBuscarGestorUsuarios();

#endif /* GESTOR_USUARIOS_TEST_H_ */
