TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += gui_glut
INCLUDEPATH += user

LIBS += -lGL -lGLU -lglut

SOURCES += main.cpp \
    cadeira.cpp \
    mesa.cpp \
    objeto.cpp \
    vetor3d.cpp \
    desenha.cpp \
    camera.cpp \
    cameradistante.cpp \
    computador.cpp \
    piso.cpp \
    quadro.cpp \
    laboratorio.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    cadeira.h \
    mesa.h \
    objeto.h \
    vetor3d.h \
    desenha.h \
    camera.h \
    cameradistante.h \
    computador.h \
    piso.h \
    quadro.h \
    laboratorio.h

