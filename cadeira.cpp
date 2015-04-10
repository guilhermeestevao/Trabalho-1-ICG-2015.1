#include "cadeira.h"

Cadeira::Cadeira()
{

}

Cadeira::~Cadeira()
{

}

void Cadeira::desenhar() const
{
    Desenha::drawGrid(10, 0, 10,1);

    Desenha::drawBox(0, 0, 0, 0.1, 1, -0.1);

    Desenha::drawBox(0.9, 0, 0, 1, 1, -0.1);

    Desenha::drawBox(0, 0, -0.9, 0.1, 2, -1);

    Desenha::drawBox(0.9, 0,-0.9, 1, 2, -1);

    Desenha::drawBox(0, 1, 0, 1, 1.1, -1);

    Desenha::drawBox(0, 1.5, -0.9, 1 ,2, -1);
}




