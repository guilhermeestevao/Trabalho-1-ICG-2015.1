#ifndef CADEIRA_H
#define CADEIRA_H

#include "objeto.h"

class Cadeira : public Objeto
{

public:
    Cadeira();
    ~Cadeira();
    virtual void desenhar() const;
};

#endif // CADEIRA_H
