#ifndef NIVEL3_H
#define NIVEL3_H

#include <QGraphicsScene>
#include <QGraphicsView>
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
    void actualizar();
    void Movimiento_Enemigo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Nivel3 *ui;
    QGraphicsScene *scene = new QGraphicsScene(this);
    QGraphicsScene *scene_2 = new QGraphicsScene(this);

    QTimer *timer;
    QTimer *timere;

    float dt;
    int h_limit;
    int v_limit;
    int semilla;

    Informacion datos_juego;

    void Puntos(int i);
    void Eliminar_vida();
    void borderCollision();
    void Colision_paredes_e();
    void keyPressEvent(QKeyEvent *event);

    Muro *Boton;
    Anuncio *vidas1;
    Anuncio *vidas2;
    Anuncio *puntaje1;
    Anuncio *puntaje2;
    QList <Muro*> Muros;
    QList <Monedas *> Bonus;
    QList<Personaje3graf*>bars;
    QList <Enemigo_graf *> Enemigo;
};

#endif // NIVEL3_H
