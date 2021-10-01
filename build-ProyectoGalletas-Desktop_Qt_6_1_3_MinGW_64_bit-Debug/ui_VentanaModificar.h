/********************************************************************************
** Form generated from reading UI file 'VentanaModificar.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAMODIFICAR_H
#define UI_VENTANAMODIFICAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Ventana_AgregarPaquete
{
public:
    QPushButton *btn_Aceptar;
    QPushButton *btn_Cancelar;

    void setupUi(QDialog *Ventana_AgregarPaquete)
    {
        if (Ventana_AgregarPaquete->objectName().isEmpty())
            Ventana_AgregarPaquete->setObjectName(QString::fromUtf8("Ventana_AgregarPaquete"));
        Ventana_AgregarPaquete->resize(796, 534);
        btn_Aceptar = new QPushButton(Ventana_AgregarPaquete);
        btn_Aceptar->setObjectName(QString::fromUtf8("btn_Aceptar"));
        btn_Aceptar->setGeometry(QRect(210, 410, 151, 61));
        btn_Cancelar = new QPushButton(Ventana_AgregarPaquete);
        btn_Cancelar->setObjectName(QString::fromUtf8("btn_Cancelar"));
        btn_Cancelar->setGeometry(QRect(430, 410, 151, 61));

        retranslateUi(Ventana_AgregarPaquete);

        QMetaObject::connectSlotsByName(Ventana_AgregarPaquete);
    } // setupUi

    void retranslateUi(QDialog *Ventana_AgregarPaquete)
    {
        Ventana_AgregarPaquete->setWindowTitle(QCoreApplication::translate("Ventana_AgregarPaquete", "Dialog", nullptr));
        btn_Aceptar->setText(QCoreApplication::translate("Ventana_AgregarPaquete", "Aceptar", nullptr));
        btn_Cancelar->setText(QCoreApplication::translate("Ventana_AgregarPaquete", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ventana_AgregarPaquete: public Ui_Ventana_AgregarPaquete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAMODIFICAR_H
