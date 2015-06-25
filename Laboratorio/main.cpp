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
#include "gui_glut/openTextures.h"
#include "gui.h"
#include "luz.h"
#define PADDING 5
#define BUFSIZE 512

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
bool multiple_viewports = false;
bool obj_transp = false;
float transparencia = 0.5;
static bool iluminacao = true;
static bool light0 = true;
static bool light1 = false;
static bool trans_luz = false;
static bool luz_pontual = false;
static bool spot_light = false;
static float spot_angle = 25.0;
float sx = 1.0;
float sy = 1.0;
float sz = 1.0;
int slices = 16;
int stacks = 16;
float lx = 0.0;
float ly = 0.0;
float lz = 0.0;
int pos_select = -1;
Camera* cam = new CameraDistante(1,3,22,0,1,0,0,1,0);
float savedCamera[9];
Laboratorio *lab = new Laboratorio();
std::vector<Objeto*>*objetos = lab->getObjetosCenario();
int qtd_lista = objetos->size();
int posVetorSelecionado = -1;
int ultimoIndice = qtd_lista -1 ;
GLuint selectBuf[BUFSIZE];
GLuint texturaLista[1];
enum { GRANITO = 0};
enum { OBJECT = 0, EYE, SPHERE_MAP };
bool textura_habilitada = false;
int indiceTextura;
bool texture_automatic;
int texture_mode;

int processHits( GLint hits, GLuint buffer[] ) {
  //for each hit in buffer
    //Number of names in the name stack
    //Minimum depth of the object
    //Maximum depth of the object
    //List of names of the name stack

  int i;
  GLuint names, *ptr, minZ,*ptrNames, numberOfNames;

  ptrNames = NULL;

  printf("Hits = %d\n",hits);
  printf("Buffer = ");
  for (i = 0; i < 4*hits; i++) {
    printf("%u ",buffer[i]);
  }
  printf("\n");

  ptr = (GLuint *) buffer;
  minZ = 0xffffffff;
  for (i = 0; i < hits; i++) {
    names = *ptr;
    //if (names == 3) {
      ptr++;
      //if ( (minZ==0xffffffff) || (*ptr < minZ && ( *(ptrNames+1)==*(ptr+3) ) ) || ( *(ptrNames+1)==0 && *(ptr+3)==1 ) ) {
      if (*ptr < minZ) {
          numberOfNames = names;
          minZ = *ptr;
          if (numberOfNames != 0)
            ptrNames = ptr+2;
      }
    //}
    ptr += names+2;
  }

  //ptr = ptrNames;
  //for (j = 0; j < numberOfNames; j++,ptr++) {
  //   printf ("%d ", *ptr);
  //}

  if (ptrNames == NULL)
    return 0;
  else
    return *ptrNames;
}


void loadTextures()
{
     if (ilGetInteger(IL_VERSION_NUM) < IL_VERSION)
     {
           printf("wrong DevIL version \n");
           return;
     }
     ilInit();

    glGenTextures(1, texturaLista);
    glBindTexture(GL_TEXTURE_2D, texturaLista[GRANITO]);
    OT::loadTexture( "/home/guilherme/git/Trabalho-1-ICG-2015.1/Laboratorio/texturas/granito.bmp", true );

}

void habilitaTextura( bool textura_habilitada, bool texture_automatic, int texture_mode ) {
    if ( textura_habilitada ) {
      glEnable(GL_TEXTURE_2D);
      if ( texture_automatic ) {
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
          if ( texture_mode == OBJECT ) {
            glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
            glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
          } else if ( texture_mode == EYE ) {
            glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
            glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
          } else {
            glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
            glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
          }
      }
    }
}

void selecionaTextura( int texture_id ) {
    glBindTexture( GL_TEXTURE_2D, texturaLista[texture_id] );
}

void desabilitaTextura( bool renderTexture, bool texture_automatic ) {
    if ( renderTexture ) {
      glDisable(GL_TEXTURE_2D);
      if ( texture_automatic ) {
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
      }
    }
}

void resize(int largura, int altura){
    width = largura;
    altura = altura;
}

void define_cor_de_selecao() {
        //material
        GLfloat mat_ambient[]    = { 0.5f, 0.0f, 0.0f, transparencia }; //1.0f };
        GLfloat mat_diffuse[]    = { 0.8f, 0.0f, 0.0f, transparencia }; //1.0f };
        GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, transparencia }; //1.0f };
        GLfloat high_shininess[] = { 100.0f };

        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

}

void define_cor_padrao() {

        //material
        GLfloat mat_ambient[]    = { 0.5f, 0.5f, 0.5f, transparencia }; //1.0f };
        GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, transparencia }; //1.0f };
        GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, transparencia }; //1.0f };
        GLfloat high_shininess[] = { 100.0f };

        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void define_iluminacao()
{
//light0
    //habilita/desabilita light0
    if (iluminacao && light0) glEnable(GL_LIGHT0);
    else glDisable(GL_LIGHT0);
    //definindo intensidades de cor da light0
    const GLfloat light0_ambient[]  = { 0.2f, 0.2f, 0.2f, 1.0f };
    const GLfloat light0_diffuse[]  = { 0.7f, 0.7f, 0.7f, 1.0f };
    const GLfloat light0_specular[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light0_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light0_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
    //posicionando light0
    GLfloat light0_position[] = { 1.0f + lx, 5.0f + ly, 1.0f + lz, 1.0f }; //4o parametro: 0.0 - luz no infinito, 1.0 - luz pontual
      if (!luz_pontual) light0_position[3] = 0.0f;
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    //desenha uma esfera representando a light0
    if (iluminacao && light0) {
        glDisable(GL_LIGHTING);
        glColor4f(1.0,1.0,1.0,1.0);
        glPushMatrix();
            glTranslatef(light0_position[0],light0_position[1],light0_position[2]);
            glutSolidSphere(0.05,slices,stacks);
        glPopMatrix();
        glEnable(GL_LIGHTING);
    }
    //desenha uma linha do (0,0,0) até a posição da light0
    if (iluminacao && light0 && trans_luz) {
        glDisable(GL_LIGHTING);
        glColor4f(1.0,1.0,1.0,1.0);
        glBegin(GL_LINES);
            glVertex3f(0,0,0);
            glVertex4fv(light0_position);
        glEnd();
        glEnable(GL_LIGHTING);
    }
    //spot_light
    if (spot_light) {
        const GLfloat light0_direction[] = { -(2.0f + lx), -(5.0f + ly), -(5.0f + lz), 1.0f };
        glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light0_direction);
        glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, spot_angle);
    } else {
        glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 180.0);
    }

//light1
    //habilita/desabilita light1
    if (iluminacao && light1) glEnable(GL_LIGHT1);
    else glDisable(GL_LIGHT1);
    //definindo intensidades de cor da light1
    const GLfloat light1_ambient[]  = { 0.02f, 0.02f, 0.02f, 1.0f };
    const GLfloat light1_diffuse[]  = { 0.4f, 0.4f, 0.4f, 1.0f };
    const GLfloat light1_specular[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    glLightfv(GL_LIGHT1, GL_AMBIENT,  light1_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE,  light1_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
    //posicionando light1
    const GLfloat light1_position[] = {1.0f + lx, 5.0f + ly, -10.0f + lz, 1.0f };
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    //desenha uma esfera representando a light1
    if (iluminacao && light1) {
        glDisable(GL_LIGHTING);
        glColor4f(1.0,1.0,1.0,1.0);
        glPushMatrix();
            glTranslatef(light1_position[0],light1_position[1],light1_position[2]);
            glutSolidSphere(0.05,slices,stacks);
        glPopMatrix();
        glEnable(GL_LIGHTING);
    }
}



static void inner_display() {

    define_iluminacao();



    if (!iluminacao) glDisable(GL_LIGHTING);
      if (!obj_transp) {
          glDisable(GL_BLEND);
          glEnable(GL_COLOR_MATERIAL);
      } else {
          glDisable(GL_COLOR_MATERIAL);
      }


        glColor4f(1,1,1,transparencia);


        glPushMatrix();
        habilitaTextura(textura_habilitada, texture_automatic, texture_mode);
          selecionaTextura(indiceTextura);
        Piso *piso = (Piso*)objetos->at(0);
        piso->desenhar();
        desabilitaTextura(textura_habilitada, texture_automatic);
        glPopMatrix();


      lab->contruirCenario();





      glEnable(GL_LIGHTING);

      glEnable(GL_BLEND);


}


void display() {

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

                habilitaTextura(textura_habilitada, texture_automatic, texture_mode);
                selecionaTextura(indiceTextura);
                inner_display();
                desabilitaTextura(textura_habilitada, texture_automatic);

    } else {
        //viewport 01 - top left
        glViewport(0, height/2.0, width/2.0, height/2.0);
            glLoadIdentity();
            gluLookAt(cam->e.x,cam->e.y,cam->e.z, cam->c.x,cam->c.y,cam->c.z, cam->u.x,cam->u.y,cam->u.z);
                inner_display();
        //viewport 02 - top right
        glViewport(width/2.0, height/2.0, width/2.0, height/2.0);
            glLoadIdentity();
            gluLookAt(0.8,3.5,-25, 0,1,0, 0,1,0);
                inner_display();
        //viewport 03 - bottom left
        glViewport(0, 0, width/2.0, height/2.0);
            glLoadIdentity();
            gluLookAt(-25,5,-5, 1,1.5,-4, 0,1,0);
                inner_display();
        //viewport 04 - bottom right
        glViewport(width/2.0, 0, width/2.0, height/2.0);
            glLoadIdentity();
            gluLookAt(2,38,-4, 2,1,-3.5, 0,0,-1);
                inner_display();
    }

    glutSwapBuffers();


}

//picking
int picking( GLint cursorX, GLint cursorY, int w, int h ) {
  GLint viewport[4];

  glDisable(GL_LIGHTING);

    glSelectBuffer(BUFSIZE,selectBuf);
    glRenderMode(GL_SELECT);

    glMatrixMode(GL_PROJECTION);
    //glPushMatrix();
    glLoadIdentity();

    glGetIntegerv(GL_VIEWPORT,viewport);
    gluPickMatrix(cursorX,viewport[3]-cursorY,w,h,viewport);

//de acordo com a implementacao
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    const float ar = height>0 ? (float) width / (float) height : 1.0;

    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    gluPerspective(30.,ar,0.1,1000.);

    glMatrixMode(GL_MODELVIEW);
    glInitNames();

        //viewport unica
        //glViewport(0, 0, width, height);
            glLoadIdentity();
            gluLookAt(cam->e.x,cam->e.y,cam->e.z, cam->c.x,cam->c.y,cam->c.z, cam->u.x,cam->u.y,cam->u.z);
                inner_display();
                //lab->contruirCenario();
//fim-de acordo com a implementacao

  glEnable(GL_LIGHTING);

//processando as intersecoes
    int hits;

    // restoring the original projection matrix
    //glMatrixMode(GL_PROJECTION);
    //glPopMatrix();
    //glMatrixMode(GL_MODELVIEW);
    //glFlush();

    // returning to normal rendering mode
    hits = glRenderMode(GL_RENDER);

    // if there are hits process them
    if (hits != 0) {
      return processHits(hits,selectBuf);
    } else {
      return 0;
    }
}

void mouseButton(int button, int state, int x, int y) {


    if (button == GLUT_LEFT_BUTTON) {
            // when the button is pressed
            if (state == GLUT_DOWN) {
                int pick = picking(x, y, 5, 5);
                if(pick==0)
                    lbpressed = true;
                else {
                    if(pos_select>=0 && pos_select<=ultimoIndice){
                        Objeto *obj = objetos->at(pos_select);

                        obj->setSelecionado(false);
                    }
                    pos_select = pick;
                    Objeto *obj = objetos->at(pos_select);
                    obj->setSelecionado(true);
                }
                //cout << pick << endl;
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
        if (!trans_obj && (!trans_luz || !obj_transp)) {
            cam->rotatex(y,last_y);
            cam->rotatey(x,last_x);
        }
        if (trans_obj) {
            ax += (y - last_y)/fator;
            ay += (x - last_x)/fator;
        }
        if (trans_luz && obj_transp) {
            fator = 100.0;
            transparencia -= (y - last_y)/fator;
            if (transparencia < 0.0) transparencia = 0.0;
            if (transparencia > 1.0) transparencia = 1.0;
        }
    }
    fator = 100.0;
    if (!lbpressed && rbpressed && !mbpressed) {
        if (!trans_obj && !trans_luz) {
            cam->translatex(x,last_x);
            cam->translatey(y,last_y);
        }
        if (trans_obj) {
            tx += (x - last_x)/fator;
            ty += -(y - last_y)/fator;
        }
        if (trans_luz) {
            lx += (x - last_x)/fator;
            ly += -(y - last_y)/fator;
        }
    }
    if (lbpressed && rbpressed && !mbpressed) {
        if (!trans_obj && !trans_luz) {
            cam->zoom(y,last_y);
        }
        if (trans_obj) {
            fator = 100.0;
            tz += (y - last_y)/fator;
            fator = 10.0;
            az += -(x - last_x)/fator;
        }
        if (trans_luz) {
            fator = 100.0;
            lz += (y - last_y)/fator;
            fator = 10.0;
            spot_angle += -(x - last_x)/fator;
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
        spot_angle=25.0;
        transparencia=0.5;
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

    case 'l':
        iluminacao = !iluminacao;
        if (!iluminacao) trans_luz = false;
        break;
        /*
        Luz::lightPosition[3] = 1 - Luz::lightPosition[3];
        if(Luz::lightPosition[3] == 1){
            lab->setSombra(true);
        }else{
            lab->setSombra(false);
        }
        */
        break;

    case '0':
        light0 = !light0;
        if (!light0) trans_luz = false;
        break;
    case '2':
        trans_luz = !trans_luz;
        break;
    case '3':
        luz_pontual = !luz_pontual;
        break;
    case '4':
        spot_light = !spot_light;
        break;
    case '1':
        light1 = !light1;
        break;
    case 'm':
        multiple_viewports = !multiple_viewports;
        break;
    case 'c':
        obj_transp = !obj_transp;
        break;

      case 'n':
        if (cam->estilo == 1) {
            delete cam;
            double dist = sqrt(1 / 3.0);
            cam = new CameraDistante(dist+3,dist+3,dist+3, 0.0,0.0,0.0, 0.0,1.0,0.0);
        }
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

    case 'u':
        textura_habilitada = !textura_habilitada;
        break;
    case 'U':
        indiceTextura++;
        indiceTextura %= 1;
        break;
    case 'r':
        texture_automatic = !texture_automatic;
        break;
    case 'R':
        texture_mode++;
        texture_mode %= 3;
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
    glutDisplayFunc(display);
    glClearColor(0,0,0,0);

    //teclado e maouse
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
    glutSpecialFunc(direcionalKeys);

    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    loadTextures();
    glutMainLoop();

    return EXIT_SUCCESS;
}
