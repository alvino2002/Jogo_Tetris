#include "Menu.h"
#include <iostream>

Menu::Menu():
	Interface()
{
	nome_jogo.setFont(fonte);
	nome_jogo.setCharacterSize(37);
	nome_jogo.setFillColor(sf::Color::White);
	nome_jogo.setString("TETRIS");
	sf::FloatRect limite_nome = nome_jogo.getLocalBounds();
	nome_jogo.setOrigin(limite_nome.width / 2.0f, limite_nome.height / 2.0f);
	nome_jogo.setPosition(130.f, 250.f);

	instrucao_1.setFont(fonte);
	instrucao_1.setCharacterSize(14);
	instrucao_1.setFillColor(sf::Color::White);
	instrucao_1.setString("Aperte ESPAÇO");
	sf::FloatRect limite_instrucao_1 = instrucao_1.getLocalBounds();
	instrucao_1.setOrigin(limite_instrucao_1.width / 2.0f, limite_instrucao_1.height / 2.0f);
	instrucao_1.setPosition(136.f, 330.f);

	instrucao_2.setFont(fonte);
	instrucao_2.setCharacterSize(14);
	instrucao_2.setFillColor(sf::Color::White);
	instrucao_2.setString("para começar");
	sf::FloatRect limite_instrucao_2 = instrucao_2.getLocalBounds();
	instrucao_2.setOrigin(limite_instrucao_2.width / 2.0f, limite_instrucao_2.height / 2.0f);
	instrucao_2.setPosition(138.f, 350.f);
}

Menu::~Menu()
{
}

void Menu::desenhar()
{
	janela->clear();

	janela->draw(nome_jogo);

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

void Menu::executar()
{
	
	desenhar();
}

bool Menu::verificarInstrucao()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		return true;
	}

	return false;
}