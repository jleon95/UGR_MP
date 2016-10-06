/*
Metodología de la Programación.
-Curso 2014-2015.
-Grupo D3.
Javier León Palomares.
Juan Manuel Garrido Valenzuela.
*/

#include <iostream>
#include "byte.h"

using namespace std;

const int NUM_BITS = 8;

///////////////////////////////////////////////////////////
void on(byte &b, int pos){

	byte mask = 1 << pos;

	b |= mask;

}

///////////////////////////////////////////////////////////
void off(byte &b, int pos){

	byte mask = 1 << pos;

	mask = ~mask;

	b &= mask;

}

///////////////////////////////////////////////////////////
bool get(byte b, int pos){

	byte mask = 1 << pos;
	bool encendido = false;

	if(b & mask)

		encendido = true;

	return encendido;

}

///////////////////////////////////////////////////////////
void print(byte b){

	for(int pos = NUM_BITS - 1 ; pos >= 0 ; pos--)

		cout << get(b, pos);
	
	cout << "\n";

}

///////////////////////////////////////////////////////////
void encender(byte &b){

	byte todos = 255;

	b = todos;

}

///////////////////////////////////////////////////////////
void apagar(byte &b){

	byte ninguno = 0;

	b = ninguno;

}

///////////////////////////////////////////////////////////
void asignar(byte &b, const bool v[]){

	bool actual;

	for(int i = 0 ; i < NUM_BITS ; i++){

		actual = get(b, i);

		if(actual != v[i])

			if(actual)

				off(b, i);

			else

				on(b, i);

	}
}

///////////////////////////////////////////////////////////
void volcar(byte b, bool v[]){

	for(int i = 0 ; i < NUM_BITS ; i++)

		v[i] = get(b, i);
	
}

///////////////////////////////////////////////////////////
void encendidos(byte b, int posic[], int &cuantos){

	cuantos = 0;

	for(int i = 0 ; i < NUM_BITS ; i++)

		if(get(b, i)){

			posic[cuantos] = i;
			cuantos++;

		}
}