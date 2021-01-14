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
    this->resize(ui->graphicsView->width(),ui->graphicsView->height());
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    crear_enemigos = new QTimer;
    connect(crear_enemigos,SIGNAL(timeout()),this,SLOT(spawn()));

    mover_enemigos = new QTimer;
    connect(mover_enemigos,SIGNAL(timeout()),this,SLOT(move_enemy()));

    crear_enemigos_s = new QTimer;
    connect(crear_enemigos_s,SIGNAL(timeout()),this,SLOT(spawn_jump()));

    mover_enemigos_s = new QTimer;
    connect(mover_enemigos_s,SIGNAL(timeout()),this,SLOT(move_enemy_jump()));


}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (jugadores.size() == 1){
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
            balas.push_back(new Bala_graph(jugadores.back()->getPX(),v_limit-jugadores.back()->getPY(),jugadores.back()->getAngulo(),jugadores.back()->getVel_inicial()));
            balas.back()->setId(1);
            scene->addItem(balas.back());
        }
    }
    else if (jugadores.size()==2){
        if(event->key() == Qt::Key_W){
            jugadores.at(0)->up();
        }
        if(event->key() == Qt::Key_S){
            jugadores.at(0)->down();
        }
        if(event->key() == Qt::Key_A){
            jugadores.at(0)->left();
        }
        if(event->key() == Qt::Key_D){
            jugadores.at(0)->right();
        }
        if(event->key() == Qt::Key_Space){
            balas.push_back(new Bala_graph(jugadores.at(0)->getPX(),v_limit-jugadores.at(0)->getPY(),jugadores.at(0)->getAngulo(),jugadores.at(0)->getVel_inicial()));
            balas.back()->setId(1);
            scene->addItem(balas.back());

        }
        if(event->key() == Qt::Key_I){
            jugadores.back()->up();
        }
        if(event->key() == Qt::Key_K){
            jugadores.back()->down();
        }
        if(event->key() == Qt::Key_J){
            jugadores.back()->left();
        }
        if(event->key() == Qt::Key_L){
            jugadores.back()->right();
        }
        if(event->key() == Qt::Key_P){
            balas.push_back(new Bala_graph(jugadores.at(1)->getPX(),v_limit-jugadores.at(1)->getPY(),jugadores.at(1)->getAngulo(),jugadores.at(1)->getVel_inicial()));
            balas.back()->setId(2);
            scene->addItem(balas.back());
        }
    }
}

void MainWindow::move()
{
    for(int i=0;i<balas.size();i++){
        balas.at(i)->actualizar(v_limit);
        if (Colisiones_Enemigos(i)){
            scene->removeItem(balas.at(i));
            if (balas.at(i)->getId() == 1){
            puntaje1->increase();}
            else{puntaje2->increase();}
            balas.removeAt(i);
        }
        else{borderCollisionbala(i);}
    }
}

void MainWindow::spawn()
{
    enemigos.push_back(new Enemigo_normal);
    scene->addItem(enemigos.back());
    N_enemigos++;

    if(N_enemigos>=10){
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
            vida->decrease_vida(1);
            if (vida->getVida() <= 0){
                scene->removeItem(vida);
                scene->removeItem(puntaje1);
                if (jugadores.size()== 2){
                    scene->removeItem(jugadores.at(1));
                    jugadores.removeAt(1);
                    scene->removeItem(puntaje2);
                }
                if(jugadores.size()==1){
                    scene->removeItem(jugadores.at(0));
                    jugadores.removeAt(0);
                }
            }
        }
    }
}

void MainWindow::spawn_jump()
{
    enemigos_s.push_back(new Enemigos_sGraph);
    scene->addItem(enemigos_s.back());
    n_enemigos_s++;

    if(n_enemigos_s>=3){
        crear_enemigos_s->stop();
    }
}

void MainWindow::move_enemy_jump()
{
    for(int i=0;i<enemigos_s.size();i++){
        enemigos_s.at(i)->actualizar(v_limit);
        borderCollision(i);
    }
}

void MainWindow::borderCollision(int i)
{
    Enemigos_saltarines *b = enemigos_s.at(i)->getEnemy();
    if (b->getPx()<0){
        scene->removeItem(enemigos_s.at(i));
        enemigos_s.removeAt(i);
        vida->decrease_vida(2);
        if (vida->getVida() == 0){
            scene->removeItem(vida);
            scene->removeItem(puntaje1);
            if (jugadores.size()== 2){
                scene->removeItem(jugadores.at(1));
                jugadores.removeAt(1);
                scene->removeItem(puntaje2);
            }
            scene->removeItem(jugadores.at(0));
            jugadores.removeAt(0);
        }
    }
    if (b->getPx()>h_limit-b->getR()){
        b->set_vel(-1*b->getE()*b->getVx(),b->getVy(),h_limit-b->getR(),b->getPy());
    }
    if (b->getPy()<b->getR()){
        enemigos_s.at(i)->up();
    }
    if (b->getPy()>v_limit-b->getR()){
        b->set_vel(b->getVx(),-1*b->getE()*b->getVy(),b->getPx(),v_limit-b->getR());
    }
}

void MainWindow::borderCollisionbala(int i)
{
    Bala *b = balas.at(i)->getBala();
    if (b->getPx()<0 || b->getPx()>h_limit-b->getR() || b->getPy()<b->getR() ){
        scene->removeItem(balas.at(i));
        balas.removeAt(i);

    }
}

bool MainWindow::Colisiones_Enemigos(int i)
{
    for(int j = 0; j < enemigos.size(); j++){
        if (balas.at(i)->collidesWithItem(enemigos.at(j))){
            scene->removeItem(enemigos.at(j));
            enemigos.removeAt(j);
            return true;
        }
    }
    for(int j = 0; j < enemigos_s.size(); j++){
        if (balas.at(i)->collidesWithItem(enemigos_s.at(j))){
            scene->removeItem(enemigos_s.at(j));
            enemigos_s.removeAt(j);
            return true;
        }
    }
    return false;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    jugadores.push_back(new Personaje(20,580));scene->addItem(jugadores.back());
    vida = new Vida();
    vida->setPos(730,10);
    scene->addItem(vida);
    puntaje1 = new Puntaje(0,1);
    puntaje1->setPos(10,10);
    scene->addItem(puntaje1);
    timer->start(20);
    crear_enemigos->start(2000);
    mover_enemigos->start(50);
    crear_enemigos_s->start(5000);
    mover_enemigos_s->start(50);
}

void MainWindow::on_pushButton_2_clicked()
{
    jugadores.push_back(new Personaje(20,580));scene->addItem(jugadores.back());
    vida = new Vida();
    vida->setPos(730,10);
    scene->addItem(vida);
    puntaje1 = new Puntaje(0,1);
    puntaje1->setPos(10,10);
    scene->addItem(puntaje1);
    jugadores.push_back(new Personaje(20,540));scene->addItem(jugadores.back());
    puntaje2 = new Puntaje(0,2);
    puntaje2->setPos(10,40);
    scene->addItem(puntaje2);
    timer->start(20);
    crear_enemigos->start(2000);
    mover_enemigos->start(50);
    crear_enemigos_s->start(5000);
    mover_enemigos_s->start(50);

}