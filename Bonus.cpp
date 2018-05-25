#include "Bonus.h"
#include <stdlib.h>
#include "glut.h"

Bonus::Bonus() {		// Constructor		
	lado = 2.0f;
	aceleracion.y = -9.8;
}

Bonus::~Bonus()			// Destructor
{
}

void Bonus::Dibuja()	// Función Dibuja Bonus	
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 10);
	glRotatef(30, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);//color aleatorio
	glutSolidCube(lado);
	glPopMatrix();
}

/*void Bonus::Mueve(float t)
{
	/*posicion.x = posicion.x + velocidad.x*t + 0.5f*aceleracion.x*t*t;
	posicion.y = posicion.y + velocidad.y*t + 0.5f*aceleracion.y*t*t;
	velocidad.x = velocidad.x + aceleracion.x*t;
	velocidad.y = velocidad.y + aceleracion.y*t;
	posicion = posicion + velocidad * t + aceleracion * (0.5f*t*t);
	velocidad = velocidad + aceleracion * t;
}*/

/*void Bonus::setPosicion(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}*/

/*void Bonus::SetAceleracion(float y)
{
	aceleracion.x = 0.0f;
	aceleracion.y = y;
}*/
