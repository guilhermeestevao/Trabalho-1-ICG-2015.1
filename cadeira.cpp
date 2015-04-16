#include "cadeira.h"

Cadeira::Cadeira()
{

}

Cadeira::~Cadeira()
{

}

void Cadeira::desenhar() const
{
    if(!selecionado)
        glColor3f(1,0,0);
    else
       glColor3f(1,1,1);


    //Pé horizontal
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslated(-0.45, 0, -0.05);
    if (eixos) {
        Desenha::drawEixos( 1 );
        glColor3f(1,1,1);
    }
    Desenha::drawBox( 0.0,0.0,0.0, 0.9, 0.04, 0.1 );
    glEnable(GL_CULL_FACE);
    glPopMatrix();

    //Pé vertical
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslated(-0.05, 0, -0.45);
    Desenha::drawBox( 0.0,0.0,0.0, 0.1, 0.04, 0.9 );
    glEnable(GL_CULL_FACE);
    glPopMatrix();

    GLUquadricObj *obj = gluNewQuadric();

    //Suporte acento
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glRotated(90, -1, 0, 0);
    glTranslated(0, 0, 0.04);    
    gluCylinder(obj, 0.1, 0.1, 0.5, 30, 30);
    glEnable(GL_CULL_FACE);
    glPopMatrix();

    //Acento
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslated(0, 0.5, 0.1);

    Desenha::drawBox(-0.3, 0, 0.3, 0.3, 0.1, -0.3);
    glEnable(GL_CULL_FACE);
    glPopMatrix();

    //Suporte encosto
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslated(0, 0.5, -0.2);
    Desenha::drawBox(-0.05, 0, 0, 0.05, 0.5, -0.1);
    glEnable(GL_CULL_FACE);
    glPopMatrix();

    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslated(0, 1, -0.2);
    Desenha::drawBox(-0.1, 0, 0, 0.1, 0.1, -0.15);
    glEnable(GL_CULL_FACE);
    glPopMatrix();

    //Encosto
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslated(0, 1, -0.2);
    Desenha::drawBox(-0.3, -0.1, 0, 0.3, 0.3, 0.1);
    glEnable(GL_CULL_FACE);
    glPopMatrix();



}




