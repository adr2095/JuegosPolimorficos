
#include "stdafx.h"
#include "Juego21.h"

/**
* @brief Constructor. Crea deck de cartas.
*/
Juego21::Juego21() : Juego()
{
	deck = new Deck();
}

/**
* @brief Destructor. elimina jugadores de lista y deck
*/
Juego21::~Juego21()
{
	delete deck;
	//for (list<Jugador21*>::iterator it = jugadores.begin(); it != jugadores.end(); it++)
	//{
	//	delete *it;
	//}
}

/**
* @brief Inicia el juego.
*/
void Juego21::jugar()
{
	crearJugadoresHumanos();
	crearJugadoresMaquinas();
	addVistas();
	repartirCartasIniciales();
	repartirCartas();
}

/**
* @brief Crea jugadores humanos segun numero de participantes introducido.
*/
void Juego21::crearJugadoresHumanos()
{
	char * nombre;
	int numeroJugadores = notifyInputInt("Ingrese cuantas personas jugaran: ");
	id = 0;
	system("cls");
	notifyOutput("Ingrese su nombre sin espacios, maximo 20 caracteres.\nSe le agregara un id al final de su nombre\n\n");
	for (int j = 0; j < numeroJugadores; j++)
	{
		++id;
		notifyOutput("Nombre de jugador ");
		notifyOutputInt(id);
		nombre = notifyInput(": ");
		jugadores.push_back(new JugadorHumano(nombre, id));
	}
	notifyOutput("\n");
}

/**
* @brief Crea jugadores maquina.
*/
void Juego21::crearJugadoresMaquinas()
{
	int numeroJugadores = notifyInputInt("Ingrese cuantos jugadores PC jugaran: ");
	notifyOutput("\n");
	for (int j = 0; j < numeroJugadores; j++)
	{
		++id;
		jugadores.push_back(new JugadorMaquina("PC", id));
	}
	system("cls");
}

/**
* @brief Agrega vistas a los jugadores
*/
void Juego21::addVistas()
{
	for (list<Jugador21*>::iterator it = jugadores.begin(); it != jugadores.end(); it++)
	{
		for (list<View*>::iterator ite = this->views.begin(); ite != this->views.end(); ++ite)
		{
			(*it)->addView((*ite));
		}
	}
}

/**
* @brief Reparte las primeras cartas.
*/
void Juego21::repartirCartasIniciales()
{
	Carta * carta = deck->obtenerCarta();
	for (list<Jugador21*>::iterator it = jugadores.begin(); it != jugadores.end(); it++)
	{
		(*it)->anadirAMano(carta);
		carta = deck->obtenerCarta();
	}
	delete carta;
}

/**
* @brief Segun la desicion tomada, reparte mas cartas o no.
*/
void Juego21::repartirCartas()
{
	Carta * carta;
	bool continuar;
	for (list<Jugador21*>::iterator it = jugadores.begin(); it != jugadores.end(); it++)
	{
		continuar = solicitarDecisiones(*it);
		while (continuar)
		{
			carta = deck->obtenerCarta();
			(*it)->anadirAMano(carta);
			continuar = solicitarDecisiones(*it);
		} 
	}
}

/**
* @brief Pregunta si el jugador humano/maquina desea continuar.
* @param Jugador * jugador. Jugador que tomará la desicion.
*/
bool Juego21::solicitarDecisiones(Jugador21 * jugador)
{
	return jugador->tomarDecision();
}

/**
* @brief Termina el juego y revela al ganador
*/
void Juego21::terminarJuego()
{
	mostrar();
	Jugador21 * ganador = seleccionarGanador();
	if (ganador != NULL)
	{
		notifyOutput("\nEl ganador es:\n");
		notifyOutput(ganador->getNombre());
		notifyOutputInt(ganador->getNumeroJugador());
		notifyOutput("\n\n");
	}
	else
	{
		notifyOutput("No hay ganador");
	}
}

/**
* @brief Muestra cartas en mano de cada jugador y sus puntajes.
*/
void Juego21::mostrar()
{
	notifyOutput("NOTA: J, Q, K equivalen a 10; A puede ser 1 o 13 segun puntaje\n\n\n");
	for (list<Jugador21*>::iterator it = jugadores.begin(); it != jugadores.end(); it++)
	{
		(*it)->setPuntaje();
		notifyOutput("Cartas de ");
		notifyOutput((*it)->getNombre());
		notifyOutput(" con un puntaje de ");
		notifyOutputInt((*it)->getPuntaje());
		notifyOutput("\n");
		(*it)->mostrar();
		notifyOutput("\n\n");
	}
}

/**
* @brief Devuelve el nombre del jugador ganador.
* @return Jugador21 *.Jugador ganador.
*/
Jugador21 * Juego21::seleccionarGanador()
{
	Jugador21 * ganador = compararPuntajes();
	return ganador;
}

/**
* @brief Compara puntajes de todos los jugadores.
* @return Jugaador21 *. Devuelve a jugador ganador.
*/
Jugador21 * Juego21::compararPuntajes()
{
	int mejorpuntaje = 0;
	int puntaje;
	Jugador21 * ganador = NULL;
	bool repetido = false;
	for (list<Jugador21*>::iterator it = jugadores.begin(); it != jugadores.end(); it++)
	{
		
		puntaje = (*it)->getPuntaje();
		if (puntaje == mejorpuntaje)
		{
			repetido = true;
		}
		if (puntaje > mejorpuntaje)
		{
			if (puntaje <= 21)
			{
				mejorpuntaje = puntaje;
				ganador = (*it);
			}
		}
	}
	if (repetido == true)
	{
		ganador = NULL;
	}

	return ganador;
}