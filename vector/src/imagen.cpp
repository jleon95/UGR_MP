/*
Metodología de la Programación.
-Curso 2014-2015.
-Grupo D3.
Javier León Palomares.
Juan Manuel Garrido Valenzuela.
*/
#include <iostream>
#include "imagen.h"
#include "pgm.h"

using namespace std;

Imagen::Imagen(){

	datos = 0;
	nfilas = 0;
	ncolumnas = 0;

}

Imagen::Imagen(int filas, int columnas){

	datos = 0;
	crear(filas, columnas);

}

Imagen::Imagen(const Imagen &otra){

	datos = 0;
	crear(otra.filas(), otra.columnas());

	for(int i = 0 ; i < nfilas * ncolumnas ; i++)

		datos[i] = otra.getPos(i);

}

Imagen::~Imagen(){

	destruir();

}

Imagen& Imagen::operator =(const Imagen &otra){

	if(this != &otra){

		crear(otra.filas(), otra.columnas());

		for(int i = 0 ; i < nfilas * ncolumnas ; i++)

			datos[i] = otra.getPos(i);

	}

	return (*this);

}

Imagen Imagen::operator +(const Imagen &otra){

	int filas_union = (nfilas > otra.filas()) ? nfilas : otra.filas();
	int columnas_union = ncolumnas + otra.columnas();

	Imagen suma(filas_union, columnas_union);

	for(int i = 0 ; i < nfilas ; i++)

		for(int j = 0 ; j < ncolumnas ; j++)

			suma.set(i,j,get(i,j));


	for(int i = 0 ; i < otra.filas() ; i++)

		for(int j = ncolumnas, k = 0 ; j < columnas_union ; j++, k++)

			suma.set(i,j,otra.get(i,k));


	return suma;

}

void Imagen::crear(int filas, int columnas){

	int total = filas * columnas;

	destruir();

	datos = new byte [total];

	for(int i = 0 ; i < total ; i++)

		datos[i] = 0;

	nfilas = filas;
	ncolumnas = columnas;

}

int Imagen::filas() const{

	return nfilas;

}

int Imagen::columnas() const{

	return ncolumnas;

}

void Imagen::set(int y, int x, byte v){

	datos[y * ncolumnas + x] = v;

}

byte Imagen::get(int y, int x) const{

	return datos[y * ncolumnas + x];

}

void Imagen::setPos(int i, byte v){

	datos[i] = v;

}

byte Imagen::getPos(int i) const{

	return datos[i];

}

bool Imagen::leerImagen(const char nombreFichero[]){

	bool exito = false;

	TipoImagen tipo = infoPGM(nombreFichero, nfilas, ncolumnas);
	
	crear(nfilas, ncolumnas);

	// Para cada tipo de imagen se utiliza su correspondiente función.
	if(tipo == IMG_PGM_BINARIO){

		if(leerPGMBinario(nombreFichero, datos, nfilas, ncolumnas))

			exito = true;

	}

	else if(tipo == IMG_PGM_TEXTO)

		if(leerPGMTexto(nombreFichero, datos, nfilas, ncolumnas))

			exito = true;


	return exito;

}

bool Imagen::escribirImagen(const char nombreFichero[]){

	return escribirPGMTexto(nombreFichero, datos, nfilas, ncolumnas);

}

void Imagen::destruir(){

	if(datos > 0){
	
		delete [] datos;
		datos = 0;
		
	}
	
	nfilas = 0;
	ncolumnas = 0;

}

void Imagen::rotar(){

	byte **imagen = new byte *[nfilas];
	byte **aux = new byte *[ncolumnas];

	// Crear matriz a partir del vector de datos. (nfilas x ncolumnas)
	for(int i = 0 ; i < nfilas ; i++)

		imagen[i] = &datos[i*ncolumnas];

	// Crear matriz auxiliar vacía con dimensiones invertidas. (ncolumnas x nfilas)
	for(int i = 0 ; i < ncolumnas ; i++)

		aux[i] = new byte[nfilas];

	// Rotar matriz imagen y copiar a auxiliar.
	for(int i = 0 ; i < ncolumnas ; i++)

		for(int j = 0 ; j < nfilas ; j++)

			aux[i][j] = imagen[nfilas - j - 1] [i];
	
	// Liberar la imagen antigua y crear una nueva vacía. (ncolumnas x nfilas)
	crear(ncolumnas,nfilas);
	// A partir de ahora ncolumnas y nfilas han intercambiado sus valores.
	
	// Actualizar reserva de memoria.
	delete [] imagen;
	imagen = new byte *[nfilas];
	
	// Asignar la nueva imagen vacía a la matriz.
	for(int i = 0 ; i < nfilas ; i++)

		imagen[i] = &datos[i*ncolumnas];

	// Copiar de vuelta la imagen ya transformada desde la matriz auxiliar.
	for(int i = 0 ; i < nfilas ; i++)

		for(int j = 0 ; j < ncolumnas ; j++)

			imagen[i][j] = aux[i][j];

	// Liberar memoria.
	for(int i = 0 ; i < nfilas ; i++)

		delete [] aux[i];

	delete [] aux;
	delete [] imagen;

}

void Imagen::rotacion(int grados, bool sentidoHorario){

	if((sentidoHorario && grados == 90) || (!sentidoHorario && grados == 270))

		rotar();

	else if((!sentidoHorario && grados == 90) || (sentidoHorario && grados == 270)){

		rotar();
		rotar();
		rotar();

	}

	else if(grados == 180){

		rotar();
		rotar();

	}
}
