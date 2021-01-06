#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    h_limit = 962;
    v_limit = 642;

    scene->setSceneRect(0,0,h_limit,v_limit);
    ui->graphicsView->setScene(scene);
    ui->centralwidget->adjustSize();
    scene->addRect(scene->sceneRect());
    ui->graphicsView->resize(scene->width(),scene->height());
    this->resize(ui->graphicsView->width()+100,ui->graphicsView->height());
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    jugadores.push_back(new Personaje(20,200));scene->addItem(jugadores.back());
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W){
        jugadores.back()->up();
    }
    if(event->key() == Qt::Key_S){
        jugadores.back()->down();
    }
    if(event->key() == Qt::Key_A){
        jugadores.back()->left();
    }
    if(event->key() == Qt::Key_D){
        jugadores.back()->right();
    }
    if(event->key() == Qt::Key_Space){
        balas.push_back(new Bala(jugadores.back()->getPX(),jugadores.back()->getPY(),jugadores.back()->getVel_inicial(),jugadores.back()->getAngulo()));
        scene->addItem(balas.back());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

