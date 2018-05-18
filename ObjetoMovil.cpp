#include"ObjetoMovil.h"

ObjetoMovil::ObjetoMovil()
{
}

ObjetoMovil::~ObjetoMovil()
{
}

Vector2D ObjetoMovil::getPos()
{
	return posicion;
}

void ObjetoMovil::setPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}

void ObjetoMovil::setPos(Vector2D pos)
{
	posicion = pos;
}

void ObjetoMovil::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

void ObjetoMovil::setVel(Vector2D vel)
{
	velocidad = vel;
}

void ObjetoMovil::mueve(float t)	// Ecuaciones MRUA
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f*t*t);
	velocidad = velocidad + aceleracion * t;
}
