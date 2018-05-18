#pragma once
#include "Casilla.h"
#define MAX_HORIZONTAL 20
#define MAX_VERTICAL 20

class Tablero {

	int tipo;
	int max_horizontal;
	int max_vertical;
	Casilla lista_casillas[MAX_HORIZONTAL][MAX_VERTICAL];
	bool movimiento;

public:
	Tablero(int t = 1);
	virtual ~Tablero();

	void dibuja();
	void inicializa(int tipo);
	void setTamanio(int a, int b);

	friend class Interaccion;
};