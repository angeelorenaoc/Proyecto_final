#include "nivel3.h"
#include "ui_nivel3.h"

Nivel3::Nivel3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Nivel3)
{
    srand(time(NULL));
    ui->setupUi(this);

    h_limit = 6000;
    v_limit = 650;

    scene->setSceneRect(0,0,h_limit,v_limit);
    ui->graphicsView->setScene(scene);
    ui->centralwidget->adjustSize();
    scene->addRect(scene->sceneRect());
    ui->graphicsView->resize(1000,650);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setStyleSheet("Nivel3 {background-image:url(:/new/Imagenes/Fondo.jpg)}");

    scene_2->setSceneRect(0,0,700,700);
    ui->graphicsView_2->setScene(scene_2);
    ui->centralwidget->adjustSize();
    scene_2->addRect(scene_2->sceneRect());
    ui->graphicsView_2->resize(700,700);
    ui->graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->pushButton_3->hide();
    ui->graphicsView->hide();
    ui->graphicsView_2->hide();

    vidas1 = new Anuncio(0,0,0,15,3);
    vidas2 = new Anuncio(0,1,0,15,3);
    puntaje1 = new Anuncio(0,0,1,15,3);
    puntaje2 = new Anuncio(0,1,1,15,3);

    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this, SLOT(actualizar()));
    timere = new QTimer;
    connect(timere,SIGNAL(timeout()),this, SLOT(Movimiento_Enemigo()));
}

Nivel3::~Nivel3()
{
    delete timer;
    delete timere;
    delete scene;
    delete ui;
}

void Nivel3:: keyPressEvent(QKeyEvent *event)
{
    if(datos_juego.getModo()==1){
        if(bars.size()>0){
            Personaje3 *player = bars.at(0)->getEsf();

            if(event->key()== Qt::Key_A){
                player->set_vel(-15,player->getVy(),player->getPx(),player->getPy());
                bars.at(0)->setFilas(0);
                ui->graphicsView->centerOn(player->getPx(),player->getPy());
            }
            if(event->key() == Qt::Key_D){
                player->set_vel(15,player->getVy(),player->getPx(),player->getPy());
                bars.at(0)->setFilas(76);
                ui->graphicsView->centerOn(player->getPx(),player->getPy());

            }
            if(event->key() == Qt::Key_W){
                player->set_vel(player->getVx(),40,player->getPx(),player->getPy());
                ui->graphicsView->centerOn(player->getPx(),player->getPy());
            }
        }
    }

    else if(datos_juego.getModo()==2){
        if(bars.size()>0){

            Personaje3 *player;

            if(vidas1->getAnuncio()>0){
                player = bars.at(0)->getEsf();
                if(event->key()== Qt::Key_A){
                    player->set_vel(-15,player->getVy(),player->getPx(),player->getPy());
                    bars.at(0)->setFilas(0);
                    ui->graphicsView->centerOn(player->getPx(),player->getPy());
                }
                if(event->key() == Qt::Key_D){
                    player->set_vel(15,player->getVy(),player->getPx(),player->getPy());
                    bars.at(0)->setFilas(76);
                    ui->graphicsView->centerOn(player->getPx(),player->getPy());
                }
                if(event->key() == Qt::Key_W){
                    player->set_vel(player->getVx(),40,player->getPx(),player->getPy());
                    ui->graphicsView->centerOn(player->getPx(),player->getPy());
                }
            }

            Personaje3 *player_two;
            if(vidas1->getAnuncio()>0){
                if(vidas2->getAnuncio()>0)
                    player_two = bars.at(1)->getEsf();

            }
            else{
                player_two = bars.at(0)->getEsf();
            }
            if(vidas2->getAnuncio()>0){
                if(event->key()== Qt::Key_J){
                    player_two->set_vel(-15,player_two->getVy(),player_two->getPx(),player_two->getPy());
                    if (vidas1->getAnuncio() > 0){bars.at(1)->setFilas(0);}
                    else {bars.at(0)->setFilas(0);
                        ui->graphicsView->centerOn(player_two->getPx(),player_two->getPy());}
                }
                if(event->key() == Qt::Key_L){
                    player_two->set_vel(15,player_two->getVy(),player_two->getPx(),player_two->getPy());
                    if (vidas1->getAnuncio() > 0){bars.at(1)->setFilas(76);}

                    else {bars.at(0)->setFilas(76);
                        ui->graphicsView->centerOn(player_two->getPx(),player_two->getPy());}
                }
                if(event->key() == Qt::Key_I){
                    player_two->set_vel(player_two->getVx(),40,player_two->getPx(),player_two->getPy());
                }
            }
        }
    }
}

void Nivel3::actualizar()
{
    for (int i = 0;i < bars.size() ;i++) {
        bars.at(i)->actualizar(v_limit);
        borderCollision();
        Eliminar_vida();
        Puntos(i);
        if (i == 0){
            if (vidas1->getAnuncio() > 0){
                vidas1->setPos(vidas1->getPx()+bars.at(i)->getEsf()->getPx(),0);
                puntaje1->setPos(puntaje1->getPx()+bars.at(i)->getEsf()->getPx(),18);
            }
            else{
                vidas2->setPos(vidas2->getPx()+bars.at(i)->getEsf()->getPx(),0);
                puntaje2->setPos(puntaje2->getPx()+bars.at(i)->getEsf()->getPx(),18);
            }
        }
        else if (i == 1){
            vidas2->setPos(vidas2->getPx()+bars.at(i)->getEsf()->getPx(),0);
            puntaje2->setPos(puntaje2->getPx()+bars.at(i)->getEsf()->getPx(),18);
        }
        if (vidas1->getAnuncio() == 0){
            scene->removeItem(vidas1);
            vidas1->decrease_vida(1);
            scene->removeItem(puntaje1);
            scene->removeItem(bars.at(0));
            bars.pop_front();
        }
        if (vidas2->getAnuncio() == 0){
            scene->removeItem(vidas2);
            scene->removeItem(puntaje2);
            if (vidas1->getAnuncio() > 0){
                vidas2->decrease_vida(1);
                scene->removeItem(bars.at(1));
                bars.pop_back();;}
            else{scene->removeItem(bars.at(0));
                vidas2->decrease_vida(1);
                bars.pop_back();}
        }
    }
}

void Nivel3::Puntos(int i)
{
    for (int j=0;j<Bonus.size();j++) {
        if(bars.at(i)->collidesWithItem(Bonus.at(j))){
            if (i == 0){
                if (vidas1->getAnuncio() > 0){
                    puntaje1->increse_score(10);
                }
                else{
                    puntaje2->increse_score(10);
                }
            }
            else if (i == 1){
                puntaje2->increse_score(10);
            }
            scene->removeItem(Bonus.at(j));
            Bonus.removeAt(j);
        }
    }
}

void Nivel3::borderCollision()
{
    for (int i = 0; i < bars.size(); i++){
        Personaje3 *b = bars.at(i)->getEsf();
        if (b->getPx()<b->getRr()){
            b->set_vel(-1*b->getE()*b->getVx(),b->getVy(),b->getRr(),b->getPy());
        }
        if (b->getPx()>h_limit-b->getRr()){
            b->set_vel(-1*b->getE()*b->getVx(),b->getVy(),h_limit-b->getRr(),b->getPy());
        }
        if (b->getPy()<b->getR()){
            b->set_vel(b->getVx(),-1*b->getE()*b->getVy(),b->getPx(),b->getR());
        }
        if (b->getPy()>v_limit-b->getR()){
            b->set_vel(b->getVx(),-1*b->getE()*b->getVy(),b->getPx(),v_limit-b->getR());
        }
    }

    for (int i = 0; i<Muros.size();i++){
        for (int j = 0; j < bars.size();j++){
            if (bars.at(j)->collidesWithItem(Muros.at(i))){
                Personaje3 *c= bars.at(j)->getEsf();
                Muro *m = Muros.at(i);

                if(c->getPy()<=v_limit-m->getPosy() && c->getPy()>=v_limit-m->getPosy()-m->getH() && c->getPx()<=m->getPosx()){
                    c->set_vel(-1*c->getE()*c->getVx(),c->getVy(),c->getPx()-c->getRr(),c->getPy());
                }
                else if(c->getPy()<=v_limit-m->getPosy() && c->getPy()>=v_limit-m->getPosy()-m->getH() && c->getPx()>=m->getPosx()+m->getW()){
                    c->set_vel(-1*c->getE()*c->getVx(),c->getVy(),c->getPx()+c->getRr(),c->getPy());
                }
                if(c->getPy()>=v_limit-m->getPosy() && c->getPx()>=m->getPosx() && c->getPx()<=m->getPosx()+m->getW()){
                    c->set_vel(c->getVx(),-1*c->getE()*c->getVy(),c->getPx(),c->getPy()+c->getRr());
                }
                else if(c->getPy()<=v_limit-m->getPosy()+m->getH() && c->getPx()>=m->getPosx() && c->getPx()<=m->getPosx()+m->getW()){
                    c->set_vel(c->getVx(),-1*c->getE()*c->getVy(),c->getPx(),c->getPy()-c->getRr());
                }
            }
        }
    }
    for (int i = 0; i < bars.size() ; i++ ) {
        if (bars.at(i)->collidesWithItem(Boton)){
            qDebug()<<"GG izi";
            //Los jugadores ganan
        }
    }
}

void Nivel3::Movimiento_Enemigo()
{
    float dist = 6001;
    int player=0;

    for (int j = 0; j < Enemigo.size() ; j++ ) {
        for(int i =0 ;i<bars.size();i++){
            Enemigo_fisica *e = Enemigo.at(j)->getEnemy();
            Personaje3 *c = bars.at(i)->getEsf();
            float new_dist = pow((pow(e->getPx()-c->getPx(),2)+pow(e->getPy()-c->getPy(),2)),0.5);
            if(dist>new_dist){
                dist=new_dist;
                player=i;
            }
        }
        dist=6001;
        if(bars.size()>0){
            Enemigo_fisica *e = Enemigo.at(j)->getEnemy();
            Personaje3 *c = bars.at(player)->getEsf();
            if (e->getPx() < c->getPx()){
                e->set_vel(7,e->getVy(),e->getPx(),e->getPy());
                Enemigo.at(j)->setFilas(80);
                Enemigo.at(j)->actualizar(v_limit);
            }
            else if (e->getPx() > c->getPx()){
                e->set_vel(-7,e->getVy(),e->getPx(),e->getPy());
                Enemigo.at(j)->setFilas(0);
                Enemigo.at(j)->actualizar(v_limit);
            }
            if (e->getPy() < c->getPy()){
                e->set_vel(e->getVx(),20,e->getPx(),e->getPy());
                Enemigo.at(j)->actualizar(v_limit);
            }
            if (e->getPy() > c->getPy()){
                e->set_vel(e->getVx(),-10,e->getPx(),e->getPy());
                Enemigo.at(j)->actualizar(v_limit);
            }
            Colision_paredes_e();
        }
    }
}

void Nivel3::Colision_paredes_e()
{
    for (int i = 0; i<Enemigo.size();i++){
        for (int j = 0; j < Muros.size();j++){
            if (Enemigo.at(i)->collidesWithItem(Muros.at(j))){

                Enemigo_fisica *c= Enemigo.at(i)->getEnemy();
                Muro *m = Muros.at(j);
                if(c->getPy()<v_limit-m->getPosy() && c->getPy()>v_limit-m->getPosy()-m->getH() && c->getPx()<m->getPosx()){
                    c->set_vel(-1*c->getE()*c->getVx(),c->getVy(),c->getPx()-c->getRr(),c->getPy());
                }
                else if(c->getPy()<v_limit-m->getPosy() && c->getPy()>v_limit-m->getPosy()-m->getH() && c->getPx()>m->getPosx()+m->getW()){
                    c->set_vel(-1*c->getE()*c->getVx(),c->getVy(),c->getPx()+c->getRr(),c->getPy());
                }
                if(c->getPy()>v_limit-m->getPosy() && c->getPx()>m->getPosx() && c->getPx()<m->getPosx()+m->getW()){
                    c->set_vel(c->getVx(),-1*c->getE()*c->getVy(),c->getPx(),c->getPy()+c->getRr());
                }
                else if(c->getPy()<v_limit-m->getPosy()+m->getH() && c->getPx()>m->getPosx() && c->getPx()<m->getPosx()+m->getW()){
                    c->set_vel(c->getVx(),-1*c->getE()*c->getVy(),c->getPx(),c->getPy()-c->getRr());
                }
            }
        }
    }

}

void Nivel3::Eliminar_vida()
{
    for (int i = 0; i < bars.size() ; i++ ) {
        for (int j = 0; j < Enemigo.size() ; j++ ) {
            if (bars.at(i)->collidesWithItem(Enemigo.at(j))){
                Personaje3 *c = bars.at(i)->getEsf();
                if (vidas1->getAnuncio() > 0 && i == 0){vidas1->decrease_vida(1);}
                else if (vidas2->getAnuncio() > 0){vidas2->decrease_vida(1);}
                //c->setPx(0);
                c->setPy(v_limit);
            }
        }
    }
}

Informacion Nivel3::getDatos_juego() const
{
    return datos_juego;
}

void Nivel3::setDatos_juego(const Informacion &value)
{
    datos_juego = value;
}

void Nivel3::on_pushButton_clicked()
{
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->graphicsView->show();

    this->resize(ui->graphicsView->width(),ui->graphicsView->height()+25);
    scene->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/nochefin.jpg")));
    Enemigo.push_back(new Enemigo_graf(0,3));
    Enemigo.back()->setPos(1000,160);
    scene->addItem(Enemigo.back());
    Enemigo.push_back(new Enemigo_graf(0,3));
    Enemigo.back()->setPos(1950,160);
    scene->addItem(Enemigo.back());
    Enemigo.push_back(new Enemigo_graf(0,3));
    Enemigo.back()->setPos(2760,120);
    scene->addItem(Enemigo.back());

    Boton = new Muro(150,250,5850,530,2);
    scene->addItem(Boton);

    for(int i=0;i<1;i++){
        Muros.push_back(new Muro(150,30,0,300,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(30,70,150,260,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(80,80,300,580,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(80,80,400,480,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(20,300,600,350,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(180,20,520,330,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(20,120,800,530,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(100,20,760,510,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(20,200,950,0,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(150,20,920,200,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(100,200,1150,450,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(20,200,1400,0,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(20,100,1600,550,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(100,20,1560,530,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(20,300,1750,0,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(100,20,1670,300,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(20,200,1900,0,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(120,20,1900,200,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(20,80,2020,140,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(40,50,2200,600,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(40,100,2240,550,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(40,150,2280,500,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(40,200,2320,450,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(40,250,2360,400,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(40,300,2400,350,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(40,250,2440,400,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(40,200,2480,450,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(40,150,2520,500,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(40,100,2560,550,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(40,50,2600,600,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(40,200,2400,0,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(30,200,2700,0,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(100,100,2730,160,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(200,40,2780,220,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(20,200,3200,450,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(180,20,3120,430,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(20,150,3400,500,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(140,20,3340,480,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(20,100,3600,550,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(100,20,3560,530,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(40,150,3200,0,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(40,200,3400,0,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(40,250,3600,0,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(100,20,3900,500,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(20,120,4000,400,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(100,20,4020,400,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(20,120,4120,300,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(100,20,4140,300,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(20,120,4240,200,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(100,20,4260,200,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(20,450,4360,200,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(40,50,4600,600,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(40,100,4640,550,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(40,150,4680,500,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(40,200,4720,450,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(40,250,4760,400,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(40,300,4800,350,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(20,200,5000,450,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(150,20,5000,450,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(20,200,5150,450,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(20,250,5085,0,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(20,100,5300,550,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(150,20,5300,550,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(20,100,5450,550,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(200,20,5300,100,3));
        scene->addItem(Muros.back());
        Muros.push_back(new Muro(200,20,5300,200,3));
        scene->addItem(Muros.back());
    }

    Bonus.push_back(new Monedas(92,275)); scene->addItem(Bonus.back());
    Bonus.push_back(new Monedas(1710,226)); scene->addItem(Bonus.back());
    Bonus.push_back(new Monedas(2420,310)); scene->addItem(Bonus.back());
    Bonus.push_back(new Monedas(3295,91)); scene->addItem(Bonus.back());
    Bonus.push_back(new Monedas(4191,372)); scene->addItem(Bonus.back());
    Bonus.push_back(new Monedas(4825,298)); scene->addItem(Bonus.back());
    Bonus.push_back(new Monedas(5401,43)); scene->addItem(Bonus.back());

    if(datos_juego.getModo()==1){
        scene->addItem(vidas1);
        scene->addItem(puntaje1);
        vidas1->setPx(0);vidas1->setPy(0);
        puntaje1->setPx(0);vidas1->setPy(18);
        for (int i = 0; i < Enemigo.size() ; i++ ) {
            Enemigo_fisica *e = Enemigo.at(i)->getEnemy();
            if(i == 0){
                e->setPx(1000); e->setPy(160);
            }
            if (i == 1){
                e->setPx(1950); e->setPy(160);
            }
            if (i == 2){
                e->setPx(2760); e->setPy(120);
            }
            Enemigo.at(i)->actualizar((v_limit));
        }
        bars.push_back((new Personaje3graf(0,0)));
        bars.back()->setFocus();
        bars.back()->actualizar((v_limit));
        scene->addItem(bars.back());
        ui->graphicsView->centerOn(bars.back());
        timer->start(3);
        timere->start(50);
    }
    else{
        timer->start(3);
        timere->start(10);
        for (int i = 0; i < Enemigo.size() ; i++ ) {
            Enemigo_fisica *e = Enemigo.at(i)->getEnemy();
            if(i == 0){
                e->setPx(1000); e->setPy(160);
            }
            if (i == 1){
                e->setPx(1950); e->setPy(160);
            }
            if (i == 2){
                e->setPx(2760); e->setPy(120);
            }
            Enemigo.at(i)->actualizar((v_limit));
        }
        scene->addItem(vidas1);
        scene->addItem(puntaje1);
        vidas1->setPx(0);vidas1->setPy(0);
        puntaje1->setPx(0);vidas1->setPy(18);
        scene->addItem(vidas2);
        scene->addItem(puntaje2);
        vidas2->setPx(0);vidas2->setPy(0);
        puntaje2->setPx(0);vidas1->setPy(18);
        bars.push_back((new Personaje3graf));
        bars.back()->actualizar((v_limit));
        scene->addItem(bars.back());
        ui->graphicsView->centerOn(bars.back());
        bars.push_back((new Personaje3graf(0,1)));
        bars.back()->actualizar((v_limit));
        scene->addItem(bars.back());
        ui->graphicsView->centerOn(bars.back());
    }

}

void Nivel3::on_pushButton_2_clicked()
{
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->graphicsView_2->show();
    this->resize(ui->graphicsView_2->width(),ui->graphicsView_2->height());
    scene_2->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Instrucciones3.jpg")));
    ui->pushButton_3->show();
}

void Nivel3::on_pushButton_3_clicked()
{
    ui->pushButton->show();
    ui->pushButton_2->show();
    this->resize(ui->graphicsView->width(),ui->graphicsView->height());
    scene_2->clear();
    ui->graphicsView_2->hide();
    ui->pushButton_3->hide();
}
