/**
* @class Jugador21
* @brief Metodos y atributos de los jugadores en 21
*/
#pragma once

#include "Model.h"
#include "Jugadas21.h"
class Jugador21 : public Model
{
protected:
	Jugadas21 * jugadas; /*!< objero Jugadas21 jugadas */
	list<Carta*> mano; /* Lista de cartas que posee el jugador  */
	bool desicion; /*!< varible bool desicion. Decide si quiere mas cartas o no */
	char * nombre; /*!< varible char * nombre */
	int numeroJugador; /*!< varible integer numeroJugador. Id único en el juego */
	int puntaje; /*!< varible integer puntaje */

public:
	Jugador21(char *, int);
	virtual ~Jugador21();
	list<Carta*> getMano();
	void anadirAMano(Carta *);
	void setPuntaje();
	virtual bool tomarDecision() = 0;
	int getNumeroJugador();
	char * getNombre();
	virtual void mostrar();
	int getPuntaje();
};

