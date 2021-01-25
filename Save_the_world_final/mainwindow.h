#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QFile>

#include "nivel_1.h"
#include "nivel2.h"
#include "nivel3.h"
#include "informacion.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int Find(string Nombre, string Clave);

private slots:
    void on_Botoncontinuar_clicked();

    void on_Volver_clicked();

    void on_Solitario_clicked();

    void on_Multijugador_clicked();

    void on_CargaPartida_clicked();

    void on_Botoncontinuar_2_clicked();

    void on_Eliminar_clicked();

    void on_Confirmar_clicked();

private:
    Ui::MainWindow *ui;

    Informacion datos_partida;       

    QList<QString> datos;

    QMessageBox msgBox;
};
#endif // MAINWINDOW_H
