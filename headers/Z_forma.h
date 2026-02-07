#pragma once
#include "Forma.h"


class TetrisJogo;

class Z_forma : public Forma
{
	public:
		Z_forma();
		~Z_forma();
		void definirGeometria(float posX, float posY, int estado);
		void rotacionar();
};

