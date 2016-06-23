#include "stdafx.h"
#include "JugadorHumanoG.h"

/**
* @brief Constructor
* @param nombre char *
* @param caracter char
*/
JugadorHumanoG::JugadorHumanoG(char * nombre, char caracter, int id) : JugadorGato(nombre, caracter, id)
{
}

/**
* @brief Destructor
*/
JugadorHumanoG::~JugadorHumanoG()
{
	delete posicion;
}

/**
* @brief Devuelve posicion a ingresar caracter.
* @return posicion int *
*/
int * JugadorHumanoG::escogerPosicion()
{
	int op = notifyInputInt("Ingrese posicion (1-9) ");
	bool disponibilidad = false;

	while (disponibilidad == false)
	{
		if (op > 0 && op <= 9)
		{
			if (op <= 3)
			{
				posicion[0] = 0;
			}
			else if (3 < op && op <= 6)
			{
				posicion[0] = 1;
			}
			else
			{
				posicion[0] = 2;
			}

			if (op == 1 || op == 4 || op == 7)
			{
				posicion[1] = 0;
			}
			else if (op == 2 || op == 5 || op == 8)
			{
				posicion[1] = 1;
			}
			else
			{
				posicion[1] = 2;
			}
			disponibilidad = verificarDisponibilidad();
			
			if (disponibilidad == false)
			{
				op = notifyInputInt("Posicion esta ocupada, intente de nuevo ");
			}
		}
		else
		{
			op = notifyInputInt("Posicion no existe, intente de nuevo ");
		}
	}
	return posicion;
}

/**
* @brief Verifica si el espacio esta lleno = false, vacio = true
* @return bool
*/
bool JugadorHumanoG::verificarDisponibilidad()
{
	if (tablero[posicion[0]][posicion[1]] == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
