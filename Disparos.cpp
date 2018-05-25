#include "Disparo.h"
#include <stdlib.h>
#include "glut.h"

Disparo::Disparo(){		// Constructor
	radio = 0.25f;
	velocidad.y = 10.0f;
}

Disparo::~Disparo()		// Destructor
{
}

/*void Disparo::Dibuja()	// Función dibuja Disparo
{
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 3.0, 3.0);
	glVertex3f((origen.x - 0.0325f), origen.y, 0.0f);
	glVertex3f((origen.x - 0.0325f), (origen.y - 15.0f), 0.0f);
	glVertex3f((origen.x + 0.0325f), (origen.y - 15.0f), 0.0f);
	glVertex3f((origen.x + 0.0325f), origen.y, 0.0f);
	glEnd();

}*/

void Disparo::dibuja()
{
	glColor3f(0.0f, 1.0f, 1.0f);

	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glVertex3f(origen.x, origen.y, 0);
	glVertex3f(posicion.x, posicion.y, 0);
	glEnd();
	glEnable(GL_LIGHTING);

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);

	glutSolidSphere(radio, 20, 20);
	glPopMatrix();
}

/*void Disparo::Mueve(float t)
{
	/*posicion.x = posicion.x + velocidad.x*t + 0.5f*aceleracion.x*t*t;
	if (posicion.y < 15) {
		posicion.y = posicion.y + velocidad.y*t + 0.5f*aceleracion.y*t*t;
	}
	if (posicion.y < 15) {
		posicion = posicion + velocidad * t + aceleracion * (0.5f*t*t);
	}
	//velocidad.x = velocidad.x + aceleracion.x*t;
	//velocidad.y = velocidad.y + aceleracion.y*t;
	if (origen.y < 15.0f) {
		origen = origen + velocidad * t + aceleracion * (0.5f*t*t);
	}
	velocidad = velocidad + aceleracion * t;
}*/

/*void Disparo::setPosicion(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
	origen.x = x;
	origen.y = y;
}*/

void Disparo::setPos(float ox, float oy)
{
	ObjetoMovil::setPos(ox,oy);
	origen = posicion;
}

