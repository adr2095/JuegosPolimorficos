/**
* @class JugadorGato.
* @brief Atributos y metodos de JugadorGato.
*/

#pragma once
#include "Model.h"
class JugadorGato : public Model
{
protected:
	int id; /*!< varible integer id. Diferencia a cada jugador PC */
	char * nombre; /*!< varible char * nombre */
	char caracter; /*!< varible char caracter (X o O) */
	int * posicion; /*!< varible integer * posicion. Donde se ingresara el caracter. */
	char tablero[3][3]; /*!< varible char tablero. Tablero con el que se esta jugando*/

public:
	JugadorGato(char *, char, int);
	virtual ~JugadorGato();
	char * getNombre();
	char getCaracter();
	int getId();
	virtual int * escogerPosicion() = 0;
	void setTablero(char[3][3]);
};

