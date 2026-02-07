#pragma once
#include "Forma.h"


class TetrisJogo;

class L_forma : public Forma
{
	public:
		L_forma();
		~L_forma();
		void definirGeometria(float posX, float posY, int estado);
		void rotacionar();
};

