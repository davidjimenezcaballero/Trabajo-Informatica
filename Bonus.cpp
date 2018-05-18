/*#include "Bonus.h"
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


#include "Bonus.h"
#include <stdlib.h>
#include "glut.h"

Bonus::Bonus()
{
	//movimiento gravitatorio           
	//velocidad vertical inicial
	aceleracion.y = -9.8f;
	velocidad.y = 5;
	lado = 2.5f;
}

Bonus::~Bonus()
{

}

void Bonus::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 10.0f);
	glRotatef(30, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);//color aleatorio
	glutSolidCube(lado);
	glPopMatrix();

}

void Bonus::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f*t*t);
	velocidad = velocidad + aceleracion * t;

	//Salto continuo del bonus 

	if (posicion.y = 0) //si ha tocado el suelo
	{
		do { // cambiamos la direccion de la aceleracion 
			 //para hacerlo ascender hasta tocar el limite de una figura (10)
			posicion = posicion + velocidad * t - aceleracion * (0.5f*t*t);
			velocidad = velocidad - aceleracion * t;
		} while (posicion.y != 10);

	}
}
void Bonus::setPos(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
}
