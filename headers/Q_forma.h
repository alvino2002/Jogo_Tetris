#pragma once
#include "Forma.h"


class TetrisJogo;

class Q_forma : public Forma
{
	public:
		Q_forma();
		~Q_forma();
		void definirGeometria(float posX, float posY, int estado);
		void rotacionar();
};

