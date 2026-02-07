#pragma once
#include "GerenciadorGrafico.h"


class Interface
{
	public:
		Interface();
		~Interface();
		static GerenciadorGrafico* pGG;
		sf::RenderWindow* janela;
		sf::Clock relogio_piscar;
		sf::Font fonte;
		bool visivel;
		virtual void executar() = 0;
		virtual void desenhar() = 0;
		virtual bool verificarInstrucao() = 0;
};

