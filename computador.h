#ifndef COMPUTADOR_H
#define COMPUTADOR_H
#include "objeto.h"

class Computador: public Objeto
{
public:
    Computador();
    ~Computador();
    virtual void desenhar() const;
};

#endif // COMPUTADOR_H
