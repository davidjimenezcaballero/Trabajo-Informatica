#pragma once
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
};