#include "EstadoFim.h"
#include "EstadoMenu.h"


EstadoFim::EstadoFim() :
	Estado(),
	pEstadoMenu()
{
	pFim = new Fim();
}

EstadoFim::~EstadoFim()
{
	if (pFim)
	{
		delete pFim;
		pFim = nullptr;
	}
}

void EstadoFim::executar()
{
	pFim->executar();

	if (pFim->verificarInstrucao())
	{
		pEstadoMenu = new EstadoMenu();
		pGE->adicionarEstado(pEstadoMenu);
	}
}