/*
 * CanciónTest.h
 *
 *  Created on: 2 mar 2026
 *      Author: estudiante
 */

#ifndef CANCIÓNTEST_H_
#define CANCIÓNTEST_H_
#include "Cancion.h"

/*
 * Ejecuta todas las pruebas de canción en orden.
 */
void pruebasCancion();

/*
 * Creamos una canción por defecto y probamos los setters y getters.
 * Creamos una canción con el constructor parametrizado y comprobamos
 * que el título, género y duración sean correctos. Probamos el
 * constructor de copia y verificamos que los datos se dupliquen bien.
 */
void pruebasConstrucoresCancion();

/*
 * Creamos dos canciones con títulos distintos y comprobamos que
 * el operador == detecte que son diferentes. Cambiamos un título
 * para que coincida y comprobamos que ahora sean iguales.
 * Probamos el operador < para verificar el orden alfabético.
 */
void pruebasOperadoresCancion();

#endif /* CANCIÓNTEST_H_ */
