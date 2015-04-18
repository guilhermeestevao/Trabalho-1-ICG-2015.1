#include "laboratorio.h"

void Laboratorio::desenhaMesas()
{

    Mesa *mesa = new Mesa();

    //Mesa do professor


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

    glPushMatrix();
    glRotated(180, 0,1,0);
    glTranslated(-2,0,-4);
    mesaProfessor->desenhar();
    objetosCenarios->push_back(mesaProfessor);
    glPopMatrix();

    glPushMatrix();
    glRotated(180, 0,1,0);
    glTranslated(-2,0,-4);
    cadeiraProfessor->desenhar();
    objetosCenarios->push_back(cadeiraProfessor);
    glPopMatrix();

    glPushMatrix();
    glRotated(180, 0,1,0);
    glTranslated(-2,0,-4);
    computadorProfessor->desenhar();
    objetosCenarios->push_back(cadeiraProfessor);
    glPopMatrix();



}

void Laboratorio::desenhaCadeiras()
{

    Cadeira *cadeira = new Cadeira();


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
    Computador *computador = new Computador();


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

void Laboratorio::desenhaQuadroEpiso()
{

    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslated(0,0,0);
    this->piso->desenhar();
    glEnable(GL_CULL_FACE);
    glPopMatrix();
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslated(0,1,5);
    this->quadro->desenhar();
    glEnable(GL_CULL_FACE);
    glPopMatrix();

}


Laboratorio::Laboratorio()
{

    this->objetosCenarios = new std::vector<Objeto*>();

    this->piso = new Piso();
    objetosCenarios->push_back(piso);
    this->quadro = new Quadro();
    objetosCenarios->push_back(quadro);
    this->mesaProfessor = new Mesa();
    objetosCenarios->push_back(mesaProfessor);
    this->cadeiraProfessor = new Cadeira();
    objetosCenarios->push_back(cadeiraProfessor);
    this->computadorProfessor = new Computador();
    objetosCenarios->push_back(computadorProfessor);

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


}

Laboratorio::~Laboratorio()
{

}

void Laboratorio::contruirCenario()
{

    desenhaQuadroEpiso();
    desenhaMesaProfessor();
    desenhaCadeiras();
    desenhaMesas();
    desenhaComputadores();


}

std::vector<Objeto *> *Laboratorio::getObjetosCenario()
{
    return this->objetosCenarios;
}
