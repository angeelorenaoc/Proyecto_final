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

//private slots:
//    void move();

public slots:
    void spawn();
    void move_enemy();
    void spawn_jump();
//    void move_enemy_jump();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene = new QGraphicsScene(this);

    int h_limit;
    int v_limit;   
    int N_enemigos=0;
    int n_enemigos_s = 0;

//    QTimer *timer;
    QTimer *crear_enemigos;
    QTimer *mover_enemigos;

    QTimer *crear_enemigos_s;
    QTimer *mover_enemigos_s;

    void keyPressEvent(QKeyEvent * event);

    QList<Personaje *> jugadores;
    QList<Bala_graph *> balas;
    QList<Enemigo_normal *> enemigos;
    QList<Enemigos_sGraph *> enemigos_s;

};
#endif // MAINWINDOW_H
