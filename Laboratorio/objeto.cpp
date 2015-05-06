#include "objeto.h"

Objeto::Objeto()
{
    selecionado = false;
    eixos = false;
    sombra = false;
    ax = ay = az = 0;
    tx = ty =  tz = 0;
    sx = sy = sz = 1;
}

Objeto::~Objeto()
{

}

void Objeto::desenhar() const
{
    glTranslated(tx, ty, tz);
    // Rotação
    if(eixos){
        Desenha::drawEixos( 1 );
        glColor3f(0,1,1);
    }


    glRotated(ax, 1, 0, 0);
    glRotated(ay, 0, 1, 0);
    glRotated(az, 0, 0, 1);
    // Escala
    glScaled(sx, sy, sz);

}

void Objeto::setRotacao(float x, float y, float z)
{
    this->ax = x;
    this->ay = y;
    this->az = z;
}

void Objeto::setEscala(float x, float y, float z)
{
    this->sx = x;
    this->sy = y;
    this->sz = z;
}

void Objeto::setTranslacao(float x, float y, float z)
{
    this->tx = x;
    this->ty = y;
    this->tz = z;
}

void Objeto::setSelecionado(bool selecionado)
{
    this->selecionado = selecionado;
}

void Objeto::setEixos(bool eixos)
{
    this->eixos = eixos;
}

void Objeto::setSombra(bool sombra)
{
    this->sombra = sombra;
}

float Objeto::getAX()
{
    return this->ax;
}

float Objeto::getAY()
{
    return this->ay;
}

float Objeto::getAZ()
{
    return this->az;
}

float Objeto::getTX()
{
    return this->tx;
}

float Objeto::getTY()
{
    return this->ty;
}

float Objeto::getTZ()
{
    return this->tz;
}

float Objeto::getSX()
{
    return this->sx;
}

float Objeto::getSY()
{
    return this->sy;
}

float Objeto::getSZ()
{
    return this->sz;
}

