#include "Casilla.h"
#include "glut.h"


Casilla::Casilla(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}

Casilla::~Casilla()
{
}

void Casilla::setPos(float px, float py)
{
	posicion.x = px;
	posicion.y = py;
}

void Casilla::setColor(Byte r, Byte g, Byte b)
{
	color.set(r, g, b);
}

void Casilla::setTipo(int tp)
{
	tipo = tp;
}

void Casilla::dibuja()
{
	switch (tipo) {
	case 0:
		glDisable(GL_LIGHTING);
		color.ponColor();
		glBegin(GL_POLYGON);
		glVertex3d(posicion.x - 5, posicion.y + 5, 0);
		glVertex3d(posicion.x - 5, posicion.y - 5, 0);
		glVertex3d(posicion.x + 5, posicion.y - 5, 0);
		glVertex3d(posicion.x + 5, posicion.y + 5, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		break;
	case 1:
		/*glDisable(GL_LIGHTING);
		color.ponColor();
		glBegin(GL_POLYGON);
		glVertex3d(posicion.x - 5, posicion.y + 5, 0);
		glVertex3d(posicion.x - 5, posicion.y - 5, 0);
		glVertex3d(posicion.x + 5, posicion.y - 5, 0);
		glVertex3d(posicion.x + 5, posicion.y + 5, 0);
		glEnd();*/
		//glEnable(GL_LIGHTING);

		//La cruz verde parte 1
		glDisable(GL_LIGHTING);
		setColor(0, 255, 0);
		color.ponColor();
		glBegin(GL_POLYGON);
		glVertex3d(posicion.x - 4, posicion.y + 3, 0);
		glVertex3d(posicion.x - 3, posicion.y + 4, 0);
		glVertex3d(posicion.x + 4, posicion.y - 3, 0);
		glVertex3d(posicion.x + 3, posicion.y - 4, 0);
		glEnd();
		//glEnable(GL_LIGHTING);
		//glDisable(GL_LIGHTING);
		setColor(0, 255, 0);
		color.ponColor();
		glBegin(GL_POLYGON);
		glVertex3d(posicion.x - 4, posicion.y - 3, 0);
		glVertex3d(posicion.x + 3, posicion.y + 4, 0);
		glVertex3d(posicion.x + 4, posicion.y + 3, 0);
		glVertex3d(posicion.x - 3, posicion.y - 4, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		break;

	case 2:
		glDisable(GL_LIGHTING);
		setColor(0, 255, 0);
		color.ponColor();
		glBegin(GL_POLYGON);
		glVertex3d(posicion.x - 5, posicion.y + 5, 0);
		glVertex3d(posicion.x - 5, posicion.y - 5, 0);
		glVertex3d(posicion.x + 5, posicion.y - 5, 0);
		glVertex3d(posicion.x + 5, posicion.y + 5, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		break;
	case 3:
		//La cruz verde parte 1
		glDisable(GL_LIGHTING);
		setColor(255, 0, 0);
		color.ponColor();
		glBegin(GL_POLYGON);
		glVertex3d(posicion.x - 4, posicion.y + 3, 0);
		glVertex3d(posicion.x - 3, posicion.y + 4, 0);
		glVertex3d(posicion.x + 4, posicion.y - 3, 0);
		glVertex3d(posicion.x + 3, posicion.y - 4, 0);
		glEnd();
		//glEnable(GL_LIGHTING);
		//glDisable(GL_LIGHTING);
		setColor(255, 0, 0);
		color.ponColor();
		glBegin(GL_POLYGON);
		glVertex3d(posicion.x - 4, posicion.y - 3, 0);
		glVertex3d(posicion.x + 3, posicion.y + 4, 0);
		glVertex3d(posicion.x + 4, posicion.y + 3, 0);
		glVertex3d(posicion.x - 3, posicion.y - 4, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		break;
	}	
}
