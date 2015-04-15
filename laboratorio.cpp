#include "laboratorio.h"

void Laboratorio::desenhaMesas()
{

    Mesa *mesa;

    for(int i = 0; i<QUANTIDADE*QUANTIDADE; i+=QUANTIDADE){
        glPushMatrix();
        glTranslated(0,0,-i);
        mesa = (Mesa*) mesas->front();
        mesa->desenhar();
        mesas->push_back(mesa);
        mesas->pop_front();
        glPopMatrix();

        glPushMatrix();
        glTranslated(-3,0,-i);
        mesa = (Mesa*) mesas->front();
        mesa->desenhar();
        mesas->push_back(mesa);
        mesas->pop_front();
        glPopMatrix();

        glPushMatrix();
        glTranslated(3,0,-i);
        mesa = (Mesa*) mesas->front();
        mesa->desenhar();
        mesas->push_back(mesa);
        mesas->pop_front();
        glPopMatrix();
    }

}

void Laboratorio::desenhaMesaProfessor()
{
     Mesa *mesa = new Mesa();
     //objetosCenarios->push_back(mesa);
     glPushMatrix();
     glRotated(180, 0,1,0);
     glTranslated(-2,0,-4);
     mesa->desenhar();
     glPopMatrix();

     Cadeira *cadeira = new Cadeira();
     //objetosCenarios->push_back(cadeira);
     glPushMatrix();
     glRotated(180, 0,1,0);
     glTranslated(-2,0,-4);
     cadeira->desenhar();
     glPopMatrix();

     Computador *computador = new Computador();
     //objetosCenarios->push_back(cadeira);
     glPushMatrix();
     glRotated(180, 0,1,0);
     glTranslated(-2,0,-4);
     computador->desenhar();
     glPopMatrix();



}

void Laboratorio::desenhaCadeiras()
{

    Cadeira *cadeira;

    for(int i = 0; i<QUANTIDADE*QUANTIDADE; i+=QUANTIDADE){
        glPushMatrix();
        glTranslated(0,0,-i);
        cadeira = (Cadeira*)cadeiras->front();
        cadeira->desenhar();
        cadeiras->push_back(cadeira);
        cadeiras->pop_front();
        glPopMatrix();

        glPushMatrix();
        glTranslated(-3,0,-i);
        cadeira = (Cadeira*)cadeiras->front();
        cadeira->desenhar();
        cadeiras->push_back(cadeira);
        cadeiras->pop_front();
        glPopMatrix();

        glPushMatrix();
        glTranslated(3,0,-i);
        cadeira = (Cadeira*)cadeiras->front();
        cadeira->desenhar();
        cadeiras->push_back(cadeira);
        cadeiras->pop_front();
        glPopMatrix();
    }

}




void Laboratorio::desenhaComputadores()
{
    Computador *computador;

    for(int i = 0; i<QUANTIDADE*QUANTIDADE; i+=QUANTIDADE){
        glPushMatrix();
        glTranslated(0,0,-i);
        computador = (Computador*)computadores->front();
        computador->desenhar();
        computadores->push_back(computador);
        computadores->pop_front();
        glPopMatrix();

        glPushMatrix();
        glTranslated(-3,0,-i);
        computador = (Computador*)computadores->front();
        computador->desenhar();
        computadores->push_back(computador);
        computadores->pop_front();
        glPopMatrix();

        glPushMatrix();
        glTranslated(3,0,-i);
        computador = (Computador*)computadores->front();
        computador->desenhar();
        computadores->push_back(computador);
        computadores->pop_front();
        glPopMatrix();
    }

}


Laboratorio::Laboratorio()
{
    this->objetosCenarios = new std::vector<Objeto*>();

    this->mesas = new std::list<Mesa*>();
    for(int i = 0; i<QUANTIDADE*3; i++){
        Mesa *mesa = new Mesa();
        mesas->push_back(mesa);
        objetosCenarios->push_back(mesa);
    }

    this->cadeiras = new std::list<Cadeira*>();
    for(int i = 0; i<QUANTIDADE*3; i++){
        Cadeira *cadeira = new Cadeira();
        cadeiras->push_back(cadeira);
        objetosCenarios->push_back(cadeira);
    }

    this->computadores = new std::list<Computador*>();
    for(int i = 0; i<QUANTIDADE*3; i++){
        Computador *computador = new Computador();
        computadores->push_back(computador);
        objetosCenarios->push_back(computador);
    }

    this->piso = new Piso();
    //objetosCenarios->push_back(piso);
    this->quadro = new Quadro();
    //objetosCenarios->push_back(quadro);
}

Laboratorio::~Laboratorio()
{

}

void Laboratorio::contruirCenario()
{
    this->piso->desenhar();
    this->quadro->desenhar();

    desenhaMesaProfessor();
    desenhaCadeiras();
    desenhaMesas();
    desenhaComputadores();


}

std::vector<Objeto *> *Laboratorio::getObjetosCenario()
{
    return this->objetosCenarios;
}
