#include "nivel_1.h"
#include "ui_nivel_1.h"
#define RUTA_MURO ":/new/Archivos_texto/Muros_N1.txt"
#define RUTA_FICHEROS "Ficheros.txt"
#define FICHEROS_RESPALDO "Respaldo.txt"

Nivel_1::Nivel_1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Nivel_1)
{
    ui->setupUi(this);

    //Escena
    h_limit = 962;
    v_limit = 642;

    //******************* Definicion de escena1 ********************************
    scene_1->setSceneRect(0,0,h_limit,v_limit);
    ui->Game->setScene(scene_1);
    ui->centralwidget->adjustSize();
    scene_1->addRect(scene_1->sceneRect());
    ui->Game->resize(800,600);
    this->resize(ui->Game->width(),ui->Game->height());
    ui->Game->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->Game->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setStyleSheet("Nivel_1 {background-image:url(:/new/Imagenes/Fondo.jpg)}");
    //**************************************************************************

    //**************** Definicion de la escena 2 ***********************
    scene_2->setSceneRect(0,0,700,700);
    ui->Anuncios->setScene(scene_2);
    ui->centralwidget->adjustSize();
    scene_2->addRect(scene_2->sceneRect());
    ui->Anuncios->resize(700,700);
    ui->Anuncios->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->Anuncios->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //******************************************************************

    //Se esconden los botones
    ui->Game->hide();   
    ui->Anuncios->hide();
    ui->Volver->hide();
    ui->Siguiente_nivel->hide();
    ui->Anuncios->hide();
    ui->Reiniciar->hide();
    ui->Fondo->hide();
    ui->Jugador1->hide();
    ui->Jugador2->hide();
    ui->Fondo1->hide();
    ui->Fondo2->hide();
    ui->Azul->hide();
    ui->Azul1->hide();
    ui->Verde->hide();
    ui->Verde1->hide();
    ui->Rosado->hide();
    ui->Rosado1->hide();
    ui->Morado->hide();
    ui->Morado1->hide();


    //******************* Se definen los timer ********************************
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

    Ganar = new QTimer();
    connect(Ganar,SIGNAL(timeout()),this,SLOT(Verificacion_Ganar()));
    //***************************************************************************

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
    //Se manejan las teclas para el movimiento
    if(N_jugadores==1){
        if(jugadores.size()>0){
            Personaje *player = jugadores.at(0);

            if(event->key()== Qt::Key_A){
                player->left();
                if(player_collides(player))//Verifica la colision con el muro
                    player->right();

                sentido_bala=1;//Cambia el sentido de la bala
            }
            if(event->key() == Qt::Key_D){
                player->right();
                if(player_collides(player))//Verifica la colision con el muro
                    player->left();

                sentido_bala=2;//Cambia el sentido de la bala
            }
            if(event->key() == Qt::Key_W){
                player->up();
                if(player_collides(player))//Verifica la colision con el muro
                    player->down();

                sentido_bala=3;//Cambia el sentido de la bala
            }
            if(event->key() == Qt::Key_S){
                player->down();
                if(player_collides(player))//Verifica la colision con el muro
                    player->up();

                sentido_bala=4;//Cambia el sentido de la bala
            }
            if(event->key() == Qt::Key_Space){//Se crea la bala
                disparos.push_back(new Bala_normal(sentido_bala));
                disparos.back()->setId(1);
                disparos.back()->setPos(player->getPosx(),player->getPosy());
                scene_1->addItem(disparos.back());
            }
            if(event->key() == Qt::Key_E){//Se activa el escudo
                if(Cooldown)
                    spawn_shield(player);
            }
            ui->Game->centerOn(player->x(),player->y());
//            vida_J1->setPx(player->getPosx()-20); vida_J1->setPy(player->getPosy()+20);
//            vida_J1->setPos(vida_J1->getPx(),vida_J1->getPy());
        }
    }
    //Para el jugador 2
    else if(N_jugadores==2){
        if(jugadores.size()>0){

            Personaje *player;
            if(vida_J1->getAnuncio()>0){
                player = jugadores.at(0);

                if(event->key()== Qt::Key_A){
                    player->left();
                    if(player_collides(player))//Se verifica la colision con los muros
                        player->right();
                    sentido_bala=1;//Cambia el sentido de la bala
                }
                if(event->key() == Qt::Key_D){
                    player->right();
                    if(player_collides(player))//Se verifica la colision con los muros
                        player->left();
                    sentido_bala=2;//Cambia el sentido de la bala
                }
                if(event->key() == Qt::Key_W){
                    player->up();
                    if(player_collides(player))//Se verifica la colision con los muros
                        player->down();
                    sentido_bala=3;//Cambia el sentido de la bala
                }
                if(event->key() == Qt::Key_S){
                    player->down();
                    if(player_collides(player))//Se verifica la colision con los muros
                        player->up();
                    sentido_bala=4;//Cambia el sentido de la bala
                }
                if(event->key() == Qt::Key_Space){//Se crea la bala
                    disparos.push_back(new Bala_normal(sentido_bala));
                    disparos.back()->setPos(player->getPosx(),player->getPosy());
                    disparos.back()->setId(1);
                    scene_1->addItem(disparos.back());
                }
                if(event->key() == Qt::Key_E){//Se crea el escudo
                    if(Cooldown)
                        spawn_shield(player);
                }
                ui->Game->centerOn(player->x(),player->y());
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
                ui->Game->centerOn(player_two->x(),player_two->y());
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
    //Se comprueba si el jugador colisiona con alguno de los muros.
    for(int i=0;i<muros.size();i++){
        if(P->collidesWithItem(muros.at(i))){
            return true;
        }
    }
    return false;
}

void Nivel_1::bullet_impact()
{
    //Cuando las balas colisionan con los enemigos.
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

    //Cuando las balas colisionan con los muros.
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
    //********Creacion de los enemigos*********
    enemigos.push_back(new Enemigo_normal(1));
    scene_1->addItem(enemigos.back());
    N_enemigos++;

    if(N_enemigos>=Lim_enemigos){
        enemy_timer->stop();
    }
    //*****************************************
}

void Nivel_1::perseguir()
{
    //Busca al jugador mas cercano para perseguirlo
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
    //***Movimiento del enemigo*********************
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
        // Comprobacion de la derrota para los jugadores
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
        Ganar->stop();

        ui->Game->hide();
        scene_2->clear();
        ui->Anuncios->show();
        ui->Anuncios->resize(467,700);
        this->resize(ui->Anuncios->width(),ui->Anuncios->height());
        ui->Anuncios->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->Anuncios->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scene_2->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Perder_nivel1.jpg")));
        ui->Salir->show();
        ui->Reiniciar->show();
        ui->Anuncios->show();

        scene_1->clear();
    }
    //**********************************************
}

bool Nivel_1::enemy_collides(Enemigo_normal *E)
{
    //***Se comprueba si el enemigo colisiona con un muro***
    for(int i=0;i<muros.size();i++){
        if(E->collidesWithItem(muros.at(i))){
            return true;
        }
    }
    return false;
    //******************************************************
}

void Nivel_1::spawn_shield(Personaje *P)
{
    // Generar los escudos y ponerlos en pantalla
    Cooldown = false; // Bandandera que impide que se vuelva a activar la habilidad
    Cooldown_timer->stop(); // Se pausa el tiempo de reactivacion de habilidad

    // Se crea los escudos y los coloca en pantalla
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

    // Se inicia el tiempo que habilidad dura en pantalla
    tiempo_de_habilidad->start(5000);
}

void Nivel_1::actualizar_escudos()
{
    // Se actualiza la posicion y velocidad de los escudos
    for(int i=0; i<escudos.size();i++){
        for(int j=0; j<escudos.size();j++){
            if(i!=j){
                escudos.at(i)->getEsf()->acelerar(escudos.at(j)->getEsf()->getPX(),escudos.at(j)->getEsf()->getPY(),escudos.at(j)->getEsf()->getMasa());
                escudos.at(i)->actualizar(dt);
            }
        }
    }

    // Se verifica la colision con los enemigos
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

    // Se verifica la colision con los muros
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
    // Una vez se cumple su tiempo en pantalla se eliminan los escudos
    for (int i=0;i<escudos.size();i++) {
        scene_1->removeItem(escudos.at(i));
        tiempo_de_habilidad->stop();
    }
    escudos.clear();
    Cooldown_timer->start(5000);
}

void Nivel_1::estado_de_habilidad()
{
    // Cambia el estado de habilidad
    if(!Cooldown)
        Cooldown=true;
}

void Nivel_1::Verificacion_Ganar()
{
    // Chequea si el jugador gano el nivel.
    int puntaje_total = 0;
    if(enemigos.size()==0 && enemy_timer->isActive()==false){
        if(vida_J1->getAnuncio()>0){
            ui->Game->hide();

            jugadores.clear();
            muros.clear();
            escudos.clear();
            disparos.clear();
            puntaje_total += puntaje_J1->getAnuncio();

            shield->stop();
            timer_move->stop();
            enemy_timer->stop();
            bullet_timer->stop();
            Cooldown_timer->stop();
            tiempo_de_habilidad->stop();
            Ganar->stop();
            scene_2->clear();
            ui->Anuncios->show();
            ui->Anuncios->resize(467,700);
            this->resize(ui->Anuncios->width()+130,ui->Anuncios->height());
            ui->Anuncios->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            ui->Anuncios->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            scene_2->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Ganar_nivel1.jpg")));
            ui->Salir->show();
            ui->Salir->move(470,330);
            ui->Siguiente_nivel->show();
            ui->Siguiente_nivel->move(470,380);

            scene_1->clear();
        }

        if(N_jugadores==2){
            if(vida_J2->getAnuncio()>0){
                ui->Game->hide();
                scene_1->clear();

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
                Ganar->stop();
                puntaje_total += puntaje_J2->getAnuncio();

                scene_2->clear();
                ui->Anuncios->show();
                ui->Anuncios->resize(467,700);
                this->resize(ui->Anuncios->width()+130,ui->Anuncios->height());
                ui->Anuncios->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                ui->Anuncios->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                scene_2->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Ganar_nivel1.jpg")));
                ui->Salir->show();
                ui->Salir->move(470,330);
                ui->Siguiente_nivel->show();
                ui->Siguiente_nivel->move(470,380);
            }
        }
        datos_partida_1.setPuntaje(puntaje_total);
        datos_partida_1.setSemilla(2);
        puntaje_total=0;
    }
}

void Nivel_1::inmunidad()
{
    //Esta inmunidad se le da al jugador cuando se pone en escena.
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

void Nivel_1::on_Inicio_clicked()
{
    //Boton que inicia el nivel
    ui->Inicio->hide();
    ui->Instrucciones->hide();
    ui->Salir->hide();
    ui->Game->show();
    ui->Configurar->hide();
    if (fondo1 == 0)
         scene_1->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Laboratorio_Oak.jpg")));
    else
        scene_1->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Laboratorio_Oak_2.jpg")));

    /*QString info;*/                       //String para leer los datos del archivo

    QFile file(RUTA_MURO);           //Objeto para manejar la lectura del archivo
    file.open(QIODevice::ReadOnly);     //Abre el archiv en modo lectura

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
        muros.push_back(new Muro(dats.at(0).toInt(),dats.at(1).toInt(),dats.at(2).toInt(),dats.at(3).toInt(),dats.at(4).toInt()));scene_1->addItem(muros.back());
        dats.clear();
        n = 0;
    }
    file.close();

    //Modo solitario.
    if(datos_partida_1.getModo()==1){
        jugadores.push_back(new Personaje(0,disenio_jugador1,1,490,400));
        scene_1->addItem(jugadores.back());
        N_jugadores++;
        ui->Game->centerOn(jugadores.at(0)->x(),jugadores.at(0)->y());

        vida_J1 = new Anuncio(0,0,0,10,1);
        vida_J1->setPx(600); vida_J1->setPy(-300);
        vida_J1->setPos(vida_J1->getPx(),vida_J1->getPy());
        scene_1->addItem(vida_J1);
        puntaje_J1 = new Anuncio(0,0,1,15,1);
        puntaje_J1->setPos(600,300);
        scene_1->addItem(puntaje_J1);


        Lim_enemigos = 30;
        timer_move->start(35);
        enemy_timer->start(1000);
        bullet_timer->start(50);
        shield->start(50);
    }
    //Modo multijuador
    else{
        jugadores.push_back(new Personaje(0,disenio_jugador2,1,470,400));
        scene_1->addItem(jugadores.back());
        N_jugadores++;
        ui->Game->centerOn(jugadores.at(0)->x(),jugadores.at(0)->y());
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

            Lim_enemigos=50;
            timer_move->start(20);
            enemy_timer->start(900);
        }
        bullet_timer->start(50);
        shield->start(50);
    }
    Ganar->start(10);
}

void Nivel_1::on_Instrucciones_clicked()
{
    ui->Inicio->hide();
    ui->Salir->hide();
    ui->Instrucciones->hide();
    ui->Siguiente_nivel->hide();
    ui->Volver->show();
    ui->Configurar->hide();
    ui->Anuncios->show();
    this->resize(ui->Anuncios->width(),ui->Anuncios->height());
    scene_2->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Instrucciones_1.jpg")));
    ui->Volver->show();
}

void Nivel_1::on_Volver_clicked()
{
    //Vuelve al inicio del nivel.
    this->resize(ui->Game->width(),ui->Game->height());
    scene_2->clear();
    ui->Anuncios->hide();
    ui->Inicio->show();
    ui->Instrucciones->show();
    ui->Volver->hide();
    ui->Salir->show();
    ui->Configurar->show();

    ui->Fondo->hide();
    ui->Jugador1->hide();
    ui->Fondo1->hide();
    ui->Fondo2->hide();
    ui->Azul->hide();
    ui->Verde->hide();
    ui->Rosado->hide();
    ui->Morado->hide();
    if (datos_partida_1.getModo()==2){
        ui->Jugador2->hide();
        ui->Morado1->hide();
        ui->Azul1->hide();
        ui->Verde1->hide();
        ui->Rosado1->hide();
    }
}

void Nivel_1::on_Reiniciar_clicked()
{
    //Si el jugador pierde, se la da la posibilidad de volver a jugar el nivel
    N_enemigos=0;
    N_jugadores=0;
    sentido_bala=4;
    sentido_bala_two=4;
    inmune = false;
    Cooldown = true;
    this->resize(ui->Game->width(),ui->Game->height());
    ui->Anuncios->resize(700,700);
    scene_2->clear();
    ui->Anuncios->hide();
    ui->Reiniciar->hide();
    ui->Inicio->show();
    ui->Instrucciones->show();
    ui->Configurar->show();
}

void Nivel_1::on_Siguiente_nivel_clicked()
{
    //Boton que permite pasar al siguiente nivel
    QFile file(RUTA_FICHEROS);           //Objeto para manejar la lectura del archivo
    file.open(QIODevice::ReadOnly);     //Abre el archiv en modo lectura
    QList <QString> datos;

    QFile filer(FICHEROS_RESPALDO);
    filer.open(QIODevice::WriteOnly);
    QString Nombre = QString::fromStdString(datos_partida_1.getNombre_equipo());
    QString Clave = QString::fromStdString(datos_partida_1.getClave());
    QString Modo= QString::number(datos_partida_1.getModo());
    QString Semilla = QString::number(datos_partida_1.getSemilla());
    QString Puntaje = QString::number(datos_partida_1.getPuntaje());

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
        QTextStream out(&filer);
        if(Name == Nombre){
            out << Nombre<<" "<<Clave<<" "<<Modo<<" "<<Semilla<<" "<<Puntaje<<"\n";
        }
        else{        
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

    // Creación de la escena para el nivel 2.
    Nivel2 *nivel_2 = new Nivel2;
    nivel_2->setDatos_partida(this->datos_partida_1);
    nivel_2->show();
    this->~Nivel_1();
}

void Nivel_1::on_Salir_clicked()
{
    /*En el caso de que haya ganado se guarda la partida y se dirige al menu principal,
     * sino solo lo dirige al menu principal*/
    if (datos_partida_1.getSemilla()==2){
        QFile file(RUTA_FICHEROS);           //Objeto para manejar la lectura del archivo
        file.open(QIODevice::ReadOnly);     //Abre el archiv en modo lectura
        QList <QString> datos;

        QFile filer(FICHEROS_RESPALDO);
        filer.open(QIODevice::WriteOnly);
        QString Nombre = QString::fromStdString(datos_partida_1.getNombre_equipo());
        QString Clave = QString::fromStdString(datos_partida_1.getClave());
        QString Modo= QString::number(datos_partida_1.getModo());
        QString Semilla = QString::number(datos_partida_1.getSemilla());
        QString Puntaje = QString::number(datos_partida_1.getPuntaje());

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
    this->hide();
    //Creacion del menu principal
    MainWindow *Menu = new MainWindow;
    Menu->show();
    this->~Nivel_1();
}

void Nivel_1::on_Configurar_clicked()
{
    // Se presetan las config
    ui->Configurar->hide();
    ui->Inicio->hide();
    ui->Instrucciones->hide();
    ui->Fondo->show();
    ui->Salir->hide();
    ui->Jugador1->show();

    ui->Fondo1->show();
    ui->Fondo2->show();
    ui->Azul->show();
    ui->Verde->show();
    ui->Rosado->show();
    ui->Morado->show();

    if (datos_partida_1.getModo()==2){
        ui->Jugador2->show();
        ui->Azul1->show();
        ui->Morado1->show();
        ui->Verde1->show();
        ui->Rosado1->show();
    }

    ui->Volver->show();

}

void Nivel_1::on_Fondo1_clicked()
{
    fondo1=0;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void Nivel_1::on_Fondo2_clicked()
{
    fondo1=1;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void Nivel_1::on_Azul_clicked()
{
    disenio_jugador1=0;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void Nivel_1::on_Rosado_clicked()
{
    disenio_jugador1=2;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void Nivel_1::on_Verde_clicked()
{
    disenio_jugador1=1;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void Nivel_1::on_Morado_clicked()
{
    disenio_jugador1=3;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void Nivel_1::on_Azul1_clicked()
{
    disenio_jugador2=0;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void Nivel_1::on_Rosado1_clicked()
{
    disenio_jugador2=2;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void Nivel_1::on_Verde1_clicked()
{
    disenio_jugador2=1;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void Nivel_1::on_Morado1_clicked()
{
    disenio_jugador1=3;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}
