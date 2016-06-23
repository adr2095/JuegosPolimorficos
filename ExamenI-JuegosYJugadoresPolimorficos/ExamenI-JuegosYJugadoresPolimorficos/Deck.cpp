#include "stdafx.h"
#include "Deck.h"

/**
* @brief Constructor
*/
Deck::Deck()
{
	for (int i = 1; i < 14; i++) // crea cartas con numero del 1-13, 4 veces = 52 cartas en total.
	{
		for (int j = 1; j < 5; j++)
		{
			deck.push_back(new Carta(i));
		}
	}
	revolverBaraja();
}

/**
* @brief Destructor. Borra cartas de la lista.
*/
Deck::~Deck()
{
	for (list<Carta*>::iterator it = deck.begin(); it != deck.end(); ++it) {
		delete *it;
	}
}

/**
* @brief Revuelve la baraja aleatoriamente. Tomado del ejemplo en clase del profesor Ruben Jimenez.
*/
void Deck::revolverBaraja()
{
	for (int i = 0; i < 100; i++)
	{
		list<Carta*>::iterator it = deck.begin();
		list<Carta*>::iterator ite = deck.begin();

		int limite = rand() % 52;
		int limite1 = rand() % 52;

		for (int j = 0; j < limite; j++)
		{
			
			++it;
		}
		for (int k = 0; k < limite1; k++)
		{
			++ite;
		}

		Carta * tmp = *it;
		*it = *ite;
		*ite = tmp;
		
	}
}

/**
* @brief Devuelve una carta de la baraja para ser repartida y la elimina del deck.
* @return Carta *. Carta de la baraja.
*/
Carta * Deck::obtenerCarta()
{
	list<Carta*>::iterator it = deck.begin();
	Carta * tmp;
	if (!deck.empty())
	{
		
		tmp = *it;
		deck.pop_front();
	}
	else
		tmp = nullptr;
	
	return tmp; // Devuelve la primera carta y la elimina del deck.
}