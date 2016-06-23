/**
* @class Juego21
* @brief Implementacion del juego 21. Hija de Juego.
*/
#pragma once

#include "Juego.h"
#include "Deck.h"
#include "Jugador21.h"
#include "JugadorHumano.h"
#include "JugadorMaquina.h"

class Juego21 : public Juego
{
private:
	Deck * deck; /*!< objeto Deck * deck */
	list<Jugador21*> jugadores; /*!< Lista de participantes */
	int id; /*!< varible integer id. Id de jugador maquina */
	void crearJugadoresHumanos(); 
	void crearJugadoresMaquinas();
	virtual void addVistas();
	void repartirCartasIniciales();
	void repartirCartas();
	bool solicitarDecisiones(Jugador21 *);
	virtual void mostrar();
	Jugador21 * seleccionarGanador();
	Jugador21 * compararPuntajes();

public:
	Juego21();
	virtual ~Juego21();
	virtual void jugar();
	virtual void terminarJuego();
};

