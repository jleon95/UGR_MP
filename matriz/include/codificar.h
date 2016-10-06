#include "imagen.h"

#ifndef _CODIFICAR_H_
#define _CODIFICAR_H_

// Oculta en la imagen pasada como primer argumento
// el mensaje pasado como segundo argumento. 
bool ocultar(Imagen &image, const char mensaje[]);

// Revela el mensaje oculto en la imagen pasada como primer
// argumento y lo copia en el vector pasado como segundo
// argumento. El parámetro "maximo" sirve para detectar errores.
bool revelar(Imagen image, char mensaje[], int maximo);

#endif
