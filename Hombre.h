#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"

class Hombre: public ObjetoMovil {
private:
	float altura;

public:
	Hombre();
	virtual ~Hombre();

	void Dibuja();
	void Mueve(float);
	float getAltura() { return altura; }
	//void setPosicion(float x, float y);
	//Vector2D getPosicion();
	//void setVel(float vx, float vy);
	//float  getAltura();

	friend class Interaccion;
};