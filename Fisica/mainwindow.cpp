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

    //Muros
//    int w,h,cx,cy;
//    ifstream Leer;
//    Leer.open("Coordenadasmuros.txt");
//    char linea[20];
//    Leer.getline(linea,sizeof (linea));
//    while (!Leer.eof()){
//        for (int i=0; i<4 ;i++){
//            char *p;
//            if (i==0){
//                p =strtok(linea, ",");
//                w=atoi(p);
//            }
//            if (i==1){
//                p =strtok(NULL, ",");
//                h=atoi(p);
//            }
//            if (i==2){
//                p =strtok(NULL, ",");
//                cx=atoi(p);
//            }
//            if (i==3){
//                p =strtok(NULL, ",");
//                cy=atoi(p);
//            }
//        }
//        Muros.push_back(new Pisos(w,h,cx,cy));
//        scene->addItem(Muros.back());
//        Leer.getline(linea,sizeof (linea));
//    }
//    Leer.close();

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
                if (c->getPx() > (Muros.at(i)->getPox()*-1)){
                    c->set_vel(0,0,c->getPx()+c->getRr(),c->getPy());
                   }
                else if (c->getPx() < (Muros.at(i)->getPox()*-1)){
                    c->set_vel(0,0,c->getPx()-c->getRr(),c->getPy());
                    }
                if (c->getPy() > (Muros.at(i)->getPoy()*-1)){
                    c->set_vel(0,0,c->getPx(),c->getPy()-c->getRr());
                    }
                else if (c->getPy() < (Muros.at(i)->getPoy()*-1)){
                    c->set_vel(0,0,c->getPx(),c->getPy()+c->getRr());
                    }
            }
        }
    }
}

void MainWindow:: keyPressEvent(QKeyEvent *event){
    if (semilla == 1){
    Cuerpo *b=bars.at(0)->getEsf();
    if (event->key()== Qt::Key_D){
        b->set_vel(15,b->getVy(),b->getPx(),b->getPy());
        bars.at(0)->setFilas(76);
        ui->graphicsView->centerOn(b->getPx(),b->getPy());
    }
    if (event->key()== Qt::Key_A){
        b->set_vel(-15,b->getVy(),b->getPx(),b->getPy());
        bars.at(0)->setFilas(0);
        ui->graphicsView->centerOn(b->getPx(),b->getPy());
    }
    if (event->key()== Qt::Key_W){
        b->set_vel(b->getVx(),40,b->getPx(),b->getPy());
        ui->graphicsView->centerOn(b->getPx(),b->getPy());
    }
    if (b->getPx() > 5600 && b->getPx() < 5900){
        if (event->key() == Qt::Key_Space){
            b->setPy(0);
        }
    }
    }
    else if (semilla == 2){
        for (int i = 0; i < bars.size() ; i++ ){
            if ( bars.size() == 2){
            if (i == 0){
            Cuerpo *b=bars.at(0)->getEsf();
            if (event->key()== Qt::Key_D){
                b->set_vel(15,b->getVy(),b->getPx(),b->getPy());
                bars.at(0)->setFilas(76);
                ui->graphicsView->centerOn(b->getPx(),b->getPy());
            }
            if (event->key()== Qt::Key_A){
                b->set_vel(-15,b->getVy(),b->getPx(),b->getPy());
                bars.at(0)->setFilas(0);
                ui->graphicsView->centerOn(b->getPx(),b->getPy());
            }
            if (event->key()== Qt::Key_W){
                b->set_vel(b->getVx(),40,b->getPx(),b->getPy());
                ui->graphicsView->centerOn(b->getPx(),b->getPy());
            }
            if (b->getPx() > 5600 && b->getPx() < 5900){
                if (event->key() == Qt::Key_Space){
                    b->setPy(0);
                }
            }
            }
            if (i ==1){
                Cuerpo *c = bars.at(1)->getEsf();
                if (event->key()== Qt::Key_L){
                    c->set_vel(15,c->getVy(),c->getPx(),c->getPy());
                    bars.at(1)->setFilas(76);
                    ui->graphicsView->centerOn(c->getPx(),c->getPy());
                }
                if (event->key()== Qt::Key_J){
                    c->set_vel(-15,c->getVy(),c->getPx(),c->getPy());
                    bars.at(1)->setFilas(0);
                    ui->graphicsView->centerOn(c->getPx(),c->getPy());
                }
                if (event->key()== Qt::Key_I){
                    c->set_vel(c->getVx(),40,c->getPx(),c->getPy());
                    ui->graphicsView->centerOn(c->getPx(),c->getPy());
                }
                if (c->getPx() > 5600 && c->getPx() < 5900){
                    if (event->key() == Qt::Key_Space){
                        c->setPy(0);
                    }
                }
            }
            }
            else if (bars.size() == 1){
                if (personaje == 0){
                    Cuerpo *b=bars.at(0)->getEsf();
                    if (event->key()== Qt::Key_D){
                        b->set_vel(15,b->getVy(),b->getPx(),b->getPy());
                        bars.at(0)->setFilas(76);
                        ui->graphicsView->centerOn(b->getPx(),b->getPy());
                    }
                    if (event->key()== Qt::Key_A){
                        b->set_vel(-15,b->getVy(),b->getPx(),b->getPy());
                        bars.at(0)->setFilas(0);
                        ui->graphicsView->centerOn(b->getPx(),b->getPy());
                    }
                    if (event->key()== Qt::Key_W){
                        b->set_vel(b->getVx(),40,b->getPx(),b->getPy());
                        ui->graphicsView->centerOn(b->getPx(),b->getPy());
                    }
                    if (b->getPx() > 5600 && b->getPx() < 5900){
                        if (event->key() == Qt::Key_Space){
                            b->setPy(0);
                        }
                    }
                }
                else if (personaje == 1){
                    Cuerpo *c = bars.at(0)->getEsf();
                    if (event->key()== Qt::Key_L){
                        c->set_vel(15,c->getVy(),c->getPx(),c->getPy());
                        bars.at(0)->setFilas(76);
                        ui->graphicsView->centerOn(c->getPx(),c->getPy());
                    }
                    if (event->key()== Qt::Key_J){
                        c->set_vel(-15,c->getVy(),c->getPx(),c->getPy());
                        bars.at(0)->setFilas(0);
                        ui->graphicsView->centerOn(c->getPx(),c->getPy());
                    }
                    if (event->key()== Qt::Key_I){
                        c->set_vel(c->getVx(),40,c->getPx(),c->getPy());
                        ui->graphicsView->centerOn(c->getPx(),c->getPy());
                    }
                    if (c->getPx() > 5600 && c->getPx() < 5900){
                        if (event->key() == Qt::Key_Space){
                            c->setPy(0);
                        }
                    }
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
                vidas1->decrease();
                //c->setPx(0);
                c->setPy(v_limit);
            }
        }
    }
}

void MainWindow::Colision_paredes_e()
{
    for (int i = 0; i<Enemigo.size();i++){
        for (int j = 0; j < Muros.size();j++){
            if (Enemigo.at(i)->collidesWithItem(Muros.at(j))){
                Enemigos *c= Enemigo.at(i)->getEsf();
                if (c->getPx() > (Muros.at(i)->getPox()*-1)){
                    c->set_vel(0,0,c->getPx()+c->getRr(),c->getPy());
                   }
                else if (c->getPx() < (Muros.at(i)->getPox()*-1)){
                    c->set_vel(0,0,c->getPx()-c->getRr(),c->getPy());
                    }
                if (c->getPy() > (Muros.at(i)->getPoy()*-1)){
                    c->set_vel(0,0,c->getPx(),c->getPy()-c->getR());
                    }
                else if (c->getPy() < (Muros.at(i)->getPoy()*-1)){
                    c->set_vel(0,0,c->getPx(),c->getPy()+c->getR());
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
        if (i == 0){
            vidas1->setPos(vidas1->getPx()+bars.at(i)->getEsf()->getPx(),0);
        }
        else if (i == 1){
            vidas2->setPos(vidas2->getPx()+bars.at(i)->getEsf()->getPx(),0);
        }
        if (vidas1->getVida() == 0){
            scene->removeItem(bars.at(0));
            bars.removeAt(0);
            personaje = 0;
        }
        if (vidas2->getVida() == 0){
            scene->removeItem(bars.at(1));
            bars.removeAt(1);
            personaje = 1;
        }
    }
}

void MainWindow::Movimiento_Enemigo()
{
    for (int i = 0; i < bars.size(); i++){
        for (int j = 0; j < Enemigo.size() ; j++ ) {
            Enemigos *e = Enemigo.at(j)->getEsf();
            Cuerpo *c = bars.at(i)->getEsf();
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
    vidas1 = new Vida();
    scene->addItem(vidas1);
    vidas1->setPx(0);vidas1->setPy(0);
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
    vidas1 = new Vida();
    scene->addItem(vidas1);
    vidas1->setPx(0);vidas1->setPy(0);
    vidas2 = new Vida();
    scene->addItem(vidas2);
    vidas2->setPx(0);vidas2->setPy(0);
    bars.push_back((new Cuerpograf));
    bars.back()->actualizar((v_limit));
    scene->addItem(bars.back());
    ui->graphicsView->centerOn(bars.back());
    bars.push_back((new Cuerpograf));
    bars.back()->actualizar((v_limit));
    scene->addItem(bars.back());
    ui->graphicsView->centerOn(bars.back());
}
