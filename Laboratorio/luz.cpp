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
    lightPosition[1] = 10.0f;
    lightPosition[2] = 3.0f;
    lightPosition[3] = 0.0f;
}
