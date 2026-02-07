#pragma once
#include "Forma.h"


class TetrisJogo;

class S_forma : public Forma
{
	public:
		S_forma();
		~S_forma();
		void definirGeometria(float posX, float posY, int estado);
		void rotacionar();
};

