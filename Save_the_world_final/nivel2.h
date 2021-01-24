#ifndef NIVEL2_H
#define NIVEL2_H

#include <QGraphicsScene>
#include <QGraphicsView>
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
    void move();
    void spawn();
    void move_enemy();
    void spawn_jump();
    void move_enemy_jump();

private slots:
    void on_Iniciar_clicked();

    void on_Instrucciones_clicked();

    void on_Volver_clicked();

private:
    Ui::Nivel2 *ui;
    QGraphicsScene *scene = new QGraphicsScene(this);
    QGraphicsScene *scene_2 = new QGraphicsScene;

    int h_limit;
    int v_limit;
    int N_enemigos=0;
    int Total_enemigos;

    Informacion datos_partida;

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
    QList<Bala_parabolica_graf *> balas;
    QList<Enemigo_normal *> enemigos;
    QList<Enemigo_graf *> enemigos_s;

    Anuncio *vida;
    Anuncio *puntaje1;
    Anuncio *puntaje2;
    Anuncio *velocidad_1;
    Anuncio *velocidad_2;
};

#endif // NIVEL2_H
