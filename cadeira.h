#ifndef CADEIRA_H
#define CADEIRA_H

#include "objeto.h"

class Cadeira : public Objeto
{

public:
    Cadeira();
    ~Cadeira();
    virtual void desenhar(/*float inicioX, float inicioY, float inicioZ, float altura, float largura, float alturaAcento*/) const;
};

#endif // CADEIRA_H
