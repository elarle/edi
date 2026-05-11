#ifndef GESTOR_ARTISTAS_TEST_H_
#define GESTOR_ARTISTAS_TEST_H_

#include "GestorArtistas.h"

/**
 * DESC={Ejecuta de forma ordenada todas las funciones de prueba del Gestor de Artistas
 * para verificar que la estructura funciona correctamente.}
 *
 * COMP={O(1)}
 *
 * PRE={La clase GestorArtistas debe estar bien implementada y lista para usarse.}
 *
 * POST={Muestra por consola el progreso de las pruebas y avisa si alguna falla.}
 */
void pruebasGestorArtistas();

/**
 * DESC={Crea punteros de GestorArtistas para probar los constructores. Verifica que
 * un gestor nuevo esté vacío y que el constructor de copia duplique bien la
 * información de un gestor a otro. Al final borra los objetos para liberar memoria.}
 *
 * COMP={O(n)}
 *
 * PRE={La clase GestorArtistas debe tener constructor por defecto, de copia y
 * el método numElementos.}
 *
 * POST={Informa si el número de artistas en el gestor no es el que debería ser.}
 */
void pruebaConstructoresGestorArtistas();

/**
 * DESC={Crea un gestor, inserta varios artistas y usa un puntero de tipo Artista
 * para intentar encontrarlos por su nombre. Prueba casos donde el artista existe
 * y casos donde no para asegurar que la búsqueda es fiable. Al acabar libera
 * la memoria del gestor.}
 *
 * COMP={O(n)}
 *
 * PRE={El método buscar de GestorArtistas debe estar programado.}
 *
 * POST={Avisa si el gestor no encuentra a un artista que sí está o si devuelve
 * datos cuando no debería.}
 */
void pruebaBuscarGestorArtistas();

/**
 * DESC={Crea un gestor y comprueba que el contador de artistas funciona bien al
 * estar vacío, al añadir varios artistas distintos y al intentar añadir uno
 * que ya existe (duplicado), verificando que no se cuente dos veces.}
 *
 * COMP={O(1)}
 *
 * PRE={El método numElementos e insertar deben estar disponibles.}
 *
 * POST={Informa si el conteo de artistas en el gestor es incorrecto.}
 */
void pruebaNumElementosGestorArtistas();

/**
 * DESC={Crea un gestor e inserta varios artistas para comprobar que los datos
 * (nombre, país y seguidores) se guardan correctamente. Utiliza la función
 * buscar para sacar el artista y revisar sus atributos uno por uno.}
 *
 * COMP={O(n)}
 *
 * PRE={Los métodos insertar y buscar deben funcionar correctamente.}
 *
 * POST={Avisa si los datos recuperados del artista no coinciden con los que
 * se insertaron al principio.}
 */
void pruebaInsertarGestorArtistas();

/**
 * DESC={}
 * COMP={}
 * PRE={}
 * POST={}
 */
void pruebaMayorSeguidores();

#endif /* GESTOR_ARTISTAS_TEST_H_ */
