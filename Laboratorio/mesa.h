#ifndef MESA_H
#define MESA_H
#include "objeto.h"


class Mesa: public Objeto
{

public:
    Mesa();
    ~Mesa();
    virtual void desenhar() const;
};

#endif // MESA_H
