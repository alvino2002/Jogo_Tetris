#pragma once
#include <SFML/Graphics.hpp>

/* Referência utilizada: Ex-Monitor de Técnicas De Programação Giovane Limas Salvi */
/* Canal: https://www.youtube.com/@gege171/featured */

class GerenciadorGrafico
{
	private:
		sf::RenderWindow* janela;
		static GerenciadorGrafico* pGerenciadorGrafico; // Ponteiro Global, Singleton
		GerenciadorGrafico();

	public:
		~GerenciadorGrafico();
		static GerenciadorGrafico* getGerenciadorGrafico();
		sf::RenderWindow* pegarJanela();
		void limparJanela();
		void fecharJanela();
		const bool verificaJanelaAberta();
		void mostrarJogo();
		static void deletar();
};

