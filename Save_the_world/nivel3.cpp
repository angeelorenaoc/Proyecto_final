#include "nivel3.h"
#include "ui_nivel3.h"
#define RUTA_MURO3 ":/new/Archivos_texto/Muros_N3.txt"
#define RUTA_MONEDA ":/new/Archivos_texto/Monedas_N3.txt"
#define RUTA_FICHEROS "Ficheros.txt"
#define FICHEROS_RESPALDO "Respaldo.txt"

Nivel3::Nivel3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Nivel3)
{
    srand(time(NULL));
    ui->setupUi(this);

    // Dimensiones de la escena
    h_limit = 6000;
    v_limit = 650;

    //************ Definicion de escena en la que se va a jugar *****************
    scene->setSceneRect(0,0,h_limit,v_limit);
    ui->Game->setScene(scene);
    ui->centralwidget->adjustSize();
    scene->addRect(scene->sceneRect());
    ui->Game->resize(1000,650);
    ui->Game->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->Game->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //***************************************************************************

    setStyleSheet("Nivel3 {background-image:url(:/new/Imagenes/Fondo.jpg)}"); //Fondo que tiene la ventana

    //************ Definicion de escena en la que se muestran los anuncios *****************
    scene_2->setSceneRect(0,0,700,700);
    ui->Anuncios->setScene(scene_2);
    ui->centralwidget->adjustSize();
    scene_2->addRect(scene_2->sceneRect());
    ui->Anuncios->resize(700,700);
    ui->Anuncios->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->Anuncios->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //**************************************************************************************

    //Se ocultan los botones que no se necesitan en el momento
    ui->Volver->hide();
    ui->Game->hide();
    ui->Anuncios->hide();
    ui->Reiniciar->hide();
    ui->Volver_jugar->hide();
    ui->Siguiente->hide();
    ui->Salir->move(380,530);
    ui->Fondo->hide();
    ui->Jugador1->hide();
    ui->Fondo1->hide();
    ui->Fondo2->hide();
    ui->Fondo3->hide();
    ui->Fondo4->hide();
    ui->Hombre->hide();
    ui->Mujer->hide();
    ui->Jugador2->hide();
    ui->Hombre1->hide();
    ui->Mujer1->hide();
    //********************************************************

    //***** Se crean los timer y se conectan con sus respectivas funciones *********
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this, SLOT(actualizar()));
    timere = new QTimer;
    connect(timere,SIGNAL(timeout()),this, SLOT(Movimiento_Enemigo()));
    Lose = new QTimer;
    connect(Lose,SIGNAL(timeout()),this, SLOT(Perder()));
    Colisiones = new QTimer;
    connect(Colisiones,SIGNAL(timeout()),this, SLOT(borderCollision()));
    //*****************************************************************************

}

Nivel3::~Nivel3()
{
    delete timer;
    delete timere;
    delete scene;
    delete ui;
}

//Metodo que maneja las teclas del jugador
void Nivel3:: keyPressEvent(QKeyEvent *event)
{
    if(datos_juego.getModo()==1){
        if(bars.size()>0){
            Personaje3 *player = bars.at(0)->getEsf();

            if(event->key()== Qt::Key_A){
                player->set_vel(-15,player->getVy(),player->getPx(),player->getPy());
                bars.at(0)->setFilas(0);
                ui->Game->centerOn(player->getPx(),player->getPy());
            }
            if(event->key() == Qt::Key_D){
                player->set_vel(15,player->getVy(),player->getPx(),player->getPy());
                bars.at(0)->setFilas(76);
                ui->Game->centerOn(player->getPx(),player->getPy());

            }
            if(event->key() == Qt::Key_W){
                player->set_vel(player->getVx(),40,player->getPx(),player->getPy());
                ui->Game->centerOn(player->getPx(),player->getPy());
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
                    ui->Game->centerOn(player->getPx(),player->getPy());
                }
                if(event->key() == Qt::Key_D){
                    player->set_vel(15,player->getVy(),player->getPx(),player->getPy());
                    bars.at(0)->setFilas(76);
                    ui->Game->centerOn(player->getPx(),player->getPy());
                }
                if(event->key() == Qt::Key_W){
                    player->set_vel(player->getVx(),40,player->getPx(),player->getPy());
                    ui->Game->centerOn(player->getPx(),player->getPy());
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
                        ui->Game->centerOn(player_two->getPx(),player_two->getPy());}
                }
                if(event->key() == Qt::Key_L){
                    player_two->set_vel(15,player_two->getVy(),player_two->getPx(),player_two->getPy());
                    if (vidas1->getAnuncio() > 0){bars.at(1)->setFilas(76);}

                    else {bars.at(0)->setFilas(76);
                        ui->Game->centerOn(player_two->getPx(),player_two->getPy());}
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
    //Ciclo que actualiza las posciones del enemigo y hace algunas verificaciones
    for (int i = 0;i < bars.size() ;i++) {
        bars.at(i)->actualizar(v_limit);
        Eliminar_vida();//Metodo que disminuye la vida
        Puntos(i);//Metodo que aumenta el puntaje
        if (i == 0){
            //Se verifica si la vida es mayor a 0. Ademas se trasladan los anuncios con el jugador.
            if (vidas1->getAnuncio() > 0){
                vidas1->setPos(vidas1->getPx()+bars.at(i)->getEsf()->getPx()-30,0);
                puntaje1->setPos(puntaje1->getPx()+bars.at(i)->getEsf()->getPx()-50,18);
            }
            else{
                vidas2->setPos(vidas2->getPx()+bars.at(i)->getEsf()->getPx()-30,0);
                puntaje2->setPos(puntaje2->getPx()+bars.at(i)->getEsf()->getPx()-50,18);
            }
        }
        else if (i == 1){
            vidas2->setPos(vidas2->getPx()+bars.at(i)->getEsf()->getPx()-30,0);
            puntaje2->setPos(puntaje2->getPx()+bars.at(i)->getEsf()->getPx()-50,18);
        }
        //Se revisa el numero de vidas de cada jugador, en caso que sea 0, este sera eliminado.
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
    //Metodo para comprobar las colisiones con muros, bordes o el boton final.
//    borderCollision();
}

void Nivel3::Puntos(int i)
{
    /* Metodo que se encarga de verificar el jugador al que se le
     * hara el aumento del puntaje si este colisiona con el bonus.*/
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
    //***************Cuando colisiona con los bordes de la escena****************************
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
    //***************************************************************************************

    //***************************************Cuando el jugador colisiona con los muros*********************************************************
    for (int i = 0; i<Muros.size();i++){
        for (int j = 0; j < bars.size();j++){
            if (bars.at(j)->collidesWithItem(Muros.at(i))){
                Personaje3 *c= bars.at(j)->getEsf();
                Muro *m = Muros.at(i);
                //Las colisiones se hacen con un cambio de velocidad.
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
    //*******************************************************************************************************************************************

    //*****************Cuando el jugador colisiona con el boton final**************************
    for (int i = 0; i < bars.size() ; i++ ) {
        if (bars.at(i)->collidesWithItem(Boton)){
            int Puntaje_total=datos_juego.getPuntaje();
            ui->Game->hide();
            Bonus.clear();
            Muros.clear();
            bars.clear();
            Enemigo.clear();

            timer->stop();
            timere->stop();
            Lose->stop();

            Puntaje_total += puntaje1->getAnuncio();
            Puntaje_total += puntaje2->getAnuncio();

            ui->Salir->show();
            ui->Salir->move(470,320);
            ui->Siguiente->show();
            scene_2->setSceneRect(0,0,466,700);
            ui->Anuncios->setScene(scene_2);
            ui->centralwidget->adjustSize();
            scene_2->addRect(scene_2->sceneRect());
            ui->Anuncios->show();
            ui->Anuncios->resize(466,700);
            this->resize(ui->Anuncios->width()+90,ui->Anuncios->height());
            ui->Anuncios->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            ui->Anuncios->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            scene_2->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Ganar_nivel3.jpg")));

            datos_juego.setPuntaje(Puntaje_total);
            Puntaje_total=0;
            scene->clear();
        }
    }
    //*****************************************************************************************
}

void Nivel3::Movimiento_Enemigo()
{
    float dist = 6001;
    int player=0;

    //****************Calcula el jugador mas cercano para seguirlo********************************
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
            // Se actualiza el movimiento del enemigo de acuerdo a el calculo entregado.
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
    //********************************************************************************************
}

void Nivel3::Perder()
{
    //Se comprueba cuando el jugadores o jugadores pierden el nivel.
    if(bars.size() == 0){
        ui->Game->hide();
        Bonus.clear();
        Muros.clear();
        bars.clear();
        Enemigo.clear();

        timer->stop();
        timere->stop();
        Lose->stop();

        ui->Salir->show();
        ui->Salir->move(470,320);
        ui->Reiniciar->show();
        scene_2->setSceneRect(0,0,466,700);
        ui->Anuncios->setScene(scene_2);
        ui->centralwidget->adjustSize();
        scene_2->addRect(scene_2->sceneRect());
        ui->Anuncios->show();
        ui->Anuncios->resize(466,700);
        this->resize(ui->Anuncios->width()+90,ui->Anuncios->height());
        ui->Anuncios->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->Anuncios->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scene_2->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Perder_nivel3.jpg")));

        scene->clear();
    }
}

void Nivel3::Colision_paredes_e()
{
    //*********************************************Cuando el enemigo colisiona con un muro***************************************************
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
    //***************************************************************************************************************************************

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

void Nivel3::on_Inicio_clicked()
{
    ui->Inicio->hide();
    ui->Instrucciones->hide();
    ui->Game->show();
    ui->Salir->hide();
    ui->Configurar->hide();

    //Boton que inicia el nivel y carga todo lo necesario a escena
    this->resize(ui->Game->width(),ui->Game->height()+25);

    if(fondo3==0)
        scene->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/nochefin.jpg")));
    else if(fondo3==1)
        scene->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Hangar_guerra.jpg")));
    else if(fondo3==2)
        scene->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Explosion_nuclear.jpg")));
    else
        scene->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Fondo_Random.jpg")));

    QFile file(RUTA_MURO3);           //Objeto para manejar la lectura del archivo
    file.open(QIODevice::ReadOnly);     //Abre el archivo en modo lectura

    QList<QString> dats;
    int n=0;
    while (file.atEnd() == false){
        QString line = file.readLine();
        while(n>=0){      //Ciclo para guardar cada dato de la linea de texto en su posicion correspondiente en el arreglo vec
            n = line.indexOf(" ");
            if(n!=0){
                dats.append(line.left(n));
            }
            line=line.remove(0,n+1);
        }
        Muros.push_back(new Muro(dats.at(0).toInt(),dats.at(1).toInt(),dats.at(2).toInt(),dats.at(3).toInt(),dats.at(4).toInt()));scene->addItem(Muros.back());
        dats.clear();
        n = 0;
    }
    file.close();

    QFile ARCHIVO(RUTA_MONEDA);           //Objeto para manejar la lectura del archivo
    ARCHIVO.open(QIODevice::ReadOnly);     //Abre el archiv en modo lectura

    QList<QString> datos;
    n=0;
    while (ARCHIVO.atEnd() == false){
        QString line = ARCHIVO.readLine();
        while(n>=0){      //Ciclo para guardar cada dato de la linea de texto en su posicion correspondiente en el arreglo vec
            n = line.indexOf(" ");
            if(n!=0){
                datos.append(line.left(n));
            }
            line=line.remove(0,n+1);
        }
        Bonus.push_back(new Monedas(datos.at(0).toInt(),datos.at(1).toInt()));scene->addItem(Bonus.back());
        datos.clear();
        n = 0;
    }
    ARCHIVO.close();

    //******Creacion de enemigos*************
    Enemigo.push_back(new Enemigo_graf(0,3));
    Enemigo.back()->setPos(1000,160);
    scene->addItem(Enemigo.back());
    Enemigo.push_back(new Enemigo_graf(0,3));
    Enemigo.back()->setPos(1950,160);
    scene->addItem(Enemigo.back());
    Enemigo.push_back(new Enemigo_graf(0,3));
    Enemigo.back()->setPos(2760,120);
    scene->addItem(Enemigo.back());
    Enemigo.push_back(new Enemigo_graf(0,3));
    Enemigo.back()->setPos(4500,120);
    scene->addItem(Enemigo.back());
    Enemigo.push_back(new Enemigo_graf(0,3));
    Enemigo.back()->setPos(5950,120);
    scene->addItem(Enemigo.back());
    //***************************************

    //**********Boton*******************
    Boton = new Muro(150,250,5850,530,2);
    scene->addItem(Boton);
    //**********************************

    //***********Anuncios**************
    vidas1 = new Anuncio(0,4,0,15,3);
    vidas2 = new Anuncio(0,0,0,15,3);
    puntaje1 = new Anuncio(0,4,1,15,3);
    puntaje2 = new Anuncio(0,0,1,15,3);
    //*********************************

    //Modo solitario
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
            if (i == 3){
                e->setPx(4500); e->setPy(120);
            }
            if (i == 4){
                e->setPx(5950); e->setPy(120);
            }
            Enemigo.at(i)->actualizar((v_limit));
        }
        bars.push_back((new Personaje3graf(0,disenio_jugador1)));
        bars.back()->setFocus();
        bars.back()->actualizar((v_limit));
        scene->addItem(bars.back());
        ui->Game->centerOn(bars.back());
        timer->start(4);
        timere->start(40);
    }

    //Modo multijugador
    else{
        timer->start(4);
        timere->start(40);
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
            if (i == 3){
                e->setPx(4500); e->setPy(120);
            }
            if (i == 4){
                e->setPx(5950); e->setPy(120);
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
        bars.push_back((new Personaje3graf(0,disenio_jugador1)));
        bars.back()->actualizar((v_limit));
        scene->addItem(bars.back());
        ui->Game->centerOn(bars.back());
        bars.push_back((new Personaje3graf(0,disenio_jugador2)));
        bars.back()->actualizar((v_limit));
        scene->addItem(bars.back());
        ui->Game->centerOn(bars.back());
    }
    Lose->start(10);
    Colisiones->start(1);

}

void Nivel3::on_Instrucciones_clicked()
{
    //**************Muestra las instrucciones en escena*************************
    ui->Inicio->hide();
    ui->Instrucciones->hide();
    ui->Anuncios->show();
    this->resize(ui->Anuncios->width(),ui->Anuncios->height());
    scene_2->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Instrucciones3.jpg")));
    ui->Volver->show();
    ui->Configurar->hide();
    ui->Salir->hide();
    //***************************************************************************
}

void Nivel3::on_Volver_clicked()
{
    //*****Boton que lo lleva al inicio del nivel*******
    ui->Inicio->show();
    ui->Instrucciones->show();
    scene_2->clear();
    ui->Anuncios->hide();
    ui->Volver->hide();
    ui->Salir->show();
    ui->Configurar->show();
    ui->Fondo->hide();
    ui->Jugador1->hide();
    ui->Fondo1->hide();
    ui->Fondo2->hide();
    ui->Fondo3->hide();
    ui->Fondo4->hide();
    ui->Hombre->hide();
    ui->Mujer->hide();
    ui->Jugador2->hide();
    ui->Hombre1->hide();
    ui->Mujer1->hide();
    this->resize(800,700);
    //*************************************************
}

void Nivel3::on_Siguiente_clicked()
{
    //Muestra una imagen felicitando al jugador
    scene_2->clear();
    ui->Siguiente->hide();
    ui->Salir->move(226,600);
    ui->Volver_jugar->show();
    ui->Volver_jugar->move(226,550);
    scene_2->setSceneRect(0,0,547,700);
    ui->Anuncios->setScene(scene_2);
    ui->centralwidget->adjustSize();
    scene_2->addRect(scene_2->sceneRect());
    ui->Anuncios->show();
    ui->Anuncios->resize(547,700);
    this->resize(ui->Anuncios->width(),ui->Anuncios->height());
    ui->Anuncios->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->Anuncios->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene_2->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Felicitaciones.jpg")));
}

void Nivel3::on_Reiniciar_clicked()
{
    //En el caso de que el jugador pierda el nivel, se le da la posibilidad de repetirlo.
    scene_2->setSceneRect(0,0,700,700);
    ui->Anuncios->setScene(scene_2);
    ui->centralwidget->adjustSize();
    scene_2->addRect(scene_2->sceneRect());
    ui->Anuncios->resize(700,700);

    this->resize(800,700);
    scene_2->clear();
    ui->Anuncios->hide();
    ui->Reiniciar->hide();
    ui->Salir->move(380,530);
    ui->Salir->show();
    ui->Inicio->show();
    ui->Instrucciones->show();
    ui->Configurar->show();
    ui->Salir->move(380,530);
}

void Nivel3::on_Salir_clicked()
{
    /*Este boton guarda los datos(en el caso de que haya ganado)
     * y lleva al usuario al menu principal.*/
    if (datos_juego.getSemilla()==3){
        QFile file(RUTA_FICHEROS);           //Objeto para manejar la lectura del archivo
        file.open(QIODevice::ReadOnly);     //Abre el archiv en modo lectura
        QList <QString> datos;

        QFile filer(FICHEROS_RESPALDO);
        filer.open(QIODevice::WriteOnly);
        QString Nombre = QString::fromStdString(datos_juego.getNombre_equipo());
        QString Clave = QString::fromStdString(datos_juego.getClave());
        QString Modo= QString::number(datos_juego.getModo());
        QString Semilla = QString::number(datos_juego.getSemilla());
        QString Puntaje = QString::number(datos_juego.getPuntaje());

        int n=0;
        while (file.atEnd() == false){
            QString line = file.readLine();
            while(n>=0){      //Ciclo para guardar cada dato de la linea de texto en su posicion correspondiente en el arreglo vec
                n = line.indexOf(" ");
                if(n!=0){
                    datos.append(line.left(n));
                }
                line=line.remove(0,n+1);
            }
            QString Name = datos.at(0);
            QString Password = datos.at(1);
            QString modo = datos.at(2);
            QString semilla = datos.at(3);
            QString puntaje = datos.at(4);
            if(Name == Nombre){
                QTextStream out(&filer);
                out << Nombre<<" "<<Clave<<" "<<Modo<<" "<<Semilla<<" "<<Puntaje<<"\n";
            }
            else{
                QTextStream out(&filer);
                out << Name<<" "<<Password<<" "<<modo<<" "<<semilla<<" "<<puntaje;
            }
            datos.clear();
            n = 0;
        }
        filer.flush();
        filer.close();
        file.close();
        file.remove();
        filer.rename(RUTA_FICHEROS);
    }

    //Se crea el menu
    this->hide();
    MainWindow *Menu = new MainWindow;
    Menu->show();
    this->~Nivel3();
}

void Nivel3::on_Volver_jugar_clicked()
{   
    /*Cuando finaliza el juego al jugador se le da la opcion de volver a jugarlo sin la necesidad
     *de reingresar o cambiar los datos, en esta parte del codigo, se cambia la semilla
     *y se reinicia el puntaje*/
    datos_juego.setSemilla(1);
    datos_juego.setPuntaje(0);
    QFile file(RUTA_FICHEROS);           //Objeto para manejar la lectura del archivo
    file.open(QIODevice::ReadOnly);     //Abre el archiv en modo lectura
    QList <QString> datos;

    QFile filer(FICHEROS_RESPALDO);
    filer.open(QIODevice::WriteOnly);
    QString Nombre = QString::fromStdString(datos_juego.getNombre_equipo());
    QString Clave = QString::fromStdString(datos_juego.getClave());
    QString Modo= QString::number(datos_juego.getModo());

    int n=0;
    while (file.atEnd() == false){
        QString line = file.readLine();
        while(n>=0){      //Ciclo para guardar cada dato de la linea de texto en su posicion correspondiente en el arreglo vec
            n = line.indexOf(" ");
            if(n!=0){
                datos.append(line.left(n));
            }
            line=line.remove(0,n+1);
        }
        QString Name = datos.at(0);
        QString Password = datos.at(1);
        QString modo = datos.at(2);
        QString semilla = datos.at(3);
        QString puntaje = datos.at(4);
        if(Name == Nombre){
            QTextStream out(&filer);
            out << Nombre<<" "<<Clave<<" "<<Modo<<" "<<"1"<<" "<<"0"<<"\n";
        }
        else{
            QTextStream out(&filer);
            out << Name<<" "<<Password<<" "<<modo<<" "<<semilla<<" "<<puntaje;
        }
        datos.clear();
        n = 0;
    }
    filer.flush();
    filer.close();
    file.close();
    file.remove();
    filer.rename(RUTA_FICHEROS);

    //Se crea la escena con el primer nivel.
    Nivel_1 *nivel1 = new Nivel_1;
    nivel1->setDatos_partida_1(this->datos_juego);
    nivel1->show();
    this->~Nivel3();
}

void  Nivel3::on_Configurar_clicked()
{
    ui->Configurar->hide();
    ui->Inicio->hide();
    ui->Instrucciones->hide();
    ui->Fondo->show();
    ui->Jugador1->show();
    ui->Salir->hide();

    ui->Fondo1->show();
    ui->Fondo2->show();
    ui->Fondo3->show();
    ui->Fondo4->show();
    ui->Hombre->show();
    ui->Mujer->show();

    if (datos_juego.getModo()==2){
        ui->Jugador2->show();
        ui->Hombre1->show();
        ui->Mujer1->show();
    }

    ui->Volver->show();

}

void  Nivel3::on_Fondo1_clicked()
{
    fondo3=0;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void  Nivel3::on_Fondo2_clicked()
{
    fondo3=1;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void Nivel3::on_Fondo3_clicked()
{
    fondo3=2;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void Nivel3::on_Fondo4_clicked()
{
    fondo3=3;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void  Nivel3::on_Hombre_clicked()
{
    disenio_jugador1=0;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void  Nivel3::on_Mujer_clicked()
{
    disenio_jugador1=1;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void  Nivel3::on_Hombre1_clicked()
{
    disenio_jugador2=3;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void  Nivel3::on_Mujer1_clicked()
{
    disenio_jugador2=4;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

