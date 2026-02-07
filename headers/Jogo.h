#pragma once
#include "GerenciadorEstado.h"
#include "EstadoMenu.h"
#include "GerenciadorGrafico.h"


class Jogo
{
	public:
		Jogo();
		~Jogo();
		void rodarJogo();
		GerenciadorEstado* pGE;
		GerenciadorGrafico* pGG;
		EstadoMenu* pEstadoMenu;
};