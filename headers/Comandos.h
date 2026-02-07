#pragma once
#include "Interface.h"


class Comandos : public Interface
{
	private:
		sf::Text comando_1;
		sf::Text comando_2;
		sf::Text comando_3;
		sf::Text comando_4;
		sf::Text instrucao_1;
		sf::Text instrucao_2;

	public:
		Comandos();
		~Comandos();
		void executar();
		void desenhar();
		bool verificarInstrucao();
};

