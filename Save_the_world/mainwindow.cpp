#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,400,400);

    jugador = new personaje();
    jugador->setPosx(200); jugador->setPosy(200);
    jugador->setPos(200,200);
    scene->addItem(jugador);

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_A){
        jugador->left();
    }
    else if(event->key() == Qt::Key_D){
        jugador->right();
    }
    else if(event->key() == Qt::Key_W){
        jugador->up();
    }
    else if(event->key() == Qt::Key_S){
        jugador->down();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
