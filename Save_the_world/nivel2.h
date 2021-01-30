#ifndef NIVEL2_H
#define NIVEL2_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QMainWindow>
#include <QKeyEvent>
#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QList>
#include <QFile>
#include <QString>

#include "anuncio.h"
#include "personaje.h"
#include "informacion.h"
#include "enemigo_graf.h"
#include "enemigo_fisica.h"
#include "enemigo_normal.h"
#include "bala_parabolica.h"
#include "bala_parabolica_graf.h"
#include "mainwindow.h"
#include "nivel3.h"
#include "vida_ii.h"

// Clase encargada de administrar lo relacionado con el nivel 2

namespace Ui {
class Nivel2;
}

class Nivel2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Nivel2(QWidget *parent = nullptr);
    ~Nivel2();

    Informacion getDatos_partida() const;
    void setDatos_partida(const Informacion &value);

public slots:

    //***** Generar enemigos ******
    void spawn();
    void spawn_jump();
    //*****************************

    //**** Mover elementos ********
    void move();
    void move_enemy();
    void move_enemy_jump();
    //*****************************

    void victory(); //Verifica cuando los jugadores ganan

private slots:

    //************ Botones **************
    void on_Iniciar_clicked();
    void on_Instrucciones_clicked();
    void on_Volver_clicked();
    void on_Salir_clicked();
    void on_Siguiente_clicked();
    void on_Reiniciar_clicked();
    void on_Fondo1_clicked();
    void on_Fondo2_clicked();
    void on_Azul_clicked();
    void on_Rojo_clicked();
    void on_Verde_clicked();
    void on_Azul1_clicked();
    void on_Rojo1_clicked();
    void on_Verde1_clicked();
    void on_Configurar_clicked();
    //**********************************

private:
    Ui::Nivel2 *ui;
    QGraphicsScene *scene = new QGraphicsScene(this);
    QGraphicsScene *scene_2 = new QGraphicsScene;

    // Dimensiones de la pantalla
    int h_limit;
    int v_limit;

    // Determinan el numero de enemigos a crear
    int N_enemigos=0;
    int Total_enemigos;

    Informacion datos_partida; //Informacion del jugador

    QTimer *timer;
    QTimer *crear_enemigos;
    QTimer *mover_enemigos;
    QTimer *crear_enemigos_s;
    QTimer *mover_enemigos_s;
    QTimer *win;

    QMessageBox msgBox;

    void keyPressEvent(QKeyEvent * event);

    //***Colisiones de los elementos en pantalla***
    void borderCollision(int i);
    void borderCollisionbala(int i);
    bool Colisiones_Enemigos(int i);
    //*********************************************

    //*** Listas de elementos en pantalla ***
    QList<Personaje *> jugadores;
    QList<Bala_parabolica_graf *> balas;
    QList<Enemigo_normal *> enemigos;
    QList<Enemigo_graf *> enemigos_s;
    //***************************************

    //**** Anuncuios *****
    int disenio_jugador1=0;
    int disenio_jugador2=1;
    int fondo2=0;
    int Color=0;
    int Color_2=1;

    Vida_II *vida;
    Anuncio *puntaje1;
    Anuncio *puntaje2;
    Anuncio *velocidad_1;
    Anuncio *velocidad_2;
    //********************
};

#endif // NIVEL2_H
