#ifndef LABORATORIO_H
#define LABORATORIO_H
#include "mesa.h"
#include "cadeira.h"
#include "quadro.h"
#include "piso.h"
#include "computador.h"
#include <list>
#include <iostream>
#define QUANTIDADE 4 //Quantidade de filas!
using namespace std;

class Laboratorio
{


private:
    std::list<Mesa*>* mesas;
    std::list<Cadeira*>* cadeiras;
    std::list<Computador*>* computadores;
    Objeto* quadro;
    Objeto* piso;
    void desenhaMesas();
    void desenhaMesaProfessor();
    void desenhaCadeiras();
    void desenhaComputadores();


public:
    Laboratorio();
    ~Laboratorio();
    void contruirCenario();
};

#endif // LABORATORIO_H
