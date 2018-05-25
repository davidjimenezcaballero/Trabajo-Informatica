#include "Hombre.h"
#include <stdlib.h>
#include "glut.h"

Hombre::Hombre(){
	altura= 1.8f;
}

Hombre::~Hombre(){
}

void Hombre::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(altura, 20, 20);
	glPopMatrix();
}

void Hombre::Mueve(float t)
{
	//posicion.x = posicion.x + velocidad.x*t + 0.5f*aceleracion.x*t*t;
	//posicion.y = posicion.y + velocidad.y*t + 0.5f*aceleracion.y*t*t;
	//velocidad.x = velocidad.x + aceleracion.x*t;
	//velocidad.y = velocidad.y + aceleracion.y*t;
	
	/*posicion = posicion + velocidad * t + aceleracion * (0.5f*t*t);
	velocidad = velocidad + aceleracion * t;
	//Estableceremos los límites de movimiento del objeto hombre
	if (posicion.x > 10.0f)posicion.x = 10.0f;
	if (posicion.x < -10.0f)posicion.x = -10.0f;*/
	ObjetoMovil::mueve(t);
}

/*void Hombre::setPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}*/

/*Vector2D Hombre::getPosicion()
{
	Vector2D temp;
	temp.x = posicion.x;
	temp.y = posicion.y;
	return temp;
	/*if (n == 'x')
		return posicion.x;
	if (n == 'y')
		return posicion.y;
	else
		return posicion.x;
}*/

/*void Hombre::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}*/

