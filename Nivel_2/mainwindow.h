#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include "bala.h"
#include "bala_graph.h"
#include "personaje.h"
#include "vida.h"
#include "enemigo_normal.h"
#include "enemigos_saltarines.h"
#include "enemigos_sgraph.h"
#include "puntaje.h"
#include <QKeyEvent>
#include <QList>
#include <QDebug>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void spawn();
    void move_enemy();
    void spawn_jump();
    void move_enemy_jump();
    void move();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene = new QGraphicsScene(this);

    int h_limit;
    int v_limit;
    int N_enemigos=0;
//    int n_enemigos_s = 0;
    int Total_enemigos;

    QTimer *timer;
    QTimer *crear_enemigos;
    QTimer *mover_enemigos;

    QTimer *crear_enemigos_s;
    QTimer *mover_enemigos_s;

    void keyPressEvent(QKeyEvent * event);
    void borderCollision(int i);
    void borderCollisionbala(int i);
    bool Colisiones_Enemigos(int i);

    QList<Personaje *> jugadores;
    QList<Bala_graph *> balas;
    QList<Enemigo_normal *> enemigos;
    QList<Enemigos_sGraph *> enemigos_s;
    Vida *vida;
    Puntaje *puntaje1;
    Puntaje *puntaje2;
    Puntaje *velocidad_1;
    Puntaje *velocidad_2;

};
#endif // MAINWINDOW_H
