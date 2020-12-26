#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);

    h_limit = 4000;
    v_limit = 650;

    timer = new QTimer(this);
    timere = new QTimer();
    scene->setSceneRect(0,0,h_limit,v_limit);
//    scene->setBackgroundBrush(QBrush(QImage(":/new/fondo/istockphoto-915097804-170667a.jpg")));

    ui->graphicsView->setScene(scene);
    ui->centralwidget->adjustSize();
    scene->addRect(scene->sceneRect());
    ui->graphicsView->resize(1000,650);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    vidas = new Vida();
    scene->addItem(vidas);
    vidas->setPos(0,0);

    Muros.push_back(new Pisos(150,30,0,-300));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(30,60,-150,-260));
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
    Muros.push_back(new Pisos(30,200,-950,0));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(130,30,-920,-200));
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
    Muros.push_back(new Pisos(40,200,-2700,0));
    scene->addItem(Muros.back());
    Muros.push_back(new Pisos(100,100,-2740,-160));
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


    connect(timer,SIGNAL(timeout()),this, SLOT(actualizar()));
    connect(timere,SIGNAL(timeout()),this, SLOT(Movimiento_Enemigo()));
}

MainWindow::~MainWindow()
{
    delete timer;
    delete scene;
    delete ui;
}

void MainWindow::borderCollision(Cuerpo *b)
{
    if (b->getPx()<b->getR()){
        b->set_vel(-1*b->getE()*b->getVx(),b->getVy(),b->getR(),b->getPy());
    }
    if (b->getPx()>h_limit-b->getR()){
        b->set_vel(-1*b->getE()*b->getVx(),b->getVy(),h_limit-b->getR(),b->getPy());
    }
    if (b->getPy()<b->getR()){
        b->set_vel(b->getVx(),-1*b->getE()*b->getVy(),b->getPx(),b->getR());
    }
    if (b->getPy()>v_limit-b->getR()){
        b->set_vel(b->getVx(),-1*b->getE()*b->getVy(),b->getPx(),v_limit-b->getR());
    }
    for (int i = 0; i<Muros.size();i++){
        for (int j = 0; j < bars.size();j++){
            if (bars.at(j)->collidesWithItem(Muros.at(i))){
                Cuerpo *c= bars.at(j)->getEsf();
                if (c->getPx() < Muros.at(i)->getPox()){
                   /*c->set_vel(-1*c->getE()*c->getVx(),c->getVy(),c->getPx()-c->getR(),c->getPy());*/
                   c->set_vel(0,0,c->getPx()-(Muros.at(i)->getW()/2),c->getPy());
                   }
                if (c->getPx() > Muros.at(i)->getPox()){
                   /*c->set_vel(c->getVx(),-1*c->getE()*c->getVy(),c->getPx()+c->getR(),c->getPy());*/
                    c->set_vel(0,0,c->getPx()+(Muros.at(i)->getW()/2),c->getPy());
                    }
                if (c->getPy() < Muros.at(i)->getPoy()){
                   /*c->set_vel(c->getVx(),-1*c->getE()*c->getVy(),c->getPx(),c->getPy()-c->getR());*/
                    c->set_vel(0,0,c->getPx(),c->getPy()-(Muros.at(i)->getH()/2));
                    }
                if (c->getPy() > Muros.at(i)->getPoy()){
                    /*c->set_vel(c->getVx(),-1*c->getE()*c->getVy(),c->getPx(),c->getPy()+c->getR());*/
                    c->set_vel(0,0,c->getPx(),c->getPy()+(Muros.at(i)->getH()/2));
                    }
            }
        }
    }
}

void MainWindow:: keyPressEvent(QKeyEvent *event){
    Cuerpo *b=bars.at(0)->getEsf();
    if (event->key()== Qt::Key_D){
        for (int i = 0; i < Muros.size() ; i++ ) {
            if (bars.at(0)->collidesWithItem(Muros.at(i))){
                borderCollision(bars.at(0)->getEsf());
            }
        }
        b->set_vel(15,b->getVy(),b->getPx(),b->getPy());
        ui->graphicsView->centerOn(b->getPx(),b->getPy());
    }
    if (event->key()== Qt::Key_A){
        for (int i = 0; i < Muros.size() ; i++ ) {
            if (bars.at(0)->collidesWithItem(Muros.at(i))){
                borderCollision(bars.at(0)->getEsf());
            }
        }
        b->set_vel(-15,b->getVy(),b->getPx(),b->getPy());
        ui->graphicsView->centerOn(b->getPx(),b->getPy());
    }
    if (event->key()== Qt::Key_W){
        for (int i = 0; i < Muros.size() ; i++ ) {
            if (bars.at(0)->collidesWithItem(Muros.at(i))){
                borderCollision(bars.at(0)->getEsf());
            }
        }
        b->set_vel(b->getVx(),20,b->getPx(),b->getPy());
        ui->graphicsView->centerOn(b->getPx(),b->getPy());
    }

}
void MainWindow::actualizar()
{
    for (int i = 0;i < bars.size() ;i++) {
        bars.at(i)->actualizar(v_limit);
        borderCollision(bars.at(i)->getEsf());
    }
}

void MainWindow::Movimiento_Enemigo()
{

}
void MainWindow::on_pushButton_clicked()
{
    timer->start(3);
    bars.push_back((new Cuerpograf));
    bars.back()->setFocus();
    bars.back()->actualizar((v_limit));
    scene->addItem(bars.back());
    ui->graphicsView->centerOn(bars.back());

}




