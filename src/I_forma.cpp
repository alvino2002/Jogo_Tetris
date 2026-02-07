#include "I_forma.h"
#include "TetrisJogo.h"


I_forma::I_forma():
    Forma()
{

}

I_forma::~I_forma()
{

}

void I_forma::definirGeometria(float posX, float posY, int estado)
{
    ponto_rotacao = sf::Vector2f(posX, posY);

    estado_atual = estado;

    /* Ponto de rotação: centro de um grid 4X4 */
    if (estado == 1)
    {
        blocos[0].setPosition(sf::Vector2f(posX - 40.5f, posY - 13.5f)); 
        blocos[1].setPosition(sf::Vector2f(posX - 13.5f, posY - 13.5f)); 
        blocos[2].setPosition(sf::Vector2f(posX + 13.5f, posY - 13.5f));
        blocos[3].setPosition(sf::Vector2f(posX + 40.5f, posY - 13.5f));
    }

    else if (estado == 2)
    {
        blocos[0].setPosition(sf::Vector2f(posX + 13.5f, posY - 40.5f));
        blocos[1].setPosition(sf::Vector2f(posX + 13.5f, posY - 13.5f));
        blocos[2].setPosition(sf::Vector2f(posX + 13.5f, posY + 13.5f));
        blocos[3].setPosition(sf::Vector2f(posX + 13.5f, posY + 40.5f));
    }

    else if (estado == 3)
    {
        blocos[0].setPosition(sf::Vector2f(posX + 40.5f, posY + 13.5f));
        blocos[1].setPosition(sf::Vector2f(posX + 13.5f, posY + 13.5f));
        blocos[2].setPosition(sf::Vector2f(posX - 13.5f, posY + 13.5f));
        blocos[3].setPosition(sf::Vector2f(posX - 40.5f, posY + 13.5f));
    }

    else
    {
        blocos[0].setPosition(sf::Vector2f(posX - 13.5f, posY + 40.5f));
        blocos[1].setPosition(sf::Vector2f(posX - 13.5f, posY + 13.5f));
        blocos[2].setPosition(sf::Vector2f(posX - 13.5f, posY - 13.5f));
        blocos[3].setPosition(sf::Vector2f(posX - 13.5f, posY - 40.5f));
    }
}

void I_forma::rotacionar()
{
    int estado_desejado = 0;
    estado_desejado = (estado_atual + cont_bloqueio) % 4 + 1;
    int x = 0;
    int y = 0;

    /* ==================================== Estado 1 =============================================== */

    if (estado_desejado == 1)
    {
        /* Posições do ponto de referência */
        x = (int)(ponto_rotacao.x / 27);
        y = (int)((ponto_rotacao.y - 120.f) / 27) - 1; 

        if (x == 10)
        {
            x = 9;
            ponto_rotacao.x -= 27.f;
        }

        if (TetrisJogo::disponivel(x, y))
        {
            /* Analisando quantas posições estão livres à direita */
            int dir = x + 1;
            while (dir != 10 && TetrisJogo::disponivel(dir, y)) // 10 é parede
            {
                dir++;
            }

            /* Analisando quantas posições estão livres à esquerda */
            int esq = x - 1;
            while (esq != -1 && TetrisJogo::disponivel(esq, y)) // -1 é parede 
            {
                esq--;
            }

            if (dir - esq - 1 >= 4)
            {
                if (x - esq == 1) // Sem posição livre à esquerda
                {
                    x += 2;
                    ponto_rotacao.x += 54.f;
                    definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                    cont_bloqueio = 0;
                }

                else if (x - esq == 2) // Uma posição livre à esquerda
                {
                    x += 1;
                    ponto_rotacao.x += 27.f;
                    definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                    cont_bloqueio = 0;
                }

                else if (dir - x == 1) // Sem posição livre à direita
                {
                    x -= 1;
                    ponto_rotacao.x -= 27.f;
                    definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                    cont_bloqueio = 0;
                }

                else
                {
                    definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                    cont_bloqueio = 0;
                }
            }

            else
            {
                cont_bloqueio++;
            }
        }

        else if (!TetrisJogo::disponivel(x, y))
        {
            if (x > 3)
            {
                if (TetrisJogo::disponivel(x - 1, y) && TetrisJogo::disponivel(x - 2, y) &&
                    TetrisJogo::disponivel(x - 3, y) && TetrisJogo::disponivel(x - 4, y))
                {
                    x -= 2;
                    ponto_rotacao.x -= 54.f;
                    definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                    cont_bloqueio = 0;
                }
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

    else if (estado_desejado == 2)
    {
        /* Posições do ponto de referência */
        x = (int)(ponto_rotacao.x / 27);
        y = (int)((ponto_rotacao.y - 120.f) / 27); //mudei aqui

        if (y == 20)
        {
            y = 19;
            ponto_rotacao.y -= 27.f;
        }

        if (TetrisJogo::disponivel(x, y))
        {
            /* Analisando quantas posições acima estão livres */
            int acima = y - 1;
            while (acima != -1 && TetrisJogo::disponivel(x, acima))
            {
                acima--;
            }

            /* Analisando quantas posições abaixo estão livres  */
            int abaixo = y + 1;
            while (abaixo != 20 && TetrisJogo::disponivel(x, abaixo))
            {
                abaixo++;
            }

            if (abaixo - acima - 1 >= 4)
            {

                if (y - acima == 1) // Sem posição livre acima
                {
                    y += 2;
                    ponto_rotacao.y += 54.f;
                    definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                    cont_bloqueio = 0;
                }

                else if (x - acima == 2) // Uma posição livre acima
                {
                    y += 1;
                    ponto_rotacao.y += 27.f;
                    definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                    cont_bloqueio = 0;
                }

                else if (abaixo - y == 1) // Sem posição livre abaixo
                {
                    y -= 1;
                    ponto_rotacao.y -= 27.f;
                    definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                    cont_bloqueio = 0;
                }

                else
                {
                    definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                    cont_bloqueio = 0;
                }
            }

            else
            {
                cont_bloqueio++;
            }
        }

        else if (!TetrisJogo::disponivel(x, y))
        {
            if (y > 3)
            {
                if (TetrisJogo::disponivel(x, y - 1) && TetrisJogo::disponivel(x, y - 2) &&
                    TetrisJogo::disponivel(x, y - 3) && TetrisJogo::disponivel(x, y - 4))
                {
                    y -= 2;
                    ponto_rotacao.y -= 54.f;
                    definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                    cont_bloqueio = 0;
                }
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

    else if (estado_desejado == 3)
    {
        /* Posições do ponto de referência */
        x = (int)(ponto_rotacao.x / 27) - 1;
        y = (int)((ponto_rotacao.y - 120.f) / 27); 

        if (x == -1)
        {
            x = 0;
            ponto_rotacao.x += 27.f;
        }

        if (TetrisJogo::disponivel(x, y))
        {
            /* Analisando quantas posições estão livres à direita */
            int dir = x + 1;
            while (dir != 10 && TetrisJogo::disponivel(dir, y)) // 10 é parede
            {
                dir++;
            }

            /* Analisando quantas posições estão livres à esquerda */
            int esq = x - 1;
            while (esq != -1 && TetrisJogo::disponivel(esq, y)) // -1 é parede 
            {
                esq--;
            }

            if (dir - esq - 1 >= 4)
            {

                if (x - esq == 1) // Sem posição livre à esquerda
                {
                    x += 1;
                    ponto_rotacao.x += 27.f;
                    definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                    cont_bloqueio = 0;
                }

                else if (dir - x == 1) // Sem posição livre à direita
                {
                    x -= 2;
                    ponto_rotacao.x -= 54.f;
                    definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                    cont_bloqueio = 0;
                }

                else if (dir - x == 2) // Uma posição livre à direita
                {
                    x -= 1;
                    ponto_rotacao.x -= 27.f;
                    definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                    cont_bloqueio = 0;
                }

                else
                {
                    definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                    cont_bloqueio = 0;
                }
            }

            else
            {
                cont_bloqueio++;
            }
        }

        else if (!TetrisJogo::disponivel(x, y))
        {
            if (x < 6)
            {
                if (TetrisJogo::disponivel(x + 1, y) && TetrisJogo::disponivel(x + 2, y) &&
                    TetrisJogo::disponivel(x + 3, y) && TetrisJogo::disponivel(x + 4, y))
                {
                    x += 2;
                    ponto_rotacao.x += 54.f;
                    definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                    cont_bloqueio = 0;
                }
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

    else 
    {
        /* Posições do ponto de referência */
        x = (int)(ponto_rotacao.x / 27) - 1; 
        y = (int)((ponto_rotacao.y - 120) / 27); 

        if (TetrisJogo::disponivel(x, y))
        {
            /* Analisando quantas posições acima estão livres */
            int acima = y - 1;
            while (acima != -1 && TetrisJogo::disponivel(x, acima))
            {
                acima--;
            }

            /* Analisando quantas posições abaixo estão livres  */
            int abaixo = y + 1;
            while (abaixo != 20 && TetrisJogo::disponivel(x, abaixo))
            {
                abaixo++;
            }

            if (abaixo - acima - 1 >= 4)
            {

                if (y - acima == 1) // Sem posição livre acima
                {
                    y += 1;
                    ponto_rotacao.y += 27.f;
                    definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                    cont_bloqueio = 0;
                }


                else if (abaixo - y == 1) // Sem posição livre abaixo
                {
                    y -= 2;
                    ponto_rotacao.y -= 54.f;
                    definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                    cont_bloqueio = 0;
                }

                else if (abaixo - y == 1) // Uma posição livre abaixo
                {
                    y -= 1;
                    ponto_rotacao.y -= 27.f;
                    definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                    cont_bloqueio = 0;
                }

                else
                {
                    definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                    cont_bloqueio = 0;
                }
            }

            else
            {
                cont_bloqueio++;
            }
        }

        else if (!TetrisJogo::disponivel(x, y))
        {
            if (y < 16)
            {
                if (TetrisJogo::disponivel(x, y + 1) && TetrisJogo::disponivel(x, y + 2) &&
                    TetrisJogo::disponivel(x, y + 3) && TetrisJogo::disponivel(x, y + 4))
                {
                    y += 2;
                    ponto_rotacao.y += 54.f;
                    definirGeometria(ponto_rotacao.x, ponto_rotacao.y, estado_desejado);
                    cont_bloqueio = 0;
                }
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