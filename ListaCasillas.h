#pragma once

#pragma once
#define MAX_CASILLA 100

#include "Casilla.h"

class ListaCasillas {

public:
	ListaCasillas();				// Constructor
	virtual ~ListaCasillas();		// Destructor

	//void mueve(float t);
	void dibuja();

	bool agregar(Casilla *e);
	void eliminar(Casilla *e);
	void eliminar(int index);
	void destruirContenido();

	//Casilla* colision(Hombre h);
	//void rebote(Pared p);
	//void rebote();
	//void rebote(Caja caja);

	int getNumero() { return numero; }
	Casilla *operator [](int i);

	//Casilla* colision(Casilla &e);

private:
	Casilla * lista[10];
	int numero;
};