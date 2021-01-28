#ifndef NIVEL3_H
#define NIVEL3_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QMainWindow>
#include <QKeyEvent>
#include <string.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <QDebug>
#include <QTimer>
#include <QList>
#include <QFile>
#include <QString>

#include "muro.h"
#include "anuncio.h"
#include "monedas.h"
#include "personaje3.h"
#include "informacion.h"
#include "enemigo_graf.h"
#include "personaje3graf.h"
#include "enemigo_fisica.h"
#include "mainwindow.h"
#include "nivel_1.h"

// Clase encargada de administrar lo relacionado con el nivel 3

namespace Ui {
class Nivel3;
}

class Nivel3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Nivel3(QWidget *parent = nullptr);
    ~Nivel3();

    Informacion getDatos_juego() const;
    void setDatos_juego(const Informacion &value);

public slots:
    //****** Movimiento *******
    void actualizar();
    void Movimiento_Enemigo();
    void borderCollision();
    //*************************

    void Perder();

private slots:
    //*********** Botones *************
    void on_Inicio_clicked();
    void on_Instrucciones_clicked();
    void on_Volver_clicked();
    void on_Siguiente_clicked();
    void on_Reiniciar_clicked();
    void on_Salir_clicked();
    void on_Volver_jugar_clicked();
    void on_Fondo1_clicked();
    void on_Fondo2_clicked();
    void on_Hombre_clicked();
    void on_Mujer_clicked();
    void on_Hombre1_clicked();
    void on_Mujer1_clicked();
    void on_Configurar_clicked();
    //*********************************

private:
    Ui::Nivel3 *ui;
    QGraphicsScene *scene = new QGraphicsScene(this);
    QGraphicsScene *scene_2 = new QGraphicsScene(this);

    QTimer *timer;
    QTimer *timere;
    QTimer *Lose;
    QTimer *Colisiones;

    QMessageBox msgBox;

    float dt;
    int semilla;
    int h_limit;
    int v_limit;

    Informacion datos_juego;

    void Puntos(int i);
    void Eliminar_vida();
    void Colision_paredes_e();
    void keyPressEvent(QKeyEvent *event);

    //****** Elementos de la partida *****
    int disenio_jugador1=0;
    int disenio_jugador2=3;
    int fondo3=0;
    Muro *Boton;
    Anuncio *vidas1;
    Anuncio *vidas2;
    Anuncio *puntaje1;
    Anuncio *puntaje2;
    QList <Muro*> Muros;
    QList <Monedas *> Bonus;
    QList<Personaje3graf*>bars;
    QList <Enemigo_graf *> Enemigo;
    //************************************
};

#endif // NIVEL3_H
