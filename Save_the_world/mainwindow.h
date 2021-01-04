#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include "personaje.h"
#include "enemy.h"
#include "bala_comun.h"
#include "paredes.h"
#include "escudo.h"
#include "escudo_graph.h"
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
    void actualizar_escudos();
    void delete_escudos();
    void estado_de_habilidad();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene = new QGraphicsScene;
    QTimer *enemy_timer;
    QTimer *timer_move;
    QTimer *bullet_timer;
    QTimer *shield;
    QTimer *Cooldown_timer;
    QTimer *tiempo_de_habilidad;

    bool Cooldown = true;
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
    void spawn_shield(personaje *P);

    QList<personaje *> jugadores;
    QList<enemy *> enemigos;
    QList<paredes *> muros;
    QList<Bala_comun *> disparos;
    QList<escudo_graph *> escudos;
};
#endif // MAINWINDOW_H
