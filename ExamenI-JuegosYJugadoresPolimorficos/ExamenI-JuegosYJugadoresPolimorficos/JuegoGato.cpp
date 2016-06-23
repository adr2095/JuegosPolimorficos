#include "stdafx.h"
#include "JuegoGato.h"

/**
* @brief Constructor. Inciliza tablero y ganador.
*/
JuegoGato::JuegoGato() : Juego()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			tablero[i][j] = NULL;
		}
	}
	ganador = 'N';
	caracter = NULL;
}

/**
* @brief Destructor
*/
JuegoGato::~JuegoGato()
{
	for (list<JugadorGato*>::iterator it = jugadores.begin(); it != jugadores.end(); it++)
	{
		delete *it;
	}
}

/**
* @brief Comienza el juego.
*/
void JuegoGato::jugar()
{
	crearJugadoresHumanos();
	crearJugadoresMaquinas();
	addVistas();
	mostrar();
	empezarTurnos();
}

/**
* @brief Crea los jugadores humanos
*/
void JuegoGato::crearJugadoresHumanos()
{
	bool salida = false;
	numeroJugadores = notifyInputInt("Ingrese cuantas personas jugaran:\n[0] PC vs PC\n[1] Persona vs PC\n[2] Persona vs persona\nCantidad: ");
	system("cls");
	notifyOutput("Ingrese su nombre sin espacios, maximo 20 caracteres.\nSe le agregara un id al final de su nombre\n\n");
	while (salida == false)
	{
		if (numeroJugadores <= 2)
		{
			for (int j = 0; j < numeroJugadores; j++)
			{
				char * nombre = notifyInput("Nombre de jugador: ");
				if (caracter == NULL)
				{
					caracter = toupper(notifyInputChar("Escoja un caracter, X o O: "));
				}
				else
				{
					if (caracter == 'X')
					{
						caracter = 'O';
					}
					else
					{
						caracter = 'X';
					}
				}
				if (caracter == 'X' || caracter == 'O')
				{
					jugadores.push_back(new JugadorHumanoG(nombre, caracter, (j + 1)));
				}
				else
				{
					while ((caracter != 'X' && caracter == 'O') || (caracter == 'X' && caracter != 'O'))
					{
						caracter = toupper(notifyInputChar("Caracter invalido, intente de nuevo: "));
					}
				}
			}
			salida = true;
		}
		else
		{
			numeroJugadores = notifyInputInt("\nCantidad incorrecta, intente de nuevo:\n[0] PC vs PC\n[1] Persona vs PC\n[2] Persona vs persona\nCantidad: ");
		}
	}
	system("cls");
}

/**
* @brief Crea jugadores maquina
*/
void JuegoGato::crearJugadoresMaquinas()
{
	JugadorGato * jugador;
	if (numeroJugadores == 2)
	{
		numeroJugadores = 0;
	}
	else if (numeroJugadores == 0)
	{
		numeroJugadores = 2;
	}

	for (int j = 0; j < numeroJugadores; j++)
	{
		if (caracter == 'X')
		{
			jugador = new JugadorMaquinaG('O', (j + 1));
			jugadores.push_back(jugador);
		}
		else
		{
			jugador = new JugadorMaquinaG('X', (j + 1));
			jugadores.push_back(jugador);
		}
		notifyOutput("Jugador ");
		notifyOutput(jugador->getNombre());
		notifyOutputInt(jugador->getId());
		notifyOutput(" con el caracter ");
		notifyOutputChar(jugador->getCaracter());
		notifyOutput("\n");
		caracter = 'X';
	}
}

/**
* @brief Empieza los turnos.
*/
void JuegoGato::empezarTurnos()
{
	int * i;
	char c;
	char * nombre;
	while (verTablero() == false && ganador == 'N')
	{
		for (list<JugadorGato*>::iterator it = jugadores.begin(); it != jugadores.end() && ganador == 'N' && verTablero() == false; ++it)
		{
			nombre = (*it)->getNombre();
			notifyOutput("Turno de ");
			notifyOutput(nombre);
			notifyOutputInt((*it)->getId());
			notifyOutput("\n");
			(*it)->setTablero(tablero); // actualiza el tablero
			i = escogerPosicion((*it));
			c = (*it)->getCaracter();
			ingresarCaracter(i, c);
			if (nombre != "PC" || numeroJugadores == 1)
			{
				system("cls");
			}
			mostrar();
			ganador = recorrerTablero();
		}
	}
	terminarJuego();
}

/**
* @brief Devuelve false si tablero aun tiene posiciones vacias o true si ya esta completamente lleno.
* @return lleno bool
*/
bool JuegoGato::verTablero()
{
	int i = 0;
	bool lleno = true;
	int j = 0;

	for (int i = 0; i < 3 && lleno; ++i)
	{
		for (int j = 0; j < 3 && lleno; ++j)
		{
			if (tablero[i][j] == NULL)
			{
				lleno = false;
			}
		}
	}
	return lleno;
}

/**
* @brief Ingresa el caracter en la posicion que el jugador escogio.
*/
void JuegoGato::ingresarCaracter(int * posicion, char c) {
	tablero[posicion[0]][posicion[1]] = c;
}

/**
* @brief Devuelve posicion que jugador escoge.
* @return posicion int *
*/
int * JuegoGato::escogerPosicion(JugadorGato * jugador)
{
	return jugador->escogerPosicion();
}

/**
* @brief Termina el juego si ya hay un ganador o el tablero esta lleno
*/
void JuegoGato::terminarJuego()
{
	JugadorGato * vencedor = seleccionarGanador();
	if (vencedor == NULL)
	{
		notifyOutput("No hay ganador");
		notifyOutput("\n\n");
	}
	else
	{
		notifyOutput("El ganador es: ");
		notifyOutput(vencedor->getNombre());
		notifyOutputInt(vencedor->getId());
		notifyOutput("\n\n");
	}
}

/**
* @brief Agrega las vistas a cada jugador.
*/
void JuegoGato::addVistas()
{
	for (list<JugadorGato*>::iterator it = jugadores.begin(); it != jugadores.end(); it++)
	{
		for (list<View*>::iterator ite = this->views.begin(); ite != this->views.end(); ++ite)
		{
			(*it)->addView((*ite));
		}
	}
}

/**
* @brief Muestra el tablero y la posicion de los caracteres.
*/
void JuegoGato::mostrar()
{
	notifyOutputChar('\n');
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			notifyOutputChar(' ');
			notifyOutputChar(tablero[i][j]);
			if (j != 2)
			{
				notifyOutputChar('|');
			}
		}
		notifyOutputChar('\n');
		if (i != 2)
		{
			notifyOutput("_______________");
			notifyOutputChar('\n');
		}
	}
	notifyOutputChar('\n');
}

/**
* @brief Devuelve el ganador.
* @return g JugadorGato *
*/
JugadorGato * JuegoGato::seleccionarGanador()
{ 
	JugadorGato * g = NULL;
	bool salida = false;

	list<JugadorGato*>::iterator it = jugadores.begin();

		while (it != jugadores.end() && salida == false)
		{
			
			if ((*it)->getCaracter() == ganador)

			{
				g = *it;
				salida = true;
			}
			++it;
		}

	return g;
}

/**
* @brief Devuelve el caracter ganador o 'N' si no hay en ninguna posicion
* @return car char
*/
char JuegoGato::recorrerTablero()
{
	char g = recorrerLineas();
	if (g == 'N')
	{
		g = recorerColumnas();
		if (g == 'N')
		{
			g = recorrerDiagonales();
		}
	}
	return g;
}

/**
* @brief Devuelve el caracter ganador o 'N' si no hay horizontalmente
* @return car char
*/
char JuegoGato::recorrerLineas()
{
	char car = 'N';
	int i = 0;
	bool encontrado = false;

	while (i < 3 && encontrado == false)
	{
		if (tablero[i][1] != NULL && tablero[i][0] == tablero[i][1] && tablero[i][2] == tablero[i][1])
		{
			car = tablero[i][1];
			encontrado = true;
		}
		i++;
	}
	return car;
}

/**
* @brief Devuelve el caracter ganador o 'N' si no hay verticalmente
* @return car char
*/
char JuegoGato::recorerColumnas()
{
	char car = 'N';

	int j = 0;
	bool encontrado = false;

	while (j < 3 && encontrado == false )
	{
		if (tablero[0][j] != NULL && tablero[0][j] == tablero[1][j] && tablero[2][j] == tablero[1][j])
		{
			car = tablero[1][j];
			encontrado = true;
		}
		j++;
	}
	return car;
}

/**
* @brief Devuelve el caracter ganador o 'N' si no hay diagonalmente
* @return car char
*/
char JuegoGato::recorrerDiagonales()
{
	char car = 'N';
	if (tablero[1][1] != NULL)
	{
		if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2])
		{
			car = tablero[0][0];
		}
		if (car == 'N')
		{
			if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])
			{
				car = tablero[0][2];
			}
		}
	}
	return car;
}