#include "Interaccion.h"

void Interaccion::rebote(Hombre &h, Caja c)
{
	float xmax = c.frontal.limite2.x;
	float xmin = c.frontal.limite1.x;
	if (h.posicion.x > xmax)h.posicion.x = xmax;
	if (h.posicion.x < xmin)h.posicion.x = xmin;
}

bool Interaccion::rebote(Bonus & b, Caja c)
{
	Vector2D dir;
	float dif = c.frontal.distancia(b.posicion, &dir) -b.lado;
	if (dif < 0.0f) {
		Vector2D v_inicial = b.velocidad;
		b.velocidad = v_inicial - dir * 2.0*(v_inicial*dir);
		b.posicion = b.posicion - dir * dif;
		return true;
	}
	return false;
}

bool Interaccion::rebote(Esfera &e, Pared p)
{
	Vector2D dir;
	float dif = p.distancia(e.posicion, &dir) - e.radio;
	if (dif <= 0.0f)
	{
		Vector2D v_inicial = e.velocidad;
		e.velocidad = v_inicial - dir * 2.0*(v_inicial*dir);
		e.posicion = e.posicion - dir * dif;
		return true;
	}
	return false;
}

void Interaccion::rebote(Esfera& e, Caja c)
{
	rebote(e, c.frontal);
	rebote(e, c.trasera);
	rebote(e, c.pared_dcha);
	rebote(e, c.pared_izq);
}

bool Interaccion::rebote(Esfera &esfera1, Esfera &esfera2)
{
	//Vector que une los centros
	Vector2D dif = esfera2.posicion - esfera1.posicion;
	float d = dif.modulo();
	float dentro = d - (esfera1.radio + esfera2.radio);

	if (dentro<0.0f)//si hay colision
	{
		//El modulo y argumento de la velocidad de la pelota1
		float v1 = esfera1.velocidad.modulo();
		float ang1 = esfera1.velocidad.argumento();

		//El modulo y argumento de la velocidad de la pelota2
		float v2 = esfera2.velocidad.modulo();
		float ang2 = esfera2.velocidad.argumento();

		//el argumento del vector que une los centros
		float angd = dif.argumento();

		//Separamos las esferas, lo que se han incrustado
		//la mitad cada una
		Vector2D desp(dentro / 2 * cos(angd), dentro / 2 * sin(angd));
		esfera1.posicion = esfera1.posicion + desp;
		esfera2.posicion = esfera2.posicion - desp;

		angd = angd - 3.14159f / 2;//la normal al choque

								   //El angulo de las velocidades en el sistema relativo antes del choque
		float th1 = ang1 - angd;
		float th2 = ang2 - angd;

		//Las componentes de las velocidades en el sistema relativo ANTES del choque
		float u1x = v1 * cos(th1);
		float u1y = v1 * sin(th1);
		float u2x = v2 * cos(th2);
		float u2y = v2 * sin(th2);

		//Las componentes de las velocidades en el sistema relativo DESPUES del choque
		//la componente en X del sistema relativo no cambia
		float v1x = u1x;
		float v2x = u2x;

		//en el eje Y, rebote elastico
		float m1 = esfera1.radio;
		float m2 = esfera2.radio;
		float py = m1 * u1y + m2 * u2y;//Cantidad de movimiento inicial ejey
		float ey = m1 * u1y*u1y + m2 * u2y*u2y;//Energia cinetica inicial ejey

											   //los coeficientes y discriminante de la ecuacion cuadrada
		float a = m2 * m2 + m1 * m2;
		float b = -2 * py*m2;
		float c = py * py - m1 * ey;
		float disc = b * b - 4 * a*c;
		if (disc<0)disc = 0;

		//las nuevas velocidades segun el eje Y relativo
		float v2y = (-b + sqrt(disc)) / (2 * a);
		float v1y = (py - m2 * v2y) / m1;

		//Modulo y argumento de las velocidades en coordenadas absolutas
		float modv1, modv2, fi1, fi2;
		modv1 = sqrt(v1x*v1x + v1y * v1y);
		modv2 = sqrt(v2x*v2x + v2y * v2y);
		fi1 = angd + atan2(v1y, v1x);
		fi2 = angd + atan2(v2y, v2x);

		//Velocidades en absolutas despues del choque en componentes
		esfera1.velocidad.x = modv1 * cos(fi1);
		esfera1.velocidad.y = modv1 * sin(fi1);
		esfera2.velocidad.x = modv2 * cos(fi2);
		esfera2.velocidad.y = modv2 * sin(fi2);
	}
	return false;
}

bool Interaccion::colision(Esfera e, Hombre h)
{
	Vector2D pos = h.getPos(); //la posicion de la base del hombre
	pos.y += h.getAltura() / 2.0f; //posicion del centro
	float distancia = (e.posicion - pos).modulo();
	if (distancia<e.radio)
		return true;
	return false;
}

bool Interaccion::colision(Disparo d, Pared p)
{
	Vector2D pos = d.getPos();
	float dist = p.distancia(pos);
	if (dist<d.getRadio())
		return true;
	return false;
}

bool Interaccion::colision(Disparo d, Caja c)
{
	return colision(d, c.trasera);
}

Interaccion::Interaccion()
{
}

Interaccion::~Interaccion()
{
}

//----------------------------------------------------------------------------------------
void Interaccion::choque(Esfera & e, Caja c)
{
	float xmin = c.frontal.limite1.x + 5.0f;
	float xmax = c.frontal.limite2.x - 5.0f;
	float ymax = c.pared_dcha.limite2.y - 5.0f;
	float ymin = c.pared_dcha.limite1.y + 5.0f;

	// Límites de movimiento horizontal
	if (e.posicion.x <= (xmin))e.posicion.x = xmin;
	if (e.posicion.x >= xmax)e.posicion.x = xmax;

	//Límites de movimiento vertical
	if (e.posicion.y <= ymin)e.posicion.y = ymin;
	if (e.posicion.y >= ymax)e.posicion.y = ymax;
}

void Interaccion::choque(Cubo & b, Caja c)
{
	float xmin = c.frontal.limite1.x + 5.0f;
	float xmax = c.frontal.limite2.x - 5.0f;
	float ymax = c.pared_dcha.limite2.y - 5.0f;
	float ymin = c.pared_dcha.limite1.y + 5.0f;

	// Límites de movimiento horizontal
	if (b.posicion.x <= (xmin))b.posicion.x = xmin;
	if (b.posicion.x >= xmax)b.posicion.x = xmax;

	//Límites de movimiento vertical
	if (b.posicion.y <= ymin)b.posicion.y = ymin;
	if (b.posicion.y >= ymax)b.posicion.y = ymax;
}

bool Interaccion::movimiento_vertical(Esfera & e, Tablero t)
{
	// Permite el movimiento vertical si se encuentra en una de las casillas
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if ((e.posicion.x == t.lista_casillas[i][j].posicion.x))
				return true;
		}
	}
	return false;
}

bool Interaccion::movimiento_horizontal(Esfera & e, Tablero t)
{
	// Permite el movimiento vertical si se encuentra en una de las casillas
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (e.posicion.y == t.lista_casillas[i][j].posicion.y)
				return true;
		}
	}
	return false;
	
}