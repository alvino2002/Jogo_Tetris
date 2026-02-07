#include "Jogo.h"

Jogo::Jogo():
	pEstadoMenu()
{
	pGE = GerenciadorEstado::getGerenciadorEstado();
	pGG = GerenciadorGrafico::getGerenciadorGrafico();
}

Jogo::~Jogo()
{
}

void Jogo::rodarJogo()
{
	pEstadoMenu = new EstadoMenu();
	pGE->adicionarEstado(pEstadoMenu);

	while (pGG->verificaJanelaAberta())
	{
		sf::Event evento;

		while (pGG->pegarJanela()->pollEvent(evento))
		{
			if (evento.type == sf::Event::Closed)
			{
				pGG->fecharJanela();
			}
		}
		pGE->executar();
	}

}
