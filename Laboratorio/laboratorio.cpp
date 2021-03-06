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
        glPushName(mesa->id);
        mesa->desenhar();
        glPopName();
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

            mesa->desenhar();
            glPopName();
            glEnable(GL_LIGHTING);
            glPopMatrix();
        }

        mesas->push_back(mesa);
        mesas->pop_front();

        glPushMatrix();
        glColor3f(0.6,0.4,0.0);
        glTranslated(3,0,-i);
        mesa = (Mesa*) mesas->front();
        glPushName(mesa->id);
        mesa->desenhar();
        glPopName();
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
        glPushName(mesa->id);
        mesa->desenhar();
        glPopName();
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
    glPushName(mesaProfessor->id);
    mesaProfessor->desenhar();
    glPopName();
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

        mesaProfessor->desenhar();
        glEnable(GL_LIGHTING);
        glPopMatrix();
    }

    objetosCenarios->push_back(mesaProfessor);


    glPushMatrix();
    glColor3f(1,0,0);
    glRotated(180, 0,1,0);
    glTranslated(-2,0,-4);
    glPushName(cadeiraProfessor->id);
    cadeiraProfessor->desenhar();
    glPopName();
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

        cadeiraProfessor->desenhar();
        glEnable(GL_LIGHTING);
        glPopMatrix();
    }

    objetosCenarios->push_back(cadeiraProfessor);

    glPushMatrix();
    glColor3f(0,0,1);
    glRotated(180, 0,1,0);
    glTranslated(-2,0,-4);
    computadorProfessor->desenhar();
    glPushName(computadorProfessor->id);
    objetosCenarios->push_back(cadeiraProfessor);
    glPopName();
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
        glPushName(cadeira->id);
        cadeira->desenhar();
        glPopName();
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
        glPushName(cadeira->id);
        cadeira->desenhar();
        glPopName();
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
        glPushName(cadeira->id);
        cadeira->desenhar();
        glPopName();
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
        glColor3f(0,0,1);
        computador = (Computador*)computadores->front();
        glPushName(computador->id);
        computador->desenhar();
        glPopName();
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
            glColor3f(0,0,0);

            computador->desenhar();
            glEnable(GL_LIGHTING);
            glPopMatrix();
        }

        computadores->push_back(computador);
        computadores->pop_front();


        glPushMatrix();
        glTranslated(-3,0,-i);
        glColor3f(0,0,1);
        computador = (Computador*)computadores->front();
        glPushName(computador->id);
        computador->desenhar();
        glPopName();
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
            glColor3f(0,0,0);

            computador->desenhar();
            glEnable(GL_LIGHTING);
            glPopMatrix();
        }

        computadores->push_back(computador);
        computadores->pop_front();

        glPushMatrix();
        glTranslated(3,0,-i);
        glColor3f(0,0,1);
        computador = (Computador*)computadores->front();
        glPushName(computador->id);
        computador->desenhar();
        glPopName();
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

            computador->desenhar();
            glEnable(GL_LIGHTING);
            glPopMatrix();
        }

        computadores->push_back(computador);
        computadores->pop_front();

    }


}

void Laboratorio::desenhaQuadroEpiso()
{

    glPushMatrix();
    glPushName(piso->id);
    glDisable(GL_CULL_FACE);
    glTranslated(0,0,0);
    //this->piso->desenhar();
    glPopName();
    glEnable(GL_CULL_FACE);
    glPopMatrix();
    glPushMatrix();
    glPushName(quadro->id);
    glDisable(GL_CULL_FACE);
    glTranslated(0,1,5);
    this->quadro->desenhar();
    glPopName();
    glEnable(GL_CULL_FACE);
    glPopMatrix();
    glPushMatrix();
    glPushName(parede->id);
    glDisable(GL_CULL_FACE);
    glTranslated(5,0,-8);
    this->parede->desenhar();
    glPopName();
    glEnable(GL_CULL_FACE);
    glPopMatrix();

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
    piso->id = 0;
    objetosCenarios->push_back(piso);
    this->parede = new Parede();
    parede->id = 1;
    objetosCenarios->push_back(parede);
    this->quadro = new Quadro();
    quadro->id = 2;
    objetosCenarios->push_back(quadro);
    this->mesaProfessor = new Mesa();
    mesaProfessor->id = 3;
    objetosCenarios->push_back(mesaProfessor);
    this->cadeiraProfessor = new Cadeira();
    cadeiraProfessor->id = 4;
    objetosCenarios->push_back(cadeiraProfessor);
    this->computadorProfessor = new Computador();
    computadorProfessor->id = 5;
    objetosCenarios->push_back(computadorProfessor);
    int k = 6;
    this->mesas = new std::list<Mesa*>();
    for(int i = 0; i<QUANTIDADE*3; i++){
        Mesa *mesa = new Mesa();
        mesa->id = k;
        mesas->push_back(mesa);
        objetosCenarios->push_back(mesa);
        k++;
    }

    this->cadeiras = new std::list<Cadeira*>();
    for(int i = 0; i<QUANTIDADE*3; i++){
        Cadeira *cadeira = new Cadeira();
        cadeira->id = k;
        cadeiras->push_back(cadeira);
        objetosCenarios->push_back(cadeira);
        k++;
    }

    this->computadores = new std::list<Computador*>();
    for(int i = 0; i<QUANTIDADE*3; i++){
        Computador *computador = new Computador();
        computador->id = k;
        computadores->push_back(computador);
        objetosCenarios->push_back(computador);
        k++;
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
