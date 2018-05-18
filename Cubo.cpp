#include "Cubo.h"
#include "glut.h"

//Constructor de cubos por defecto
Cubo::Cubo()
{
	lado = 10.0f;
	velocidad.x = 4;
	velocidad.y = 4;
}

Cubo::~Cubo()
{
}

//Dibujo de los cubos
void Cubo::dibuja()
{
	color.ponColor();
	glTranslatef(posicion.x, posicion.y, 5.0f);
	glutSolidCube(lado);
	glTranslatef(-posicion.x, -posicion.y, -5.0f);
}

//Movimiento de los cubos (Hay que retocar esto en el caso del posicionamiento de las casillas)

void Cubo::mueve(float t)
{
	posicion = posicion + velocidad * t;// +aceleracion * (0.5f*t*t);
										//velocidad = velocidad + aceleracion*t;
}

//SetColor de cubos
void Cubo::setColor(Byte r, Byte v, Byte a)
{
	//Metodo privado de color de cubos
	color.set(r, v, a);
}
//Lado de los cubos 
void Cubo::setLado(float l)
{
	if (l<0.1F)
		l = 0.1F;
	lado = l;
}
//Posicion de los cubos
void Cubo::setPos(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
}
//Velocidad de los cubos
void Cubo::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}