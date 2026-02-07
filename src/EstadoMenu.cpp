#include "EstadoMenu.h"


EstadoMenu::EstadoMenu():
	Estado(),
	pEstadoComandos()
{
	pMenu = new Menu();
}

EstadoMenu::~EstadoMenu()
{
	if (pMenu)
	{
		delete pMenu;
		pMenu = nullptr;
	}
}

void EstadoMenu::executar()
{
	pMenu->executar();
	
	if (pMenu->verificarInstrucao())
	{
		pEstadoComandos = new EstadoComandos();
		pGE->adicionarEstado(pEstadoComandos);
	}
}