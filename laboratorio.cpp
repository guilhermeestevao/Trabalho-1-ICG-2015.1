#include "laboratorio.h"





void Laboratorio::desenhaMesas()
{
    Mesa *mesa = new Mesa();

    for(int i = 0; i<QUANTIDADE*QUANTIDADE; i+=QUANTIDADE){
        glPushMatrix();
        glTranslated(0,0,-i);
        mesa->desenhar();
        glPopMatrix();

        glPushMatrix();
        glTranslated(-3,0,-i);
        mesa->desenhar();
        glPopMatrix();

        glPushMatrix();
        glTranslated(3,0,-i);
        mesa->desenhar();
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

    Cadeira *cadeira = new Cadeira();

    for(int i = 0; i<QUANTIDADE*QUANTIDADE; i+=QUANTIDADE){
        glPushMatrix();
        glTranslated(0,0,-i);
        cadeira->desenhar();
        glPopMatrix();

        glPushMatrix();
        glTranslated(-3,0,-i);
        cadeira->desenhar();
        glPopMatrix();

        glPushMatrix();
        glTranslated(3,0,-i);
        cadeira->desenhar();
        glPopMatrix();
    }

}




void Laboratorio::desenhaComputadores()
{
    Computador *computador = new Computador();

    for(int i = 0; i<QUANTIDADE*QUANTIDADE; i+=QUANTIDADE){
        glPushMatrix();
        glTranslated(0,0,-i);
        computador->desenhar();
        glPopMatrix();

        glPushMatrix();
        glTranslated(-3,0,-i);
        computador->desenhar();
        glPopMatrix();

        glPushMatrix();
        glTranslated(3,0,-i);
        computador->desenhar();
        glPopMatrix();
    }

}

Laboratorio::Laboratorio()
{
    this->mesas = new std::list<Mesa*>();
    this->cadeiras = new std::list<Cadeira*>();
    this->computadores = new std::list<Computador*>();
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
