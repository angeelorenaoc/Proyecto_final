#include "nivel_1.h"
#include "ui_nivel_1.h"

Nivel_1::Nivel_1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Nivel_1)
{
    ui->setupUi(this);
}

Nivel_1::~Nivel_1()
{
    delete ui;
}
