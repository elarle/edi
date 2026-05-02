#ifndef GESTOR_USUARIOS_TEST_H_
#define GESTOR_USUARIOS_TEST_H_

#include "GestorUsuarios.h"

/**
 * DESC={Ejecuta todas las funciones de prueba del Gestor de Usuarios para asegurar
 * que la gestión de la lista de usuarios funciona correctamente.}
 *
 * COMP={O(1)}
 *
 * PRE={La clase GestorUsuarios debe estar implementada y accesible.}
 *
 * POST={Muestra por consola el inicio y el fin de las pruebas generales de usuarios.}
 */
void pruebasGestorUsuarios();

/**
 * DESC={Crea punteros de GestorUsuarios para verificar los constructores. Prueba
 * que un gestor nuevo empiece con cero elementos y que el constructor de copia
 * cree un gestor idéntico al original. Al terminar, libera la memoria con delete.}
 *
 * COMP={O(n)}
 *
 * PRE={La clase GestorUsuarios debe tener constructor por defecto, de copia y
 * el método numElementos.}
 *
 * POST={Avisa si el número de usuarios en el gestor no es correcto al crear o copiar.}
 */
void pruebasConstructoresGestorUsuarios();

/**
 * DESC={Crea un gestor e inserta varios usuarios de prueba usando una fecha de
 * nacimiento común. Comprueba que el contador de elementos aumenta correctamente
 * con cada inserción y muestra los usuarios por pantalla. Finalmente borra la
 * fecha y el gestor.}
 *
 * COMP={O(n)}
 *
 * PRE={El método insertar y numElementos deben estar disponibles en GestorUsuarios.}
 *
 * POST={Informa si el gestor no tiene los 3 usuarios que se han intentado insertar.}
 */
void pruebasInsertarGestorUsuarios();

/**
 * DESC={Crea un gestor con varios usuarios y utiliza un puntero de tipo Usuario
 * para buscarlos por su nombre. Verifica que el programa encuentre a los usuarios
 * que existen y que no se equivoque al buscar nombres que no están en la lista.}
 *
 * COMP={O(n)}
 *
 * PRE={El método buscar de GestorUsuarios debe estar programado.}
 *
 * POST={Informa mediante un error si la búsqueda de un usuario falla o si encuentra
 * a alguien que no existe.}
 */
void pruebasBuscarGestorUsuarios();

#endif /* GESTOR_USUARIOS_TEST_H_ */
