#pragma once
#include "Interface.h"


class Fim : public Interface
{
	private:
		sf::Text fim;
		sf::Text pontuacao;
		sf::Text instrucao_1;
		sf::Text instrucao_2;

	public:
		Fim();
		~Fim();
		void executar();
		void desenhar();
		bool verificarInstrucao();
};

