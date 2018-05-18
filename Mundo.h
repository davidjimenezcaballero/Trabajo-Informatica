#pragma once
#include "Caja.h"
#include "Hombre.h"
#include "Esfera.h"
#include "Bonus.h"
#include "Disparo.h"
#include "ListaEsferas.h"
#include "ListaDisparos.h"	
#include "Casilla.h"
#include "Tablero.h"
#include "Cubo.h"


class Mundo {

	Tablero tablero;
	Casilla casilla1;
	Casilla casilla2;
	Casilla casilla3;

	/*ListaEsferas esferas;
	ListaDisparos disparos;
	Hombre hombre;
	Pared plataforma;
	Disparo disparo;*/

	Bonus bonus;
	Esfera esfera;
	Cubo cubo;
	Caja caja;

	float x_ojo;
	float y_ojo;
	float z_ojo;

public:
	~Mundo();

	void setVista(float x, float y, float z);
	void Tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void Inicializa();
	void RotarOjo();
	void Mueve();
	void Dibuja();
};