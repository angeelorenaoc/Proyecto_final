#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "personaje.h"
#include "enemy.h"
#include "bala_comun.h"
#include "paredes.h"
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>
#include <QList>
#include <math.h>

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
    void bullet_impact();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene = new QGraphicsScene;
    QTimer *enemy_timer;
    QTimer *timer_move;
    QTimer *bullet_timer;

    float dt;
    int h_limit;
    int v_limit;
    int N_enemigos=0;
    int N_jugadores=0;
    int sentido_bala=2;
    int sentido_bala_two=1;
    float dist;    

    void keyPressEvent(QKeyEvent * evento);
    bool player_collides(personaje *P);
    bool enemy_collides(enemy *E);

    QList<personaje *> jugadores;
    QList<enemy *> enemigos;
    QList<paredes *> muros;
    QList<Bala_comun *> disparos;
};
#endif // MAINWINDOW_H
