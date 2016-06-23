#include "stdafx.h"
#include "JugadorMaquinaG.h"

/**
* @brief Constructor
* @param caracter char
*/
JugadorMaquinaG::JugadorMaquinaG(char caracter, int id) : JugadorGato("PC", caracter, id)
{
}

/**
* @brief Destructor
*/
JugadorMaquinaG::~JugadorMaquinaG()
{
}

/**
* @brief Devuelve la posicion esocogida
* @return posicion int *
*/
int * JugadorMaquinaG::escogerPosicion()
{
	considerarPosicion();
	return posicion;
}


/**
* @brief Considera la mejor posicion segun los caracteres del oponente
*/
void JugadorMaquinaG::considerarPosicion()
{
	if (caracter == 'X')
	{
		cOp = 'O';
	}
	else
	{
		cOp = 'X';
	}

	if (tablero[INI][INI] == cOp || tablero[INI][FIN] == cOp || tablero[FIN][INI] == cOp || tablero[FIN][FIN] == cOp)
	{
		if (tablero[1][1] == NULL)
		{
			posicion[0] = 1;
			posicion[1] = 1;
		}
		else
		{
			buscarOponente();
		}
	}
	else if (tablero[1][1] == cOp)
	{
		if (tablero[0][2] == NULL)
		{
			posicion[0] = 0;
			posicion[1] = 2;
		}
		else
		{
			buscarOponente();
		}
	}
	else
	{
		int i = rand() % 2;
		int j = rand() % 2;
		while (tablero[i][j] != NULL)
		{
			i = rand() % 3;
			j = rand() % 3;
		}
		posicion[0] = i;
		posicion[1] = j;
	}
}

/**
* @brief Busca caracteres seguidos del oponente
*/
void JugadorMaquinaG::buscarOponente()
{
	if (revisarLineas() == false)
	{
		if (revisarColumnas() == false)
		{
			if (revisarDiagonales() == false)
			{
				int i = rand() % 2;
				int j = rand() % 2;
				while (tablero[i][j] != NULL)
				{
					i = rand() % 3;
					j = rand() % 3;
				}
				posicion[0] = i;
				posicion[1] = j;
			}
		}
	}
}

/**
* @brief Devuelve true si encontro al oponente horizontalmente.
* @return encontrado bool
*/
bool JugadorMaquinaG::revisarLineas()
{
	int i = 0;
	encontrado = false;

	while (i < 3 && encontrado == false && tablero[i][1] != NULL)
	{
		if (tablero[i][1] == cOp)
		{
			if (tablero[i][0] == tablero[i][1] && tablero[i][2] == NULL)
			{
					posicion[0] = i;
					posicion[1] = 2;
					encontrado = true;
			}
			else if (tablero[i][2] == tablero[i][1] && tablero[i][0] == NULL)
			{
					posicion[0] = i;
					posicion[1] = 0;
					encontrado = true;
			}
		}
		i++;
	}
	return encontrado;
}

/**
* @brief Devuelve true si encontro al oponente verticalmente.
* @return encontrado bool
*/
bool JugadorMaquinaG::revisarColumnas()
{
	int j = 0;
	while (j < 3 && encontrado == false && tablero[1][j] != NULL)
	{
		if (tablero[1][j] == cOp)
		{
			if (tablero[0][j] == tablero[1][j] && tablero[2][j] == NULL)
			{
					posicion[0] = 2;
					posicion[1] = j;
					encontrado = true;
			}
			else if (tablero[2][j] == tablero[1][j] && tablero[0][j] == NULL)
			{
				posicion[0] = 0;
				posicion[1] = j;
				encontrado = true;
			}
		}
		j++;
	}
	return encontrado;
}

/**
* @brief Devuelve true si encontro al oponente diagonalmente.
* @return encontrado bool
*/
bool JugadorMaquinaG::revisarDiagonales()
{
	if (tablero[1][1] != NULL)
	{
		if (tablero[1][1] == cOp)
		{
			if (tablero[0][0] == tablero[1][1] && tablero[2][2] == NULL)
			{
				posicion[0] = 2;
				posicion[1] = 2;
				encontrado = true;
			}
			else if (tablero[1][1] == tablero[2][2] && tablero[0][0] == NULL)
			{
				posicion[0] = 0;
				posicion[1] = 0;
				encontrado = true;
			}
		}
	}
	return encontrado;
}
