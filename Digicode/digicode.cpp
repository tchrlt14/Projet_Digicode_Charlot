#include "digicode.h"
#include "ui_digicode.h"

Digicode::Digicode(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Digicode)
{
    ui->setupUi(this);
}

Digicode::~Digicode()
{
    delete ui;
}
