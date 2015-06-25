#ifndef OBJETO_H
#define OBJETO_H
#include <GL/gl.h>
#include <GL/glu.h>
#include "bib/Desenha.h"

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
    void setEixos(bool eixos);
    int id;
    float getAX();
    float getAY();
    float getAZ();
    float getTX();
    float getTY();
    float getTZ();
    float getSX();
    float getSY();
    float getSZ();

protected:
    float ax, ay, az;
    float sx, sy, sz;
    float tx, ty, tz;
    float matrizSombra[16];
    bool selecionado, eixos;
};

#endif // OBJETO_H
