#ifndef CADEIRAPROFESSOR_H
#define CADEIRAPROFESSOR_H

#include <GL/glut.h>
#include <Objeto.h>
#include <Desenha.h>

class CadeiraProfessor : public Objeto
{
    public:

        bool selected;
        bool eixos;
        int ax, ay, az;
        int sx, sy, sz;
        int tx, ty, tz;

        CadeiraProfessor();
        ~CadeiraProfessor();

        void desenhar();
        void setRotated(float x, float y, float z);
        void setScaled(float x, float y, float z);
        void setTranslated(float x, float y, float z);
        void setEixos(bool enable);
        void setSelected(bool enable);








    protected:

    private:

};

#endif // CADEIRAPROFESSOR_H
