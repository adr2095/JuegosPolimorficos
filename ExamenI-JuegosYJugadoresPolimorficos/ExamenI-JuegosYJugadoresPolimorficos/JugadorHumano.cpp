#include "stdafx.h"
#include "JugadorHumano.h"

/**
* @brief Constructor
* @param nombre char *
* @param numeroJugador int
*/
JugadorHumano::JugadorHumano(char * nombre, int numeroJugador) : Jugador21(nombre, numeroJugador)
{
}

/**
* @brief Destructor
*/
JugadorHumano::~JugadorHumano()
{
}

/**
* @brief Pide a la persona si desea continuar = true, o no = false
* @return desicion bool
*/
bool JugadorHumano::tomarDecision()
{
	notifyOutput("Estas son las cartas que posee ");
	notifyOutput(nombre);
	notifyOutputInt(numeroJugador);
	notifyOutput("\n");

	mostrar();
	notifyOutput("\n");
	notifyOutput("\n");
	int d = notifyInputInt("Desea otra carta? Ingrese 1 para si, 2 para no: ");
	system("cls");
	int salida = 0;
	while (salida == 0)
	{
		switch (d)
		{
		case 1:
		{
			desicion = true;
			salida = 1;
			break;
		}
		case 2:
		{
			desicion = false;
			salida = 1;
			break;
		}
		default:
		{
			notifyOutput("Estas son las cartas que posee ");
			notifyOutput(nombre);
			notifyOutputInt(numeroJugador);
			notifyOutput("\n");

			mostrar();
			notifyOutput("\n");
			notifyOutput("\n");
			d = notifyInputInt("La opcion no existe. Intente de nuevo: ");
			system("cls");
			break;
		}
		}
	}
	return desicion;
}

