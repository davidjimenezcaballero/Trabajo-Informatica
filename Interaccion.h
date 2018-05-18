#pragma once
#include "Hombre.h"
#include "Caja.h"
#include "Esfera.h"
#include "Bonus.h"
#include "Disparo.h"
#include "Tablero.h"
#include "Cubo.h"

class Interaccion {

public:
	Interaccion();
	virtual ~Interaccion();

	// ¿Qué se hace cuando se choca con los límites del tablero?
	static void choque(Esfera &e, Caja c);
	static void choque(Cubo & b, Caja c);

	// Limitar el movimiento a las posiciones de las casillas del tablero
	static bool movimiento_vertical(Esfera &e, Tablero t);
	static bool movimiento_horizontal(Esfera & e, Tablero t);
	



	static bool rebote(Esfera &e, Pared p);
	static void rebote(Esfera &e, Caja c);
	static void rebote(Hombre &h, Caja c);
	static bool rebote(Esfera &e1, Esfera &e2);

	static bool rebote(Bonus &b, Caja c);

	//Funciones para saber si hay colisión
	static bool colision(Esfera e, Hombre h);
	static bool colision(Disparo d, Pared p);
	static bool colision(Disparo d, Caja c);
};