#include "Forma.h"
#include "TetrisJogo.h"


Forma::Forma():
	estado_atual(),
	disponivel_esq(),
	disponivel_dir(), 
	relogio_movimento(),
	relogio_fixacao(),
	ponto_rotacao()
	
{
	texturaBloco.loadFromFile("Textura.png");

	for (int i = 0; i < 4; i++)
	{
		blocos[i].setTexture(&texturaBloco);
		blocos[i].setSize(sf::Vector2f(25.f, 25.f)); // Cada quadrado terá dimensão 25x25 
		blocos[i].setOrigin(sf::Vector2f(12.5f, 12.5f));
	}

	cont_bloqueio = 0;
	em_superficie = false;
	disponivel_vert = true;
	duracao_movimento = 0.8f - TetrisJogo::nivel * 0.037f;
	duracao_fixacao = 0.3f;
	fixo = false;
	iniciou_fixacao = false;
	pGG = GerenciadorGrafico::getGerenciadorGrafico();
}

Forma::~Forma()
{
	
}

void Forma::criar(float posIniX, float posIniY, int estado)
{
	definirGeometria(posIniX, posIniY, estado);
}

sf::RectangleShape* Forma::pegarBloco(int i)
{
	return &blocos[i];
}

void Forma::moverHorizontal(bool sentido)
{
	disponivel_esq = true;
	disponivel_dir = true;

	for (int i = 0; i < 4 && disponivel_esq; i++)
	{
		int x = (int)(blocos[i].getPosition().x / 27);
		int y = (int)((blocos[i].getPosition().y - 120.f) / 27); //mudei aqui

		if (blocos[i].getPosition().x > 14.5f && TetrisJogo::disponivel(x - 1, y))
		{
			disponivel_esq = true;
		}

		else
		{
			disponivel_esq = false;
		}
	}

	for (int i = 0; i < 4 && disponivel_dir; i++)
	{
		int x = (int)(blocos[i].getPosition().x / 27);
		int y = (int)((blocos[i].getPosition().y - 120.f) / 27);

		if (blocos[i].getPosition().x < 257.5f && TetrisJogo::disponivel(x + 1, y))
		{
			disponivel_dir = true;
		}

		else
		{
			disponivel_dir = false;
		}
	}

	if (sentido != 1 && disponivel_esq) //Mover para esquerda
	{
		for (int i = 0; i < 4; i++)
		{
			blocos[i].move(sf::Vector2f(-27.f, 0));
		}

		ponto_rotacao.x -= 27.f;
	}
	
	else if (sentido == 1 && disponivel_dir) //Mover para direita
	{
		for (int i = 0; i < 4; i++)
		{
			blocos[i].move(sf::Vector2f(27.f, 0));
		}

		ponto_rotacao.x += 27.f;
	}
}

void Forma::moverVertical()
{
	em_superficie = false;

	for (int i = 0; i < 4 && !em_superficie; i++)
	{
		int x = (int)(blocos[i].getPosition().x / 27);
		int y = (int)((blocos[i].getPosition().y - 120.f) / 27); 

		if (blocos[i].getPosition().y < 647.5f && TetrisJogo::disponivel(x, y + 1)) 
		{
			em_superficie = false;
		}

		else
		{
			em_superficie = true;
		}
	}

	if (!em_superficie)
	{
		if (relogio_movimento.getElapsedTime().asSeconds() >= duracao_movimento)
		{
			for (int i = 0; i < 4; i++)
			{
				blocos[i].move(sf::Vector2f(0, 27.f));
			}
			relogio_movimento.restart();

			ponto_rotacao.y += 27.f;
		}

		iniciou_fixacao = false;
	}

	else
	{
		if (!iniciou_fixacao)
		{
			iniciou_fixacao = true;
			relogio_fixacao.restart();
		}

		if (relogio_fixacao.getElapsedTime().asSeconds() >= duracao_fixacao)
		{
			bool aindaComSuperficie = false;

			for (int i = 0; i < 4; i++)
			{
				int x = (int)(blocos[i].getPosition().x / 27);
				int y = (int)((blocos[i].getPosition().y - 120.f) / 27); 

				if (blocos[i].getPosition().y >= 647.5f ||
					!TetrisJogo::disponivel(x, y + 1))
				{
					aindaComSuperficie = true;
				}
			}

			if (aindaComSuperficie)
			{
				fixo = true;

				for (int k = 0; k < 4; k++)
				{
					int x = (int)(blocos[k].getPosition().x / 27);
					int y = (int)((blocos[k].getPosition().y - 120.f) / 27); //mudei aqui
					TetrisJogo::preencherGrid(x, y);
				}
			}
		}
	}
}

bool Forma::pegarFixo()
{
	return fixo;
}

void Forma::definirDuracaoMovimento(float duracao)
{
	duracao_movimento = duracao;
}

GerenciadorGrafico* Forma::pGG = nullptr;