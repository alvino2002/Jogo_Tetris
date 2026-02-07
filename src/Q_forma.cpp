#include "Q_forma.h"
#include "TetrisJogo.h"


Q_forma::Q_forma():
    Forma()
{
   
}

Q_forma::~Q_forma()
{

}

void Q_forma::definirGeometria(float posX, float posY, int estado)
{
    ponto_rotacao = sf::Vector2f(posX, posY);

    estado_atual = estado;

    /* Caso especial: todos os estados são iguais */
    if (estado)
    {
        blocos[0].setPosition(sf::Vector2f(posX - 13.5f, posY - 13.5f));
        blocos[1].setPosition(sf::Vector2f(posX - 13.5f, posY + 13.5f));
        blocos[2].setPosition(sf::Vector2f(posX + 13.5f, posY - 13.5f));
        blocos[3].setPosition(sf::Vector2f(posX + 13.5f, posY + 13.5f));
    }
}

void Q_forma::rotacionar()
{
    definirGeometria(ponto_rotacao.x, ponto_rotacao.y, 1);
}