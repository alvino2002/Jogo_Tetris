#include "EstadoComandos.h"

EstadoComandos::EstadoComandos() :
	Estado(),
	pEstadoTJ()
{
	pComandos = new Comandos();
}

EstadoComandos::~EstadoComandos()
{
	if (pComandos)
	{
		delete (pComandos);
		pComandos = nullptr;
	}
}

void EstadoComandos::executar()
{
	pComandos->executar();

	if (pComandos->verificarInstrucao())
	{
		TetrisJogo::resetarJogo();
		pEstadoTJ = new EstadoTetrisJogo();
		pGE->adicionarEstado(pEstadoTJ);
	}
}