#include "digicode.h"
#include "ui_digicode.h"

Digicode::Digicode(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Digicode)
    ,NB_TOUCHES(12)
{
    codeSecret="1234";
    ui->setupUi(this);
    int colonne=0, ligne=0;
    grille = new QGridLayout(this);
    afficheur = new QLineEdit(this);
    afficheur->setReadOnly(true);
    afficheur->setAlignment(Qt::AlignRight);
    afficheur->setEchoMode(QLineEdit::Password);
    afficheur->setMinimumHeight(80);
    touches = new QPushButton*[NB_TOUCHES];
    int nbColonnes = 4;
    int nbLignes = 3;
    grille->addWidget(afficheur,ligne,colonne,1,3);
    // Création du clavier
    QString TableDesSymboles[4][3] = {{"7","8","9"},{"4","5","6"},
                                      {"1","2","3"},{"On","0","Ok"}};
    this->setLayout(grille);
    for (int i = 0; i<nbColonnes;i++){
        for(int j =0;j<nbLignes;j++){
        touches[i]= new QPushButton(this);
        touches[i]->setText(TableDesSymboles[i][j]);
        touches[i]->setMaximumWidth(80);
        touches[i]->setMaximumHeight(80);
        touches[i]->setStyleSheet("background-color: rgb(128, 128, 128);");
        layout()->addWidget(touches[i]);
    }


    }
    QList<QPushButton*> allButtons = this->findChildren<QPushButton*>();
    foreach(QPushButton* button, allButtons) {
    connect(button, &QPushButton::clicked, this, &Digicode::onQPushButtonClicked);
    }
    connect(&tempoGache,&QTimer::timeout,this,&Digicode::onTimerTempoGache_timeout);
    laPorte = new Porte;
    laPorte->show();

}

Digicode::~Digicode()
{
    delete ui;
}


void Digicode::onQPushButtonClicked()
{
    QPushButton *touche;
    touche=qobject_cast<QPushButton*>(sender());
    QString expression = afficheur->text();
    QString touchetexte = touche->text();

    if(touchetexte != "Ok" && touchetexte != "On") {

        afficheur->setText(expression + touchetexte);
    }
    if(touchetexte == "Ok") {
        for (int j=0;j<4;j++){
            code = afficheur->text();
        }
        if(code==codeSecret){
            QMessageBox messageDeverouillage;
            messageDeverouillage.setText("la porte est dévérouillée");
            messageDeverouillage.exec();
            laPorte->Deverrouiller();
            tempoGache.setSingleShot(true);
            tempoGache.start(3000);
            afficheur->clear();
        }
        else{
            QMessageBox messageFaux;
            messageFaux.setText("Code Faux");
            messageFaux.exec();
        }



    }

    if(touchetexte == "On") {
        afficheur->clear();
    }
}

void Digicode::onTimerTempoGache_timeout()
{
    laPorte->Verrouiller();

}
