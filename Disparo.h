#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"

class Disparo: public ObjetoMovil {
private:
	float radio;
	Vector2D origen;

public:
	Disparo();				// Constructor
	virtual ~Disparo();		// Destructor

	void dibuja();			// Función Dibuja disparo
	float getRadio() { return radio; }
	void setPos(float ox, float oy);		//Acceso parte privada
	
	//void Mueve(float);		// Función gestión movimiento
	//void setPosicion(float x, float y);		//Acceso parte privada

};