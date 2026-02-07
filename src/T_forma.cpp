#include "T_forma.h"
#include "TetrisJogo.h"


T_forma::T_forma():
    Forma()
{
    
}

T_forma::~T_forma()
{

}

void T_forma::definirGeometria(float posX, float posY, int estado)
{
    ponto_rotacao = sf::Vector2f(posX, posY);

    estado_atual = estado;

    /* Ponto de rotação: centro de um grid 3X3 */
    if (estado == 1)
    {
        blocos[0].setPosition(sf::Vector2f(posX - 27.f, posY));
        blocos[1].setPosition(sf::Vector2f(posX, posY));
        blocos[2].setPosition(sf::Vector2f(posX + 27.f, posY));
        blocos[3].setPosition(sf::Vector2f(posX, posY - 27.f));
    }
    else if (estado == 2)
    {
        blocos[0].setPosition(sf::Vector2f(posX, posY - 27.f));
        blocos[1].setPosition(sf::Vector2f(posX, posY));
        blocos[2].setPosition(sf::Vector2f(posX, posY + 27.f));
        blocos[3].setPosition(sf::Vector2f(posX + 27.f, posY));
    }
    else if (estado == 3)
    {
        blocos[0].setPosition(sf::Vector2f(posX + 27.f, posY));
        blocos[1].setPosition(sf::Vector2f(posX, posY));
        blocos[2].setPosition(sf::Vector2f(posX - 27.f, posY));
        blocos[3].setPosition(sf::Vector2f(posX, posY + 27.f));
    }
    else
    {
        blocos[0].setPosition(sf::Vector2f(posX, posY + 27.f));
        blocos[1].setPosition(sf::Vector2f(posX, posY));
        blocos[2].setPosition(sf::Vector2f(posX, posY - 27.f));
        blocos[3].setPosition(sf::Vector2f(posX - 27.f, posY));
    }
}

void T_forma::rotacionar()
{
    int estado_desejado = 0;
    estado_desejado = (estado_atual + cont_bloqueio) % 4 + 1;
    int x = 0;
    int y = 0;
    x = (int)(ponto_rotacao.x / 27);
    y = (int)((ponto_rotacao.y - 120.f) / 27); 

    /* ==================================== Estado 1 =============================================== */

    if (estado_desejado == 1)
    {
        if (x == 9)
        {
            x = 8;
            ponto_rotacao.x -= 27.f;
        }

        if (!TetrisJogo::disponivel(x + 1, y) && x > 1)
        {
            x--;
            ponto_rotacao.x -= 27.f;

            if (TetrisJogo::disponivel(x, y) && TetrisJogo::disponivel(x - 1, y) &&
                TetrisJogo::disponivel(x + 1, y) && TetrisJogo::disponivel(x, y - 1))
            {
                definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                cont_bloqueio = 0;
            }

            else
            {
                cont_bloqueio++;
            }
        }

        else if (TetrisJogo::disponivel(x + 1, y))
        {
            if (TetrisJogo::disponivel(x, y) && TetrisJogo::disponivel(x - 1, y) &&
                TetrisJogo::disponivel(x + 1, y) && TetrisJogo::disponivel(x, y - 1))
            {
                definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                cont_bloqueio = 0;
            }

            else
            {
                cont_bloqueio++;
            }
        }

        else
        {
            cont_bloqueio++;
        }
    }

    /* ==================================== Estado 2 =============================================== */

    if (estado_desejado == 2)
    {
        if (y == 19)
        {
            y = 18;
            ponto_rotacao.y -= 27.f;
        }

        if (!TetrisJogo::disponivel(x, y + 1) && y > 1)
        {
            y--;
            ponto_rotacao.y -= 27.f;

            if (TetrisJogo::disponivel(x, y) && TetrisJogo::disponivel(x, y + 1) &&
                TetrisJogo::disponivel(x, y - 1) && TetrisJogo::disponivel(x + 1, y))
            {
                definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                cont_bloqueio = 0;
            }

            else
            {
                cont_bloqueio++;
            }
        }

        else if (TetrisJogo::disponivel(x, y + 1))
        {
            if (TetrisJogo::disponivel(x, y) && TetrisJogo::disponivel(x, y + 1) &&
                TetrisJogo::disponivel(x, y - 1) && TetrisJogo::disponivel(x + 1, y))
            {
                definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                cont_bloqueio = 0;
            }

            else
            {
                cont_bloqueio++;
            }
        }

        else
        {
            cont_bloqueio++;
        }
    }

    /* ==================================== Estado 3 =============================================== */

    if (estado_desejado == 3)
    {

        if (x == 0)
        {
            x = 1;
            ponto_rotacao.x += 27.f;
        }


        if (!TetrisJogo::disponivel(x - 1, y) && x < 8)
        {
            x++;
            ponto_rotacao.x += 27.f;

            if (TetrisJogo::disponivel(x, y) && TetrisJogo::disponivel(x - 1, y) &&
                TetrisJogo::disponivel(x + 1, y) && TetrisJogo::disponivel(x, y + 1))
            {
                definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                cont_bloqueio = 0;
            }

            else
            {
                cont_bloqueio++;
            }
        }

        else if (TetrisJogo::disponivel(x - 1, y))
        {
            if (TetrisJogo::disponivel(x, y) && TetrisJogo::disponivel(x - 1, y) &&
                TetrisJogo::disponivel(x + 1, y) && TetrisJogo::disponivel(x, y + 1))
            {
                definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                cont_bloqueio = 0;
            }

            else
            {
                cont_bloqueio++;
            }
        }

        else
        {
            cont_bloqueio++;
        }
    }

    /* ==================================== Estado 4 =============================================== */

    if (estado_desejado == 4)
    {
        if (y == 0)
        {
            y = 1;
            ponto_rotacao.y += 27.f;
        }

        if (!TetrisJogo::disponivel(x, y - 1) && y < 17)
        {
            y++;
            ponto_rotacao.y += 27.f;

            if (TetrisJogo::disponivel(x, y) && TetrisJogo::disponivel(x, y + 1) &&
                TetrisJogo::disponivel(x, y - 1) && TetrisJogo::disponivel(x - 1, y))
            {
                definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                cont_bloqueio = 0;
            }

            else
            {
                cont_bloqueio++;
            }
        }

        else if (TetrisJogo::disponivel(x, y - 1))
        {
            if (TetrisJogo::disponivel(x, y) && TetrisJogo::disponivel(x, y + 1) &&
                TetrisJogo::disponivel(x, y - 1) && TetrisJogo::disponivel(x - 1, y))
            {
                definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                cont_bloqueio = 0;
            }

            else
            {
                cont_bloqueio++;
            }
        }

        else
        {
            cont_bloqueio++;
        }
    }
}