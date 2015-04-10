#include "mesa.h"

Mesa::Mesa()
{

}

Mesa::~Mesa()
{

}

void Mesa::desenhar() const
{
    Desenha::drawBox(-1, 1.5, -0.5 ,2,1.6, 1);
    Desenha::drawBox(-1, 0, -0.5, -0.9, 0.1, 1);

    Desenha::drawBox(2, 0, -0.5, 1.9, 0.1, 1);
    Desenha::drawBox(-1, 0.1, 0, -0.9, 1.5, 0.5);

    Desenha::drawBox(1.9, 0.1,0 ,2, 1.5, 0.5);
}

