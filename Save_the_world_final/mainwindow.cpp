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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Nivel_1 *nivel_1 = new Nivel_1;
    nivel_1->setDatos_partida_1(this->datos_partida);
    nivel_1->show();
    this->hide();

//    Nivel2 *nivel_2 = new Nivel2;
//    nivel_2->setDatos_partida(this->datos_partida);
//    nivel_2->show();
//    this->hide();

//    Nivel3 *nivel_3 = new Nivel3;
//    nivel_3->setDatos_juego(this->datos_partida);
//    nivel_3->show();
//    this->hide();

}

void MainWindow::on_pushButton_2_clicked()
{
//    datos_partida.setModo(2);
//    datos_partida.setPuntaje(0);
//    datos_partida.setSemilla(1);
}

void MainWindow::on_pushButton_3_clicked()
{

}
