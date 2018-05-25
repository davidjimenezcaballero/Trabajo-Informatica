#include "ListaCasillas.h"
#include "Interaccion.h"

ListaCasillas::ListaCasillas()
{
	/*numero = 10;
	for (int i = 0; i < MAX_CASILLA; i++)
		lista[i] = 0;*/
	for (int i = 0; i < 10; i++) {
		lista[i]->setPos(-45.0f + i * 10, 45);
	}
}

ListaCasillas::~ListaCasillas()
{
}

bool ListaCasillas::agregar(Casilla * c)
{
	for (int i = 0; i<numero; i++)//para evitar que se añada una casilla ya existente
		if (lista[i] == c)
			return false;
	if (numero < MAX_CASILLA)
		lista[numero++] = c;
	else
		return false;
	return true;
}

void ListaCasillas::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

/*void ListaCasillas::rebote(Casilla casilla)
{
	for (int i = 0; i<numero; i++)
		Interaccion::rebote(*(lista[i]), caja); // Acceso al contenido con *
}

void ListaEsferas::rebote(Pared p)
{
	for (int i = 0; i<numero; i++)
		Interaccion::rebote(*(lista[i]), p);
}*/

void ListaCasillas::destruirContenido()
{
	/*for (int i = 0; i<numero; i++)
		delete lista[i];
	numero = 0;*/
}

/*void ListaEsferas::rebote()
{
	for (int i = 0; i<numero - 1; i++)
		for (int j = i + 1; j<numero; j++)
			Interaccion::rebote(*(lista[i]), *(lista[j]));
}*/

void ListaCasillas::eliminar(int index)
{
	/*if ((index<0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i<numero; i++)
		lista[i] = lista[i + 1];*/
}

void ListaCasillas::eliminar(Casilla * c)
{
	/*for (int i = 0; i<numero; i++)
		if (lista[i] == c)
		{
			eliminar(i);
			return;
		}*/
}

/*
Esfera * ListaEsferas::colision(Hombre h)
{
	for (int i = 0; i<numero; i++)
	{
		if (Interaccion::colision(*(lista[i]), h))
			return lista[i];
	}
	return 0;
}*/
/*
Esfera* ListaEsferas::colision(Esfera &e) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::rebote(e, *(lista[i])))
			return lista[i];
	}
	return 0;
}*/

Casilla * ListaCasillas::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i<0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}
