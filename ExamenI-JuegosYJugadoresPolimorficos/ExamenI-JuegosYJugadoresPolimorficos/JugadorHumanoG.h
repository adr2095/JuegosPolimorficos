/**
* @class JugadorHumanoG
* @brief Metodos del JugadorHumanoG. Hija de JugadorGato.
*/
#pragma once

#include "JugadorGato.h"

class JugadorHumanoG : public JugadorGato
{
private:
	virtual int * escogerPosicion();
	bool verificarDisponibilidad();
public:
	JugadorHumanoG(char *, char, int);
	virtual ~JugadorHumanoG();
};

