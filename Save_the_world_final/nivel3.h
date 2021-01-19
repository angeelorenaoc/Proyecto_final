#ifndef NIVEL3_H
#define NIVEL3_H

#include <QMainWindow>

namespace Ui {
class Nivel3;
}

class Nivel3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Nivel3(QWidget *parent = nullptr);
    ~Nivel3();

private:
    Ui::Nivel3 *ui;
};

#endif // NIVEL3_H
