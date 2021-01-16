#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QList>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <QDebug>

#include "cuerpo.h"
#include "cuerpograf.h"
#include "vida.h"
#include "pisos.h"
#include "enemigos.h"
#include "enemigosgraf.h"
#include "boton_final.h"
#include "monedas.h"

using namespace std;

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
    void actualizar();
    void Movimiento_Enemigo();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *timere;
    QGraphicsScene *scene = new QGraphicsScene(this);
    float dt;
    int h_limit;
    int v_limit;
    int semilla;
    void borderCollision();
    void keyPressEvent(QKeyEvent *event);
    void Eliminar_vida();
    void Puntos(int i);
    void Colision_paredes_e();
    QList<Cuerpograf*>bars;
    Vida *vidas1;
    Vida *vidas2;
    Vida *puntaje1;
    Vida *puntaje2;
    QList<Pisos*> Muros;
    QList <Enemigosgraf *> Enemigo;
    QList <monedas *> Bonus;
    Boton_final *Boton;
};
#endif // MAINWINDOW_H
