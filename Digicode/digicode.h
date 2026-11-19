#ifndef DIGICODE_H
#define DIGICODE_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QJSEngine>
#include <QMessageBox>
#include <QTimer>
#include "porte.h"
#include <QDebug>

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui {
class Porte;
class Digicode;
}
QT_END_NAMESPACE

class Digicode : public QWidget
{
    Q_OBJECT

public:
    explicit Digicode(QWidget *parent = nullptr);
    ~Digicode() override;
    int NB_TOUCHES;
    void onQPushButtonClicked();
private slots:
    void onTimerTempoGache_timeout();
private:
    Ui::Digicode *ui;
    QPushButton **touches;
    QLineEdit *afficheur;
    QGridLayout *grille;
    QString code;
    QString codeSecret;
    Porte *laPorte;
    QTimer tempoGache;
};
#endif // DIGICODE_H
