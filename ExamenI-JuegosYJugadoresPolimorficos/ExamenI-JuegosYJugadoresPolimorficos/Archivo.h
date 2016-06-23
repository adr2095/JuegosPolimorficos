/**
* @class Archivo
* @brief Metodos de Archivo. Hija de View.
*/

#pragma once
#include "View.h"

using namespace std;
class Archivo : public View
{
private:
	ofstream escritura;
public:
	Archivo();
	~Archivo();
	virtual char * input(char *);
	virtual void output(char *);
	virtual int inputInt(char *);
	virtual char inputChar(char *);
	virtual void outputInt(int);
	virtual void outputChar(char);
};

