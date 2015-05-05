#ifndef LABORATORIO_H
#define LABORATORIO_H
#include "mesa.h"
#include "cadeira.h"
#include "quadro.h"
#include "piso.h"
#include "computador.h"
#include "parede.h"
#include <list>
#include <vector>
#include <iostream>
#define QUANTIDADE 4 //Quantidade de filas!
using namespace std;

class Laboratorio
{


private:
    std::vector<Objeto*>* objetosCenarios;
    std::list<Mesa*>* mesas;
    std::list<Cadeira*>* cadeiras;
    std::list<Computador*>* computadores;
    Objeto* quadro;
    Objeto* piso;
    Objeto* parede;
    Objeto* mesaProfessor;
    Objeto* cadeiraProfessor;
    Objeto* computadorProfessor;
    void desenhaMesas();
    void desenhaMesaProfessor();
    void desenhaCadeiras();
    void desenhaComputadores();
    void desenhaQuadroEpiso();


public:
    Laboratorio();
    ~Laboratorio();
    void contruirCenario();
    std::vector<Objeto*>* getObjetosCenario();
};

#endif // LABORATORIO_H
