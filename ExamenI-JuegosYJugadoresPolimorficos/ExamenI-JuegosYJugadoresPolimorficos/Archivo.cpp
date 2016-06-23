#include "stdafx.h"
#include "Archivo.h"

using namespace std;

/**
* @brief Constructor
*/
Archivo::Archivo() : View()
{
	escritura.open("OutputJuego.txt");
}

/**
* @brief Destructor
*/
Archivo::~Archivo()
{
	escritura.close();
}

/**
* @brief Devuelve NULL
* @param msj char *
* @return NULL
*/
char * Archivo::input(char * msj)
{
	return NULL;
}

/**
* @brief Devuelve NULL
* @param msj char *
* @return NULL
*/
int Archivo::inputInt(char * msj)
{
	return NULL;
}

/**
* @brief Devuelve NULL
* @param msj char *
* @return NULL
*/
char Archivo::inputChar(char * msj)
{
	return NULL;
}

/**
* @brief Escribe en el archivo msj tipo char *
* @param msj char *
*/
void Archivo::output(char * msj)
{
	escritura << msj << " ";
}

/**
* @brief Escribe en el archivo msj tipo int *
* @param msj int
*/
void Archivo::outputInt(int i)
{
	escritura << i << " ";
}

/**
* @brief Escribe en el archivo msj tipo char 
* @param c char 
*/
void Archivo::outputChar(char c)
{
	escritura << c << " ";
}
