#include "Interface.h"


Interface::Interface():
	relogio_piscar()
{
	fonte.loadFromFile("PressStart2P-Regular.ttf");
	visivel = true;
	pGG = GerenciadorGrafico::getGerenciadorGrafico();
	janela = pGG->pegarJanela();
}

Interface::~Interface()
{
}

GerenciadorGrafico* Interface::pGG = nullptr;