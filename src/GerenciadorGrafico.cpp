#include "GerenciadorGrafico.h"


GerenciadorGrafico::GerenciadorGrafico() :
	janela(new sf::RenderWindow(sf::VideoMode(272.f, 662.f), "Tetris")) //mudei aqui
{
	
}

GerenciadorGrafico::~GerenciadorGrafico()
{
	if (janela)
	{
		delete janela;
		janela = nullptr;
	}

	deletar();
}

GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico()
{
	if (pGerenciadorGrafico == nullptr)
	{
		pGerenciadorGrafico = new GerenciadorGrafico();
	}
	return pGerenciadorGrafico;
}

sf::RenderWindow* GerenciadorGrafico::pegarJanela()
{
	return janela;
}

void GerenciadorGrafico::limparJanela()
{
	janela->clear();
}

void GerenciadorGrafico::fecharJanela()
{
	janela->close();
}

const bool GerenciadorGrafico::verificaJanelaAberta()
{
	return (janela->isOpen());
}

void GerenciadorGrafico::mostrarJogo()
{
	janela->display();
}

void GerenciadorGrafico::deletar()
{
	if (pGerenciadorGrafico)
	{
		delete pGerenciadorGrafico;
		pGerenciadorGrafico = nullptr;
	}
}

GerenciadorGrafico* GerenciadorGrafico::pGerenciadorGrafico = nullptr;