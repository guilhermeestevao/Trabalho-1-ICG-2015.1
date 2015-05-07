#include "parede.h"

Parede::Parede()
{

}

Parede::~Parede()
{

}

void Parede::desenhar() const
{
    Objeto::desenhar();

    if(!selecionado)
        glColor3f(128/255.0,128/255.0,128/255.0);
    else
        glColor3f(1,1,1);

    //Desenha parede

    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslated(0,0,0);
    Desenha::drawBox(0, 0, 13,  0.1, 4, -5);
    glEnable(GL_CULL_FACE);
    glPopMatrix();
}

