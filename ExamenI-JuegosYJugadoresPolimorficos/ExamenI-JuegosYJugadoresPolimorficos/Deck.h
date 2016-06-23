/**
* @class Deck
* @brief Crea deck de cartas.
*/

#pragma once

#include "stdafx.h"
#include "Carta.h"

using namespace std;

class Deck
{
private:
	list<Carta*> deck; /*!<Lista de Carta * */
	void revolverBaraja();
public:
	Deck();
	virtual ~Deck();
	Carta * obtenerCarta();
};