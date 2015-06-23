#include "mesa.h"

Mesa::Mesa()
{

}

Mesa::~Mesa()
{

}

void Mesa::desenhar() const
{
    Objeto::desenhar();

    if(selecionado)
        glColor3f(1,1,1);


    //Tampa
    glPushMatrix();

    glTranslated(0, 0.5, 0.7);

    Desenha::drawBox(-1, 0.3, -0.5 ,1,0.4, 1);

    glPopMatrix();

    //Pé esquerdo
    glPushMatrix();

    glTranslated(0, 0, 0.7);
    Desenha::drawBox(-1, 0, -0.5 ,-0.9,0.1, 1);

    glPopMatrix();

    //Pé direito
    glPushMatrix();

    glTranslated(0, 0, 0.7);
    Desenha::drawBox(1, 0, -0.5 ,0.9,0.1, 1);

    glPopMatrix();

    //Suporte esquerdo
    glPushMatrix();

    glTranslated(0, 0, 1);
    Desenha::drawBox(-1, 0.1, -0.2 ,-0.9, 0.8, 0.2);

    glPopMatrix();

    //Suporte direito
    glPushMatrix();

    glTranslated(0, 0, 1);
    Desenha::drawBox(1, 0.1, -0.2 ,0.9, 0.8, 0.2);

    glPopMatrix();

    //Tampa lateral
    glPushMatrix();

    glTranslated(0, 0, 1);
    Desenha::drawBox(-1, 0.3, 0.2 ,1, 0.8, 0.25);

    glPopMatrix();


}

