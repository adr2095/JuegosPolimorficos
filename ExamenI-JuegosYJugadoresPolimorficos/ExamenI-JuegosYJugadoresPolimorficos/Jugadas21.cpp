#include "stdafx.h"
#include "Jugadas21.h"

/**
* @brief Constructor
*/
Jugadas21::Jugadas21()
{
}

/**
* @brief Destructor
*/
Jugadas21::~Jugadas21()
{
}

/**
* @brief Devuelve la calificacion segun mano.
* @param mano list<Carta*>. Mano de cartas del jugador.
* @return calificacion int. 
*/
int Jugadas21::obtenerCalificacion(list<Carta*> mano)
{
	return establecerCalificacion(mano);
}

/**
* @brief establece la calificacion segun valor de carta.
* @param mano list<Carta*>. Mano de cartas del jugador.
* @return calificacion int.
*/
int Jugadas21::establecerCalificacion(list<Carta*> mano)
{
	int puntaje = 0;
	int calificacionTmp = 0;
	bool uno = false;
	int numero;
	int size= mano.size();;
	for (list<Carta*>::iterator it = mano.begin(); it != mano.end(); it++)
	{
		numero = (*it)->getNumero(); 
		if (numero == 11 || numero == 12 || numero == 13)
		{
			numero = 10;
			calificacionTmp += numero;
		}
		else if (numero == 1)
		{
			uno = true;
		}
		else
		{
			calificacionTmp += numero;
		}
	}

	if (uno == true)
	{
		if (calificacionTmp <= 8 && size != 1)
		{
			puntaje = calificacionTmp + 13;
		}
		else
		{
			puntaje = calificacionTmp + 1;
		}
	}
	else
	{
		puntaje = calificacionTmp;

	}
	return puntaje;
}
