#ifndef ARTISTA_TEST_H_
#define ARTISTA_TEST_H_

#include "Artista.h"

/**
 * DESC={Llama a todas las funciones de prueba de la clase Artista para comprobar que
 * todas funcionen bien.}
 *
 * COMP={O(1)}
 *
 * PRE={La clase Artista tiene que estar terminada.}
 *
 * POST={Muestra por pantalla los fallos si alguna prueba de Artista no sale como debería.}
 */
void pruebasArtista();

/**
 * DESC={Crea varios punteros de Artista para probar los tres tipos de constructores.
 * Primero crea uno vacío y prueba los get y set; luego crea uno con datos de ejemplo y
 * finalmente usa el de copia para ver si los datos se pasan bien de un objeto a otro.
 * Al terminar, borra los objetos con delete para no dejar basura en memoria.}
 *
 * COMP={O(1)}
 *
 * PRE={El código de Artista debe tener los constructores y los métodos get/set.}
 *
 * POST={Avisa por la consola si el nombre, el país o los seguidores no se guardan
 *  o no se leen correctamente.}
 */
void pruebasConstructoresArtista();

/**
 * DESC={Crea dos punteros de Artista para comparar sus nombres usando los operadores.
 * Prueba si el programa detecta bien cuándo dos artistas se llaman igual (==) y cuándo
 * uno va antes que otro por orden alfabético (<). Al acabar, libera la memoria de los
 * dos artistas.}
 *
 * COMP={O(1)}
 *
 * PRE={Los operadores '==' y '<' deben estar programados dentro de la clase Artista.}
 *
 * POST={Informa si el programa se equivoca al comparar o al ordenar los nombres de los artistas.}
 */
void pruebasOperadoresArtista();

void pruebaInsertarBuscarCancion();

#endif /* ARTISTA_TEST_H_ */
