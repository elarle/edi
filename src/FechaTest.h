#ifndef FECHATEST_H_
#define FECHATEST_H_

#include "Fecha.h"

/**
 * DESC={Crea punteros de Fecha para verificar que los constructores funcionan. Primero
 * crea uno por defecto y prueba sus set y get; luego crea uno con una fecha específica
 * (1/1/1970) y finalmente usa el de copia para ver si los datos se duplican bien.
 * También muestra la fecha por pantalla para revisarla visualmente y borra los
 * objetos al terminar.}
 *
 * COMP={O(1)}
 *
 * PRE={La clase Fecha debe tener los constructores, los métodos get/set y la función
 * pasarACadena.}
 *
 * POST={Informa si el día, el mes o el año no se guardan correctamente o si la copia falla.}
 */
void pruebaFecha();

#endif /* FECHATEST_H_ */
