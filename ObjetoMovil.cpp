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

void ObjetoMovil::setColor(Byte cr, Byte cv, Byte ca)
{
	color.rojo = cr;
	color.azul = ca;
	color.verde = cv;
}

void ObjetoMovil::mueve(float t)	// Ecuaciones MRUA
{
	posicion = posicion + velocidad * t;// +aceleracion * (0.5f*t*t);
										//velocidad = velocidad + aceleracion * t;
}

bool ObjetoMovil::comprobarPos(Tablero t)
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if ((posicion.x == t.lista_casillas[i][j].posicion.x) && (posicion.y == t.lista_casillas[i][j].posicion.y))
				return true;
		}
	}
	return false;
}
