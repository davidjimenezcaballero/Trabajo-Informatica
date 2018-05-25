#include "ColorRGB.h"
#include "glut.h"

ColorRGB::ColorRGB(Byte _r, Byte _v, Byte _a)
{
	rojo = _r;
	verde = _v;
	azul = _a;
}

void ColorRGB::ponColor()
{
	glColor3ub(rojo, verde, azul);
}

ColorRGB::~ColorRGB()
{
}