#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);

    h_limit = 6000;
    v_limit = 650;

    timer = new QTimer(this);
    timere = new QTimer(this);
    scene->setSceneRect(0,0,h_limit,v_limit);
    scene->setBackgroundBrush(QBrush(QImage(":/new/fondo/nochefin.jpg")));

    ui->graphicsView->setScene(scene);
    ui->centralwidget->adjustSize();
    scene->addRect(scene->sceneRect());
    ui->graphicsView->resize(1000,650);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    vidas1 = new Vida();
    vidas2 = new Vida();

    puntaje1 = new Vida(0,1);
    puntaje2 = new Vida(0,1);

    Enemigo.push_back(new Enemigosgraf);
    Enemigo.back()->setPos(1000,160);
    scene->addItem(Enemigo.back());
    Enemigo.push_back(new Enemigosgraf);
    Enemigo.back()->setPos(1950,160);
    scene->addItem(Enemigo.back());
    Enemigo.push_back(new Enemigosgraf);
    Enemigo.back()->setPos(2760,120);
    scene->addItem(Enemigo.back());

    Boton = new Boton_final();
    Boton->setPos(5850,530);
    scene->addItem(Boton);

for(int i=0;i<1;i++){
    Muros.push_back(new Pisos(150,30,0,-300));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(30,70,-150,-260));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(80,80,-300,-580));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(80,80,-400,-480));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(20,300,-600,-350));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(180,20,-520,-330));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(20,120,-800,-530));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(100,20,-760,-510));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(20,200,-950,0));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(150,20,-920,-200));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(100,200,-1150,-450));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(20,200,-1400,0));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(20,100,-1600,-550));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(100,20,-1560,-530));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(20,300,-1750,0));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(100,20,-1670,-300));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(20,200,-1900,0));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(120,20,-1900,-200));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(20,80,-2020,-140));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(40,50,-2200,-600));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(40,100,-2240,-550));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(40,150,-2280,-500));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(40,200,-2320,-450));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(40,250,-2360,-400));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(40,300,-2400,-350));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(40,250,-2440,-400));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(40,200,-2480,-450));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(40,150,-2520,-500));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(40,100,-2560,-550));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(40,50,-2600,-600));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(40,200,-2400,0));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(30,200,-2700,0));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(100,100,-2730,-160));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(200,40,-2780,-220));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(20,200,-3200,-450));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(180,20,-3120,-430));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(20,150,-3400,-500));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(140,20,-3340,-480));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(20,100,-3600,-550));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(100,20,-3560,-530));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(40,150,-3200,0));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(40,200,-3400,0));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(40,250,-3600,0));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(100,20,-3900,-500));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(20,120,-4000,-400));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(100,20,-4020,-400));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(20,120,-4120,-300));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(100,20,-4140,-300));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(20,120,-4240,-200));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(100,20,-4260,-200));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(20,450,-4360,-200));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(40,50,-4600,-600));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(40,100,-4640,-550));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(40,150,-4680,-500));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(40,200,-4720,-450));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(40,250,-4760,-400));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(40,300,-4800,-350));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(20,200,-5000,-450));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(150,20,-5000,-450));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(20,200,-5150,-450));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(20,250,-5085,0));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(20,100,-5300,-550));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(150,20,-5300,-550));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(20,100,-5450,-550));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(200,20,-5300,-100));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(200,20,-5300,-200));
    scene->addItem(Muros.back());
}

    Bonus.push_back(new monedas(92,275)); scene->addItem(Bonus.back());
    Bonus.push_back(new monedas(1710,226)); scene->addItem(Bonus.back());
    Bonus.push_back(new monedas(2420,310)); scene->addItem(Bonus.back());
    Bonus.push_back(new monedas(3295,91)); scene->addItem(Bonus.back());
    Bonus.push_back(new monedas(4191,372)); scene->addItem(Bonus.back());
    Bonus.push_back(new monedas(4825,298)); scene->addItem(Bonus.back());
    Bonus.push_back(new monedas(5401,43)); scene->addItem(Bonus.back());

    connect(timer,SIGNAL(timeout()),this, SLOT(actualizar()));
    connect(timere,SIGNAL(timeout()),this, SLOT(Movimiento_Enemigo()));
}

MainWindow::~MainWindow()
{
    delete timer;
    delete timere;
    delete scene;
    delete ui;
}

void MainWindow::borderCollision()
{
    for (int i = 0; i < bars.size(); i++){
        Cuerpo *b = bars.at(i)->getEsf();
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
                Cuerpo *c= bars.at(j)->getEsf();
                Pisos *m = Muros.at(i);

                if(c->getPy()<=v_limit+m->getPoy() && c->getPy()>=v_limit+m->getPoy()-m->getH() && c->getPx()<=-m->getPox()){
                    c->set_vel(-1*c->getE()*c->getVx(),c->getVy(),c->getPx()-(bars.at(j)->getAncho()/2),c->getPy());
                }
                else if(c->getPy()<=v_limit+m->getPoy() && c->getPy()>=v_limit+m->getPoy()-m->getH() && c->getPx()>=-m->getPox()+m->getW()){
                    c->set_vel(-1*c->getE()*c->getVx(),c->getVy(),c->getPx()+(bars.at(j)->getAncho()/2),c->getPy());
                }
                if(c->getPy()>=v_limit+m->getPoy() && c->getPx()>=-m->getPox() && c->getPx()<=-m->getPox()+m->getW()){
                    c->set_vel(c->getVx(),-1*c->getE()*c->getVy(),c->getPx(),c->getPy()+c->getRr());
                }
                else if(c->getPy()<=v_limit+m->getPoy()+m->getH() && c->getPx()>=-m->getPox() && c->getPx()<=-m->getPox()+m->getW()){
                    c->set_vel(c->getVx(),-1*c->getE()*c->getVy(),c->getPx(),c->getPy()-c->getRr());
                }
            }
        }
    }

    for (int i = 0; i < bars.size() ; i++ ) {
        if (bars.at(i)->collidesWithItem(Boton)){
            //Los jugadores ganan
        }
    }
}

void MainWindow:: keyPressEvent(QKeyEvent *event){
    if(semilla==1){
            if(bars.size()>0){
                Cuerpo *player = bars.at(0)->getEsf();

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

        else if(semilla==2){
            if(bars.size()>0){

                Cuerpo *player;

                if(vidas1->getVida()>0){
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

                Cuerpo *player_two;
                if(vidas1->getVida()>0){
                    if(vidas2->getVida()>0)
                        player_two = bars.at(1)->getEsf();

                }
                else{
                    player_two = bars.at(0)->getEsf();
                }
                if(vidas2->getVida()>0){
                    if(event->key()== Qt::Key_J){
                        player_two->set_vel(-15,player_two->getVy(),player_two->getPx(),player_two->getPy());
                        if (vidas1->getVida() > 0){bars.at(1)->setFilas(0);}
                        else {bars.at(0)->setFilas(0);
                             ui->graphicsView->centerOn(player_two->getPx(),player_two->getPy());}
                    }
                    if(event->key() == Qt::Key_L){
                        player_two->set_vel(15,player_two->getVy(),player_two->getPx(),player_two->getPy());
                        if (vidas1->getVida() > 0){bars.at(1)->setFilas(76);}

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

void MainWindow::Eliminar_vida()
{
    for (int i = 0; i < bars.size() ; i++ ) {
        for (int j = 0; j < Enemigo.size() ; j++ ) {
            if (bars.at(i)->collidesWithItem(Enemigo.at(j))){
                Cuerpo *c = bars.at(i)->getEsf();
                if (vidas1->getVida() > 0 && i == 0){vidas1->decrease();}
                else if (vidas2->getVida() > 0){vidas2->decrease();}
                //c->setPx(0);
                c->setPy(v_limit);
            }
        }
    }
}

void MainWindow::Puntos(int i)
{
    for (int j=0;j<Bonus.size();j++) {
        if(bars.at(i)->collidesWithItem(Bonus.at(j))){
            if (i == 0){
                if (vidas1->getVida() > 0){
                    puntaje1->increse();
                }
                else{
                    puntaje2->increse();
                }
            }
            else if (i == 1){
                puntaje2->increse();
            }
            scene->removeItem(Bonus.at(j));
            Bonus.removeAt(j);
        }
    }
}

void MainWindow::Colision_paredes_e()
{
    for (int i = 0; i<Enemigo.size();i++){
        for (int j = 0; j < Muros.size();j++){
            if (Enemigo.at(i)->collidesWithItem(Muros.at(j))){

                Enemigos *c= Enemigo.at(i)->getEsf();
                Pisos *m = Muros.at(j);

                if(c->getPy()<v_limit+m->getPoy() && c->getPy()>v_limit+m->getPoy()-m->getH() && c->getPx()<-m->getPox()){
                    c->set_vel(-1*c->getE()*c->getVx(),c->getVy(),c->getPx()-(Enemigo.at(i)->getAncho()/2),c->getPy());
                }
                else if(c->getPy()<v_limit+m->getPoy() && c->getPy()>v_limit+m->getPoy()-m->getH() && c->getPx()>-m->getPox()+m->getW()){
                    c->set_vel(-1*c->getE()*c->getVx(),c->getVy(),c->getPx()+(Enemigo.at(i)->getAncho()/2),c->getPy());
                }
                if(c->getPy()>v_limit+m->getPoy() && c->getPx()>-m->getPox() && c->getPx()<-m->getPox()+m->getW()){
                    c->set_vel(c->getVx(),-1*c->getE()*c->getVy(),c->getPx(),c->getPy()+c->getRr());
                }
                else if(c->getPy()<v_limit+m->getPoy()+m->getH() && c->getPx()>-m->getPox() && c->getPx()<-m->getPox()+m->getW()){
                    c->set_vel(c->getVx(),-1*c->getE()*c->getVy(),c->getPx(),c->getPy()-c->getRr());
                }
            }
        }
    }

}

void MainWindow::actualizar()
{
    for (int i = 0;i < bars.size() ;i++) {
        bars.at(i)->actualizar(v_limit);
        borderCollision();
        Eliminar_vida();
        Puntos(i);
        if (i == 0){
            if (vidas1->getVida() > 0){
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
        if (vidas1->getVida() == 0){
            scene->removeItem(vidas1);
            vidas1->decrease();
            scene->removeItem(puntaje1);
            scene->removeItem(bars.at(0));
            //timere->stop();
            bars.pop_front();
            //delete vidas1;
        }
        if (vidas2->getVida() == 0){
            scene->removeItem(vidas2);
            scene->removeItem(puntaje2);
            if (vidas1->getVida() > 0){
                vidas2->decrease();
                scene->removeItem(bars.at(1));
                //timere->stop();
                bars.pop_back();}
            else{scene->removeItem(bars.at(0));
                vidas2->decrease();
                //timere->stop();
                bars.pop_back();}
            //delete vidas2;
        }
    }
}

void MainWindow::Movimiento_Enemigo()
{
    float dist = 6001;
    int player=0;

    for (int j = 0; j < Enemigo.size() ; j++ ) {
        for(int i =0 ;i<bars.size();i++){
            Enemigos *e = Enemigo.at(j)->getEsf();
            Cuerpo *c = bars.at(i)->getEsf();
            float new_dist = pow((pow(e->getPx()-c->getPx(),2)+pow(e->getPy()-c->getPy(),2)),0.5);
            if(dist>new_dist){
                dist=new_dist;
                player=i;
            }
        }
        dist=6001;
        if(bars.size()>0){
        Enemigos *e = Enemigo.at(j)->getEsf();
        Cuerpo *c = bars.at(player)->getEsf();
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

void MainWindow::on_pushButton_clicked()
{
    semilla = 1;
    timer->start(3);
    timere->start(10);
    //vidas1 = new Vida();
    scene->addItem(vidas1);
    scene->addItem(puntaje1);
    vidas1->setPx(0);vidas1->setPy(0);
    puntaje1->setPx(0);vidas1->setPy(18);
    for (int i = 0; i < Enemigo.size() ; i++ ) {
        Enemigos *e = Enemigo.at(i)->getEsf();
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
    bars.push_back((new Cuerpograf));
    //bars.back()->setFocus();
    bars.back()->actualizar((v_limit));
    scene->addItem(bars.back());
    ui->graphicsView->centerOn(bars.back());

}

void MainWindow::on_pushButton_2_clicked()
{
    semilla = 2;
    timer->start(3);
    timere->start(10);
    for (int i = 0; i < Enemigo.size() ; i++ ) {
        Enemigos *e = Enemigo.at(i)->getEsf();
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
    //vidas1 = new Vida();
    scene->addItem(vidas1);
    scene->addItem(puntaje1);
    vidas1->setPx(0);vidas1->setPy(0);
    puntaje1->setPx(0);vidas1->setPy(18);
    //vidas2 = new Vida();
    scene->addItem(vidas2);
    scene->addItem(puntaje2);
    vidas2->setPx(0);vidas2->setPy(0);
    puntaje2->setPx(0);vidas1->setPy(18);
    bars.push_back((new Cuerpograf));
    bars.back()->actualizar((v_limit));
    scene->addItem(bars.back());
    ui->graphicsView->centerOn(bars.back());
    bars.push_back((new Cuerpograf(0,1)));
    bars.back()->actualizar((v_limit));
    scene->addItem(bars.back());
    ui->graphicsView->centerOn(bars.back());
}
