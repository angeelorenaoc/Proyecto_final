#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>

#include "cuerpo.h"
#include "cuerpograf.h"
#include "vida.h"
#include "pisos.h"
#include "enemigos.h"
#include "enemigosgraf.h"

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

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *timere;
    QGraphicsScene *scene = new QGraphicsScene(this);
    float dt;
    int h_limit;
    int v_limit;
    void borderCollision(Cuerpo *b);
    void keyPressEvent(QKeyEvent *event);
    QList<Cuerpograf*>bars;
    Vida *vidas;
    QList<Pisos*> Muros;
    QList <Enemigosgraf *> Enemigo;
};
#endif // MAINWINDOW_H
