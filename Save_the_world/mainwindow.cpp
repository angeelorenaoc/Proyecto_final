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


    timer = new QTimer(this);
    enemy_timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    connect(enemy_timer,SIGNAL(timeout()),this,SLOT(move_enemy()));

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    personaje_physics *b = jugadores.at(0)->getEsf();
    if(event->key()== Qt::Key_A){
        b->set_vel(-25,b->getVY(),b->getPX(),b->getPY());
    }
    if(event->key() == Qt::Key_D){
        b->set_vel(25,b->getVY(),b->getPX(),b->getPY());
    }
    if(event->key() == Qt::Key_W){
        b->set_vel(b->getVX(),25,b->getPX(),b->getPY());
    }
    if(event->key() == Qt::Key_S){
        b->set_vel(b->getVX(),-25,b->getPX(),b->getPY());
    }
}

MainWindow::~MainWindow()
{
    delete timer;
    delete scene;
    delete ui;
}

void MainWindow::actualizar()
{
    for(int i = 0; i<jugadores.size(); i++){
        jugadores.at(i)->actualizar(v_limit);
        borderCollision(jugadores.at(i)->getEsf());
    }
}

void MainWindow::move_enemy()
{
    for (int i = 0; i < jugadores.size(); i++){
        for (int j = 0; j < enemigos.size() ; j++ ) {
            enemy_physics *e = enemigos.at(j)->getEsf();
            personaje_physics *c = jugadores.at(i)->getEsf();
            if (e->getPX() < c->getPX()){
                e->set_vel(15,e->getVY(),e->getPX(),e->getPY());
                enemigos.at(j)->actualizar(v_limit);
            }
            if (e->getPX() > c->getPX()){
                e->set_vel(-15,e->getVY(),e->getPX(),e->getPY());
                enemigos.at(j)->actualizar(v_limit);
            }
            if (e->getPY() < c->getPY()){
              e->set_vel(e->getVX(),15,e->getPX(),e->getPY());
              enemigos.at(j)->actualizar(v_limit);
            }
            if (e->getPY() > c->getPY()){
              e->set_vel(e->getVX(),-15,e->getPX(),e->getPY());
              enemigos.at(j)->actualizar(v_limit);
            }

        }
    }
}



void MainWindow::borderCollision(personaje_physics *b)
{

    if (b->getPX()<b->getR()){
        b->set_vel(-1*b->getE()*b->getVX(),b->getVY(),b->getR(),b->getPY());
    }
    if (b->getPX()>h_limit-b->getR()){
        b->set_vel(-1*b->getE()*b->getVX(),b->getVY(),h_limit-b->getR(),b->getPY());
    }
    if (b->getPY()<b->getR()){
        b->set_vel(b->getVX(),-1*b->getE()*b->getVY(),b->getPX(),b->getR());
    }
    if (b->getPY()>v_limit-b->getR()){
        b->set_vel(b->getVX(),-1*b->getE()*b->getVY(),b->getPX(),v_limit-b->getR());
    }

}

void MainWindow::on_pushButton_clicked()
{
    timer->start(20);
    enemy_timer->start(50);
    jugadores.push_back(new personaje);
    jugadores.back()->actualizar(v_limit);
    scene->addItem(jugadores.back());

    enemigos.push_back(new enemy);
    enemigos.back()->actualizar(v_limit);
    scene->addItem(enemigos.back());

}
