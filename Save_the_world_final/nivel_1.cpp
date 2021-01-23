#include "nivel_1.h"
#include "ui_nivel_1.h"

Nivel_1::Nivel_1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Nivel_1)
{
    ui->setupUi(this);

    //Escena
    h_limit = 962;
    v_limit = 642;

    scene_1->setSceneRect(0,0,h_limit,v_limit);
    ui->graphicsView->setScene(scene_1);
    ui->centralwidget->adjustSize();
    scene_1->addRect(scene_1->sceneRect());
    ui->graphicsView->resize(800,600);
    this->resize(ui->graphicsView->width(),ui->graphicsView->height());
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setStyleSheet("Nivel_1 {background-image:url(:/new/Imagenes/Fondo.jpg)}");

    scene_2->setSceneRect(0,0,700,700);
    ui->graphicsView_2->setScene(scene_2);
    ui->centralwidget->adjustSize();
    scene_2->addRect(scene_2->sceneRect());
    ui->graphicsView_2->resize(700,700);
    ui->graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->graphicsView->hide();
    ui->graphicsView_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_6->hide();

    enemy_timer = new QTimer(this);
    connect(enemy_timer,SIGNAL(timeout()),this,SLOT(spawn()));

    timer_move = new QTimer(this);
    connect(timer_move,SIGNAL(timeout()),this,SLOT(perseguir()));

    bullet_timer = new QTimer(this);
    connect(bullet_timer,SIGNAL(timeout()),this,SLOT(bullet_impact()));

    shield = new QTimer(this);
    connect(bullet_timer,SIGNAL(timeout()),this,SLOT(actualizar_escudos()));
    dt=300;

    tiempo_de_habilidad = new QTimer(this);
    connect(tiempo_de_habilidad,SIGNAL(timeout()),this,SLOT(delete_escudos()));

    Cooldown_timer = new QTimer(this);
    connect(Cooldown_timer,SIGNAL(timeout()),this,SLOT(estado_de_habilidad()));

    tiempo_inmunidad = new QTimer();
    connect(tiempo_inmunidad,SIGNAL(timeout()),this,SLOT(inmunidad()));

}

Nivel_1::~Nivel_1()
{
    delete shield;
    delete timer_move;
    delete enemy_timer;
    delete bullet_timer;
    delete Cooldown_timer;
    delete tiempo_de_habilidad;
    delete tiempo_inmunidad;
    delete ui;
}

void Nivel_1::keyPressEvent(QKeyEvent *event)
{
    if(N_jugadores==1){
        if(jugadores.size()>0){
            Personaje *player = jugadores.at(0);

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
                disparos.push_back(new Bala_normal(sentido_bala));
                disparos.back()->setId(1);
                disparos.back()->setPos(player->getPosx(),player->getPosy());
                scene_1->addItem(disparos.back());
            }
            if(event->key() == Qt::Key_E){
                if(Cooldown)
                    spawn_shield(player);
            }
            vida_J1->setPx(player->getPosx()-20); vida_J1->setPy(player->getPosy()+20);
            vida_J1->setPos(vida_J1->getPx(),vida_J1->getPy());
//            qDebug()<<vida_J1->x()<<vida_J1->y();
        }
    }

    else if(N_jugadores==2){
        if(jugadores.size()>0){

            Personaje *player;
            if(vida_J1->getAnuncio()>0){
                player = jugadores.at(0);

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
                    disparos.push_back(new Bala_normal(sentido_bala));
                    disparos.back()->setPos(player->getPosx(),player->getPosy());
                    disparos.back()->setId(1);
                    scene_1->addItem(disparos.back());
                }
                if(event->key() == Qt::Key_E){
                    if(Cooldown)
                        spawn_shield(player);
                }
                vida_J1->setPx(player->getPosx()-20); vida_J1->setPy(player->getPosy()+20);
                vida_J1->setPos(vida_J1->getPx(),vida_J1->getPy());
            }

            Personaje *player_two;
            if(vida_J1->getAnuncio()>0){
                if(vida_J2->getAnuncio()>0)
                    player_two = jugadores.at(1);
            }
            else{
                player_two = jugadores.at(0);
                ui->graphicsView->centerOn(player_two->x(),player_two->y());
            }
            if(vida_J2->getAnuncio()>0){
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
                    disparos.push_back(new Bala_normal(sentido_bala_two));
                    disparos.back()->setId(2);
                    disparos.back()->setPos(player_two->getPosx(),player_two->getPosy());
                    scene_1->addItem(disparos.back());
                }
                if(event->key() == Qt::Key_O){
                    if(Cooldown)
                        spawn_shield(player_two);
                }

                vida_J2->setPx(player_two->getPosx()-20); vida_J2->setPy(player_two->getPosy()+20);
                vida_J2->setPos(vida_J2->getPx(),vida_J2->getPy());

            }
        }
    }
}

bool Nivel_1::player_collides(Personaje *P)
{
    for(int i=0;i<muros.size();i++){
        if(P->collidesWithItem(muros.at(i))){
            return true;
        }
    }
    return false;
}

void Nivel_1::bullet_impact()
{
    for (int j=0;j<disparos.size();j++) {
        for (int i=0;i<enemigos.size();i++) {
            if(enemigos.at(i)->collidesWithItem(disparos.at(j))){
                scene_1->removeItem(enemigos.at(i));
                scene_1->removeItem(disparos.at(j));
                int id = disparos.at(j)->getId();
                if(id==1){
                    puntaje_J1->increse_score(5);
                }
                else{
                    puntaje_J2->increse_score(5);
                }
                enemigos.removeAt(i);
                disparos.removeAt(j);
                break;
            }
        }
    }
    for (int i=0;i<muros.size();i++) {
        for (int j=0;j<disparos.size();j++) {
            if(disparos.at(j)->collidesWithItem(muros.at(i))){
                scene_1->removeItem(disparos.at(j));
                disparos.removeAt(j);
            }
        }
    }
}

void Nivel_1::spawn()
{
    enemigos.push_back(new Enemigo_normal(1));
    scene_1->addItem(enemigos.back());
    N_enemigos++;

    if(N_enemigos>=30){
        enemy_timer->stop();
    }
}

void Nivel_1::perseguir()
{
    float dist = 999;
    int player=0, enemigo=0;
    for(int i=0;i<enemigos.size();i++){
        for(int j=0;j<jugadores.size();j++){
            Enemigo_normal *e = enemigos.at(i);
            Personaje *p = jugadores.at(j);
            float new_dist = pow((pow(e->getPosx()-p->getPosx(),2)+pow(e->getPosy()-p->getPosy(),2)),0.5);
            if(dist>new_dist){
                dist=new_dist;
                enemigo=i;
                player=j;

            }
        }
        dist=999;
        move_enemy(jugadores.at(player),enemigos.at(i),enemigo,player);
    }
}

void Nivel_1::move_enemy(Personaje *c, Enemigo_normal *e,int i, int j)
{
    if(e->getPosx() > c->getPosx()){
        e->left();

        if(enemy_collides(e)){
            e->right();}
    }
    else if(e->getPosx() < c->getPosx()){
        e->right();
        if(enemy_collides(e)){
            e->left();}
    }
    if(e->getPosy() > c->getPosy()){
        e->up();
        if(enemy_collides(e)){
            e->down();}
    }
    else if(e->getPosy() < c->getPosy()){
        e->down();
        if(enemy_collides(e)){
            e->up();}
    }
    if(e->collidesWithItem(c)){
        if(j==0){
            if(N_jugadores==1){
                if(vida_J1->getAnuncio()<=1){
                    vida_J1->decrease_vida(1);
                    scene_1->removeItem(c);
                    jugadores.removeAt(j);
                    scene_1->removeItem(vida_J1);
                    scene_1->removeItem(e);
                    enemigos.removeAt(i);
                }
                else{
                    if(!inmune){
                        vida_J1->decrease_vida(1);
                        c->setPosx(495); c->setPosy(400);
                        c->setPos(495,400);
                        inmune = true;
                        tiempo_inmunidad->start(2000);
                        scene_1->removeItem(e);
                        enemigos.removeAt(i);
                    }
                }
            }
            else{
                if(vida_J1->getAnuncio()>0){
                    if(vida_J1->getAnuncio()<=1){
                        vida_J1->decrease_vida(1);
                        scene_1->removeItem(c);
                        jugadores.removeAt(j);
                        scene_1->removeItem(vida_J1);
                        scene_1->removeItem(e);
                        enemigos.removeAt(i);
                    }
                    else{
                        if(!inmune){
                            vida_J1->decrease_vida(1);
                            c->setPosx(495); c->setPosy(400);
                            c->setPos(495,400);
                            inmune = true;
                            tiempo_inmunidad->start(2000);
                            scene_1->removeItem(e);
                            enemigos.removeAt(i);
                        }
                    }
                }
                else if(vida_J2->getAnuncio()>0){
                    if(vida_J2->getAnuncio()<=1){
                        vida_J2->decrease_vida(1);
                        scene_1->removeItem(c);
                        jugadores.removeAt(j);
                        scene_1->removeItem(vida_J2);
                        scene_1->removeItem(e);
                        enemigos.removeAt(i);
                    }
                    else{
                        if(!inmune){
                            vida_J2->decrease_vida(1);
                            c->setPosx(495); c->setPosy(400);
                            c->setPos(495,400);
                            inmune = true;
                            tiempo_inmunidad->start(2000);
                            scene_1->removeItem(e);
                            enemigos.removeAt(i);
                        }
                    }
                }
            }
        }
        else{
            if(vida_J2->getAnuncio()<=1){
                vida_J2->decrease_vida(1);
                scene_1->removeItem(c);
                jugadores.removeAt(j);
                scene_1->removeItem(vida_J2);
                scene_1->removeItem(e);
                enemigos.removeAt(i);
            }
            else{
                if(!inmune){
                    vida_J2->decrease_vida(1);
                    c->setPosx(495); c->setPosy(400);
                    c->setPos(495,400);
                    inmune = true;
                    tiempo_inmunidad->start(2000);
                    scene_1->removeItem(e);
                    enemigos.removeAt(i);
                }
            }
        }
    }
    if(jugadores.size()<=0){
        for(int i=0;i<muros.size();i++){
            scene_1->removeItem(muros.at(i));
        }
        for(int i=0;i<escudos.size();i++){
            scene_1->removeItem(escudos.at(i));
        }
        for(int i=0;i<enemigos.size();i++){
            scene_1->removeItem(enemigos.at(i));
        }
        for(int i=0;i<disparos.size();i++){
            scene_1->removeItem(disparos.at(i));
        }
        muros.clear();
        escudos.clear();
        enemigos.clear();
        disparos.clear();

        shield->stop();
        timer_move->stop();
        enemy_timer->stop();
        bullet_timer->stop();
        Cooldown_timer->stop();
        tiempo_de_habilidad->stop();
        qDebug()<<"YOU LOSE";
        ui->graphicsView->hide();
        scene_2->clear();
        ui->graphicsView_2->show();
        ui->graphicsView_2->resize(467,700);
        this->resize(ui->graphicsView_2->width(),ui->graphicsView_2->height());
        ui->graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scene_2->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Perder_nivel1.jpg")));
        ui->pushButton_5->show();
        ui->pushButton_6->show();
    }
}

bool Nivel_1::enemy_collides(Enemigo_normal *E)
{
    for(int i=0;i<muros.size();i++){
        if(E->collidesWithItem(muros.at(i))){
            return true;
        }
    }
    return false;
}

void Nivel_1::spawn_shield(Personaje *P)
{
    Cooldown = false;
    Cooldown_timer->stop();

    escudos.push_back(new escudo_graf(P->getPosx(),P->getPosy(),0,0));
    escudos.back()->getEsf()->setMasa(1000);

    escudos.push_back(new escudo_graf(P->getPosx()+40,P->getPosy(),0,-0.009));
    scene_1->addItem(escudos.back());

    escudos.push_back(new escudo_graf(P->getPosx()-40,P->getPosy(),0,0.009));
    scene_1->addItem(escudos.back());

    escudos.push_back(new escudo_graf(P->getPosx(),P->getPosy()+40,0.009,0));
    scene_1->addItem(escudos.back());

    escudos.push_back(new escudo_graf(P->getPosx(),P->getPosy()-40,-0.009,0));
    scene_1->addItem(escudos.back());

    tiempo_de_habilidad->start(5000);
}

void Nivel_1::actualizar_escudos()
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
                scene_1->removeItem(enemigos.at(i));
                scene_1->removeItem(escudos.at(j));
                puntaje_J1->increse_score(1);
                if(jugadores.size()==2){
                    puntaje_J2->increse_score(1);
                }
                enemigos.removeAt(i);
                escudos.removeAt(j);
            }
        }
    }
    for (int i=0;i<muros.size();i++) {
        for (int j=0;j<escudos.size();j++) {
            if(escudos.at(j)->collidesWithItem(muros.at(i))){
                scene_1->removeItem(escudos.at(j));
                escudos.removeAt(j);
            }
        }
    }
}

void Nivel_1::delete_escudos()
{
    for (int i=0;i<escudos.size();i++) {
        scene_1->removeItem(escudos.at(i));
        tiempo_de_habilidad->stop();
    }
    escudos.clear();
    Cooldown_timer->start(5000);
}

void Nivel_1::estado_de_habilidad()
{
    if(!Cooldown)
        Cooldown=true;
}

void Nivel_1::inmunidad()
{
    inmune = false;
    tiempo_inmunidad->stop();
}

Informacion Nivel_1::getDatos_partida_1() const
{
    return datos_partida_1;
}

void Nivel_1::setDatos_partida_1(const Informacion &value)
{
    datos_partida_1 = value;
}

void Nivel_1::on_pushButton_clicked()
{
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_5->hide();
    ui->graphicsView->show();
    scene_1->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Laboratorio_Oak.jpg")));

    for(int i =0; i <1; i++){
    muros.push_back(new Muro(67,31,0,67,1));scene_1->addItem(muros.back());
    muros.push_back(new Muro(96,96,67,289,1));scene_1->addItem(muros.back());
    muros.push_back(new Muro(962,81,0,0,1));scene_1->addItem(muros.back());
    muros.push_back(new Muro(190,194,388,0,1));scene_1->addItem(muros.back());
    muros.push_back(new Muro(320,51,642,142,1));scene_1->addItem(muros.back());
    muros.push_back(new Muro(96,96,802,288,1));scene_1->addItem(muros.back());
    muros.push_back(new Muro(32,110,930,309,1));scene_1->addItem(muros.back());
    muros.push_back(new Muro(64,33,674,387,1));scene_1->addItem(muros.back());
    muros.push_back(new Muro(288,64,674,417,1));scene_1->addItem(muros.back());
    muros.push_back(new Muro(256,59,706,470,1));scene_1->addItem(muros.back());
    muros.push_back(new Muro(112,97,850,545,1));scene_1->addItem(muros.back());
    muros.push_back(new Muro(96,64,194,128,1));scene_1->addItem(muros.back());
    muros.push_back(new Muro(34,84,0,341,1));scene_1->addItem(muros.back());
    muros.push_back(new Muro(258,64,0,417,1));scene_1->addItem(muros.back());
    muros.push_back(new Muro(194,79,0,434,1));scene_1->addItem(muros.back());
    muros.push_back(new Muro(112,97,0,544,1));scene_1->addItem(muros.back());
    muros.push_back(new Muro(0,642,0,0,1));scene_1->addItem(muros.back());
    muros.push_back(new Muro(0,642,962,0,1));scene_1->addItem(muros.back());
    muros.push_back(new Muro(962,0,0,642,1));scene_1->addItem(muros.back());}

    if(datos_partida_1.getModo()==1){
        jugadores.push_back(new Personaje(0,0,1,490,400));
        scene_1->addItem(jugadores.back());
        N_jugadores++;
        ui->graphicsView->centerOn(jugadores.at(0)->x(),jugadores.at(0)->y());

        vida_J1 = new Anuncio(0,0,0,10,1);
        vida_J1->setPx(470); vida_J1->setPy(420);
        vida_J1->setPos(vida_J1->getPx(),vida_J1->getPy());
        scene_1->addItem(vida_J1);
        puntaje_J1 = new Anuncio(0,0,1,15,1);
        puntaje_J1->setPos(420,83);
        scene_1->addItem(puntaje_J1);


        timer_move->start(50);
        enemy_timer->start(1000);
        bullet_timer->start(50);
        shield->start(50);
    }
    else{
        jugadores.push_back(new Personaje(0,0,1,470,400));
        scene_1->addItem(jugadores.back());
        N_jugadores++;
        ui->graphicsView->centerOn(jugadores.at(0)->x(),jugadores.at(0)->y());
        vida_J1 = new Anuncio(0,0,0,10);
        vida_J1->setPx(470); vida_J1->setPy(420);
        scene_1->addItem(vida_J1);
        puntaje_J1 = new Anuncio(0,0,1,15);
        puntaje_J1->setPos(420,52);
        scene_1->addItem(puntaje_J1);

        if(N_jugadores<2){
            jugadores.push_back(new Personaje(0,1,1,510,400));
            scene_1->addItem(jugadores.back());
            N_jugadores++;
            vida_J2 = new Anuncio(0,1,0,10);
            vida_J2->setPx(490); vida_J2->setPy(420);
            scene_1->addItem(vida_J2);
            puntaje_J2 = new Anuncio(0,1,1,15);
            puntaje_J2->setPos(420,83);
            scene_1->addItem(puntaje_J2);

            timer_move->start(15);
            enemy_timer->start(800);
        }
        bullet_timer->start(50);
        shield->start(50);
    }
}

void Nivel_1::on_pushButton_2_clicked()
{
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
    ui->graphicsView_2->show();
    this->resize(ui->graphicsView_2->width(),ui->graphicsView_2->height());
    scene_2->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Instrucciones_1.jpg")));
    ui->pushButton_3->show();
}

void Nivel_1::on_pushButton_3_clicked()
{
    this->resize(ui->graphicsView->width(),ui->graphicsView->height());
    scene_2->clear();
    ui->graphicsView_2->hide();
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->hide();
}

void Nivel_1::on_pushButton_6_clicked()
{

}

void Nivel_1::on_pushButton_4_clicked()
{

}

void Nivel_1::on_pushButton_5_clicked()
{

}
