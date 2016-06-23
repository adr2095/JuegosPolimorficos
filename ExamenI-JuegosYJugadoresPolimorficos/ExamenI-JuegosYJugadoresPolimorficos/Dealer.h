#pragma once

#include "JugadorHumano.h"
#include "JugadorMaquina.h"
#include "Jugador21.h"
#include "Deck.h"
#include "Carta.h"

class Dealer : public Model
{
private:
	int turnoActual = 0;
	Deck * deck;
	list<int> puntajes; // era list<Deck*>.
	list<Jugador21*> jugadores;
	int id;


public:

	Dealer();

	Dealer(int, int);

	~Dealer();

	void crearJugadoresHumanos(int i);

	void crearJugadoresMaquinas(int numeroJugadores);

	void repartirCartas();

	void repartirCartasIniciales();

	bool solicitarDecisiones(Jugador21 * it);

	void puntajeManos(list<Carta*>);

	int * compararPuntajes();

	char* seleccionarGanador();
};

