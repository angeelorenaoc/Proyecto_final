#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "personaje.h"
#include "personaje_physics.h"
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>

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

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    personaje *jugador;

    float dt;
    int h_limit;
    int v_limit;
    void borderCollision(personaje_physics *b);
    void keyPressEvent(QKeyEvent * evento);
    QList<personaje *> bars;


};
#endif // MAINWINDOW_H
