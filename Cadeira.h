#ifndef CADEIRA_H
#define CADEIRA_H

#include <GL/glut.h>
#include <Objeto.h>
#include <Desenha.h>

class Cadeira : public Objeto
{
    public:

        bool shadow;
        bool selected;
        bool eixos;
        int ax, ay, az;
        int sx, sy, sz;
        int tx, ty, tz;

        Cadeira();
        ~Cadeira();

        void desenhar();
        void setRotated(float x, float y, float z);
        void setScaled(float x, float y, float z);
        void setTranslated(float x, float y, float z);
        void setEixos(bool enable);
        void setSelected(bool enable);
        void setShadows(bool enable);


    protected:

    private:
};

#endif // CADEIRA_H
