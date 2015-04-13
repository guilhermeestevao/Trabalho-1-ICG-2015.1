#ifndef QUADRO_H
#define QUADRO_H
#include "objeto.h"

class Quadro: public Objeto
{
public:
    Quadro();
    ~Quadro();
     virtual void desenhar() const;
};

#endif // QUADRO_H
