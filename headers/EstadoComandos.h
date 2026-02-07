#pragma once
#include "Estado.h"
#include "Comandos.h"
#include "EstadoTetrisJogo.h"


class EstadoComandos : public Estado
{
	private:
		Comandos* pComandos;

	public:
		EstadoComandos();
		~EstadoComandos();
		EstadoTetrisJogo* pEstadoTJ;
		void executar();
};