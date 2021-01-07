#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    h_limit = 800;
    v_limit = 600;

    scene->setSceneRect(0,0,h_limit,v_limit);
    ui->graphicsView->setScene(scene);
    ui->centralwidget->adjustSize();
    scene->addRect(scene->sceneRect());
    ui->graphicsView->resize(scene->width(),scene->height());
    this->resize(ui->graphicsView->width()+100,ui->graphicsView->height());
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

//    timer = new QTimer;
//    connect(timer,SIGNAL(timeout()),this,SLOT(balas.back()->move()));
//    timer->start(50);

    crear_enemigos = new QTimer;
    connect(crear_enemigos,SIGNAL(timeout()),this,SLOT(spawn()));
    crear_enemigos->start(2000);

    mover_enemigos = new QTimer;
    connect(mover_enemigos,SIGNAL(timeout()),this,SLOT(move_enemy()));
    mover_enemigos->start(50);

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
//        balas.push_back(new Bala_graph(jugadores.back()->getPX(),jugadores.back()->getPY(),jugadores.back()->getVel_inicial(),jugadores.back()->getAngulo()));
//        scene->addItem(balas.back());
    }
}

//void MainWindow::move()
//{
//    for(int i=0;i<balas.size();i++){
//        balas.at(i)->move();
//    }
//}

void MainWindow::spawn()
{
    enemigos.push_back(new Enemigo_normal);
    scene->addItem(enemigos.back());
    N_enemigos++;

    if(N_enemigos>=5){
        crear_enemigos->stop();
    }
}

void MainWindow::move_enemy()
{
    for(int i=0;i<enemigos.size();i++){
        enemigos.at(i)->move();
        if(enemigos.at(i)->getPX()<=0){
            scene->removeItem(enemigos.at(i));
            enemigos.removeAt(i);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
