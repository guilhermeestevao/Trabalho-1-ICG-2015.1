#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <iomanip>
#include "cadeira.h"
#include "mesa.h"
#include "bib/Camera.h"
#include "bib/CameraDistante.h"
#include "bib/Desenha.h"
#include "computador.h"
#include "piso.h"
#include "quadro.h"
#include "laboratorio.h"
#include "gui.h"
#include "luz.h"
#define PADDING 5

using namespace std;

float width = 1280;
float height= 720;
bool lbpressed = false;
bool mbpressed = false;
bool rbpressed = false;
bool projecao = false;
float trans_obj = false;
float last_x = 0.0;
float last_y = 0.0;
float tx = 0.0;
float ty = 0.0;
float tz = 0.0;
float ax = 0.0;
float ay = 0.0;
float az = 0.0;
float delta = 5.0;
bool trans_luz = false;
bool multiple_viewports = false;
bool obj_transp = false;
float transparencia = 0.5;
float sx = 1.0;
float sy = 1.0;
float sz = 1.0;
int slices = 16;
int stacks = 16;
int pos_select = -1;
Camera* cam = new CameraDistante(1,3,22,0,1,0,0,1,0);
float savedCamera[9];
Laboratorio *lab = new Laboratorio();
std::vector<Objeto*>*objetos = lab->getObjetosCenario();
int qtd_lista = objetos->size();

void resize(int largura, int altura){
    width = largura;
    altura = altura;
}




void display() {

    //displayInit();

    if (!obj_transp) glDisable(GL_BLEND); //transparencia

    glColor4f(1,1,1,transparencia);

    //glColor3f(1,1,1);

    //posicao da luz
    glPushMatrix();
    glutGUI::trans_luz = trans_luz;
    GUI::setLight(0, Luz::lightPosition[0], Luz::lightPosition[1], Luz::lightPosition[2], false, false);
    glLightfv(GL_LIGHT0, GL_POSITION, Luz::lightPosition);
    glPopMatrix();

    lab->contruirCenario();



    cout<<"e.x = "<<cam->e.x<<"e.y = "<<cam->e.y<<"e.z = "<<cam->e.z<<"c.x = "<<cam->c.x<<"c.y = "<<cam->c.y<<"c.z = "<<cam->c.z<<"u.x = "<<cam->u.x<<"u.y"<<cam->u.y<<"u.z = "<<cam->u.z<<endl;

}

void displayInit() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    const float ar = height>0 ? (float) width / (float) height : 1.0;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.,ar,0.1,1000.);

    glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();



    if (!multiple_viewports) {
        //viewport unica
        glViewport(0, 0, width, height);
            glLoadIdentity();
            gluLookAt(cam->e.x,cam->e.y,cam->e.z, cam->c.x,cam->c.y,cam->c.z, cam->u.x,cam->u.y,cam->u.z);
                display();
    } else {
        //viewport 01 - top left
        glViewport(0, height/2.0, width/2.0, height/2.0);
            glLoadIdentity();
            gluLookAt(cam->e.x,cam->e.y,cam->e.z, cam->c.x,cam->c.y,cam->c.z, cam->u.x,cam->u.y,cam->u.z);
                display();
        //viewport 02 - top right
        glViewport(width/2.0, height/2.0, width/2.0, height/2.0);
            glLoadIdentity();
            gluLookAt(0.8,3.5,-25, 0,1,0, 0,1,0);
                display();
        //viewport 03 - bottom left
        glViewport(0, 0, width/2.0, height/2.0);
            glLoadIdentity();
            gluLookAt(-25,5,-5, 1,1.5,-4, 0,1,0);
                display();
        //viewport 04 - bottom right
        glViewport(width/2.0, 0, width/2.0, height/2.0);
            glLoadIdentity();
            gluLookAt(2,38,-4, 2,1,-3.5, 0,0,-1);
                display();
    }

    glutSwapBuffers();


}




void mouseButton(int button, int state, int x, int y) {


    // if the left button is pressed
    if (button == GLUT_LEFT_BUTTON) {
        // when the button is pressed
        if (state == GLUT_DOWN) {
            lbpressed = true;
        } else {// state = GLUT_UP
            lbpressed = false;
        }
    }
    // if the middle button is pressed
    if (button == GLUT_MIDDLE_BUTTON) {
        // when the button is pressed
        if (state == GLUT_DOWN) {
            mbpressed = true;
        } else {// state = GLUT_UP
            mbpressed = false;
        }
    }
    // if the left button is pressed
    if (button == GLUT_RIGHT_BUTTON) {
        // when the button is pressed
        if (state == GLUT_DOWN) {
            rbpressed = true;
        } else {// state = GLUT_UP
            rbpressed = false;
        }
    }
    last_x = x;
    last_y = y;
}

void mouseMove(int x, int y) {

    Objeto* obj;
    if(pos_select != -1){
        obj = objetos->at(pos_select);

        ax = obj->getAX();
        ay = obj->getAY();
        az = obj->getAZ();
        tx = obj->getTX();
        ty = obj->getTY();
        tz = obj->getTZ();
        sx = obj->getSX();
        sy = obj->getSY();
        sz = obj->getSZ();
    }

    float fator = 10.0;
    if (lbpressed && !rbpressed && !mbpressed) {
        if (!trans_obj) {
            cam->rotatex(y,last_y);
            cam->rotatey(x,last_x);
        } else {
            ax += (y - last_y)/fator;
            ay += (x - last_x)/fator;
        }
    }

    fator = 100.0;
    if (!lbpressed && rbpressed && !mbpressed) {
        if (!trans_obj && !trans_luz) {
            cam->translatex(x,last_x);
            cam->translatey(y,last_y);
        } else {
            if (trans_obj){
                tx += (x - last_x)/fator;
                ty += -(y - last_y)/fator;
            }
            if (trans_luz){
                Luz::lightPosition[0] += (x - last_x)/fator;
                Luz::lightPosition[1] += -(y - last_y)/fator;
            }
        }
    }

    if (lbpressed && rbpressed && !mbpressed) {
        if (!trans_obj && !trans_luz) {
            cam->zoom(y,last_y);
        } else {
            if (trans_obj) {
                tz += (y - last_y)/fator;
                fator = 10.0;
                az += -(x - last_x)/fator;
            }
            if (trans_luz) {
                Luz::lightPosition[2] += (y - last_y)/fator;
            }
        }
    }

    fator = 100.0;
    if (!lbpressed && !rbpressed && mbpressed) {
        if (!trans_obj) {
        } else {
            sx += (x - last_x)/fator;
            sy += -(y - last_y)/fator;
        }
    }
    if (lbpressed && !rbpressed && mbpressed) {
        if (!trans_obj) {
        } else {
            sz += (y - last_y)/fator;
        }
    }

    last_x = x;
    last_y = y;





    if(pos_select != -1){
        obj->setTranslacao(tx, ty, tz);
        obj->setRotacao(ax, ay, az);
        obj->setEscala(sx, sy, sz);
    }
    glutPostRedisplay();
}



void direcionalKeys( int key, int x, int y ) {
    Objeto* obj;
    Objeto* anterior;
    Objeto* proximo;
    switch (key) {
    case GLUT_KEY_UP:

        if(pos_select == qtd_lista-1){
            pos_select = -1;
        }

        pos_select++;
        obj = objetos->at(pos_select);
        obj->setSelecionado(true);

        if(pos_select != 0){
            anterior = objetos->at(pos_select-1);
            anterior->setSelecionado(false);
        }else{
            anterior = objetos->at(qtd_lista-1);
            anterior->setSelecionado(false);
        }

        break;

    case GLUT_KEY_DOWN:

        if(pos_select == 0){
            pos_select = qtd_lista-1;
        }

        if(pos_select == -1){
            pos_select = 1;
        }


        if(pos_select == qtd_lista-1){
            obj = objetos->at(0);
            obj->setSelecionado(false);
        }

        pos_select--;
        obj = objetos->at(pos_select);
        obj->setSelecionado(true);

        if(pos_select != qtd_lista){
            anterior = objetos->at(pos_select+1);
            anterior->setSelecionado(false);
        }else{
            proximo = objetos->at(qtd_lista+1);
            proximo->setSelecionado(false);
        }

        break;
    case GLUT_KEY_RIGHT:
        obj = objetos->at(pos_select);
        obj->setEixos(true);
        break;
    case GLUT_KEY_LEFT:
        obj = objetos->at(pos_select);
        obj->setEixos(false);
        break;

    }

    glutPostRedisplay();

}


void key(unsigned char key, int x, int y)
{
    Objeto* obj;

    if(pos_select != -1){
        obj = objetos->at(pos_select);


        ax = obj->getAX();
        ay = obj->getAY();
        az = obj->getAZ();
        tx = obj->getTX();
        ty = obj->getTY();
        tz = obj->getTZ();
        sx = obj->getSX();
        sy = obj->getSY();
        sz = obj->getSZ();

    }

    switch (key)
    {
    case 27 :
    case 13 :
        exit(0);
        break;

    case 'F':
        glutFullScreen();
        break;
    case 'f':
        glutReshapeWindow(1280,720);
        break;
    case '+':
        slices++;
        stacks++;
        break;
    case '-':
        if (slices>3 && stacks>3)
        {
            slices--;
            stacks--;
        }
        break;
    case 'X':
        ax+=delta;
        break;
    case 'Y':
        ay+=delta;
        break;
    case 'Z':
        az+=delta;
        break;
    case 'x':
        ax-=delta;
        break;
    case 'y':
        ay-=delta;
        break;
    case 'z':
        az-=delta;
        break;
    case 'w':
        tz+=1;
        break;
    case 's':
        tz-=1;
        break;
    case 'd':
        tx-=1;
        break;
    case 'a':
        tx+=1;
        break;
    case 'q':
        ty+=1;
        break;
    case 'e':
        ty-=1;
        break;
    case 'W':
        sz *=2;
        break;
    case 'S':
        sz /=2;
        break;
    case 'D':
        sx*=2;
        break;
    case 'A':
        sx/=2;
        break;
    case 'Q':
        sy*=2;
        break;
    case 'E':
        sy/=2;
        break;
    case 'i':
        ax=ay=az=0.0;
        tx=ty=tz=0.0;
        sx=sy=sz=1.0;
        break;
    case 't':
        trans_obj = !trans_obj;
        break;
    case 'p':
        projecao = true;
        break;
    case 'P':
        projecao = false;
        break;
    case 'v':
        trans_luz = !trans_luz;
        break;
    case 'T':
        obj_transp = !obj_transp;
        break;
    case 'l':
        Luz::lightPosition[3] = 1 - Luz::lightPosition[3];
        if(Luz::lightPosition[3] == 1){
            lab->setSombra(true);
        }else{
            lab->setSombra(false);
        }

        break;

    case 'n':
        if (cam->estilo == 1) {
            delete cam;
            double dist = sqrt(1 / 3.0);
            cam = new CameraDistante(dist+3,dist+3,dist+3, 0.0,0.0,0.0, 0.0,1.0,0.0);
        }
        break;

    case 'm':
        multiple_viewports = !multiple_viewports;
        break;
    case 'c':
        obj_transp = !obj_transp;
        break;

    /*
    case 'c':
        static int posCam = 0;
        posCam++;
        if (cam->estilo == 1) {
            delete cam;
            if (posCam%5==0) cam = new CameraDistante(); //CameraDistante(0,1,5, 0,1,0, 0,1,0);
            if (posCam%5==1) cam = new CameraDistante(10,20,8, 0,1,0, 0,1,0);
            if (posCam%5==2) cam = new CameraDistante(0,6.5,-16, 0,1,0, 0,1,0);
            if (posCam%5==3) cam = new CameraDistante(-13,7,17 , 0,1,0, 0,1,0);
            if (posCam%5==4) cam = new CameraDistante(savedCamera[0],savedCamera[1],savedCamera[2],savedCamera[3],savedCamera[4],savedCamera[5],savedCamera[6],savedCamera[7],savedCamera[8]);
        } else if (cam->estilo == 2) {
            delete cam;
            cam = new CameraDistante(1,3,22,0,1,0,0,1,0);
        }
        break;
    */
    case 'b':
        //save current camera location
        savedCamera[0] = cam->e.x;
        savedCamera[1] = cam->e.y;
        savedCamera[2] = cam->e.z;
        savedCamera[3] = cam->c.x;
        savedCamera[4] = cam->c.y;
        savedCamera[5] = cam->c.z;
        savedCamera[6] = cam->u.x;
        savedCamera[7] = cam->u.y;
        savedCamera[8] = cam->u.z;
        break;
    }

    if(pos_select != -1){
        obj->setTranslacao(tx, ty, tz);
        obj->setRotacao(ax, ay, az);
        obj->setEscala(sx, sy, sz);
    }
    glutPostRedisplay();
}



void idle(void)
{
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{

    Luz::inicializar();


    //Inicializando tela e suas dimensoes
    glutInit(&argc, argv);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Laboratorio");
    //glutReshapeFunc(tamanho);
    glutDisplayFunc(displayInit);
    glClearColor(0,0,0,0);

    //teclado e maouse
    glutKeyboardFunc(key);
    //glutIdleFunc(idle);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
    glutSpecialFunc(direcionalKeys);



    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
    const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };
    const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
    const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
    const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat high_shininess[] = { 100.0f };
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutMainLoop();
}
