#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "bala.h"
#include "bala_graph.h"
#include "personaje.h"
#include "vida.h"
#include <QKeyEvent>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene = new QGraphicsScene(this);

    int h_limit;
    int v_limit;

    void keyPressEvent(QKeyEvent * event);

    QList<Personaje *> jugadores;
    QList<Bala *> balas;

};
#endif // MAINWINDOW_H
