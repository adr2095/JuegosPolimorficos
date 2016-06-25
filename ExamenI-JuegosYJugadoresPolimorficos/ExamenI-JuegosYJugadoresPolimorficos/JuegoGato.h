/**
* @class JuegoGato
* @brief Atributos y metodos del juego gato. Hija de juego.
*/

#pragma once

#include "Juego.h"
#include "JugadorGato.h"
#include "JugadorHumanoG.h"
#include "JugadorMaquinaG.h"

using namespace std;

class JuegoGato : public Juego
{
private :
	int numeroJugadores; /*!< variable integer numeroJugadores. Saber el modo de juego */
	list<JugadorGato *> jugadores; /*!< list<JugadorGato*> jugadores. Lista de participantes */
    char tablero[3][3]; /*!< varible char[3][3] tablero */
	char caracter; /*!< varible char caracter. Caracter escogido por humano*/
	char ganador; /*!< varible char ganador*/
	virtual void crearJugadoresHumanos();
	virtual void crearJugadoresMaquinas();
	void empezarTurnos();
	bool verTablero();
	void ingresarCaracter(int * posicion, char caracter);
	int * escogerPosicion(JugadorGato *);
	virtual void addVistas();
	virtual void mostrar();
	JugadorGato * seleccionarGanador();
	char recorrerTablero();
	char recorrerLineas();
	char recorerColumnas();
	char recorrerDiagonales();

public:
	JuegoGato();
	virtual ~JuegoGato();
	virtual void jugar();
	virtual void terminarJuego();

};

