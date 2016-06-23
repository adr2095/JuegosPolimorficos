#include "stdafx.h"
#include "Carta.h"

/**
* @brief Constructor
* @param numero int. Numero de carta.
*/
Carta::Carta(int numero)
{
	this->numero = numero;
}

/**
* @brief Destructor
*/
Carta::~Carta()
{
}

/**
* @brief Devuelve numero de carta.
* @return int numero. Numero de carta.
*/
int Carta::getNumero()
{
	return this->numero;
}
