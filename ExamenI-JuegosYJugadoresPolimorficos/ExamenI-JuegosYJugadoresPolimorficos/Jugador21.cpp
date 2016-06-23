 #include "stdafx.h"
#include "Jugador21.h"

/**
* @brief Constructor
* @param nombre char *. Nombre del jugador.
* @param numeroJugador integer. Id del jugador
*/
Jugador21::Jugador21(char * nombre, int numeroJugador) : nombre(nombre), numeroJugador(numeroJugador)
{
}

/**
* @brief Destructor
*/
Jugador21::~Jugador21()
{
	delete jugadas;
}

/**
* @brief Devuelve mano del jugador
* @return mano list<Carta>.
*/
list<Carta*> Jugador21::getMano()
{
	return this->mano;
}

/**
* @brief Agrega carta a mano del jugador.
* @param carta Carta *
*/
void Jugador21::anadirAMano(Carta * carta)
{
	this->mano.push_back(carta);
}

/**
* @brief Establece el puntaje total de todas las cartas.
*/
void Jugador21::setPuntaje()
{
	puntaje = jugadas->obtenerCalificacion(getMano());
}

/**
* @brief Devuelve el id de jugador.
* @return numeroJugador int.
*/
int Jugador21::getNumeroJugador()
{
	return numeroJugador;
}

/**
* @brief Devuelve el nombre del jugador.
* @return nombre char*
*/
char * Jugador21::getNombre()
{
	return nombre;
}

/**
* @brief Muestra cartas que posee en ese momento el jugador.
*/
void Jugador21::mostrar()
{
	int valor;
	for (list<Carta*>::iterator it = mano.begin(); it != mano.end(); it++)
	{
		valor = (*it)->getNumero();
		if (valor == 1)
		{
			notifyOutputChar('A');
		}
		else if (valor == 11)
		{
			notifyOutputChar('J');
		}
		else if (valor == 12)
		{
			notifyOutputChar('Q');
		}
		else if (valor == 13)
		{
			notifyOutputChar('K');
		}
		else
		{
			notifyOutputInt(valor);
		}
		notifyOutput(" ");
	}
}

/**
* @brief Devuelve calificacion total de la mano del jugador.
* @return puntaje int.
*/
int Jugador21::getPuntaje()
{
	return this->puntaje;
}
