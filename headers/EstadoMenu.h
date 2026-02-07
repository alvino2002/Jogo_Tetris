#pragma once
#include "Estado.h"
#include "Menu.h"
#include "EstadoComandos.h"


class EstadoMenu : public Estado
{
	private:
		Menu* pMenu;

	public:
		EstadoMenu();
		~EstadoMenu();
		EstadoComandos* pEstadoComandos;
		void executar();
};