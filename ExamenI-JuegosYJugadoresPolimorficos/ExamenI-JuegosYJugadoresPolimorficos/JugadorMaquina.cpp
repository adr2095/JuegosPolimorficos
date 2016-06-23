#include "stdafx.h"
#include "JugadorMaquina.h"

/**
* @brief Constructor
* @param nombre char *
* @param numeroJugador int
*/
JugadorMaquina::JugadorMaquina(char * nombre, int numeroJugador) : Jugador21(nombre, numeroJugador)
{
}

/**
* @brief Destructor
*/
JugadorMaquina::~JugadorMaquina()
{
}

/**
* @brief Segun la calificacion la PC decide si seguir = true o no = false
* @return desicion bool
*/
bool JugadorMaquina::tomarDecision()
{
	desicion = false;
	int calificacion = jugadas->obtenerCalificacion(getMano());
	if (calificacion == 21)
	{
		desicion = false;
	}
	else if (calificacion < 13)
	{
		desicion = true;
	}
	else
	{
		desicion = false;
	}
	return desicion;
}
