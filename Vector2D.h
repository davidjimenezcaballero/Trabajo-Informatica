#pragma once
#include <cmath>

class Vector2D{
public:		//atributos
	float x;
	float y;

public:		//métodos
	Vector2D(float xv = 0.0f, float yv = 0.0f); // Constructor
	virtual ~Vector2D();						// Destructor

	float modulo();						//módulo del vector
	float argumento();					//argumento del vector
	Vector2D unitario();				//devuelve un vector unitario
	Vector2D operator-(Vector2D &);		//resta de vectores
	Vector2D operator+(Vector2D &);		//suma de vectores
	float operator*(Vector2D &);		//producto escalar de vectores
	Vector2D operator*(float);			//Producto de un vector por un escalar
	//Vector2D operator+(Vector2D op);
	Vector2D operator+(float real);

};