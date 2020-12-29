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

    vidas = new Vida();
    scene->addItem(vidas);
    vidas->setPos(0,0);

    Enemigo.push_back(new Enemigosgraf);
    Enemigo.back()->setPos(50,279);
    scene->addItem(Enemigo.back());
    Enemigo.push_back(new Enemigosgraf);
    Enemigo.back()->setPos(1000,179);
    scene->addItem(Enemigo.back());
    Enemigo.push_back(new Enemigosgraf);
    Enemigo.back()->setPos(1950,179);
    scene->addItem(Enemigo.back());
    Enemigo.push_back(new Enemigosgraf);
    Enemigo.back()->setPos(2760,139);
    scene->addItem(Enemigo.back());

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
//    for (int i = 0; i<Muros.size();i++){
//        for (int j = 0; j < bars.size();j++){
//            if (bars.at(j)->collidesWithItem(Muros.at(i))){
//                Cuerpo *c= bars.at(j)->getEsf();
//                if (c->getPx() < Muros.at(i)->getPox()){
//                   /*c->set_vel(-1*c->getE()*c->getVx(),c->getVy(),c->getPx()-c->getR(),c->getPy());*/
//                   c->set_vel(0,0,c->getPx()-(Muros.at(i)->getW()/2),c->getPy());
//                   }
//                if (c->getPx() > Muros.at(i)->getPox()){
//                   /*c->set_vel(c->getVx(),-1*c->getE()*c->getVy(),c->getPx()+c->getR(),c->getPy());*/
//                    c->set_vel(0,0,c->getPx()+(Muros.at(i)->getW()/2),c->getPy());
//                    }
//                if (c->getPy() < Muros.at(i)->getPoy()){
//                   /*c->set_vel(c->getVx(),-1*c->getE()*c->getVy(),c->getPx(),c->getPy()-c->getR());*/
//                    c->set_vel(0,0,c->getPx(),c->getPy()-(Muros.at(i)->getH()/2));
//                    }
//                if (c->getPy() > Muros.at(i)->getPoy()){
//                    /*c->set_vel(c->getVx(),-1*c->getE()*c->getVy(),c->getPx(),c->getPy()+c->getR());*/
//                    c->set_vel(0,0,c->getPx(),c->getPy()+(Muros.at(i)->getH()/2));
//                    }
//            }
//        }
//    }
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
        b->set_vel(b->getVx(),40,b->getPx(),b->getPy());
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
    for (int i = 0; i < bars.size(); i++){
        for (int j = 0; j < Enemigo.size() ; j++ ) {
            Enemigos *e = Enemigo.at(j)->getEsf();
            Cuerpo *c = bars.at(i)->getEsf();
            if (e->getPx() < c->getPx()){
                e->set_vel(15,e->getVy(),e->getPx(),e->getPy());
                Enemigo.at(j)->actualizar(v_limit);
            }
            if (e->getPx() > c->getPx()){
                e->set_vel(-15,e->getVy(),e->getPx(),e->getPy());
                Enemigo.at(j)->actualizar(v_limit);
            }
            if (e->getPy() < c->getPy()){
              e->set_vel(e->getVx(),40,e->getPx(),e->getPy());
              Enemigo.at(j)->actualizar(v_limit);
            }
//            borderCollision();

        }
    }
}
void MainWindow::on_pushButton_clicked()
{
    timer->start(3);
    timere->start(10);
    for (int i = 0; i < Enemigo.size() ; i++ ) {
        Enemigos *e = Enemigo.at(i)->getEsf();
        if (i==0){
            e->setPx(50); e->setPy(279);
        }
        if(i == 1){
            e->setPx(1000); e->setPy(179);
        }
        if (i == 2){
            e->setPx(1950); e->setPy(179);
        }
        if (i == 3){
            e->setPx(2760); e->setPy(139);
        }
        Enemigo.at(i)->actualizar((v_limit));
    }
    bars.push_back((new Cuerpograf));
    bars.back()->setFocus();
    bars.back()->actualizar((v_limit));
    scene->addItem(bars.back());
    ui->graphicsView->centerOn(bars.back());

}




