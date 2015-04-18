#include "computador.h"

Computador::Computador()
{

}

Computador::~Computador()
{

}

void Computador::desenhar() const
{
    Objeto::desenhar();

    if(!selecionado)
        glColor3f(0,0,1);
    else
       glColor3f(1,1,1);

    //base monitor

    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslated(0.3, 0.8, 0.7);

    Desenha::drawBox(0, 0.1, 0.3, 0.3, 0.15, 0.6);
    glEnable(GL_CULL_FACE);
    glPopMatrix();

    //Suporte monitor
    GLUquadricObj *obj = gluNewQuadric();
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glRotated(90, -1, 0, 0);
    glTranslated(0.45, -1.2, 0.9);
    gluCylinder(obj, 0.05, 0.05, 0.2, 30, 30);
    glEnable(GL_CULL_FACE);
    glPopMatrix();

    //Monitor
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslated(-0.1, 0.7, 0.9);
    Desenha::drawBox(0, 0.4, 0.3, 1.1, 1, 0.4);
    glEnable(GL_CULL_FACE);
    glPopMatrix();

    //CPU
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslated(-0.8, 0.8, 0.3);
    Desenha::drawBox(0, 0, 0.3, 0.3, 0.8, 1);
    glEnable(GL_CULL_FACE);
    glPopMatrix();

    //Teclado
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslated(0.3, 0.8, 0);
    Desenha::drawBox(-0.2, 0.1, 0.3, 0.5, 0.15, 0.6);
    glEnable(GL_CULL_FACE);
    glPopMatrix();

    //Mouse
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslated(-0.4, 0.8, 0.3);
    Desenha::drawBox(0.15, 0.1, 0.3, 0.3, 0.15, 0.5);
    glEnable(GL_CULL_FACE);
    glPopMatrix();



}

