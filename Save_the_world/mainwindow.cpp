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
    //scene->setBackgroundBrush(QBrush(QImage(":/new/prefix1/Laboratorio_Oak.jpg")));

    enemy_timer = new QTimer(this);
    connect(enemy_timer,SIGNAL(timeout()),this,SLOT(spawn()));
    enemy_timer->stop();

    timer_move = new QTimer(this);
    connect(timer_move,SIGNAL(timeout()),this,SLOT(move_enemy()));
    timer_move->stop();

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    personaje *player = jugadores.at(0);
    personaje *player_two = jugadores.at(1);
    if(event->key()== Qt::Key_A){
        if(player->getPosx()>0+player->getR())
            player->left();
        sentido_bala=1;
    }
    if(event->key() == Qt::Key_D){
        if(player->getPosx()<800-player->getR())
            player->right();
        sentido_bala=2;
    }
    if(event->key() == Qt::Key_W){
        if(player->getPosy()>10+player->getR())
            player->up();
        sentido_bala=3;
    }
    if(event->key() == Qt::Key_S){
        if(player->getPosy()<560)
            player->down();
        sentido_bala=4;
    }
    if(event->key() == Qt::Key_Space){
        disparos.back() = new Bala_comun(sentido_bala);
        disparos.back()->setPos(player->getPosx(),player->getPosy());
        scene->addItem(disparos.back());
    }

    if(event->key()== Qt::Key_Left){
        if(player->getPosx()>0+player->getR())
            player_two->left();
        sentido_bala=1;
    }
    if(event->key() == Qt::Key_Right){
        if(player->getPosx()<800-player->getR())
            player->right();
        sentido_bala=2;
    }
    if(event->key() == Qt::Key_Up){
        if(player->getPosy()>10+player->getR())
            player->up();
        sentido_bala=3;
    }
    if(event->key() == Qt::Key_Down){
        if(player->getPosy()<560)
            player->down();
        sentido_bala=4;
    }
    if(event->key() == Qt::Key_Enter){
        disparos.back() = new Bala_comun(sentido_bala);
        disparos.back()->setPos(player->getPosx(),player->getPosy());
        scene->addItem(disparos.back());
    }
}

void MainWindow::bullet_impact()
{
    for (int i=0;i<enemigos.size();i++) {
        for (int j=0;j<disparos.size();j++) {
            if(enemigos.at(i)->collidesWithItem(disparos.at(j))){
                scene->removeItem(enemigos.at(i));
                scene->removeItem(disparos.at(j));
                delete enemigos.at(i);
                delete disparos.at(j);
            }
        }
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

    if(N_enemigos>=5){
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
                e->left();
            }
            else if(e->getPosx() < c->getPosx()){
                e->right();
            }
            if(e->getPosy() > c->getPosy()){
                e->up();
            }
            else if(e->getPosy() < c->getPosy()){
                e->down();
            }
        }
    }
    bullet_impact();
}

void MainWindow::on_pushButton_clicked()
{
    jugadores.push_back(new personaje);
    jugadores.back()->setPosx(100);jugadores.back()->setPosy(100);
    jugadores.back()->setPos(100,100);
    scene->addItem(jugadores.back());

    enemy_timer->start(2000);
    timer_move->start(50);
}
