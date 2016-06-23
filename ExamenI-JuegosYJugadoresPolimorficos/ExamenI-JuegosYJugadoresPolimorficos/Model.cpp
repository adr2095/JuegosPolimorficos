#include "stdafx.h"
#include "Model.h"

using namespace std;

/**
* @brief Constructor
*/
Model::Model()
{
}

/**
* @brief Destructor
*/
Model::~Model()
{	
}

/**
* @brief Agrega vistas a la lista de vistas.
* @param  * vista View. Lista a agregar.
*/
void Model::addView(View * vista)
{
	views.push_back(vista);
}

/**
* @brief Elimina vistas de la lista de vistas.
* @param  vista View *. Lista a eliminar.
*/
void Model::deleteView(View * vista)
{
	//¿cuál de las dos?
	views.remove(vista);
}

/**
* @brief Notifica de output tipo char *.
* @param msj char *. Mensaje a mostrar.
*/
void Model::notifyOutput(char * msj)
{
	for (list<View*>::iterator it = views.begin(); it != views.end(); it++)
	{
		(*it)->output(msj);
	}
}

/**
* @brief Notifica de output tipo int.
* @param i int. Entero a mostrar.
*/
void Model::notifyOutputInt(int i)
{
	for (list<View*>::iterator it = views.begin(); it != views.end(); it++)
	{
		(*it)->outputInt(i);
	}
}

/**
* @brief Notifica de un output tipo char.
* @param c char. Caracter a mostrar.
*/
void Model::notifyOutputChar(char c)
{
	for (list<View*>::iterator it = views.begin(); it != views.end(); it++)
	{
		(*it)->outputChar(c);
	}
}

/**
* @brief Notifica de un input tipo char *.
* @param msj char *. Mensaje a mostrar.
* @return char * mensaje introducido
*/
char * Model::notifyInput(char * msj)
{
	char * in;

	list<View*>::iterator it = views.begin();

	do
	{
		in = (*it)->input(msj);
		++it;
	} while (in == NULL  && it != views.end());

	return in;
}

/**
* @brief Notifica de un input tipo int.
* @param msj char *. Mensaje a mostrar.
* @return int. Numero introducido.
*/
int Model::notifyInputInt(char * msj)
{
	int in;

	list<View*>::iterator it = views.begin();

	do
	{
		in = (*it)->inputInt(msj);
		++it;
	} while (in == NULL  && it != views.end());
	return in;
}

/**
* @brief Notifica de un input tipo char.
* @param msj char *. Mensaje a mostrar.
* @return char. Caracter introducido.
*/
char Model::notifyInputChar(char * msj)
{
	char in;

	list<View*>::iterator it = views.begin();

	do
	{
		in = (*it)->inputChar(msj);
		++it;
	} while (in == NULL  && it != views.end());
	return in;
}

/**
* @brief Devuelve la lista de vistas.
* @return list<View*>. Listas de vistas.
*/
list<View*> Model::getList()
{
	return views;
}
