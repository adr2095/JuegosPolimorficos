/**
* @class JugadorMaquina
* @brief Metodos de JugadorMaquina. Hija de Jugador21.
*/

#pragma once
#include "Jugador21.h"
class JugadorMaquina : public Jugador21
{
private:
	virtual bool tomarDecision();
public:
	JugadorMaquina(char *, int);
	virtual ~JugadorMaquina();
};

