#include "objeto.h"

Objeto::Objeto()
{
    sombra = false;
    selecionado =false;
    eixos = false;
    ax, ay, az = 0;
    tx, ty, tz = 0;
    sx, sy, sz = 1;
}

Objeto::~Objeto()
{

}

void Objeto::desenhar() const
{


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
