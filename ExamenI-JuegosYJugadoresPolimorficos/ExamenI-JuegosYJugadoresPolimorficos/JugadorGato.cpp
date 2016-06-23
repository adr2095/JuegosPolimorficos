#include "stdafx.h"
#include "JugadorGato.h"

/**
* @brief Constructor
* @param nombre char *
* @param caracter char
*/
JugadorGato::JugadorGato(char * nombre, char caracter, int id) : nombre(nombre), caracter(caracter), id(id)
{
	posicion = new int[2];
}

/**
* @brief Destructor
*/
JugadorGato::~JugadorGato()
{
}

/**
* @brief Actualiza el tablero en juego
* @param table[3][3] char. Tablero del juego
*/
void JugadorGato::setTablero(char table[3][3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			tablero[i][j] = table[i][j];
		}
	}
}


/**
* @brief Devuelve nombre del jugador
* @return nombre char*
*/
char * JugadorGato::getNombre()
{
	return this->nombre;
}

/**
* @brief Devuelve el caracter dle jugador.
* @return caracter char
*/
char JugadorGato::getCaracter()
{
	return this->caracter;
}

int JugadorGato::getId()
{
	return this->id;
}

