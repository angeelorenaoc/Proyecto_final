#ifndef NIVEL_1_H
#define NIVEL_1_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QKeyEvent>
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <math.h>
#include <QList>
#include <QFile>
#include <QString>

#include "muro.h"
#include "anuncio.h"
#include "personaje.h"
#include "informacion.h"
#include "bala_normal.h"
#include "escudo_graf.h"
#include "escudos_fisica.h"
#include "enemigo_normal.h"
#include "mainwindow.h"
#include "nivel2.h"

// Clase encargada de administrar lo relacionado con el nivel 1

namespace Ui {
class Nivel_1;
}

class Nivel_1 : public QMainWindow
{
    Q_OBJECT

    Informacion datos_partida_1;

public:
    explicit Nivel_1(QWidget *parent = nullptr);
    ~Nivel_1();

    Informacion getDatos_partida_1() const;
    void setDatos_partida_1(const Informacion &value);

public slots:
    void spawn();
    void inmunidad();
    void perseguir();
    void bullet_impact();
    void delete_escudos();
    void actualizar_escudos();
    void estado_de_habilidad();
    void Verificacion_Ganar();

private slots:
    //***********Botones**************
    void on_Inicio_clicked();
    void on_Instrucciones_clicked();
    void on_Volver_clicked();
    void on_Siguiente_nivel_clicked();
    void on_Reiniciar_clicked();
    void on_Salir_clicked();
    //********************************

private:
    Ui::Nivel_1 *ui;
    QGraphicsScene *scene_1 = new QGraphicsScene;
    QGraphicsScene *scene_2 = new QGraphicsScene;

    QTimer *shield;
    QTimer *timer_move;
    QTimer *enemy_timer;
    QTimer *bullet_timer;
    QTimer *Cooldown_timer;
    QTimer *tiempo_de_habilidad;
    QTimer *tiempo_inmunidad;
    QTimer *Ganar;

    float dt;
    int h_limit;
    int v_limit;    
    int N_enemigos=0;
    int Lim_enemigos;
    int N_jugadores=0;
    int sentido_bala=4;
    bool inmune = false;
    bool Cooldown = true;
    int sentido_bala_two=4;

    void spawn_shield(Personaje *P);
    bool player_collides(Personaje *P);
    bool enemy_collides(Enemigo_normal *E);
    void keyPressEvent(QKeyEvent * evento);
    void move_enemy(Personaje *c, Enemigo_normal *e,int i,int j);

    //Objetos necesarios para el nivel
    Anuncio *vida_J1;
    Anuncio *vida_J2;
    Anuncio *puntaje_J1;
    Anuncio *puntaje_J2;
    QList<Muro *> muros;
    QList<escudo_graf *> escudos;
    QList<Personaje *> jugadores;
    QList<Bala_normal *> disparos;
    QList<Enemigo_normal *> enemigos;


};

#endif // NIVEL_1_H
