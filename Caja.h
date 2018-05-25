#pragma once
#include "Pared.h"

class Caja{
private:
	Pared frontal;		// Pared frontal
	Pared trasera;		// Pared trasera
	Pared pared_izq;	// Pared izquierda
	Pared pared_dcha;	// Pared derecha
public:
	Caja();				// Constructor
	virtual ~Caja();	// Destructor

	void Dibuja();		// Función dibuja Caja

	friend class Interaccion;	// Clase amiga de Interacción
								// Da acceso a su parte privada
};