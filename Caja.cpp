#include "Caja.h"

Caja::Caja(){		// Constructor Caja
	
	//Estableceremos la posición de las paredes
	frontal.setLimites(-50.0f, -50.0f, 50.0f, -50.0f);
	pared_dcha.setLimites(50.0f, -50.0f, 50.0f, 50.0f);
	trasera.setLimites(50.0f, 50.0f, -50.0f, 50.0f);
	pared_izq.setLimites(-50.0f, 50.0f, -50.0f, -50.0f);

	// Estableceremos el color de las pareds
	frontal.setColor(244, 224, 79);
	trasera.setColor(244, 224, 79);
	pared_dcha.setColor(214, 203, 127);
	pared_izq.setColor(214, 203, 127);
}

Caja::~Caja()		//Destructor de la caja
{
}

void Caja::Dibuja()		//Función dibuja Caja usando la función dibuja pared.
{
	frontal.dibuja();
	trasera.dibuja();
	pared_izq.dibuja();
	pared_dcha.dibuja();
}

