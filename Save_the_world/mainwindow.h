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

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene = new QGraphicsScene;
    QTimer *enemy_timer;
    QTimer *timer_move;

    float dt;
    int h_limit;
    int v_limit;
    int N_enemigos=0;
    int sentido_bala=1;
    float dist;

    void keyPressEvent(QKeyEvent * evento);
    void Spawn_bullet(personaje *P);
    bool player_collides(personaje *P);
    bool enemy_collides(enemy *E);

    QList<personaje *> jugadores;
    QList<enemy *> enemigos;
    QList<paredes *> muros;
    Bala_comun *Disparo_frontal;
};
#endif // MAINWINDOW_H
