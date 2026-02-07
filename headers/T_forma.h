#pragma once
#include "Forma.h"


class TetrisJogo;

class T_forma : public Forma
{
	public:
		T_forma();
		~T_forma();
		void definirGeometria(float posX, float posY, int estado);
		void rotacionar();
};

