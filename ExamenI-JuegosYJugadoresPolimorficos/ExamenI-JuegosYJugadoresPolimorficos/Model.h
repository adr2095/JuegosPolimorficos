/**
* @class Model
* @brief Modelo de las clases.
*/
#pragma once

#include "View.h"
using namespace std;

class View;
class Model
{
protected:
	list<View *> views; /*Lista tipo View * views */

public:
	Model();
	virtual~ Model(); 
	void addView(View *);
	void deleteView(View *);
	void notifyOutput(char *);
	void notifyOutputInt(int);
	void notifyOutputChar(char);
	char * notifyInput(char *);
	int notifyInputInt(char *);
	char notifyInputChar(char *);
	list<View*> getList();
};

