#include "nivel2.h"
#include "ui_nivel2.h"

Nivel2::Nivel2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Nivel2)
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
    setStyleSheet("Nivel2 {background-image:url(:/new/Imagenes/Fondo.jpg)}");

    scene_2->setSceneRect(0,0,902,605);
    ui->graphicsView_2->setScene(scene_2);
    ui->centralwidget->adjustSize();
    scene_2->addRect(scene_2->sceneRect());
    ui->graphicsView_2->resize(902,605);
    ui->graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->pushButton_3->hide();
    ui->graphicsView->hide();
    ui->graphicsView_2->hide();

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

Nivel2::~Nivel2()
{
    delete ui;
}

void Nivel2::keyPressEvent(QKeyEvent *event)
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
            velocidad_1->increse_score(-5);
        }
        if(event->key() == Qt::Key_D){
            jugadores.back()->right();
            velocidad_1->increse_score(5);
        }
        if(event->key() == Qt::Key_Space){
            balas.push_back(new Bala_parabolica_graf(jugadores.back()->getPosx(),v_limit-jugadores.back()->getPosy(),jugadores.back()->getAngulo(),jugadores.back()->getVel_inicial()));
            balas.back()->setId(1);
            jugadores.back()->disparo();
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
            velocidad_1->increse_score(-5);
        }
        if(event->key() == Qt::Key_D){
            jugadores.at(0)->right();
            velocidad_1->increse_score(5);
        }
        if(event->key() == Qt::Key_Space){
            balas.push_back(new Bala_parabolica_graf(jugadores.at(0)->getPosx(),v_limit-jugadores.at(0)->getPosy(),jugadores.at(0)->getAngulo(),jugadores.at(0)->getVel_inicial()));
            balas.back()->setId(1);
            jugadores.at(0)->disparo();
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
            velocidad_2->increse_score(-5);
        }
        if(event->key() == Qt::Key_L){
            jugadores.back()->right();
            velocidad_2->increse_score(5);
        }
        if(event->key() == Qt::Key_P){
            balas.push_back(new Bala_parabolica_graf(jugadores.at(1)->getPosx(),v_limit-jugadores.at(1)->getPosy(),jugadores.at(1)->getAngulo(),jugadores.at(1)->getVel_inicial()));
            balas.back()->setId(2);
            jugadores.at(1)->disparo();
            scene->addItem(balas.back());
        }
    }
}

void Nivel2::move()
{
    for(int i=0;i<balas.size();i++){
        balas.at(i)->actualizar(v_limit);
        if (Colisiones_Enemigos(i)){
            scene->removeItem(balas.at(i));
            balas.removeAt(i);
        }
        else{borderCollisionbala(i);}
    }
}

void Nivel2::borderCollisionbala(int i)
{
    Bala_parabolica *b = balas.at(i)->getBala();
    if (b->getPx()<0 || b->getPx()>h_limit-b->getR() || b->getPy()<b->getR() ){
        scene->removeItem(balas.at(i));
        balas.removeAt(i);

    }
}

void Nivel2::spawn()
{
    enemigos.push_back(new Enemigo_normal(2));
    scene->addItem(enemigos.back());
    N_enemigos++;

    if(N_enemigos>=Total_enemigos){
        crear_enemigos->stop();
    }
}

void Nivel2::move_enemy()
{
    for(int i=0;i<enemigos.size();i++){
        enemigos.at(i)->left();
        if(enemigos.at(i)->getPosx()<=0){
            scene->removeItem(enemigos.at(i));
            enemigos.removeAt(i);
            vida->decrease_vida(1);
            if (vida->getAnuncio() <= 0){
                scene->removeItem(vida);
                if (jugadores.size()== 2){
                    scene->removeItem(jugadores.at(1));
                    jugadores.removeAt(1);
                    scene->removeItem(puntaje2);
                    scene->removeItem(velocidad_2);
                }
                if(jugadores.size()==1){
                    scene->removeItem(jugadores.at(0));
                    jugadores.removeAt(0);
                    scene->removeItem(puntaje1);
                    scene->removeItem(velocidad_1);
                }
                for(int i=0;i<enemigos.size();i++){scene->removeItem(enemigos.at(i));} enemigos.clear();
                for(int i=0;i<enemigos_s.size();i++){scene->removeItem(enemigos_s.at(i));} enemigos_s.clear();
                for(int i=0;i<balas.size();i++){scene->removeItem(balas.at(i));} balas.clear();
                timer->stop();
                crear_enemigos->stop();
                mover_enemigos->stop();
                crear_enemigos_s->stop();
                mover_enemigos_s->stop();
            }
        }
    }
}

void Nivel2::spawn_jump()
{
    enemigos_s.push_back(new Enemigo_graf(0,2));
    scene->addItem(enemigos_s.back());
    N_enemigos++;

    if(N_enemigos>=Total_enemigos){
        crear_enemigos_s->stop();
    }
}

void Nivel2::move_enemy_jump()
{
    for(int i=0;i<enemigos_s.size();i++){
        enemigos_s.at(i)->actualizar(v_limit);
        enemigos_s.at(i)->Actualizacion();
        borderCollision(i);
    }
}

void Nivel2::borderCollision(int i)
{
    Enemigo_fisica *b = enemigos_s.at(i)->getEnemy();
    if (b->getPx()<0){
        scene->removeItem(enemigos_s.at(i));
        enemigos_s.removeAt(i);
        vida->decrease_vida(2);
        if (vida->getAnuncio() == 0){
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

bool Nivel2::Colisiones_Enemigos(int i)
{
    for(int j = 0; j < enemigos.size(); j++){
        if (balas.at(i)->collidesWithItem(enemigos.at(j))){
            if (balas.at(i)->getId() == 1)
                puntaje1->increse_score(1);
            else
                puntaje2->increse_score(1);
            scene->removeItem(enemigos.at(j));
            enemigos.removeAt(j);
            return true;
        }
    }
    for(int j = 0; j < enemigos_s.size(); j++){
        if (balas.at(i)->collidesWithItem(enemigos_s.at(j))){
            if (balas.at(i)->getId() == 1)
                puntaje1->increse_score(3);
            else
                puntaje2->increse_score(3);
            scene->removeItem(enemigos_s.at(j));
            enemigos_s.removeAt(j);
            return true;
        }
    }
    return false;
}

Informacion Nivel2::getDatos_partida() const
{
    return datos_partida;
}

void Nivel2::setDatos_partida(const Informacion &value)
{
    datos_partida = value;
}

void Nivel2::on_pushButton_clicked()
{
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->graphicsView->show();
    scene->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Bosque.jpg")));


    if(datos_partida.getModo()==1){
        Total_enemigos = 30;
        jugadores.push_back(new Personaje(nullptr,0,2,40,540));scene->addItem(jugadores.back());
        vida = new Anuncio(0,0,0,15,2);
        vida->setPos(710,40);
        scene->addItem(vida);
        puntaje1 = new Anuncio(0,0,1,16,2);
        puntaje1->setPos(670,540);
        scene->addItem(puntaje1);
        velocidad_1 = new Anuncio(0,0,2,10,2);
        velocidad_1->setPos(0,575);
        scene->addItem(velocidad_1);
        timer->start(20);
        crear_enemigos->start(2000);
        mover_enemigos->start(20);
        crear_enemigos_s->start(5000);
        mover_enemigos_s->start(15);
    }
    else{
        Total_enemigos = 60;
        jugadores.push_back(new Personaje(nullptr,40,540,2));scene->addItem(jugadores.back());
        vida = new Anuncio(0,0,0,15,2);
        vida->setPos(710,40);
        scene->addItem(vida);
        puntaje1 = new Anuncio(0,0,1,16,2);
        puntaje1->setPos(670,540);
        scene->addItem(puntaje1);
        velocidad_1 = new Anuncio(0,0,2,10,2);
        velocidad_1->setPos(0,575);
        scene->addItem(velocidad_1);
        jugadores.push_back(new Personaje(nullptr,40,470,1));scene->addItem(jugadores.back());
        puntaje2 = new Anuncio(0,1,1,16,2);
        puntaje2->setPos(670,470);
        scene->addItem(puntaje2);
        velocidad_2 = new Anuncio(0,1,2,10,2);
        velocidad_2->setPos(0,500);
        scene->addItem(velocidad_2);
        timer->start(20);
        crear_enemigos->start(1500);
        mover_enemigos->start(25);
        crear_enemigos_s->start(3000);
        mover_enemigos_s->start(20);
    }
}

void Nivel2::on_pushButton_2_clicked()
{
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->graphicsView_2->show();
    this->resize(ui->graphicsView_2->width(),ui->graphicsView_2->height());
    scene_2->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Instrucciones2.jpg")));
    ui->pushButton_3->show();

}

void Nivel2::on_pushButton_3_clicked()
{
    this->resize(ui->graphicsView->width(),ui->graphicsView->height());
    scene_2->clear();
    ui->graphicsView_2->hide();
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->hide();
}
