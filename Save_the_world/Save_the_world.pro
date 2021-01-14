QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    anuncios.cpp \
    bala_comun.cpp \
    enemy.cpp \
    escudo.cpp \
    escudo_graph.cpp \
    main.cpp \
    mainwindow.cpp \
    paredes.cpp \
    personaje.cpp \
    puntaje.cpp

HEADERS += \
    anuncios.h \
    bala_comun.h \
    enemy.h \
    escudo.h \
    escudo_graph.h \
    mainwindow.h \
    paredes.h \
    personaje.h \
    puntaje.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Disenho.qrc
