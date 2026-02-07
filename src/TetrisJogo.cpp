#include "TetrisJogo.h"


/* ==================== Referencia: https://tetris.wiki/Super_Rotation_System ============================*/

TetrisJogo::TetrisJogo():
	quadrados(),
    forma(),
    estado()
{
	pGG = GerenciadorGrafico::getGerenciadorGrafico();
    janela = pGG->pegarJanela();
   
    sequencia[0] = sortear();
    sequencia[1] = sortear();
    fim_do_jogo = false;

    fonte.loadFromFile("PressStart2P-Regular.ttf");
}

TetrisJogo::~TetrisJogo()
{
    if (forma)
    {
        delete forma;
        forma = nullptr;
    }

    quadrados.clear();

    if (janela)
    {
        janela = nullptr;
    }
}

int TetrisJogo::sortear()
{
	return rand() % 7;
}

void TetrisJogo::executar()
{
    while (!fim_do_jogo)
    {
        verificarNivel();

        if (quadrados.empty())
        {
            if (forma)
            {
                delete forma;
                forma = nullptr;
            }

            switch (sequencia[0])
            {
                case 0:
                {
                    forma = new I_forma();
                    forma->criar(136, 175, 3); 
                    break;
                }

                case 1:
                {
                    forma = new L_forma();
                    forma->criar(122.5, 161.5, 3); 
                    break;
                }

                case 2:
                {
                    forma = new L_inv_forma();
                    forma->criar(122.5, 161.5, 3); 
                    break;
                }

                case 3:
                {
                    forma = new Q_forma();
                    forma->criar(136, 148, 3); 
                    break;
                }

                case 4:
                {
                    forma = new S_forma();
                    forma->criar(122.5, 161.5, 3); 
                    break;
                }

                case 5:
                {
                    forma = new T_forma();
                    forma->criar(122.5, 161.5, 3);
                    break;
                }

                case 6:
                {
                
                    forma = new Z_forma();
                    forma->criar(122.5, 161.5, 3); 
                    break;
                }
            }

            for (int i = 0; i < 4; i++)
            {
                quadrados.push_back(forma->pegarBloco(i));
            }

            fim_do_jogo = verificarFimDoJogo();
        }

        if (forma && forma->pegarFixo())
        {
            quadrados.clear();
            sequencia[0] = sequencia[1];
            sequencia[1] = sortear();
        }

        sf::Event evento;
        while (janela->pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
            {
                janela->close();
            }

            else if (evento.type == sf::Event::KeyPressed)
            {
                if (evento.key.code == sf::Keyboard::Right)
                {
                    forma->moverHorizontal(1);
                }

                else if (evento.key.code == sf::Keyboard::Left)
                {
                    forma->moverHorizontal(0);
                }

                else if (evento.key.code == sf::Keyboard::Space)
                {
                    forma->rotacionar();
                }

                if (evento.key.code == sf::Keyboard::Down)
                {
                    forma->definirDuracaoMovimento(0.02f);
                }
            }
        }

        pGG->limparJanela();

        if (forma && !forma->pegarFixo())
        {
            forma->moverVertical();

            for (int i = 0; i < quadrados.size(); i++)
            {
                desenharFormaMovel(*quadrados[i]);
            }
        }

        desenharProximo(sequencia[1]);

        desenharPainel();

        desenharFormaFixa();

        pGG->mostrarJogo();
    }
}

/* Método para desenhar a peça em movimento */
void TetrisJogo::desenharFormaMovel(sf::RectangleShape forma)
{
    janela->draw(forma);
}

/* Método para desenhar todas as peças fixas */
void TetrisJogo::desenharFormaFixa()
{
    verificarLinhaCompleta();

    for (int j = 0; j < 20; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            if (grid[i][j] == 1) //Peça fixa
            {
                sf::Texture textura;
                textura.loadFromFile("Textura.png");
                sf::RectangleShape fixa;
                fixa.setTexture(&textura);
                fixa.setSize(sf::Vector2f(25.f, 25.f));
                fixa.setOrigin(sf::Vector2f(12.5f, 12.5f));
                fixa.setPosition(sf::Vector2f(14.5 + 27 * i, 134.5 + 27 * j));
                janela->draw(fixa);
            }
        }
    }
}

void TetrisJogo::desenharPainel()
{
    sf::RectangleShape divisoria_1;
    divisoria_1.setSize(sf::Vector2f(264, 2));
    divisoria_1.setPosition(sf::Vector2f(4, 4));
    janela->draw(divisoria_1);

    sf::RectangleShape divisoria_2;
    divisoria_2.setSize(sf::Vector2f(2, 111));
    divisoria_2.setPosition(sf::Vector2f(4, 4));
    janela->draw(divisoria_2);

    sf::RectangleShape divisoria_3;
    divisoria_3.setSize(sf::Vector2f(2, 111));
    divisoria_3.setPosition(sf::Vector2f(266, 4));
    janela->draw(divisoria_3);

    sf::RectangleShape divisoria_4;
    divisoria_4.setSize(sf::Vector2f(264, 2));
    divisoria_4.setPosition(sf::Vector2f(4, 113));
    janela->draw(divisoria_4);

    sf::RectangleShape divisoria_5;
    divisoria_5.setSize(sf::Vector2f(264, 2));
    divisoria_5.setPosition(sf::Vector2f(4, 55));
    janela->draw(divisoria_5);

    sf::RectangleShape divisoria_6;
    divisoria_6.setSize(sf::Vector2f(2, 58));
    divisoria_6.setPosition(sf::Vector2f(136, 55));
    janela->draw(divisoria_6);

    sf::RectangleShape divisoria_7;
    divisoria_7.setSize(sf::Vector2f(2, 70));
    divisoria_7.setPosition(sf::Vector2f(136, 4));
    janela->draw(divisoria_7);

    sf::Text textoPontuacao;
    textoPontuacao.setFont(fonte);
    textoPontuacao.setCharacterSize(18);
    textoPontuacao.setFillColor(sf::Color::White);
    textoPontuacao.setString("PONTOS");
    textoPontuacao.setPosition(19.f, 63.f);

    sf::Text pontuacao;
    pontuacao.setFont(fonte);
    pontuacao.setCharacterSize(19);
    pontuacao.setFillColor(sf::Color::White);
    pontuacao.setString(std::to_string(TetrisJogo::pontuacao));
    float centroX = 69.f;
    float centroY = 98.f;
    sf::FloatRect limite_pontuacao = pontuacao.getGlobalBounds();
    pontuacao.setPosition(centroX - limite_pontuacao.width / 2.f, centroY - limite_pontuacao.height / 2.f);

    sf::Text linhas;
    linhas.setFont(fonte);
    linhas.setCharacterSize(17);
    linhas.setFillColor(sf::Color::White);
    linhas.setString("LINHAS");
    sf::FloatRect limite_linhas = linhas.getLocalBounds();
    linhas.setOrigin(limite_linhas.width / 2.0f, limite_linhas.height / 2.0f);
    linhas.setPosition(68.f, 20.f);

    sf::Text qtde_linhas;
    qtde_linhas.setFont(fonte);
    qtde_linhas.setCharacterSize(18);
    qtde_linhas.setFillColor(sf::Color::White);
    qtde_linhas.setString(std::to_string(TetrisJogo::linhas_totais));
    float centro_X = 68.f;
    float centro_Y = 42.f;
    sf::FloatRect limite_qtde = qtde_linhas.getGlobalBounds();
    qtde_linhas.setPosition(centro_X - limite_qtde.width / 2.f, centro_Y - limite_qtde.height / 2.f);

    sf::Text texto_nivel;
    texto_nivel.setFont(fonte);
    texto_nivel.setCharacterSize(17);
    texto_nivel.setFillColor(sf::Color::White);
    texto_nivel.setString("NIVEL");
    sf::FloatRect limite_texto_nivel = texto_nivel.getLocalBounds();
    texto_nivel.setOrigin(limite_texto_nivel.width / 2.0f, limite_texto_nivel.height / 2.0f);
    texto_nivel.setPosition(200.f, 20.f);

    sf::Text nivel;
    nivel.setFont(fonte);
    nivel.setCharacterSize(18);
    nivel.setFillColor(sf::Color::White);
    nivel.setString(std::to_string(TetrisJogo::nivel));
    float centro_X_nivel = 200.f;
    float centro_Y_nivel = 42.f;
    sf::FloatRect limite_nivel = nivel.getGlobalBounds();
    nivel.setPosition(centro_X_nivel - limite_nivel.width / 2.f, centro_Y_nivel - limite_nivel.height / 2.f);


    janela->draw(textoPontuacao);
    janela->draw(pontuacao);
    janela->draw(linhas);
    janela->draw(qtde_linhas);
    janela->draw(nivel);
    janela->draw(texto_nivel);
}

void TetrisJogo::desenharProximo(int sorteado)
{
    sf::Texture textura;
    textura.loadFromFile("Textura.png");

    sf::RectangleShape proximo[4];
    for (int i = 0; i < 4; i++)
    {
        proximo[i].setTexture(&textura);
        proximo[i].setSize(sf::Vector2f(25.f, 25.f));
        proximo[i].setOrigin(sf::Vector2f(12.5f, 12.5f));
    }

    switch (sorteado)
    {
        case 0:
        {
            proximo[0].setPosition(sf::Vector2f(162.f, 85.5f));
            proximo[1].setPosition(sf::Vector2f(189.f, 85.5f));
            proximo[2].setPosition(sf::Vector2f(216.f, 85.5f));
            proximo[3].setPosition(sf::Vector2f(243.f, 85.5f));
            break;
        }

        case 1:
        {
            proximo[0].setPosition(sf::Vector2f(177.f, 71.5f));
            proximo[1].setPosition(sf::Vector2f(204.f, 71.5f));
            proximo[2].setPosition(sf::Vector2f(231.f, 71.5f));
            proximo[3].setPosition(sf::Vector2f(177.f, 98.5f));
            break;
        }

        case 2:
        {
            proximo[0].setPosition(sf::Vector2f(177.f, 71.5f));
            proximo[1].setPosition(sf::Vector2f(204.f, 71.5f));
            proximo[2].setPosition(sf::Vector2f(231.f, 71.5f));
            proximo[3].setPosition(sf::Vector2f(231.f, 98.5f));
            break;
        }

        case 3:
        {
            proximo[0].setPosition(sf::Vector2f(190.f, 71.5f));
            proximo[1].setPosition(sf::Vector2f(217.f, 71.5f));
            proximo[2].setPosition(sf::Vector2f(190.f, 98.5f));
            proximo[3].setPosition(sf::Vector2f(217.f, 98.5f));
            break;
        }

        case 4:
        {
            proximo[0].setPosition(sf::Vector2f(204.f, 71.5f));
            proximo[1].setPosition(sf::Vector2f(231.f, 71.5f));
            proximo[2].setPosition(sf::Vector2f(204.f, 98.5f));
            proximo[3].setPosition(sf::Vector2f(177.f, 98.5f));
            break;
        }

        case 5:
        {
            proximo[0].setPosition(sf::Vector2f(177.f, 71.5f));
            proximo[1].setPosition(sf::Vector2f(204.f, 71.5f));
            proximo[2].setPosition(sf::Vector2f(231.f, 71.5f));
            proximo[3].setPosition(sf::Vector2f(204.f, 98.5f));
            break;
        }

        case 6:
        {
            proximo[0].setPosition(sf::Vector2f(204.f, 71.5f));
            proximo[1].setPosition(sf::Vector2f(177.f, 71.5f));
            proximo[2].setPosition(sf::Vector2f(204.f, 98.5f));
            proximo[3].setPosition(sf::Vector2f(231.f, 98.5f));
            break;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        janela->draw(proximo[i]);
    }
}

void TetrisJogo::verificarLinhaCompleta()
{
    linhas_completas = 0;

    for (int j = 0; j < 20; j++)
    {
        int soma = 0;

        for (int i = 0; i < 10; i++)
        {
            soma += grid[i][j];
        }

        if (soma == 10)
        {
            apagarLinhaCompleta(j);
            linhas_completas++;
        }
    }

    if (linhas_completas > 0)
    {
        aumentarPontuacao(linhas_completas);
        aumentarLinhas(linhas_completas);
    }
}

void TetrisJogo::apagarLinhaCompleta(int j)
{
    for (int i = 0; i < 10; i++)
    {
        grid[i][j] = 0;
    }

    for (int k = j; k > 0; k--)
    {
        for (int i = 0; i < 10; i++)
        {
            if (grid[i][k - 1] == 1)
            {
                grid[i][k] = 1;
            }

            grid[i][k - 1] = 0;
        }
    }
}

void TetrisJogo::aumentarPontuacao(int linhas_completas)
{
    /* https://tetris.wiki/Scoring */

    switch (linhas_completas)
    {
        case 1:
        {
            pontuacao += 40 * (1 + nivel);
            break;
        }
        case 2:
        {
            pontuacao += 100 * (1 + nivel);
            break;
        }

        case 3:
        {
            pontuacao += 300 * (1 + nivel);
            break;
        }

        case 4:
        {
            pontuacao += 1200 * (1 + nivel);
            break;
        }
    }
}

void TetrisJogo::aumentarLinhas(int linhas_completas)
{
    linhas_totais += linhas_completas;
}

void TetrisJogo::verificarNivel()
{
    /* A cada 10 linhas completas, o nível aumenta */

    nivel = linhas_totais / 10;
}

bool TetrisJogo::verificarFimDoJogo()
{   
    /* O jogo acaba quando a próxima peça a nascer ocupar uma posição já preenchida */

    int x;
    int y;

    for (int i = 0; i < quadrados.size(); i++)
    {
        x = int(quadrados[i]->getPosition().x / 27);
        y = int((quadrados[i]->getPosition().y - 120) / 27);

        if (!disponivel(x, y))
        {
            return true;
        }
    }

    return false;
}


/* Método para definir se a posição no grid está disponível */
bool TetrisJogo::disponivel(int i, int j)
{
    if (0 <= i && i <= 9 && 0 <= j && j <= 19)
    {
        if (grid[i][j] == 1)
        {
            return false;
        }

        else
        {
            return true;
        }
    }

    return false;
}

void TetrisJogo::preencherGrid(int i, int j)
{
    grid[i][j] = 1;
}

void TetrisJogo::resetarJogo()
{
    nivel = 0;
    pontuacao = 0;
    linhas_totais = 0;

    for (int j = 0; j < 20; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            grid[i][j] = 0;
        }
    }
}

GerenciadorGrafico* TetrisJogo::pGG = nullptr;

int TetrisJogo::grid[10][20] = {};

int TetrisJogo::pontuacao = 0;

int TetrisJogo::linhas_totais = 0;

int TetrisJogo::nivel = 0;