QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bala.cpp \
    bala_graph.cpp \
    enemigo_normal.cpp \
    enemigos_saltarines.cpp \
    enemigos_sgraph.cpp \
    main.cpp \
    mainwindow.cpp \
    personaje.cpp \
<<<<<<< HEAD
    puntaje.cpp \
=======
>>>>>>> 522d6ef6ce13ae778b3c4033ea9ffc986048a540
    vida.cpp

HEADERS += \
    bala.h \
    bala_graph.h \
    enemigo_normal.h \
    enemigos_saltarines.h \
    enemigos_sgraph.h \
    mainwindow.h \
    personaje.h \
<<<<<<< HEAD
    puntaje.h \
=======
>>>>>>> 522d6ef6ce13ae778b3c4033ea9ffc986048a540
    vida.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
