QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    anuncio.cpp \
    enemigo_fisica.cpp \
    enemigo_graf.cpp \
    enemigo_normal.cpp \
    main.cpp \
    mainwindow.cpp \
    muro.cpp \
    nivel_1.cpp \
    personaje.cpp

HEADERS += \
    anuncio.h \
    enemigo_fisica.h \
    enemigo_graf.h \
    enemigo_normal.h \
    mainwindow.h \
    muro.h \
    nivel_1.h \
    personaje.h

FORMS += \
    mainwindow.ui \
    nivel_1.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
