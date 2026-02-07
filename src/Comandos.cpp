#include "Comandos.h"

Comandos::Comandos():
	Interface()
{
	comando_1.setFont(fonte);
	comando_1.setCharacterSize(11);
	comando_1.setFillColor(sf::Color::White);
	comando_1.setString("RIGHT: Mover para direita");
	comando_1.setPosition(2.f, 60.f);

	comando_2.setFont(fonte);
	comando_2.setCharacterSize(11);
	comando_2.setFillColor(sf::Color::White);
	comando_2.setString("LEFT: Mover para esquerda");
	comando_2.setPosition(2.f, 100.f);

	comando_3.setFont(fonte);
	comando_3.setCharacterSize(11);
	comando_3.setFillColor(sf::Color::White);
	comando_3.setString("DOWN: Forçar queda");
	comando_3.setPosition(2.f, 140.f);

	comando_4.setFont(fonte);
	comando_4.setCharacterSize(11);
	comando_4.setFillColor(sf::Color::White);
	comando_4.setString("SPACE: Rotacionar");
	comando_4.setPosition(2.f, 180.f);

	instrucao_1.setFont(fonte);
	instrucao_1.setCharacterSize(14);
	instrucao_1.setFillColor(sf::Color::White);
	instrucao_1.setString("Aperte I");
	instrucao_1.setPosition(80.f, 330.f);

	instrucao_2.setFont(fonte);
	instrucao_2.setCharacterSize(14);
	instrucao_2.setFillColor(sf::Color::White);
	instrucao_2.setString("para iniciar");
	instrucao_2.setPosition(55.f, 350.f);
}

Comandos::~Comandos()
{

}

void Comandos::executar()
{
	desenhar();
}

void Comandos::desenhar()
{
	janela->clear();

	janela->draw(comando_1);
	janela->draw(comando_2);
	janela->draw(comando_3);
	janela->draw(comando_4);

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

bool Comandos::verificarInstrucao()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		return true;
	}

	return false;
}