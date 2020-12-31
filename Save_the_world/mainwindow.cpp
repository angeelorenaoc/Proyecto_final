#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Escena
    h_limit = 800;
    v_limit = 600;

    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,h_limit,v_limit);
    ui->graphicsView->setScene(scene);
    ui->centralwidget->adjustSize();
    scene->addRect(scene->sceneRect());
    ui->graphicsView->resize(scene->width(),scene->height());
    this->resize(ui->graphicsView->width()+100,ui->graphicsView->height());
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    enemy_timer = new QTimer(this);
    connect(enemy_timer,SIGNAL(timeout()),this,SLOT(spawn()));
    enemy_timer->stop();

    timer_move = new QTimer(this);
    connect(timer_move,SIGNAL(timeout()),this,SLOT(move_enemy()));

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_A){
        jugadores.at(0)->left();
    }
    else if(event->key() == Qt::Key_D){
        jugadores.at(0)->right();
    }
    else if(event->key() == Qt::Key_W){
        jugadores.at(0)->up();
    }
    else if(event->key() == Qt::Key_S){
        jugadores.at(0)->down();
    }
}

MainWindow::~MainWindow()
{
    delete enemy_timer;
    delete scene;
    delete ui;
}

void MainWindow::spawn()
{
    enemigos.push_back(new enemy);
    scene->addItem(enemigos.back());
    N_enemigos++;

    if(N_enemigos==5){
        enemy_timer->stop();
    }
}

void MainWindow::move_enemy()
{
    for(int i=0;i<jugadores.size();i++){
        for(int j=0;j<enemigos.size();j++){

            personaje *c = jugadores.at(i);
            enemy *e = enemigos.at(j);

            if(e->getPosx() > c->getPosx()){
                e->setPosx(e->getPosx()-e->getVelocidad());
                e->setPos(e->getPosx(),e->getPosy());
            }
            if(e->getPosx() < c->getPosx()){
                e->setPosx(e->getPosx()+e->getVelocidad());
                e->setPos(e->getPosx(),e->getPosy());
            }
            if(e->getPosy() > c->getPosy()){
                e->setPosy(e->getPosy()-e->getVelocidad());
                e->setPos(e->getPosx(),e->getPosy());
            }
            if(e->getPosy() < c->getPosy()){
                e->setPosy(e->getPosy()+e->getVelocidad());
                e->setPos(e->getPosy(),e->getPosy());
            }
        }
    }
}



void MainWindow::on_pushButton_clicked()
{
    jugadores.push_back(new personaje);
    jugadores.back()->setPosx(100);jugadores.back()->setPosy(100);
    jugadores.back()->setPos(100,100);
    scene->addItem(jugadores.back());

    enemy_timer->start(2000);
    timer_move->start(200);

}
