#include "Cubo.h"
#include "glut.h"

//Constructor de cubos por defecto
Cubo::Cubo()
{
	lado = 10.0f;
}

Cubo::Cubo(float lado, float px, float py, Byte r, Byte g, Byte b)
{
	posicion.x = px;
	posicion.y = py;
	color.rojo = r;
	color.azul = g;
	color.azul = b;
}

Cubo::~Cubo()
{
}

//Dibujo de los cubos
void Cubo::dibuja()
{
	glColor3ub(color.rojo, color.verde, color.azul);
	glTranslatef(posicion.x, posicion.y, 5.0f);
	glutSolidCube(lado);
	glTranslatef(-posicion.x, -posicion.y, -5.0f);
}

//Lado de los cubos 
void Cubo::setLado(float l)
{
	if (l<0.1F)
		l = 0.1F;
	lado = l;
}