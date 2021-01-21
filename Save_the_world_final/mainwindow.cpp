#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    qDebug()<<datos_partida.getClave()<<datos_partida.getPuntaje()<<datos_partida.getSemilla()<<datos_partida.getModo();

    Nivel_1 *nivel_1 = new Nivel_1;
    nivel_1->setDatos_partida_1(this->datos_partida);
    nivel_1->show();
    //this->hide();


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
