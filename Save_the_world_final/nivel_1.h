#ifndef NIVEL_1_H
#define NIVEL_1_H

#include <QMainWindow>

namespace Ui {
class Nivel_1;
}

class Nivel_1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Nivel_1(QWidget *parent = nullptr);
    ~Nivel_1();

private:
    Ui::Nivel_1 *ui;
};

#endif // NIVEL_1_H
