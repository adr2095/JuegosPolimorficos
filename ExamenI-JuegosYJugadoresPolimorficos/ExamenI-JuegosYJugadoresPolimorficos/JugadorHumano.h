/**
* @class JugadorHumano
* @brief Metodos del jugador humano. Hija de Jugador21.
*/
#pragma once

#include "Jugador21.h"

class JugadorHumano : public Jugador21
{
private:
	virtual bool tomarDecision();
public:
	JugadorHumano(char *, int);
	virtual ~JugadorHumano();
};

