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
#include "anuncios.h"
#include "puntaje.h"
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
    void perseguir();
    void bullet_impact();
    void delete_escudos();
    void actualizar_escudos();
    void estado_de_habilidad();
    void inmunidad();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene = new QGraphicsScene;
    QTimer *shield;
    QTimer *timer_move;
    QTimer *enemy_timer;
    QTimer *bullet_timer;
    QTimer *Cooldown_timer;
    QTimer *tiempo_de_habilidad;
    QTimer *tiempo_inmunidad;

    float dt;
    int h_limit;
    int v_limit;
    int N_enemigos=0;
    int N_jugadores=0;
    int sentido_bala=2;
    bool Cooldown = true;
    bool inmune = false;
    int sentido_bala_two=1;

    bool enemy_collides(enemy *E);
    void spawn_shield(personaje *P);
    bool player_collides(personaje *P);
    void keyPressEvent(QKeyEvent * evento);
    void move_enemy(personaje *c, enemy *e,int i,int j);

    anuncios *anuncio_J1;
    anuncios *anuncio_J2;
    puntaje *puntaje_J1;
    puntaje *puntaje_J2;
    QList<paredes *> muros;
    QList<enemy *> enemigos;
    QList<personaje *> jugadores;
    QList<Bala_comun *> disparos;
    QList<escudo_graph *> escudos;
};
#endif // MAINWINDOW_H
