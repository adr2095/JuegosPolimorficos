#include "stdafx.h"
#include "Consola.h"

using namespace std;

/**
* @brief Constructor
*/
Consola::Consola() : View()
{
}

/**
* @brief Destructor
*/
Consola::~Consola()
{
}

/**
* @brief Devuelve imput tipo char *.
* @param mensaje char *
* @return in char *
*/
char * Consola::input(char * mensaje)
{
	char * in = new char[20];
	cout << mensaje;

	cin >> in;

	return in;
}

/**
* @brief Devuelve imput tipo int.
* @param mensaje char *
* @return in int
*/
int Consola::inputInt(char * mensaje)
{
	char * in = new char[1];
	cout << mensaje;
	cin >> in;
	return atoi(in);
}

/**
* @brief Devuelve imput tipo char.
* @param mensaje char *
* @return in char
*/
char Consola::inputChar(char * mensaje)
{
	char in;
	cout << mensaje;
	cin >> in;
	return in;
}

/**
* @brief Imprime mensaje.
* @param mensaje char *
*/
void Consola::output(char * mensaje)
{
	cout << mensaje;
}
/**
* @brief Imprime mensaje.
* @param mensaje int
*/
void Consola::outputInt(int i)
{
	cout << i;
}

/**
* @brief Imprime mensaje.
* @param mensaje char
*/
void Consola::outputChar(char c)
{
	cout << c << " ";
}