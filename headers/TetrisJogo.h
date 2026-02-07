#pragma once
#include "I_forma.h"
#include "L_forma.h"
#include "L_inv_forma.h"
#include "Q_forma.h"
#include "S_forma.h"
#include "T_forma.h"
#include "Z_forma.h"
#include <vector>


class TetrisJogo
{
	private:
		sf::RenderWindow* janela;
		static GerenciadorGrafico* pGG;
		std::vector<sf::RectangleShape*> quadrados;
		Forma* forma;
		static int grid[10][20]; // 10 colunas e 20 linhas
		
	public:
		TetrisJogo();
		~TetrisJogo();
		static int pontuacao;
		static int linhas_totais;
		static int nivel;
		int estado;
		int sequencia[2]; // sequencia[0] : forma atual , sequencia[1] : próxima forma
		int linhas_completas;
		bool fim_do_jogo;
		sf::Font fonte;
		int sortear();
		void executar();
		void desenharFormaMovel(sf::RectangleShape forma);
		void desenharFormaFixa();
		void desenharPainel();
		void desenharProximo(int sorteado);
		void verificarLinhaCompleta();
		void apagarLinhaCompleta(int j);
		void aumentarPontuacao(int linhas_completas);
		void aumentarLinhas(int linhas_completas);
		void verificarNivel();
		bool verificarFimDoJogo();
		static bool disponivel(int i, int j);
		static void preencherGrid(int i, int j);
		static void resetarJogo();
};

