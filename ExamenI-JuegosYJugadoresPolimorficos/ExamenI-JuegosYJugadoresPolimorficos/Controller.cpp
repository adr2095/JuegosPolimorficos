#include "stdafx.h"
#include "Controller.h"

/**
* @brief Constructor. Crea objeto Model y objetos de View.
*/
Controller::Controller()
{
	srand(time(NULL));
	model = new Model();
	vistaConsola = new Consola(); // ¿como hacer esto más dinámico?
	vistaArchivo = new Archivo();
}

/**
* @brief Desctructor
*/
Controller::~Controller()
{
	delete model;
	//delete vistaConsola; //da error!
	//delete vistaArchivo;
}

/**
* @brief  Inicia el programa.
*/
void Controller::iniciar()
{
	bool salida = false; //da opcion para continuar jugando y escoger otro juego.
	int juego;

	model->addView(vistaConsola);
	model->addView(vistaArchivo);
	
	list<View*> viewC = model->getList();
	
	model->notifyOutput("Bienvenido! \n\n\n");
	while (salida == false)
	{
		juego = model->notifyInputInt("Ingrese el numero del juego que desea jugar:\n[1] 21 \n[2] Gato\n[3] Salir \nOpcion: ");
		system("cls");

		switch (juego)
		{
		case 1:
		{
			Juego21 * juego21 = new Juego21();

			for (list<View*>::iterator it = viewC.begin(); it != viewC.end(); ++it) // agrega vistas al modelo juego 21
			{
				juego21->addView((*it));
			}

			juego21->jugar();
			juego21->terminarJuego();
			delete juego21;
			break;
		}
		case 2:
		{
			JuegoGato * gato = new JuegoGato();
			for (list<View*>::iterator it = viewC.begin(); it != viewC.end(); ++it) // agrega vistas al modelo juego 21
			{
				gato->addView((*it));
			}

			gato->jugar();
			delete gato;
			break;
		}
		case 3:
		{
			salida = 3;
			break;
		}
		default:
		{
			juego = model->notifyInputInt("La opcion es invalida. Intente de nuevo: ");
			break;
		}
		}
		 
		if (0 < juego && juego <= 2) //verifica que opcion este entre 0 y 2
		{
			salida = model->notifyInputInt("\nIngrese 0 para jugar de nuevo o cualquier numero para salir: ");
			system("cls");
		}
	}
	
	for (list<View*>::iterator it = viewC.begin(); it != viewC.end(); ++it) //delete de las vistas en lista.
	{
		delete (*it);
	}
}
