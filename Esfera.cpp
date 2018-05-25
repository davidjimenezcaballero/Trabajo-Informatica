#include "Esfera.h"
#include <stdlib.h>
#include "glut.h"

Esfera::Esfera()
{
	color.rojo = color.verde = color.azul = 255;
	radio = 1.0f;
	setPos(9, 3);
	setVel(0, 0);
}

Esfera::Esfera(float rad, float x, float y, float vx, float vy)
{
	radio = rad;
	setPos(x, y);
	setVel(vx, vy);
	setColor(255, 255, 100);
}

Esfera::~Esfera()
{
}

void Esfera::Dibuja()
{
	glColor3ub(color.rojo, color.verde, color.azul);
	glTranslatef(posicion.x, posicion.y, 5.0f);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, -5.0f);
}

void Esfera::setRadio(float r)
{
	if (r<0.1F)
		r = 0.1F;
	radio = r;
}