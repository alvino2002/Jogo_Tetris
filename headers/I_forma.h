#pragma once
#include "Forma.h"


class TetrisJogo;

class I_forma : public Forma
{
	public:
		I_forma();
		~I_forma();
		void definirGeometria(float posX, float posY, int estado);
		void rotacionar();
};