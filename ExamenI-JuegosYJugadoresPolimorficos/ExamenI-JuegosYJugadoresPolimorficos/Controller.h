/**
* @class Controller
* @brief Controlador de las clases.
*/

#pragma once

#include "View.h"
#include "Model.h"
#include "Consola.h"
#include"Archivo.h"
#include "Juego21.h"
#include "JuegoGato.h"

class Controller
{
private:
	Consola * vistaConsola; /*!< objeto Consola * vistaConsola */
	Archivo * vistaArchivo; /*!< objeto Archivo * vistaArchivo */
	Model * model; /*!< objeto Model * model */

public:
	Controller();
	~Controller();
	void iniciar();
};

