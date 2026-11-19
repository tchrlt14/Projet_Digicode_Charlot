/********************************************************************************
** Form generated from reading UI file 'porte.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORTE_H
#define UI_PORTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Porte
{
public:
    QLabel *labelEtat;
    QLabel *labelImage;

    void setupUi(QDialog *Porte)
    {
        if (Porte->objectName().isEmpty())
            Porte->setObjectName("Porte");
        Porte->resize(400, 300);
        labelEtat = new QLabel(Porte);
        labelEtat->setObjectName("labelEtat");
        labelEtat->setGeometry(QRect(140, 230, 151, 61));
        labelImage = new QLabel(Porte);
        labelImage->setObjectName("labelImage");
        labelImage->setGeometry(QRect(120, 10, 131, 191));

        retranslateUi(Porte);

        QMetaObject::connectSlotsByName(Porte);
    } // setupUi

    void retranslateUi(QDialog *Porte)
    {
        Porte->setWindowTitle(QCoreApplication::translate("Porte", "Dialog", nullptr));
        labelEtat->setText(QString());
        labelImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Porte: public Ui_Porte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTE_H
