#include "Esfera.h"
#include <stdlib.h>
#include "glut.h"

Esfera::Esfera()
{
	rojo = verde = azul = 255;
	radio = 1.0f;
	aceleracion.y = 0.0;
	setPos(9, 3);
	setVel(0, 0);
}

Esfera::Esfera(float rad, float x, float y, float vx, float vy)
{
	radio = rad;
	setPos(x, y);
	setVel(vx, vy);
	setColor(255, 255, 100);
	aceleracion.y = 0.0f;
}

Esfera::~Esfera()
{
}

void Esfera::Dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 5.0f);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, -5.0f);
}

void Esfera::setColor(unsigned char cr, unsigned char cv, unsigned char cz)
{
	rojo = cr;
	azul = cz;
	verde = cv;
}

void Esfera::setRadio(float r)
{
	if (r<0.1F)
		r = 0.1F;
	radio = r;
}

void Esfera::Mueve(float t)
{
		posicion = posicion + velocidad * t;
}

