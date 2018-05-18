#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"

class Esfera: public ObjetoMovil {

protected:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	float radio;
public:
	bool tipo;

public:
	Esfera();		//Constructor 1
	Esfera(float rad, float x = 0.0f, float y = 0.0f,
		float vx = 0.0f, float vy = 0.0f);	// Constructor 2
	virtual ~ Esfera();				

	void Dibuja();
	void setColor(unsigned char cr, unsigned char cz, unsigned char cv);
	void setRadio(float r);

	void Mueve(float t);
	//void setPos(float px, float py);
	//void setVel(float vx, float vy);

	friend class Interaccion;
};