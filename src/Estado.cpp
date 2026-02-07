#include "Estado.h"
#include "GerenciadorEstado.h"


Estado::Estado()
{
	pGE = GerenciadorEstado::getGerenciadorEstado();
}

Estado::~Estado()
{
	if (pGE)
	{
		delete (pGE);
		pGE = nullptr;
	}
}

GerenciadorEstado* Estado::pGE = nullptr;