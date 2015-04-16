#include "mesa.h"

Mesa::Mesa()
{

}

Mesa::~Mesa()
{

}

void Mesa::desenhar() const
{

    if(!selecionado)
        glColor3f(0,1,0);
    else
        glColor3f(1,1,1);

    //Tampa
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslated(0, 0.5, 0.7);
    if(eixos){
        Desenha::drawEixos(1);
        glColor3f(1,1,1);
    }
    Desenha::drawBox(-1, 0.3, -0.5 ,1,0.4, 1);
    glEnable(GL_CULL_FACE);
    glPopMatrix();

    //Pé esquerdo
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslated(0, 0, 0.7);
    Desenha::drawBox(-1, 0, -0.5 ,-0.9,0.1, 1);
    glEnable(GL_CULL_FACE);
    glPopMatrix();

    //Pé direito
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslated(0, 0, 0.7);
    Desenha::drawBox(1, 0, -0.5 ,0.9,0.1, 1);
    glEnable(GL_CULL_FACE);
    glPopMatrix();

    //Suporte esquerdo
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslated(0, 0, 1);
    Desenha::drawBox(-1, 0.1, -0.2 ,-0.9, 0.8, 0.2);
    glEnable(GL_CULL_FACE);
    glPopMatrix();

    //Suporte direito
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslated(0, 0, 1);
    Desenha::drawBox(1, 0.1, -0.2 ,0.9, 0.8, 0.2);
    glEnable(GL_CULL_FACE);
    glPopMatrix();

    //Tampa lateral
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslated(0, 0, 1);
    Desenha::drawBox(-1, 0.3, 0.2 ,1, 0.8, 0.25);
    glEnable(GL_CULL_FACE);
    glPopMatrix();


}

