#include "porte.h"
#include "ui_porte.h"

Porte::Porte(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Porte)
{
    ui->setupUi(this);
    Verrouiller();
}

Porte::~Porte()
{
    delete ui;
}

void Porte::Deverrouiller()
{
    ui->labelImage->setPixmap(QPixmap(":/img/images/porte_ouverte.png"));
    ui->labelEtat->setText("La porte est déverrouillée");
}

void Porte::Verrouiller()
{
    ui->labelImage->setPixmap(QPixmap(":/img/images/porte_fermee.png"));
    ui->labelEtat->setText("La porte est verrouillée");
}
