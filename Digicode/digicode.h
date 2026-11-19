#ifndef DIGICODE_H
#define DIGICODE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Digicode;
}
QT_END_NAMESPACE

class Digicode : public QWidget
{
    Q_OBJECT

public:
    explicit Digicode(QWidget *parent = nullptr);
    ~Digicode() override;

private:
    Ui::Digicode *ui;
};
#endif // DIGICODE_H
