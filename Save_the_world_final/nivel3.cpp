#include "nivel3.h"
#include "ui_nivel3.h"

Nivel3::Nivel3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Nivel3)
{
    ui->setupUi(this);
}

Nivel3::~Nivel3()
{
    delete ui;
}
