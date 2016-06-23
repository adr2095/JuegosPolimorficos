/**
* @class Jugadas
* @brief Da calificaciones segun las cartas en mano.
*/
#pragma once

#include "Carta.h"

class Jugadas21
{
private:
	int establecerCalificacion(list<Carta*> mano);
public:
	Jugadas21();
	~Jugadas21();
	int obtenerCalificacion(list<Carta*> mano);
};

