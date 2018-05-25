#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"

class Esfera : public ObjetoMovil {

protected:
	// Atributos
	float radio;
	int tipo;

public:
	Esfera();											//Constructor 1
	Esfera(float rad, float x = 0.0f, float y = 0.0f,
		float vx = 0.0f, float vy = 0.0f);				// Constructor 2
	virtual ~Esfera();									// Destructor 		

														//Métodos 
	void Dibuja();
	void setRadio(float r);

	friend class Interaccion;
};