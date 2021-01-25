#include "mainwindow.h"
#include "ui_mainwindow.h"
#define RUTA_FICHEROS "Ficheros.txt"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setStyleSheet("MainWindow {background-image:url(:/new/Imagenes/Fondo.jpg)}");

    ui->Nombre->hide();
    ui->Clave->hide();
    ui->Botoncontinuar->hide();
    ui->Volver->hide();
    ui->Ingresar->hide();
    ui->Botoncontinuar_2->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::Find(string Nombre, string Clave)
{
    /*QString info;*/                       //String para leer los datos del archivo

    QFile file(RUTA_FICHEROS);           //Objeto para manejar la lectura del archivo
    file.open(QIODevice::ReadOnly);     //Abre el archiv en modo lectura

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
        string Name = datos.at(0).toStdString();
        string Password = datos.at(1).toStdString();
        if(Name == Nombre){
            if(Password == Clave){
                file.close();
                return 2;
            }
            else{
                file.close();
                return 1;
            }

        }
        datos.clear();
        n = 0;
    }
    file.close();
    return 0;
}

void MainWindow::on_Botoncontinuar_clicked()
{
    string Nombre = ui->Nombre->text().toStdString();
    string Clave = ui->Clave->text().toStdString();


    if(Find(Nombre,Clave)==2){
        datos_partida.setNombre_equipo(datos.at(0).toStdString());
        datos_partida.setClave(datos.at(1).toInt());
        datos_partida.setModo(datos.at(2).toInt());
        datos_partida.setSemilla(datos.at(3).toInt());
        datos_partida.setPuntaje(datos.at(4).toInt());
//        qDebug()<<datos_partida.getClave() << datos_partida.getModo() << datos_partida.getSemilla() << datos_partida.getPuntaje();
        if(datos_partida.getSemilla()==1){
            Nivel_1 *nivel_1 = new Nivel_1;
            nivel_1->setDatos_partida_1(this->datos_partida);
            nivel_1->show();
            this->~MainWindow();
        }
        else if(datos_partida.getSemilla()==2){
            Nivel2 *nivel_2 = new Nivel2;
            nivel_2->setDatos_partida(this->datos_partida);
            nivel_2->show();
            this->~MainWindow();
        }
        else{
            Nivel3 *nivel_3 = new Nivel3;
            nivel_3->setDatos_juego(this->datos_partida);
            nivel_3->show();
            this->~MainWindow();
        }
    }
    else{
        msgBox.setText("El usuario no existe. Verifique usuario y contraseña");
        msgBox.exec();
    }
}

void MainWindow::on_Volver_clicked()
{
    ui->Ingresar->hide();
    ui->Nombre->hide();
    ui->Clave->hide();
    ui->Volver->hide();
    ui->Botoncontinuar->hide();
    ui->Solitario->show();
    ui->Multijugador->show();
    ui->CargaPartida->show();
    ui->Seleccionar->show();

}

void MainWindow::on_Solitario_clicked()
{
    ui->Solitario->hide();
    ui->Multijugador->hide();
    ui->CargaPartida->hide();
    ui->Nombre->show();
    ui->Clave->show();
    ui->Botoncontinuar_2->show();

    datos_partida.setModo(1);
}

void MainWindow::on_Multijugador_clicked()
{
    ui->Solitario->hide();
    ui->Multijugador->hide();
    ui->CargaPartida->hide();
    ui->Nombre->show();
    ui->Clave->show();
    ui->Botoncontinuar_2->show();

    datos_partida.setModo(2);
}

void MainWindow::on_CargaPartida_clicked()
{
    ui->Seleccionar->hide();
    ui->Solitario->hide();
    ui->Multijugador->hide();
    ui->CargaPartida->hide();
    ui->Ingresar->show();
    ui->Volver->show();
    ui->Nombre->show();
    ui->Clave->show();
    ui->Botoncontinuar->show();
}

void MainWindow::on_Botoncontinuar_2_clicked()
{
    QString Nombre = ui->Nombre->text();
    QString Clave = ui->Clave->text();

    if(Find(Nombre.toStdString(),Clave.toStdString())==1 || Find(Nombre.toStdString(),Clave.toStdString())==2){
        msgBox.setText("El usuario ya existe, intente con otro nombre");
        msgBox.exec();
    }
    else{
        QFile file(RUTA_FICHEROS);
        file.open(QIODevice::WriteOnly | QIODevice::Text |QIODevice::Append);

        QTextStream out(&file);
        out << Nombre<<" "<<Clave<<" "<<datos_partida.getModo()<<" "<<"1"<<" "<<"0"<<"\n";
        file.flush();
        file.close();

        datos_partida.setSemilla(1);
        datos_partida.setPuntaje(0);

        Nivel_1 *nivel_1 = new Nivel_1;
        nivel_1->setDatos_partida_1(this->datos_partida);
        nivel_1->show();
        this->~MainWindow();
    }
}
