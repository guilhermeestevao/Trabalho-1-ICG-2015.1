#include "quadro.h"

Quadro::Quadro()
{

}

Quadro::~Quadro()
{

}

void Quadro::desenhar() const
{
    Objeto::desenhar();

    if(!selecionado){
        glColor3f(0,1,1);
    }else{
        glColor3f(1,1,1);
    }


    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslated(0,0,0);
    Desenha::drawBox(-3, 0, 0, 3, 2, 0.1);
    glEnable(GL_CULL_FACE);
    glPopMatrix();
}

