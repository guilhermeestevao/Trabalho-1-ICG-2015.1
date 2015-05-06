#include "luz.h"

GLfloat *Luz::lightPosition;

Luz::Luz()
{

}

Luz::~Luz()
{

}

void Luz::inicializar()
{
    lightPosition = (float*) malloc(4*sizeof(float));
    lightPosition[0] = 0.0f;
    lightPosition[1] = 4.5f;
    lightPosition[2] = 4.0f;
    lightPosition[3] = 0.0f;
}
