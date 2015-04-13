#ifndef LABORATORIO_H
#define LABORATORIO_H
#include "mesa.h"
#include "cadeira.h"
#include "quadro.h"
#include "piso.h"
#include "computador.h"
#include <list>
#define QUANTIDADE 1
using namespace std;

class Laboratorio
{


private:
    std::list<Mesa*>* mesas;
    Objeto* cadeira;
    Objeto* quadro;
    Objeto* piso;
    Objeto* computador;
    void desenhaMesas();
    void desenhaCadeiras();
    void desenhaComputadores();


public:
    Laboratorio();
    ~Laboratorio();
    void contruirCenario();
};

#endif // LABORATORIO_H
