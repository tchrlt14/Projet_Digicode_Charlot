#ifndef PORTE_H
#define PORTE_H

#include <QDialog>

namespace Ui {
class Porte;
}

class Porte : public QDialog
{
    Q_OBJECT

public:
    explicit Porte(QWidget *parent = nullptr);
    ~Porte();

private:
    Ui::Porte *ui;
};

#endif // PORTE_H
