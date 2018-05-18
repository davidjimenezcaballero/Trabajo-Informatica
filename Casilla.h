#pragma once

#pragma once
#include "ColorRGB.h"
#include "Vector2D.h"

class Casilla {

	Vector2D posicion;
	ColorRGB color;
	int tipo;

public:

	Casilla(float x , float y );
	virtual ~Casilla();

	void setPos(float px=0.0f, float py=0.0f);
	void setColor(Byte r= 255, Byte g=255, Byte b=255);
	void setTipo(int tp = 0);
	void dibuja();

	friend class Interaccion;
};