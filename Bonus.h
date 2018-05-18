/*#pragma once
#include"ObjetoMovil.h"
#include "Vector2D.h"

class Bonus: public ObjetoMovil {
private:
	float lado;
public:
	Bonus();
	virtual ~Bonus();

	void Dibuja();

	friend class Interaccion;
};*/


#pragma once

#include "Vector2D.h"
#include "ColorRGB.h"
class Bonus
{
	friend class Interaccion;
public:
	void mueve(float t);
	void dibuja();
	void setPos(float ix, float iy);
	Bonus();
	virtual ~Bonus();

private:
	float lado;//2.5
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;//que vaya rapidito para que haya choque seguro

};