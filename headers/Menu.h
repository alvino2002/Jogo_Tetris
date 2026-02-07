#pragma once
#include "Interface.h"


class Menu : public Interface
{
	private:
		sf::Text nome_jogo;
		sf::Text instrucao_1;
		sf::Text instrucao_2;

	public:
		Menu();
		~Menu();
		void executar();
		void desenhar();
		bool verificarInstrucao();	
};

