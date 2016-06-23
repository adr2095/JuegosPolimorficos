/**
* @class Carta
* @brief Crea cartas.
*/

#pragma once

#include "stdafx.h"
using namespace std;

class Carta
{
private: 
	int numero; /*!< varible integer numero. Numero de carta */

public:
	Carta(int); 
	~Carta();
	int getNumero();
};