#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <iomanip>
#include "cadeira.h"
#include "mesa.h"
#include "camera.h"
#include "cameradistante.h"
#include "desenha.h"
#include "computador.h"
#include "piso.h"
#include "quadro.h"
#include "laboratorio.h"

using namespace std;

float width = 1280;
float height= 720;
bool lbpressed = false;
bool mbpressed = false;
bool rbpressed = false;
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
float sx = 1.0;
float sy = 1.0;
float sz = 1.0;
int slices = 16;
int stacks = 16;

Camera* cam = new CameraDistante();
float savedCamera[9];

void tamanho(int largura, int altura){
    width = largura;
    altura = altura;
}

void displayInit() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    const float ar = height>0 ? (float) width / (float) height : 1.0;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.,ar,0.1,1000.);
    //Camera
    gluLookAt(cam->e.x,cam->e.y,cam->e.z, cam->c.x,cam->c.y,cam->c.z, cam->u.x,cam->u.y,cam->u.z);
}

void display() {
    displayInit();

    glColor3f(1,1,1);

    //Desenha::drawGrid(10, 0, 10,1);

    Laboratorio *lab = new Laboratorio();
    lab->contruirCenario();

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
        if (!trans_obj) {
            cam->translatex(x,last_x);
            cam->translatey(y,last_y);
        } else {
            tx += (x - last_x)/fator;
            ty += -(y - last_y)/fator;
        }
    }
    if (lbpressed && rbpressed && !mbpressed) {
        if (!trans_obj) {
            cam->zoom(y,last_y);
        } else {
            tz += (y - last_y)/fator;
            fator = 10.0;
            az += -(x - last_x)/fator;
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
    glutPostRedisplay();
}

void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27 :
    case 13 :
    case 'q':
        exit(0);
        break;

    case 'F':
        glutFullScreen();
        break;
    case 'f':
        glutReshapeWindow(800,600);
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

    case 'i':
        ax=ay=az=0.0;
        tx=ty=tz=0.0;
        sx=sy=sz=1.0;
        break;

    case 't':
        trans_obj = !trans_obj;
        break;

    case 'c':
        static int posCam = 0;
        posCam++;
        if (cam->estilo == 1) {
            delete cam;
            if (posCam%5==0) cam = new CameraDistante(); //CameraDistante(0,1,5, 0,1,0, 0,1,0);
            if (posCam%5==1) cam = new CameraDistante(5,1,0, 0,1,0, 0,1,0);
            if (posCam%5==2) cam = new CameraDistante(0,1,-5, 0,1,0, 0,1,0);
            if (posCam%5==3) cam = new CameraDistante(-5,1,0, 0,1,0, 0,1,0);
            if (posCam%5==4) cam = new CameraDistante(savedCamera[0],savedCamera[1],savedCamera[2],savedCamera[3],savedCamera[4],savedCamera[5],savedCamera[6],savedCamera[7],savedCamera[8]);
        } else if (cam->estilo == 2) {
            delete cam;
            cam = new CameraDistante();
        }
        break;

    case 's':
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

    glutPostRedisplay();
}

void idle(void)
{
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{

    //Inicializando tela e suas dimensoes
    glutInit(&argc, argv);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Laboratorio");
    glutReshapeFunc(tamanho);
    glutDisplayFunc(display);
    glClearColor(0,0,0,0);

    //teclado e maouse
    glutKeyboardFunc(key);
    //glutIdleFunc(idle);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);


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
