#include "EstadoTetrisJogo.h"


EstadoTetrisJogo::EstadoTetrisJogo():
	Estado(),
	pEstadoFim()
{
	pTetrisJogo = new TetrisJogo();
}

EstadoTetrisJogo::~EstadoTetrisJogo()
{
	if (pTetrisJogo)
	{
		delete pTetrisJogo;
		pTetrisJogo = nullptr;
	}
}

void EstadoTetrisJogo::executar()
{
	pTetrisJogo->executar();

	if (pTetrisJogo->verificarFimDoJogo())
	{
		pEstadoFim = new EstadoFim();
		pGE->adicionarEstado(pEstadoFim);
	}
}