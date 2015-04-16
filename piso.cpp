#include "piso.h"


Piso::Piso()
{

}

Piso::~Piso()
{

}

void Piso::desenhar() const
{
    if(!selecionado){
        glColor3f(1,1,0);
    }else{
        glColor3f(1,1,1);
    }

    glPushMatrix();
        glDisable(GL_CULL_FACE);
        glTranslated(0,0,0);
        if (eixos) {
            Desenha::drawEixos(3.5);
            glColor3f(1,1,1);
        }
        Desenha::drawBox(-5, -0.1, -13, 5, 0, 6);
        glEnable(GL_CULL_FACE);
    glPopMatrix();
}
