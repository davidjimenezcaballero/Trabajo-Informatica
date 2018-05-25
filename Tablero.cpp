#include "Tablero.h"

Tablero::Tablero(int t)
{
	tipo = t;
}

Tablero::~Tablero()
{
}

void Tablero::setTamanio(int a, int b) {
	if ((a < 4) || (b < 4)) {
		max_horizontal = 5; max_vertical = 5; inicializa(tipo); return;
	}
	if (a > MAX_HORIZONTAL || b > MAX_VERTICAL) {
		max_horizontal = 20; max_vertical = 20; inicializa(tipo); return;
	}
	if (a > 4 && b > 4 && a < MAX_HORIZONTAL&&b < MAX_VERTICAL) {
		max_horizontal = a; max_vertical = b; inicializa(tipo);
	}
}

void Tablero::dibuja()
{
	for (int i = 0; i < max_horizontal; i++)
		for (int j = 0; j < max_vertical; j++)
			lista_casillas[i][j].dibuja();
}

void Tablero::inicializa(int tipo)
{
	switch (tipo) {
	case 1:
		for (int i = 0; i < max_horizontal; i++) {
			for (int j = 0; j < max_vertical; j++) {
				lista_casillas[i][j].setPos(-45.0f + i * 10, -45.0f + j * 10);
			}
		}

		for (int i = 0; i < max_horizontal; i++) {
			if (i % 2 == 0) {
				for (int j = 0; j < max_vertical; j++)
					if (j % 2 == 0)
						lista_casillas[i][j].setColor(100, 100, 100);
			}
			else {
				for (int j = 0; j < max_vertical; j++)
					if (j % 2 == 0)
						lista_casillas[i][j].setColor(255, 255, 255);
					else
						lista_casillas[i][j].setColor(100, 100, 100);
			}
		}
		break;
	case 2:
		break;
	}
}


