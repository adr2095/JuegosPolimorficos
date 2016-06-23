// ExamenI-JuegosYJugadoresPolimorficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Controller.h"
using namespace std;

int main()
{
	Controller * control = new Controller();
	control->iniciar();
	delete control;
    return 0;
}

