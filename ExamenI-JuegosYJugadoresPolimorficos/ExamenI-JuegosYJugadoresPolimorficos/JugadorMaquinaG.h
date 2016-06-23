/**
* @class JugadorMaquinaG
* @brief Atributos y metodos de JugadorMaquinaG. Hija de JugadorGato.
*/
#pragma once

#include "JugadorGato.h"
#define INI 0 //inicio de la matriz
#define FIN 2 // fin de la matriz

class JugadorMaquinaG : public JugadorGato
{
private:
	bool encontrado;/*!< varible bool encontrado. Si se encontro 2 caracteres seguidos del oponente */
	char cOp; /*!< varible char cOp. Cacracter del oponente */
	virtual int * escogerPosicion();
	void considerarPosicion();
	void buscarOponente();
	bool revisarLineas();
	bool revisarColumnas();
	bool revisarDiagonales();

public:
	JugadorMaquinaG(char, int);
	virtual ~JugadorMaquinaG();
};

