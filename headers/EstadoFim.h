#pragma once
#include "Estado.h"
#include "Fim.h"
#include "GerenciadorEstado.h"


class EstadoMenu; // Evitar include circular

class EstadoFim : public Estado
{
	private:
		Fim* pFim;

	public:
		EstadoFim();
		~EstadoFim();
		EstadoMenu* pEstadoMenu;
		void executar();
};

