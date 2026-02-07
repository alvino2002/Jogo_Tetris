#pragma once
#include <stack>
#include "Estado.h"

/* Esta classe, em conjunto com a classe Estado, definem o estado atual do jogo */

/* Referência utilizada: Ex-Monitor de Técnicas De Programação Matheus Burda */
/* Canal: https://www.youtube.com/channel/UCrNDrGwDXmBErjp0BGqqOUw/featured */

class GerenciadorEstado
{
	private:
		std::stack <Estado*> pilhaEstados;
		static GerenciadorEstado* pGerenciadorEstado;
		GerenciadorEstado();

	public:
		~GerenciadorEstado();
		static GerenciadorEstado* getGerenciadorEstado();
		void executar();
		void adicionarEstado(Estado* estado);
		void limparPilha();
};