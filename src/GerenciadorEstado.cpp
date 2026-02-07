#include "GerenciadorEstado.h"


GerenciadorEstado::GerenciadorEstado()
{

}

GerenciadorEstado* GerenciadorEstado::getGerenciadorEstado()
{
	if (pGerenciadorEstado == nullptr)
	{
		pGerenciadorEstado = new GerenciadorEstado();
	}
	else
	{
		return pGerenciadorEstado;
	}
}

GerenciadorEstado::~GerenciadorEstado()
{
}

void GerenciadorEstado::executar()
{
	if (!pilhaEstados.empty() && pilhaEstados.top() != nullptr)
	{
		pilhaEstados.top()->executar();
	}
}

void GerenciadorEstado::adicionarEstado(Estado* estado)
{
	
	if (estado)
	{
		pilhaEstados.push(estado);
	}
}

void GerenciadorEstado::limparPilha()
{
	while (pilhaEstados.empty() != true)
	{
		if (pilhaEstados.top() != nullptr)
		{
			delete (pilhaEstados.top());
			pilhaEstados.pop();
		}
	}
}

GerenciadorEstado* GerenciadorEstado::pGerenciadorEstado = nullptr;