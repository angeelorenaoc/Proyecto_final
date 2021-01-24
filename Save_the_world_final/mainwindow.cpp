#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setStyleSheet("MainWindow {background-image:url(:/new/Imagenes/Fondo.jpg)}");

    datos_partida.setNombre_equipo("Juacho");
    datos_partida.setClave(1234);
    datos_partida.setModo(1);
    datos_partida.setPuntaje(0);
    datos_partida.setSemilla(1);

    ui->Nombre->hide();
    ui->Clave->hide();
    ui->Botoncontinuar->hide();
    ui->Volver->hide();
    ui->Ingresar->hide();


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Botoncontinuar_clicked()
{
    QString Nombre = ui->Nombre->text();
    QString Clave = ui->Clave->text();
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
    //    Nivel_1 *nivel_1 = new Nivel_1;
    //    nivel_1->setDatos_partida_1(this->datos_partida);
    //    nivel_1->show();
    //    this->hide();

        Nivel2 *nivel_2 = new Nivel2;
        nivel_2->setDatos_partida(this->datos_partida);
        nivel_2->show();
        this->hide();

//        Nivel3 *nivel_3 = new Nivel3;
//        nivel_3->setDatos_juego(this->datos_partida);
//        nivel_3->show();
//        this->hide();
}

void MainWindow::on_Multijugador_clicked()
{

    //    datos_partida.setModo(2);
    //    datos_partida.setPuntaje(0);
    //    datos_partida.setSemilla(1);
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
