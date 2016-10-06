 /*
Metodología de la Programación.
-Curso 2014-2015.
-Grupo D3.
Javier León Palomares.
Juan Manuel Garrido Valenzuela.
*/

#include <string.h>
#include "codificar.h"
#include "imagen.h"
#include "byte.h"

using namespace std;

bool ocultar(Imagen &image, const char mensaje[]){

	bool exito = false;
	int size = strlen(mensaje);

	// Sólo si el tamaño del mensaje en bits ('\0' incluido) cabe en el vector de la imagen. 
	if(8 * (size + 1) < image.columnas() * image.filas()){

		for(int i = 0 ; i <= size ; i++){ // Para cada carácter del mensaje.

			// Cada uno de los 8 bits del carácter (izq. -> der.) se oculta en un byte de la imagen.
			for(int j = 7, escribiendo = 8 * i ; j >= 0 ; j--, escribiendo++){

				byte actual = image.getPos(escribiendo); // Se copia el byte actual de la imagen.

				// La posición 0 del byte actual se pone al mismo valor que el bit a ocultar.
				if(get(mensaje[i], j))

					on(actual, 0);

				else

					off(actual, 0);

				image.setPos(escribiendo, actual); // Se almacena el byte ya modificado.

			}
		}

		exito = true;

	}

	return exito;

}

bool revelar(Imagen image, char mensaje[], int maximo){

	bool exito = true;
	int pos_imagen = 0;
	int pos_mensaje = 0;
	int size = image.filas() * image.columnas();
	byte caracter;

	do{

		// Para cada 8 bits de izquierda a derecha se obtiene un carácter del mensaje.
		for(int bit = 7 ; bit >= 0 && pos_imagen < size ; bit--, pos_imagen++){

			if(get(image.getPos(pos_imagen), 0))

				on(caracter, bit);

			else

				off(caracter, bit);

		}

		// Con 8 bits almacenados en 1 carácter (byte), se guarda éste en el vector del mensaje.
		mensaje[pos_mensaje] = caracter;
		pos_mensaje++;

	}while(caracter != '\0' && pos_mensaje < maximo && pos_imagen < size); // Mientras no se encuentre '\0', 
																		   // no se llene el vector del mensaje
	// Si el último carácter no es '\0', ha habido un error.			   // o no se llegue al final de la imagen.
	if(caracter != '\0') 

		exito = false;

	return exito;

}
