/**
* @class Juego
* @brief Clase puramente virtual. Hija de modelo.
*/

#pragma once
#include "Model.h"

class Juego : public Model
{
protected:
	virtual void crearJugadoresHumanos() = 0;
	virtual void crearJugadoresMaquinas() = 0;
	virtual void addVistas() = 0;
	virtual void mostrar() = 0;

public:
	Juego();/*Contructor */
	virtual ~Juego(); /*! Destructor*/
	virtual void terminarJuego() = 0; /*!< Finaliza el juego*/
	virtual void jugar() = 0; /*!< Inicia el juego */
};

