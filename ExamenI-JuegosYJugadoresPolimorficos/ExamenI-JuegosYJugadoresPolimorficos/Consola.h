/**
* @class Consola
* @brief Metodos de Consola. Hija de View.
*/

#pragma once

#include "View.h"

class Consola : public View
{
public:
	Consola();
	virtual ~Consola();
	virtual char* input(char *);
	virtual int inputInt(char *);
	virtual char inputChar(char *);
	virtual void output(char *);
	virtual void outputInt(int);
	virtual void outputChar(char);
};

