/*
Metodología de la Programación.
-Curso 2014-2015.
-Grupo D3.
Javier León Palomares.
Juan Manuel Garrido Valenzuela.
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include "codificar.h"
#include "imagen.h"

using namespace std;

int main(){

	const int MAXNOMBRE = 100;
	const int MAXTAM = 125;
	char nombre_entrada[MAXNOMBRE], nombre_salida[MAXNOMBRE];
	char mensaje[MAXTAM], sentido;
	Imagen image, image2, image3;
	int opcion, grados;

	do{

		// Menú.
		cout << "\n1 - Ocultar";
		cout << "\n2 - Revelar";
		cout << "\n3 - Rotar";
		cout << "\n4 - Concatenar";
		cout << "\n5 - Salir\n";

		// Filtro de opciones.
		do{

			cout << "\nSeleccione una opción: ";
			cin >> opcion;
			cin.ignore();

		}while(opcion < 1 || opcion > 5);

		switch(opcion){

			// Ocultar mensaje.
			case 1: cout << "\nIntroduzca la imagen de entrada: ";
					cin.getline(nombre_entrada, MAXNOMBRE);

					// Cargar el archivo en la imagen.
					if(!image.leerImagen(nombre_entrada)){

						cout << "\nError al leer la imagen de entrada.\n";
						return 1;

					}

					cout << "\nIntroduzca la imagen de salida: ";
					cin.getline(nombre_salida, MAXNOMBRE);
					cout << "\nIntroduzca el mensaje: ";
					cin.getline(mensaje, MAXTAM);

					// Ocultar el mensaje en la imagen.
					if (!ocultar(image, mensaje)){
		
						cout << "\nError: El mensaje es demasiado largo para ocultarlo en la imagen.\n";
						return 1;

					}

					cout << "\nOcultando...";

					// Guardar la imagen en el archivo.
					if(!image.escribirImagen(nombre_salida)){

						cout << "\nError al escribir la imagen de salida.\n";
						return 1;

					}

					break;

			// Revelar mensaje.
			case 2: cout << "\nIntroduzca la imagen de entrada: ";
					cin.getline(nombre_entrada, MAXNOMBRE);

					// Cargar el archivo en la imagen.
					if(!image.leerImagen(nombre_entrada)){

						cout << "\nError al leer la imagen de entrada.\n";
						return 1;

					}

					// Revelar el mensaje oculto.
					if (!revelar(image, mensaje, MAXTAM)){
		
						cout << "\nError: La imagen no contiene un mensaje o el mensaje es demasiado largo.\n";
						return 1;

					}

					// Imprimir el mensaje por pantalla.
					cout << "\nEl mensaje obtenido es: ";

					for (int i = 0 ; i <= strlen(mensaje) ; i++)
		
						cout << mensaje[i];

					cout << "\n";

					break;

			// Rotar imagen.
			case 3: cout << "\nIntroduzca la imagen de entrada: ";
					cin.getline(nombre_entrada, MAXNOMBRE);

					// Cargar el archivo en la imagen.
					if(!image.leerImagen(nombre_entrada)){

						cout << "\nError al leer la imagen de entrada.\n";
						return 1;

					}

					cout << "\nIntroduzca la imagen de salida: ";
					cin.getline(nombre_salida, MAXNOMBRE);

					cout << "\nIntroduzca los grados de rotación (90, 180 ó 270): ";
					cin >> grados;
					cout << "\n¿En sentido horario (Y/N)?: ";
					cin >> sentido;

					// Rotar según los parámetros obtenidos.
					if(toupper(sentido) == 'Y')

						image.rotacion(grados,true);

					else if(toupper(sentido) == 'N')

						image.rotacion(grados, false);

					else

						cout << "\nNo ha introducido un sentido válido.";

					// Guardar la imagen en el archivo.
					if(!image.escribirImagen(nombre_salida)){

						cout << "\nError al escribir la imagen de salida.\n";
						return 1;

					}

					// Imprimir el mensaje por pantalla.
					cout << "\nRotación completada.";
					cout << "\n";

					break;

			// Concatenar dos imágenes.
			case 4: cout << "\nIntroduzca la primera imagen de entrada: ";
					cin.getline(nombre_entrada, MAXNOMBRE);

					// Cargar el archivo en la imagen.
					if(!image.leerImagen(nombre_entrada)){

						cout << "\nError al leer la primera imagen de entrada.\n";
						return 1;

					}

					cout << "\nIntroduzca la segunda imagen de entrada: ";
					cin.getline(nombre_entrada, MAXNOMBRE);

					// Cargar el archivo en la imagen.
					if(!image2.leerImagen(nombre_entrada)){

						cout << "\nError al leer la segunda imagen de entrada.\n";
						return 1;

					}

					cout << "\nIntroduzca la imagen de salida: ";
					cin.getline(nombre_salida, MAXNOMBRE);

					image3 = image + image2;

					if(!image3.escribirImagen(nombre_salida)){

						cout << "\nError al escribir la imagen de salida.\n";
						return 1;

					}

					cout << "\nConcatenación completada.";
					cout << "\n";

					break;

			// Salir.
			case 5: cout << "\nSaliendo del programa...\n";
					break;

		}

	}while(opcion != 5);

	return 0;

}
