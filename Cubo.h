#pragma once

#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
class Cubo
{
	friend class Interaccion;
public:

	void mueve(float t);
	void dibuja();

	void setColor(Byte r, Byte v, Byte a);
	void setLado(float l);
	void setPos(float ix, float iy);
	void setVel(float vx, float vy);
	Cubo();
	~Cubo();
private:
	ColorRGB color;
	float lado;// lado en el constructor de 10
	Vector2D posicion;
	Vector2D velocidad;
};