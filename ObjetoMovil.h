#pragma once
#include"Vector2D.h"

class ObjetoMovil {		//Esta será una clase base

protected:
	Vector2D posicion;		// Atributo: posición
	Vector2D velocidad;		// Atributo: velocidad
	Vector2D aceleracion;	// Atributo: Aceleración

public:
	ObjetoMovil();					// Constructor
	virtual ~ObjetoMovil();			// Destrcutor
	Vector2D getPos();				// Acceso parte protected
	void setPos(float x, float y);	// Establecer posicion por el paso de dos parámetros float
	void setPos(Vector2D pos);		// Establecer posicion por el paso de un vector
	void setVel(float vx, float vy);// EStablecer velocidad por el paso de dos parámetros float
	void setVel(Vector2D vel);		// Establecer velocidad por el paso de  un vector
	void mueve(float t);			// Gestión del movimiento
};