#ifndef PISO_H
#define PISO_H
#include "objeto.h"

class Piso: public Objeto
{

public:
    Piso();
    ~Piso();
    virtual void desenhar() const;

};
#endif // PISO_H
