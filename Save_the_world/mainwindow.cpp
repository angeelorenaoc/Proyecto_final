#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Escena
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
    scene->setBackgroundBrush(QBrush(QImage(":/Imagenes/Laboratorio_Oak.jpg")));

    enemy_timer = new QTimer(this);
    connect(enemy_timer,SIGNAL(timeout()),this,SLOT(spawn()));
    enemy_timer->stop();

    timer_move = new QTimer(this);
    connect(timer_move,SIGNAL(timeout()),this,SLOT(move_enemy()));
    timer_move->stop();

    bullet_timer = new QTimer(this);
    connect(bullet_timer,SIGNAL(timeout()),this,SLOT(bullet_impact()));
    bullet_timer->stop();

    //MUROS
    muros.push_back(new paredes(67,31,0,67));scene->addItem(muros.back());
    muros.push_back(new paredes(96,96,67,289));scene->addItem(muros.back());
    muros.push_back(new paredes(962,81,0,0));scene->addItem(muros.back());
    muros.push_back(new paredes(190,194,388,0));scene->addItem(muros.back());
    muros.push_back(new paredes(320,51,642,142));scene->addItem(muros.back());
    muros.push_back(new paredes(96,96,802,288));scene->addItem(muros.back());
    muros.push_back(new paredes(32,110,930,309));scene->addItem(muros.back());
    muros.push_back(new paredes(64,33,674,387));scene->addItem(muros.back());
    muros.push_back(new paredes(288,64,674,417));scene->addItem(muros.back());
    muros.push_back(new paredes(256,59,706,470));scene->addItem(muros.back());
    muros.push_back(new paredes(112,97,850,545));scene->addItem(muros.back());
    muros.push_back(new paredes(96,64,194,128));scene->addItem(muros.back());
    muros.push_back(new paredes(34,84,0,341));scene->addItem(muros.back());
    muros.push_back(new paredes(258,64,0,417));scene->addItem(muros.back());
    muros.push_back(new paredes(194,79,0,434));scene->addItem(muros.back());
    muros.push_back(new paredes(112,97,0,544));scene->addItem(muros.back());
    muros.push_back(new paredes(0,642,0,0));scene->addItem(muros.back());
    muros.push_back(new paredes(0,642,962,0));scene->addItem(muros.back());
    muros.push_back(new paredes(962,0,0,642));scene->addItem(muros.back());

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{    
    if(jugadores.size()==1){
        personaje *player = jugadores.at(0);

        if(event->key()== Qt::Key_A){
                player->left();
            if(player_collides(player))
                player->right();

            ui->graphicsView->centerOn(player->x(),player->y());
            sentido_bala=1;
        }
        if(event->key() == Qt::Key_D){
                player->right();
            if(player_collides(player))
                player->left();

            ui->graphicsView->centerOn(player->x(),player->y());
            sentido_bala=2;
        }
        if(event->key() == Qt::Key_W){
                player->up();
            if(player_collides(player))
                player->down();

            ui->graphicsView->centerOn(player->x(),player->y());
            sentido_bala=3;
        }
        if(event->key() == Qt::Key_S){
                player->down();
            if(player_collides(player))
                player->up();

            ui->graphicsView->centerOn(player->x(),player->y());
            sentido_bala=4;
        }
        if(event->key() == Qt::Key_Space){
            disparos.push_back(new Bala_comun(sentido_bala));
            disparos.back()->setPos(player->getPosx(),player->getPosy());
            scene->addItem(disparos.back());
        }
    }

    else if(jugadores.size()==2){

        personaje *player = jugadores.at(0);
        if(event->key()== Qt::Key_A){
                player->left();
            if(player_collides(player))
                player->right();

            ui->graphicsView->centerOn(player->x(),player->y());
            sentido_bala=1;
        }
        if(event->key() == Qt::Key_D){
                player->right();
            if(player_collides(player))
                player->left();

            ui->graphicsView->centerOn(player->x(),player->y());
            sentido_bala=2;
        }
        if(event->key() == Qt::Key_W){
                player->up();
            if(player_collides(player))
                player->down();

            ui->graphicsView->centerOn(player->x(),player->y());
            sentido_bala=3;
        }
        if(event->key() == Qt::Key_S){
                player->down();
            if(player_collides(player))
                player->up();

            ui->graphicsView->centerOn(player->x(),player->y());
            sentido_bala=4;
        }
        if(event->key() == Qt::Key_Space){
            disparos.push_back(new Bala_comun(sentido_bala));
            disparos.back()->setPos(player->getPosx(),player->getPosy());
            scene->addItem(disparos.back());
        }
        personaje *player_two = jugadores.at(1);

        if(event->key()== Qt::Key_J){
                player_two->left();
            if(player_collides(player_two))
                player_two->right();

            sentido_bala_two=1;
        }
        if(event->key() == Qt::Key_L){
                player_two->right();
            if(player_collides(player_two))
                player_two->left();

            sentido_bala_two=2;
        }
        if(event->key() == Qt::Key_I){
                player_two->up();
            if(player_collides(player_two))
                player_two->down();

            sentido_bala_two=3;
        }
        if(event->key() == Qt::Key_K){
                player_two->down();
            if(player_collides(player_two))
                player_two->up();

            sentido_bala_two=4;
        }
        if(event->key() == Qt::Key_P){
            disparos.push_back(new Bala_comun(sentido_bala_two));
            disparos.back()->setPos(player_two->getPosx(),player_two->getPosy());
            scene->addItem(disparos.back());
        }
    }
}

bool MainWindow::player_collides(personaje *P)
{
    for(int i=0;i<muros.size();i++){
        if(P->collidesWithItem(muros.at(i))){
            return true;
        }
    }
    return false;
}

bool MainWindow::enemy_collides(enemy *E)
{
    for(int i=0;i<muros.size();i++){
        if(E->collidesWithItem(muros.at(i))){
            return true;
        }
    }
    return false;
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

void MainWindow::bullet_impact()
{
    for (int i=0;i<enemigos.size();i++) {
        for (int j=0;j<disparos.size();j++) {
            if(enemigos.at(i)->collidesWithItem(disparos.at(j))){
                scene->removeItem(enemigos.at(i));
                scene->removeItem(disparos.at(j));
                enemigos.removeAt(i);
                disparos.removeAt(j);
            }
        }
    }
    for (int i=0;i<muros.size();i++) {
        for (int j=0;j<disparos.size();j++) {
            if(disparos.at(j)->collidesWithItem(muros.at(i))){
                scene->removeItem(disparos.at(j));
                disparos.removeAt(j);
            }
        }
    }
}

void MainWindow::move_enemy()
{
    for(int i=0;i<jugadores.size();i++){
        for(int j=0;j<enemigos.size();j++){
            //dist = pow((pow((_px2-Px),2)+pow((_py2-Py),2)) ,1/2);

            personaje *c = jugadores.at(i);
            enemy *e = enemigos.at(j);

            if(e->getPosx() > c->getPosx()){
                e->left();
                if(enemy_collides(e))
                    e->right();
            }
            else if(e->getPosx() < c->getPosx()){
                e->right();
                if(enemy_collides(e))
                    e->left();
            }
            if(e->getPosy() > c->getPosy()){
                e->up();
                if(enemy_collides(e))
                    e->down();
            }
            else if(e->getPosy() < c->getPosy()){
                e->down();
                if(enemy_collides(e))
                    e->up();
            }
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked() && N_jugadores<1){
        jugadores.push_back(new personaje);
        jugadores.back()->setPosx(490);jugadores.back()->setPosy(400);
        jugadores.back()->setPos(490,400);
        scene->addItem(jugadores.back());
        N_jugadores++;
    }

    else if(ui->radioButton_2->isChecked() && N_jugadores<2){
        jugadores.push_back(new personaje);
        jugadores.back()->setPosx(470);jugadores.back()->setPosy(400);
        jugadores.back()->setPos(470,400);
        scene->addItem(jugadores.back());
        N_jugadores++;

        if(N_jugadores<2){
            jugadores.push_back(new personaje);
            jugadores.back()->setPosx(510);jugadores.back()->setPosy(400);
            jugadores.back()->setPos(510,400);
            scene->addItem(jugadores.back());
            N_jugadores++;
        }
    }

    enemy_timer->start(2000);
    timer_move->start(50);
    bullet_timer->start(50);
    ui->graphicsView->centerOn(jugadores.at(0)->x(),jugadores.at(0)->y());
}
