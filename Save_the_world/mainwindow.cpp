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
    connect(timer_move,SIGNAL(timeout()),this,SLOT(perseguir()));
    timer_move->stop();

    bullet_timer = new QTimer(this);
    connect(bullet_timer,SIGNAL(timeout()),this,SLOT(bullet_impact()));
    bullet_timer->stop();

    shield = new QTimer(this);
    connect(bullet_timer,SIGNAL(timeout()),this,SLOT(actualizar_escudos()));
    shield->stop();
    dt=300;

    tiempo_de_habilidad = new QTimer(this);
    connect(tiempo_de_habilidad,SIGNAL(timeout()),this,SLOT(delete_escudos()));
    tiempo_de_habilidad->stop();

    Cooldown_timer = new QTimer(this);
    connect(Cooldown_timer,SIGNAL(timeout()),this,SLOT(estado_de_habilidad()));
    Cooldown_timer->stop();

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
        if(event->key() == Qt::Key_E){
            if(Cooldown)
                spawn_shield(player);
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

void MainWindow::move_enemy(personaje *c, enemy *e)
{
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

void MainWindow::spawn_shield(personaje *P)
{
    Cooldown = false;
    Cooldown_timer->stop();

    escudos.push_back(new escudo_graph(P->getPosx(),P->getPosy(),0,0));
    escudos.back()->getEsf()->setMasa(1000);

    escudos.push_back(new escudo_graph(P->getPosx()+40,P->getPosy(),0,-0.009));
    scene->addItem(escudos.back());

    escudos.push_back(new escudo_graph(P->getPosx()-40,P->getPosy(),0,0.009));
    scene->addItem(escudos.back());

    escudos.push_back(new escudo_graph(P->getPosx(),P->getPosy()+40,0.009,0));
    scene->addItem(escudos.back());

    escudos.push_back(new escudo_graph(P->getPosx(),P->getPosy()-40,-0.009,0));
    scene->addItem(escudos.back());

    tiempo_de_habilidad->start(5000);
}

void MainWindow::perseguir()
{
    float dist = 999;
    int player=0;
    for(int i=0;i<enemigos.size();i++){
        for(int j=0;j<jugadores.size();j++){            
            enemy *e = enemigos.at(i);
            personaje *p = jugadores.at(j);
            float new_dist = pow((pow(e->getPosx()-p->getPosx(),2)+pow(e->getPosy()-p->getPosy(),2)),0.5);
            qDebug()<<dist<<" "<<new_dist<<" "<<i<<" "<<j;
            if(dist>new_dist){
                dist=new_dist;
                player=j;
            }
        }
        dist=999;
        move_enemy(jugadores.at(player),enemigos.at(i));
    }
}

void MainWindow::delete_escudos()
{
    for (int i=0;i<escudos.size();i++) {
        scene->removeItem(escudos.at(i));
        tiempo_de_habilidad->stop();
    }
    escudos.clear();
    Cooldown_timer->start(5000);
}

void MainWindow::estado_de_habilidad()
{
    if(!Cooldown)
        Cooldown=true;
}

MainWindow::~MainWindow()
{
    delete enemy_timer;
    delete timer_move;
    delete bullet_timer;
    delete shield;
    delete Cooldown_timer;
    delete tiempo_de_habilidad;
    delete enemy_timer;
    delete scene;
    delete ui;
}

void MainWindow::spawn()
{
    enemigos.push_back(new enemy);
    scene->addItem(enemigos.back());
    N_enemigos++;

    if(N_enemigos>=20){
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

void MainWindow::actualizar_escudos()
{
    for(int i=0; i<escudos.size();i++){
        for(int j=0; j<escudos.size();j++){
            if(i!=j){
                escudos.at(i)->getEsf()->acelerar(escudos.at(j)->getEsf()->getPX(),escudos.at(j)->getEsf()->getPY(),escudos.at(j)->getEsf()->getMasa());
                escudos.at(i)->actualizar(dt);
            }
        }
    }
    for (int i=0;i<enemigos.size();i++) {
        for (int j=0;j<escudos.size();j++) {
            if(enemigos.at(i)->collidesWithItem(escudos.at(j))){
                scene->removeItem(enemigos.at(i));
                scene->removeItem(escudos.at(j));
                enemigos.removeAt(i);
                escudos.removeAt(j);
            }
        }
    }
    for (int i=0;i<muros.size();i++) {
        for (int j=0;j<escudos.size();j++) {
            if(escudos.at(j)->collidesWithItem(muros.at(i))){
                scene->removeItem(escudos.at(j));
                escudos.removeAt(j);
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

    enemy_timer->start(1000);
    timer_move->start(20);
    bullet_timer->start(50);
    shield->start(50);
    ui->graphicsView->centerOn(jugadores.at(0)->x(),jugadores.at(0)->y());
}
