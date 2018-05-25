#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "ColorRGB.h"

class Cubo : public  ObjetoMovil
{
private:
	float lado;// lado en el constructor de 10
public:
	Cubo();												//Constructor 1
	Cubo(float lado, float px = 0.0f, float py = 0.0f,	// Constructor 2 
		Byte r = 0, Byte g = 0, Byte b = 255);
	~Cubo();											// Destructor

	void dibuja();
	void setLado(float l);

	friend class Interaccion;
};