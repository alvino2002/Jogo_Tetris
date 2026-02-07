#pragma once
#include "Estado.h"
#include "TetrisJogo.h"
#include "EstadoFim.h"


class EstadoTetrisJogo : public Estado
{
	private:
		TetrisJogo* pTetrisJogo;

	public:
		EstadoTetrisJogo();
		~EstadoTetrisJogo();
		void executar();
		EstadoFim* pEstadoFim;
};