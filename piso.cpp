#include "piso.h"


Piso::Piso()
{

}

Piso::~Piso()
{

}

void Piso::desenhar() const
{
    glColor3f(0,1,1);
    glPushMatrix();
        glDisable(GL_CULL_FACE);
        glTranslated(0,0,0);
        Desenha::drawBox(-5, -0.1, -10, 5, 0, 6);
        glEnable(GL_CULL_FACE);
    glPopMatrix();
}


