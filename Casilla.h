#pragma once

#pragma once
#include "ColorRGB.h"
#include "Vector2D.h"

class Casilla {

	Vector2D posicion;
	ColorRGB color;
	int tipo;
public:

	Casilla(float x = 0.0f, float y = 0.0f);
	virtual ~Casilla();

	void setPos(float px, float py);
	void setColor(Byte r= 255, Byte g=255, Byte b=255);
	void setTipo(int tp = 0);
	void dibuja();

	friend class ObjetoMovil;
	friend class Interaccion;
};