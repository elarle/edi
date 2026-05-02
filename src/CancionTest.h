/*
 * CanciónTest.h
 *
 *  Created on: 2 mar 2026
 *      Author: estudiante
 */

#ifndef CANCIÓNTEST_H_
#define CANCIÓNTEST_H_
#include "Cancion.h"
/**
 * DESC={Ejecuta el conjunto completo de pruebas para la clase Canción, llamando primero
 * a las pruebas de los constructores y después a las de los operadores.}
 *
 * COMP={O(1)}
 *
 * PRE={La clase Canción debe estar disponible y bien programada.}
 *
 * POST={Muestra por pantalla si el objeto Canción pasa los tests o si hay algún error.}
 */
void pruebasCancion();

/**
 * DESC={Crea punteros de Canción para comprobar que los tres constructores funcionan.
 * Primero prueba el constructor vacío usando los set y get; luego prueba el constructor
 * con datos y por último el de copia para ver si los datos se duplican bien. Al final
 * libera la memoria con delete.}
 *
 * COMP={O(1)}
 *
 * PRE={La clase Canción debe tener los tres tipos de constructores y sus métodos get y set.}
 *
 * POST={Avisa por consola si el título, género o duración no coinciden con lo esperado.}
 */
void pruebasConstrucoresCancion();

/**
 * DESC={Crea dos punteros de Canción para comparar sus títulos usando los operadores.
 * Prueba si el programa detecta bien cuándo dos canciones se llaman igual (==) y cuándo
 * una va antes que otra por orden alfabético (<). Al acabar, libera la memoria de los
 * dos objetos.}
 *
 * COMP={O(1)}
 *
 * PRE={Los operadores '==' y '<' deben estar programados dentro de la clase Canción.}
 *
 * POST={Informa si el programa se equivoca al comparar o al ordenar los títulos de las canciones.}
 */
void pruebasOperadoresCancion();

#endif /* CANCIÓNTEST_H_ */
