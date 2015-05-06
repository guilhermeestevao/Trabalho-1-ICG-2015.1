#include "laboratorio.h"

void Laboratorio::desenhaMesas()
{

    Mesa *mesa = new Mesa();

    //Mesa do professor


    for(int i = 0; i<QUANTIDADE*QUANTIDADE; i+=QUANTIDADE){

        glPushMatrix();
        glColor3f(0.6,0.4,0.0);
        glTranslated(0,0,-i);
        mesa = (Mesa*) mesas->front();
        mesa->desenhar();
        glPopMatrix();


        if(sombra){
            glPushMatrix();
            float s[16] = {
                            Luz::lightPosition[1], -Luz::lightPosition[0],                0.0,                0.0,
                            0.0,                0.0,                0.0,                0.0,
                            0.0, -Luz::lightPosition[2],  Luz::lightPosition[1],                0.0,
                            0.0, -Luz::lightPosition[3],                0.0,  Luz::lightPosition[1]
                        };
            glMultTransposeMatrixf(s);
            glDisable(GL_LIGHTING);
            glTranslated(0,0,-i);
            glTranslated(tx,ty,tz);
            glRotated(az,0,0,1);
            glRotated(ay,0,1,0);
            glRotated(ax,1,0,0);
            glColor3d(0, 0, 0);
            mesa->setSombra(true);
            mesa->desenhar();
            glEnable(GL_LIGHTING);
            glPopMatrix();
        }

        mesas->push_back(mesa);
        mesas->pop_front();

        glPushMatrix();
        glColor3f(0.6,0.4,0.0);
        glTranslated(3,0,-i);
        mesa = (Mesa*) mesas->front();
        mesa->desenhar();
        glPopMatrix();

        if(sombra){
            glPushMatrix();
            float s[16] = {
                            Luz::lightPosition[1], -Luz::lightPosition[0],                0.0,                0.0,
                            0.0,                0.0,                0.0,                0.0,
                            0.0, -Luz::lightPosition[2],  Luz::lightPosition[1],                0.0,
                            0.0, -Luz::lightPosition[3],                0.0,  Luz::lightPosition[1]
                        };
            glMultTransposeMatrixf(s);
            glDisable(GL_LIGHTING);
            glTranslated(3,0,-i);
            glTranslated(tx,ty,tz);
            glRotated(az,0,0,1);
            glRotated(ay,0,1,0);
            glRotated(ax,1,0,0);
            mesa->setSombra(true);
            glColor3f(0,0,0);
            mesa->desenhar();
            glEnable(GL_LIGHTING);
            glPopMatrix();
        }

        mesas->push_back(mesa);
        mesas->pop_front();


        glPushMatrix();
        glColor3f(0.6,0.4,0.0);
        glTranslated(-3,0,-i);
        mesa = (Mesa*) mesas->front();
        mesa->desenhar();
        glPopMatrix();

        if(sombra){
            glPushMatrix();
            float s[16] = {
                            Luz::lightPosition[1], -Luz::lightPosition[0],                0.0,                0.0,
                            0.0,                0.0,                0.0,                0.0,
                            0.0, -Luz::lightPosition[2],  Luz::lightPosition[1],                0.0,
                            0.0, -Luz::lightPosition[3],                0.0,  Luz::lightPosition[1]
                        };
            glMultTransposeMatrixf(s);
            glDisable(GL_LIGHTING);
            glTranslated(-3,0,-i);
            glTranslated(tx,ty,tz);
            glRotated(az,0,0,1);
            glRotated(ay,0,1,0);
            glRotated(ax,1,0,0);
            glColor3f(0,0,0);
            mesa->setSombra(true);
            mesa->desenhar();
            glEnable(GL_LIGHTING);
            glPopMatrix();
        }

        mesas->push_back(mesa);
        mesas->pop_front();

    }

}

void Laboratorio::desenhaMesaProfessor()
{

    glPushMatrix();
    glColor3f(0.6,0.4,0.0);
    glRotated(180, 0,1,0);
    glTranslated(-2,0,-4);
    mesaProfessor->desenhar();

    glPopMatrix();


    if(sombra){
        glPushMatrix();
        float s[16] = {
                        Luz::lightPosition[1], -Luz::lightPosition[0],                0.0,                0.0,
                        0.0,                0.0,                0.0,                0.0,
                        0.0, -Luz::lightPosition[2],  Luz::lightPosition[1],                0.0,
                        0.0, -Luz::lightPosition[3],                0.0,  Luz::lightPosition[1]
                    };
        glMultTransposeMatrixf(s);
        glDisable(GL_LIGHTING);
        glRotated(180, 0,1,0);
        glTranslated(-2,0,-4);
        glTranslated(tx,ty,tz);
        glRotated(az,0,0,1);
        glRotated(ay,0,1,0);
        glRotated(ax,1,0,0);
        glColor3f(0,0,0);
        mesaProfessor->setSombra(true);
        mesaProfessor->desenhar();
        glEnable(GL_LIGHTING);
        glPopMatrix();
    }

    objetosCenarios->push_back(mesaProfessor);


    glPushMatrix();
    glColor3f(1,0,0);
    glRotated(180, 0,1,0);
    glTranslated(-2,0,-4);
    cadeiraProfessor->desenhar();

    glPopMatrix();

    if(sombra){
        glPushMatrix();
        float s[16] = {
                        Luz::lightPosition[1], -Luz::lightPosition[0],                0.0,                0.0,
                        0.0,                0.0,                0.0,                0.0,
                        0.0, -Luz::lightPosition[2],  Luz::lightPosition[1],                0.0,
                        0.0, -Luz::lightPosition[3],                0.0,  Luz::lightPosition[1]
                    };
        glColor3f(0,0,0);
        glMultTransposeMatrixf(s);
        glDisable(GL_LIGHTING);
        glRotated(180, 0,1,0);
        glTranslated(-2,0,-4);
        glTranslated(tx,ty,tz);
        glRotated(az,0,0,1);
        glRotated(ay,0,1,0);
        glRotated(ax,1,0,0);
        glColor3f(0,0,0);
        cadeiraProfessor->setSombra(true);
        cadeiraProfessor->desenhar();
        glEnable(GL_LIGHTING);
        glPopMatrix();
    }

    objetosCenarios->push_back(cadeiraProfessor);

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
        glColor3f(1,0,0);
        glTranslated(0,0,-i);
        cadeira = (Cadeira*)cadeiras->front();
        cadeira->desenhar();
        glPopMatrix();

        if(sombra){
            glPushMatrix();
            float s[16] = {
                            Luz::lightPosition[1], -Luz::lightPosition[0],                0.0,                0.0,
                            0.0,                0.0,                0.0,                0.0,
                            0.0, -Luz::lightPosition[2],  Luz::lightPosition[1],                0.0,
                            0.0, -Luz::lightPosition[3],                0.0,  Luz::lightPosition[1]
                        };
            glColor3f(0,0,0);
            glMultTransposeMatrixf(s);
            glDisable(GL_LIGHTING);
            glTranslated(0,0,-i);
            glTranslated(tx,ty,tz);
            glRotated(az,0,0,1);
            glRotated(ay,0,1,0);
            glRotated(ax,1,0,0);
            cadeira->setSombra(true);
            cadeira->desenhar();
            glEnable(GL_LIGHTING);
            glPopMatrix();
        }

        cadeiras->push_back(cadeira);
        cadeiras->pop_front();

        glPushMatrix();
        glColor3f(1,0,0);
        glTranslated(-3,0,-i);
        cadeira = (Cadeira*)cadeiras->front();
        cadeira->desenhar();
        glPopMatrix();

        if(sombra){
            glPushMatrix();
            float s[16] = {
                            Luz::lightPosition[1], -Luz::lightPosition[0],                0.0,                0.0,
                            0.0,                0.0,                0.0,                0.0,
                            0.0, -Luz::lightPosition[2],  Luz::lightPosition[1],                0.0,
                            0.0, -Luz::lightPosition[3],                0.0,  Luz::lightPosition[1]
                        };
            glColor3f(0,0,0);
            glMultTransposeMatrixf(s);
            glDisable(GL_LIGHTING);
            glTranslated(-3,0,-i);
            glTranslated(tx,ty,tz);
            glRotated(az,0,0,1);
            glRotated(ay,0,1,0);
            glRotated(ax,1,0,0);
            cadeira->setSombra(true);
            cadeira->desenhar();
            glEnable(GL_LIGHTING);
            glPopMatrix();
        }

        cadeiras->push_back(cadeira);
        cadeiras->pop_front();


        glPushMatrix();
        glColor3f(0.6,0.4,0.0);
        glColor3f(1,0,0);
        glTranslated(3,0,-i);
        cadeira = (Cadeira*)cadeiras->front();
        cadeira->desenhar();
        glPopMatrix();

        if(sombra){
            glPushMatrix();
            float s[16] = {
                            Luz::lightPosition[1], -Luz::lightPosition[0],                0.0,                0.0,
                            0.0,                0.0,                0.0,                0.0,
                            0.0, -Luz::lightPosition[2],  Luz::lightPosition[1],                0.0,
                            0.0, -Luz::lightPosition[3],                0.0,  Luz::lightPosition[1]
                        };
            glColor3f(0,0,0);
            glMultTransposeMatrixf(s);
            glDisable(GL_LIGHTING);
            glTranslated(3,0,-i);
            glTranslated(tx,ty,tz);
            glRotated(az,0,0,1);
            glRotated(ay,0,1,0);
            glRotated(ax,1,0,0);
            glColor3f(0,0,0);
            cadeira->setSombra(true);
            cadeira->desenhar();
            glEnable(GL_LIGHTING);
            glPopMatrix();
        }

        cadeiras->push_back(cadeira);
        cadeiras->pop_front();


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
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslated(5,0,-8);
    this->parede->desenhar();
    glEnable(GL_CULL_FACE);
    glPopMatrix();






}

void Laboratorio::aplicaSombras(float *matrizSombra)
{
    this->matrizSombra = matrizSombra;
}

void Laboratorio::setSombra(bool sombra)
{
    this->sombra = sombra;
}


Laboratorio::Laboratorio()
{

    this->matrizSombra = (float*) malloc(16*sizeof(float));
    this->objetosCenarios = new std::vector<Objeto*>();
    this->piso = new Piso();
    objetosCenarios->push_back(piso);
    this->parede = new Parede();
    objetosCenarios->push_back(parede);
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
