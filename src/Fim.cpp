#include "Fim.h"
#include "TetrisJogo.h"


Fim::Fim():
	Interface()
{

	fim.setFont(fonte);
	fim.setCharacterSize(22);
	fim.setFillColor(sf::Color::White);
	fim.setString("FIM DO JOGO");
	fim.setPosition(18.f, 250.f);

	pontuacao.setFont(fonte);
	pontuacao.setCharacterSize(14);
	pontuacao.setFillColor(sf::Color::White);
	pontuacao.setString("Pontuação: " + std::to_string(TetrisJogo::pontuacao));
	pontuacao.setPosition(50.f, 300.f);

	instrucao_1.setFont(fonte);
	instrucao_1.setCharacterSize(14);
	instrucao_1.setFillColor(sf::Color::White);
	instrucao_1.setString("Aperte ENTER");
	sf::FloatRect limite_instrucao_1 = instrucao_1.getLocalBounds();
	instrucao_1.setOrigin(limite_instrucao_1.width / 2.0f, limite_instrucao_1.height / 2.0f);
	instrucao_1.setPosition(136.f, 360.f);

	instrucao_2.setFont(fonte);
	instrucao_2.setCharacterSize(14);
	instrucao_2.setFillColor(sf::Color::White);
	instrucao_2.setString("para voltar ao Menu");
	sf::FloatRect limite_instrucao_2 = instrucao_2.getLocalBounds();
	instrucao_2.setOrigin(limite_instrucao_2.width / 2.0f, limite_instrucao_2.height / 2.0f);
	instrucao_2.setPosition(136.f, 380.f);
}

Fim::~Fim()
{

}

void Fim::desenhar()
{
	janela->clear();

	janela->draw(fim);
	janela->draw(pontuacao);

	if (relogio_piscar.getElapsedTime().asSeconds() >= 0.6f) 
	{
		visivel = !visivel;
		relogio_piscar.restart();
	}

	if (visivel) 
	{
		janela->draw(instrucao_1);
		janela->draw(instrucao_2);
	}

	janela->display();

}

void Fim::executar()
{
	desenhar();
}

bool Fim::verificarInstrucao()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		return true;
	}

	return false;
}