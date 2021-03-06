#include "nivel2.h"
#include "ui_nivel2.h"
#define RUTA_FICHEROS "Ficheros.txt"
#define FICHEROS_RESPALDO "Respaldo.txt"

Nivel2::Nivel2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Nivel2)
{
    ui->setupUi(this);
    h_limit = 800;
    v_limit = 600;

    //************ Definicion de escena en la que se va a jugar *****************
    scene->setSceneRect(0,0,h_limit,v_limit); // Tamaño de la escena
    ui->graphicsView->setScene(scene);
    ui->centralwidget->adjustSize();
    scene->addRect(scene->sceneRect());
    ui->graphicsView->resize(scene->width(),scene->height());
    this->resize(ui->graphicsView->width(),ui->graphicsView->height()); //La ventana toma el tamaño de la escena
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //***************************************************************************

    setStyleSheet("Nivel2 {background-image:url(:/new/Imagenes/Fondo.jpg)}"); //Fondo que tiene la ventana

    //************ Definicion de escena en la que se muestran los graphicsView_2 *****************
    scene_2->setSceneRect(0,0,902,700);
    ui->graphicsView_2->setScene(scene_2);
    ui->centralwidget->adjustSize();
    scene_2->addRect(scene_2->sceneRect());
    ui->graphicsView_2->resize(902,605);
    ui->graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //**************************************************************************************

    //Se ocultan los botones que no se necesitan en el momento
    ui->Volver->hide();
    ui->graphicsView->hide();
    ui->graphicsView_2->hide();
    ui->Salir->move(350,530);
    ui->Siguiente->hide();
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
    ui->Rojo->hide();
    ui->Rojo1->hide();
    //********************************************************

    //***** Se crean los timer y se conectan con sus respectivas funciones *********
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

    win = new QTimer;
    connect(win,SIGNAL(timeout()),this,SLOT(victory()));
    //*****************************************************************************
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
    /* Recorre la lista de balas y llama al metodo que
     * cambia su posicion. */
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
    /* Detecta cuando una bala sale de la pantalla , si este
     * es el caso, la elimina. */
    Bala_parabolica *b = balas.at(i)->getBala();
    if (b->getPx()<0 || b->getPx()>h_limit-b->getR() || b->getPy()<b->getR() ){
        scene->removeItem(balas.at(i));
        balas.removeAt(i);

    }
}

void Nivel2::spawn()
{
    // Crea a los enemigos normales
    enemigos.push_back(new Enemigo_normal(2));
    scene->addItem(enemigos.back());
    N_enemigos++;

    if(N_enemigos>=Total_enemigos){
        /* Una vez llegado al limite de enemigos
         * se detiene el timer para que no se creen mas */
        crear_enemigos->stop();
    }
}

void Nivel2::move_enemy()
{
    // Se encarga de mover a los enemigos normales
    for(int i=0;i<enemigos.size();i++){
        enemigos.at(i)->left();
        // En caso de que lleguen al bosque los pierden vidas
        if(enemigos.at(i)->getPosx()<=0){
            scene->removeItem(enemigos.at(i));
            enemigos.removeAt(i);
            vida->decrease_vida(1);
        }
    }
}

void Nivel2::spawn_jump()
{
    // Genera a los enemigos saltarines
    enemigos_s.push_back(new Enemigo_graf(0,2));
    scene->addItem(enemigos_s.back());
    N_enemigos++;

    /* Una vez llegado al limite de enemigos
     * se detiene el timer para que no se creen mas */
    if(N_enemigos>=Total_enemigos){
        crear_enemigos_s->stop();
    }
}

void Nivel2::move_enemy_jump()
{
    // Se encarga de mover a los enemigos saltarines
    for(int i=0;i<enemigos_s.size();i++){
        enemigos_s.at(i)->actualizar(v_limit);
        enemigos_s.at(i)->Actualizacion();
        borderCollision(i);
    }
}

void Nivel2::victory()
{
    /* Varible para sumar el puntaje obtenido por los jugadores
     * y sumarlo al global. */
    int puntaje_total = datos_partida.getPuntaje();

    //************* Verifica la victoria ****************
    if(enemigos.size()==0 && enemigos_s.size()==0 && crear_enemigos->isActive()==false && crear_enemigos_s->isActive()==false){

        //*** Se limpian las listas ***
        ui->graphicsView->hide();
        balas.clear();
        enemigos_s.clear();
        enemigos.clear();
        jugadores.clear();
        //*****************************

        //*** Se detienen los timer ***
        timer->stop();
        crear_enemigos->stop();
        mover_enemigos->stop();
        crear_enemigos_s->stop();
        mover_enemigos_s->stop();
        win->stop();
        //*****************************

        //*********** Se suma el puntaje obtenido y se suma al global *************
        puntaje_total += puntaje1->getAnuncio();
        if(datos_partida.getModo() == 2){puntaje_total += puntaje2->getAnuncio();}
        datos_partida.setPuntaje(puntaje_total);
        puntaje_total = 0;
        datos_partida.setSemilla(3);
        //*************************************************************************

        //********* Se muestra la escena que contiene las felicitaciones ****************
        ui->Salir->show();
        ui->Salir->move(500,340);
        ui->Siguiente->show();
        scene_2->setSceneRect(0,0,497,700);
        ui->graphicsView_2->setScene(scene_2);
        ui->centralwidget->adjustSize();
        scene_2->addRect(scene_2->sceneRect());
        ui->graphicsView_2->show();
        ui->graphicsView_2->resize(497,700);
        this->resize(ui->graphicsView_2->width()+105,ui->graphicsView_2->height());
        ui->graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scene_2->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Ganar_nivel2.jpg")));
        //*******************************************************************************

        scene->clear(); // Se limpia la escena del juego
    }

    //************** Verifica la derrota ***************************
    else if (vida->getVida() <= 0){
        scene->removeItem(vida);
        //*** Evalula la cantidad de jugadores para eliminarlos ***
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
        //**********************************************************

        //*** Se limpian las listas ***
        ui->graphicsView->hide();
        balas.clear();
        enemigos_s.clear();
        enemigos.clear();
        jugadores.clear();
        //*****************************

        //**** Se detienen los timer ****
        timer->stop();
        crear_enemigos->stop();
        mover_enemigos->stop();
        crear_enemigos_s->stop();
        mover_enemigos_s->stop();
        win->stop();
        //*******************************

        //*********** Se muestra la escena que contiene el mensaje de derrota ****************
        scene_2->clear();
        scene_2->setSceneRect(0,0,497,700);
        ui->graphicsView_2->setScene(scene_2);
        ui->centralwidget->adjustSize();
        scene_2->addRect(scene_2->sceneRect());
        ui->graphicsView_2->show();
        ui->graphicsView_2->resize(497,700);
        this->resize(ui->graphicsView_2->width()+105,ui->graphicsView_2->height());
        ui->graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scene_2->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Perder_nivel2.jpg")));
        ui->Salir->show();
        ui->Salir->move(500,340);
        ui->Reiniciar->show();
        //*************************************************************************************

        scene->clear();
    }
}

void Nivel2::borderCollision(int i)
{
    // Analiza la colision de los enemigos con los bordes de la escena
    Enemigo_fisica *b = enemigos_s.at(i)->getEnemy();

    // Verifica cuando el enemigo llega al bosque y baja la vida del jugador
    if (b->getPx()<0){
        scene->removeItem(enemigos_s.at(i));
        enemigos_s.removeAt(i);
        vida->decrease_vida(2);
        if (vida->getVida() == 0){
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
    // Se verifica la posicion del enemigo y le da movimiento
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
    //Verifica cuando las balas chocan con los enemigos y aumenta el puntaje
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

void Nivel2::on_Iniciar_clicked()
{
    // Boton que da inicio a la partida

    ui->Iniciar->hide();
    ui->Instrucciones->hide();
    ui->graphicsView->show();
    ui->Configurar->hide();

    ui->Salir->hide();
    if (fondo2 == 0)
        scene->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Bosque.jpg")));
    else
        scene->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Bosque_noche.jpg")));

    // Modo solitario
    if(datos_partida.getModo()==1){
        Total_enemigos = 30;
        jugadores.push_back(new Personaje(nullptr,disenio_jugador1,2,40,540));scene->addItem(jugadores.back());
        vida = new Vida_II;
        vida->setPos(710,40);
        scene->addItem(vida);
        puntaje1 = new Anuncio(0,Color,1,16,2);
        puntaje1->setPos(670,540);
        scene->addItem(puntaje1);
        velocidad_1 = new Anuncio(0,Color,2,10,2);
        velocidad_1->setPos(0,575);
        scene->addItem(velocidad_1);
        timer->start(20);
        crear_enemigos->start(2000);
        mover_enemigos->start(20);
        crear_enemigos_s->start(5000);
        mover_enemigos_s->start(15);
    }
    // Modo multijugador
    else{
        Total_enemigos = 60;
        jugadores.push_back(new Personaje(nullptr,disenio_jugador1,2,40,540));scene->addItem(jugadores.back());
        vida = new Vida_II;
        vida->setPos(710,40);
        scene->addItem(vida);
        puntaje1 = new Anuncio(0,Color,1,16,2);
        puntaje1->setPos(670,540);
        scene->addItem(puntaje1);
        velocidad_1 = new Anuncio(0,Color,2,10,2);
        velocidad_1->setPos(0,575);
        scene->addItem(velocidad_1);
        jugadores.push_back(new Personaje(nullptr,disenio_jugador2,2,40,470));scene->addItem(jugadores.back());
        puntaje2 = new Anuncio(0,Color_2,1,16,2);
        puntaje2->setPos(670,470);
        scene->addItem(puntaje2);
        velocidad_2 = new Anuncio(0,Color_2,2,10,2);
        velocidad_2->setPos(0,500);
        scene->addItem(velocidad_2);
        timer->start(20);
        crear_enemigos->start(1500);
        mover_enemigos->start(25);
        crear_enemigos_s->start(3000);
        mover_enemigos_s->start(20);
    }
    win->start(10);
}

void Nivel2::on_Instrucciones_clicked()
{
    // Boton que muestra las instrucciones en pantalla
    ui->Iniciar->hide();
    ui->Instrucciones->hide();
    ui->graphicsView_2->show();
    this->resize(ui->graphicsView_2->width(),ui->graphicsView_2->height());
    scene_2->setBackgroundBrush(QBrush(QImage(":/new/Imagenes/Instrucciones2.jpg")));
    ui->Volver->show();
    ui->Salir->hide();
    ui->Configurar->hide();
}

void Nivel2::on_Volver_clicked()
{
    // Boton que permite al jugador regresar al menu de nivel
    this->resize(ui->graphicsView->width(),ui->graphicsView->height());
    scene_2->clear();
    ui->graphicsView_2->hide();
    ui->Iniciar->show();
    ui->Instrucciones->show();
    ui->Configurar->show();
    ui->Volver->hide();
    ui->Salir->show();
    ui->Fondo->hide();
    ui->Jugador1->hide();
    ui->Jugador2->hide();
    ui->Fondo1->hide();
    ui->Fondo2->hide();
    ui->Azul->hide();
    ui->Azul1->hide();
    ui->Verde->hide();
    ui->Verde1->hide();
    ui->Rojo->hide();
    ui->Rojo1->hide();
}

void Nivel2::on_Salir_clicked()
{
    // Guarda los datos del usuario cuando el jugador gana y lo lleva al menu principal
    if (datos_partida.getSemilla()==3){
        QFile file(RUTA_FICHEROS);           //Objeto para manejar la lectura del archivo
        file.open(QIODevice::ReadOnly);     //Abre el archiv en modo lectura
        QList <QString> datos;

        QFile filer(FICHEROS_RESPALDO);
        filer.open(QIODevice::WriteOnly);
        QString Nombre = QString::fromStdString(datos_partida.getNombre_equipo());
        QString Clave = QString::fromStdString(datos_partida.getClave());
        QString Modo= QString::number(datos_partida.getModo());
        QString Semilla = QString::number(datos_partida.getSemilla());
        QString Puntaje = QString::number(datos_partida.getPuntaje());

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
    MainWindow *Menu = new MainWindow;
    Menu->show();
    this->~Nivel2();
}

void Nivel2::on_Siguiente_clicked()
{
    // Guarda los usuario cuando gana y le permite avanzar al siguiente nivel

    QFile file(RUTA_FICHEROS);           //Objeto para manejar la lectura del archivo
    file.open(QIODevice::ReadOnly);     //Abre el archiv en modo lectura
    QList <QString> datos;

    QFile filer(FICHEROS_RESPALDO);
    filer.open(QIODevice::WriteOnly);
    QString Nombre = QString::fromStdString(datos_partida.getNombre_equipo());
    QString Clave = QString::fromStdString(datos_partida.getClave());
    QString Modo= QString::number(datos_partida.getModo());
    QString Semilla = QString::number(datos_partida.getSemilla());
    QString Puntaje = QString::number(datos_partida.getPuntaje());

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

    // Se crea el nivel 3
    Nivel3 *nivel_3 = new Nivel3;
    nivel_3->setDatos_juego(this->datos_partida);
    nivel_3->show();
    this->~Nivel2();
}

void Nivel2::on_Reiniciar_clicked()
{
    // Dado el caso de que el jugador haya perdido, le da la posibilidad de repetir el nivel

    scene_2->setSceneRect(0,0,902,605);
    ui->graphicsView_2->setScene(scene_2);
    ui->centralwidget->adjustSize();
    scene_2->addRect(scene_2->sceneRect());
    ui->graphicsView_2->resize(902,605);

    N_enemigos=0;
    Total_enemigos=0;
    this->resize(ui->graphicsView->width(),ui->graphicsView->height());
    scene_2->clear();
    ui->graphicsView_2->hide();
    ui->Reiniciar->hide();
    ui->Salir->move(350,530);
    ui->Iniciar->show();
    ui->Instrucciones->show();
    ui->Configurar->show();
}

void Nivel2::on_Configurar_clicked()
{
    ui->Configurar->hide();
    ui->Iniciar->hide();
    ui->Instrucciones->hide();
    ui->Fondo->show();
    ui->Jugador1->show();
    ui->Salir->hide();

    ui->Fondo1->show();
    ui->Fondo2->show();
    ui->Azul->show();
    ui->Verde->show();
    ui->Rojo->show();

    if (datos_partida.getModo()==2){
        ui->Jugador2->show();
        ui->Azul1->show();
        ui->Verde1->show();
        ui->Rojo1->show();
    }

    ui->Volver->show();

}

void Nivel2::on_Fondo1_clicked()
{
    fondo2=0;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void Nivel2::on_Fondo2_clicked()
{
    fondo2=1;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void Nivel2::on_Azul_clicked()
{
    disenio_jugador1=1;
    Color = 0;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void Nivel2::on_Rojo_clicked()
{
    disenio_jugador1=0;
    Color = 4;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void Nivel2::on_Verde_clicked()
{
    disenio_jugador1=2;
    Color = 3;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void Nivel2::on_Azul1_clicked()
{
    disenio_jugador2=1;
    Color_2 = 0;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void Nivel2::on_Rojo1_clicked()
{
    disenio_jugador2=0;
    Color_2 = 4;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}

void Nivel2::on_Verde1_clicked()
{
    disenio_jugador2=2;
    Color_2 = 3;
    msgBox.setText("Configuración guardada");
    msgBox.exec();
}
