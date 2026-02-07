#pragma once


class GerenciadorEstado;

class Estado
{
	public:
		Estado();
		~Estado();
		static GerenciadorEstado* pGE;
		virtual void executar() = 0;
};