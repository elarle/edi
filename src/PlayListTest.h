#ifndef PLAYLIST_TEST_H_
#define PLAYLIST_TEST_H_

#include "PlayList.h"

/**
 * DESC={Ejecuta todas las funciones de prueba de la PlayList para verificar que la
 * gestión de canciones y la reproducción funcionan como se espera.}
 *
 * COMP={O(1)}
 *
 * PRE={La clase PlayList debe estar correctamente implementada.}
 *
 * POST={Muestra por consola el resultado de todos los tests de la PlayList.}
 */
void pruebasPlayList();

/**
 * DESC={Crea varios punteros de PlayList para probar los tres constructores. Revisa
 * que una lista nueva empiece vacía, que se pueda cambiar su nombre y que el
 * constructor de copia funcione bien. Al terminar, libera la memoria con delete.}
 *
 * COMP={O(n), siendo n el número de canciones que se copian.}
 *
 * PRE={La clase PlayList debe tener los constructores y los métodos get/set.}
 *
 * POST={Avisa si el nombre, el número de canciones o la duración inicial fallan.}
 */
void pruebaConstructoresPlayList();

/**
 * DESC={Crea una PlayList y varios objetos Canción para probar que se añaden bien.
 * Comprueba que el número total de canciones y la duración de la lista aumentan
 * correctamente y muestra el contenido por pantalla.}
 *
 * COMP={O(1), asumiendo que insertar en la cola es constante.}
 *
 * PRE={Los métodos agregarCancion y getDuracion deben estar programados.}
 *
 * POST={Informa si la duración total o el contador de canciones no coinciden tras
 * añadir los objetos.}
 */
void pruebaAgregarCancion();

/**
 * DESC={Crea una PlayList con canciones y las va borrando una a una. En cada paso
 * comprueba que la duración de la lista y el número de canciones bajan correctamente
 * hasta quedarse vacía.}
 *
 * COMP={O(1)}
 *
 * PRE={El método eliminarCancion debe estar disponible.}
 *
 * POST={Avisa si el cálculo de tiempo o el contador fallan al quitar canciones.}
 */
void pruebaEliminarCancion();

/**
 * DESC={Crea una lista con varias canciones y llama a la función de reproducir.
 * Sirve para ver por consola si las canciones salen en el orden correcto sin
 * perderse ninguna por el camino.}
 *
 * COMP={O(n)}
 *
 * PRE={El método reproducir debe estar implementado.}
 *
 * POST={Permite verificar visualmente que todas las canciones se muestran en orden.}
 */
void pruebaReproducir();

/**
 * DESC={Crea una lista con canciones y prueba la reproducción empezando desde una
 * posición intermedia. Sirve para confirmar que el programa se salta las primeras
 * y muestra correctamente el resto.}
 *
 * COMP={O(n)}
 *
 * PRE={El método reproducirDesde debe estar implementado.}
 *
 * POST={Permite verificar visualmente que la reproducción empieza en el sitio indicado.}
 */
void pruebaReproducirDesde();

#endif /* PLAYLIST_TEST_H_ */
