#include "laboratorio.h"

void Laboratorio::desenhaMesas()
{
    for(int i = 0; i<QUANTIDADE; i++){
        mesas->push_back(new Mesa());
    }

    for(int i = 0; i<QUANTIDADE; i++){
        Mesa* mesa = (Mesa*)mesas[i].front();
        mesa->desenhar();
    }
}

void Laboratorio::desenhaCadeiras()
{

}

void Laboratorio::desenhaComputadores()
{

}

Laboratorio::Laboratorio()
{
    this->mesas = new std::list<Mesa*>();

    cadeira = new Cadeira();
    piso = new Piso();
    computador = new Computador;
    quadro = new Quadro();
}

Laboratorio::~Laboratorio()
{

}

void Laboratorio::contruirCenario()
{
    desenhaMesas();

    this->piso->desenhar();
    this->quadro->desenhar();
    this->computador->desenhar();
    this->cadeira->desenhar();
}


