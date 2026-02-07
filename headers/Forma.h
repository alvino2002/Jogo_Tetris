#pragma once
#include "GerenciadorGrafico.h"


/* Referência para criar o sistema de rotação: https://tetris.wiki/Super_Rotation_System */

class TetrisJogo;

class Forma
{
	/* Cada corpo (peça) é formado geometricamente por quadro quadrados de tamanhos iguais */
	/* Entre duas peças, haverá um espaçamento de 2 pixels */

	public:
		sf::RectangleShape blocos[4];
		sf::Texture texturaBloco;
		int estado_atual; // Cada peça apresentará 4 estados de rotação 
		int cont_bloqueio; // Variável para contabilizar quantas rotações estão bloqueadas
		sf::Vector2f ponto_rotacao; // A peça rotacionará em torno desse ponto
		bool em_superficie;
		bool disponivel_esq;
		bool disponivel_dir;
		bool disponivel_vert;
		sf::Clock relogio_movimento;
		float duracao_movimento;
		sf::Clock relogio_fixacao;
		float duracao_fixacao;
		bool fixo;
		bool iniciou_fixacao;
		static GerenciadorGrafico* pGG;

	public:
		Forma();
		~Forma();
		void criar(float posIniX, float posIniY, int estado); // Método para criar a peça 
		virtual void definirGeometria(float posX, float posY, int estado) = 0; // Definir posição dos blocos
		sf::RectangleShape* pegarBloco(int i);
		void moverHorizontal(bool sentido);
		void moverVertical();
		virtual void rotacionar() = 0;
		bool pegarFixo();
		void definirDuracaoMovimento(float duracao); // Impulsionar
};
