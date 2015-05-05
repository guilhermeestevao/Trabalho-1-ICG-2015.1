#ifndef PAREDE_H
#define PAREDE_H
#include "objeto.h"

class Parede: public Objeto
{
public:
    Parede();
    ~Parede();

    virtual void desenhar() const;

};

#endif // PAREDE_H
