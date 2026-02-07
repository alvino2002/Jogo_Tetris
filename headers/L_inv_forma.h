#pragma once
#include "Forma.h"


class TetrisJogo;

class L_inv_forma : public Forma
{
public:
	L_inv_forma();
	~L_inv_forma();
	void definirGeometria(float posX, float posY, int estado);
	void rotacionar();
};

