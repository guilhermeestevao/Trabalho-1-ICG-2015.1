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
     glPushMatrix();
     glRotated(180, 0,1,0);
     glTranslated(-2,0,-4);
     mesa->desenhar();
     glPopMatrix();

     Cadeira *cadeira = new Cadeira();
     glPushMatrix();
     glRotated(180, 0,1,0);
     glTranslated(-2,0,-4);
     cadeira->desenhar();
     glPopMatrix();

     Computador *computador = new Computador();
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
    this->mesas = new std::list<Mesa*>();
    for(int i = 0; i<QUANTIDADE*3; i++){
        mesas->push_back(new Mesa());
    }
    this->cadeiras = new std::list<Cadeira*>();
    for(int i = 0; i<QUANTIDADE*3; i++){
        cadeiras->push_back(new Cadeira());
    }
    this->computadores = new std::list<Computador*>();
    for(int i = 0; i<QUANTIDADE*3; i++){
        computadores->push_back(new Computador());
    }
    this->piso = new Piso();
    this->quadro = new Quadro();
}

Laboratorio::~Laboratorio()
{

}

void Laboratorio::contruirCenario()
{
    desenhaMesaProfessor();
    desenhaCadeiras();
    desenhaMesas();
    desenhaComputadores();
    this->piso->desenhar();
    this->quadro->desenhar();

}
