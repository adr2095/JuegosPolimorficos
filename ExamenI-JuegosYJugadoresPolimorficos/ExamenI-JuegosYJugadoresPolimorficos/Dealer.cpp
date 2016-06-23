#include "stdafx.h"
#include "Dealer.h"


Dealer::Dealer()
{
	deck = new Deck();
	crearJugadoresHumanos(1);
	crearJugadoresMaquinas(1);
	repartirCartasIniciales();
	repartirCartas();
	seleccionarGanador();
}


Dealer::~Dealer()
{
	delete deck;
	for (list<Jugador21*>::iterator it = jugadores.begin(); it != jugadores.end(); it++)
	{
		delete *it;
	}
}

void Dealer::crearJugadoresHumanos(int numeroJugadores)
{
	id = 0;
	for (int j = 0; j < numeroJugadores; j++)
	{
		++id;
		jugadores.push_back(new JugadorHumano(notifyInput("Ingrese nombre de jugador: "), id));
	}
}

void Dealer::crearJugadoresMaquinas(int numeroJugadores)
{
	for (int j = 0; j < numeroJugadores; j++)
	{
		++id;
		 jugadores.push_back(new JugadorMaquina("Maquina", id));
	}
}

void Dealer::repartirCartasIniciales()
{
	Carta * carta = deck->obtenerCarta();
		for (list<Jugador21*>::iterator it = jugadores.begin(); it != jugadores.end(); it++)
		{
			(*it)->anadirAMano(carta);
			carta= deck->obtenerCarta();
		}
}

void Dealer::repartirCartas()
{
	Carta * carta = deck->obtenerCarta();
	for (list<Jugador21*>::iterator it = jugadores.begin(); it != jugadores.end(); it++)
	{
		if (solicitarDecisiones(*it))
		{
			(*it)->anadirAMano(carta);
			carta = deck->obtenerCarta();
		}
	}
}

bool Dealer::solicitarDecisiones(Jugador21 * jugador)
{
	return jugador->tomarDecision();
}


char* Dealer::seleccionarGanador()
{
	int * ganador;
	list<Carta*> cartas;
	for (list<Jugador21*>::iterator it = jugadores.begin(); it != jugadores.end(); it++)
	{
		puntajes.push_back((*it)->obtenerPuntaje());
	}

	ganador = compararPuntajes();
	/*cout << ganador[0];*/

	list<Jugador21*>::iterator ite = jugadores.begin();
	while ( ite != jugadores.end() && (*ite)->getNumeroJugador() != ganador[0])
	{
		cout << " " << (*ite)->getNumeroJugador() << " ";
		ite++;
	}

	if (ganador[1] == 0)
	{
		return "Es empate";
	}
	else
	{
		cout << (*ite)->getNombre();
		return (*ite)->getNombre();
	}
	delete ganador;
}

int* Dealer::compararPuntajes() 
{
	int * ganador = new int[2];
	int numeroJugador = 0;
	int mejorpuntaje = 0;
	list<int>::iterator it = puntajes.begin(); 
	while (it != puntajes.end())
	{
		if ((*it) > mejorpuntaje)
		{
			++numeroJugador;
			mejorpuntaje = *it;
		}
		else if ((*it) == mejorpuntaje)
		{
			mejorpuntaje = 0;
		}
		it++;
		
	}
	ganador[0] = numeroJugador;
	ganador[1] = mejorpuntaje;
	return ganador;
}