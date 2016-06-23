/**
* @class View
* @brief Encargada de la vista de las clases.
*/

#pragma once

#include <fstream> //ifstream, ofstream
#include <iostream> //cout, cin

class View
{
public:
	View(); /* Constructor */
	virtual ~View(); /* Destructor */
	virtual void output(char *) = 0; /* Hace output tipo char *  */
	virtual void outputInt(int) = 0; /* Hace output tipo int */
	virtual void outputChar(char) = 0; /* Hace output tipo char  */
	virtual char * input(char *) = 0; /* Hace input tipo char *  */
	virtual int inputInt(char *) = 0; /* Hace input tipo int */
	virtual char inputChar(char *) = 0; /* Hace input tipo char  */
	
};

