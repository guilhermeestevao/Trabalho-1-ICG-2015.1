#ifndef OBJETO_H
#define OBJETO_H
#include <GL/gl.h>
#include <GL/glu.h>
#include "desenha.h"

class Objeto
{
public:
    Objeto();
    ~Objeto();
    virtual void desenhar() const;
    void setRotacao(float x, float y, float z);
    void setEscala(float x, float y, float z);
    void setTranslacao(float x, float y, float z);
    void setSelecionado(bool selecionado);
    void setSombra(bool sombra);
    void setEixos(bool eixos);
protected:
    float ax, ay, az;
    float sx, sy, sz;
    float tx, ty, tz;
    bool selecionado, sombra, eixos;
};

#endif // OBJETO_H
