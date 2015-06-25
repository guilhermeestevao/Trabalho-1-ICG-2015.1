TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += bib
INCLUDEPATH += gui_glut
INCLUDEPATH += user

DEFINES += USE_SDL
LIBS += -lglut -lgsl -l3ds -lGLU -lGL -lm -lSDL -lSDL_image -lIL

HEADERS += \
    bib/Camera.h \
    bib/CameraDistante.h \
    bib/CameraJogo.h \
    bib/Desenha.h \
    bib/Vetor3D.h \
    bib/model3ds.h \
    bib/stanfordbunny.h \
    gui_glut/extra.h \
    gui_glut/gui.h \
    gui_glut/openTextures.h \
    cadeira.h \
    mesa.h \
    objeto.h \
    computador.h \
    piso.h \
    quadro.h \
    laboratorio.h \
    parede.h \
    luz.h

SOURCES += \
    bib/Camera.cpp \
    bib/CameraDistante.cpp \
    bib/CameraJogo.cpp \
    bib/Desenha.cpp \
    bib/Vetor3D.cpp \
    main.cpp \
    bib/model3ds.cpp \
    gui_glut/extra.cpp \
    gui_glut/gui.cpp \
    gui_glut/openTextures.cpp \
    cadeira.cpp \
    mesa.cpp \
    objeto.cpp \
    computador.cpp \
    piso.cpp \
    quadro.cpp \
    laboratorio.cpp \
    parede.cpp \
    luz.cpp

include(deployment.pri)
qtcAddDeployment()

