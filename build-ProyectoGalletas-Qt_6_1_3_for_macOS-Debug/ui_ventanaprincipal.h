/********************************************************************************
** Form generated from reading UI file 'ventanaprincipal.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAPRINCIPAL_H
#define UI_VENTANAPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaPrincipal
{
public:
    QWidget *centralwidget;
    QPushButton *btn_Iniciar;
    QPushButton *btn_Pausar;
    QPushButton *btn_Reiniciar;
    QPushButton *btn_Modificar;
    QCheckBox *checkBox;
    QDialogButtonBox *buttonBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VentanaPrincipal)
    {
        if (VentanaPrincipal->objectName().isEmpty())
            VentanaPrincipal->setObjectName(QString::fromUtf8("VentanaPrincipal"));
        VentanaPrincipal->resize(800, 600);
        centralwidget = new QWidget(VentanaPrincipal);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btn_Iniciar = new QPushButton(centralwidget);
        btn_Iniciar->setObjectName(QString::fromUtf8("btn_Iniciar"));
        btn_Iniciar->setGeometry(QRect(30, 420, 151, 81));
        btn_Pausar = new QPushButton(centralwidget);
        btn_Pausar->setObjectName(QString::fromUtf8("btn_Pausar"));
        btn_Pausar->setGeometry(QRect(200, 420, 161, 81));
        btn_Reiniciar = new QPushButton(centralwidget);
        btn_Reiniciar->setObjectName(QString::fromUtf8("btn_Reiniciar"));
        btn_Reiniciar->setGeometry(QRect(370, 420, 151, 81));
        btn_Modificar = new QPushButton(centralwidget);
        btn_Modificar->setObjectName(QString::fromUtf8("btn_Modificar"));
        btn_Modificar->setGeometry(QRect(540, 420, 171, 81));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(160, 120, 61, 61));
        buttonBox = new QDialogButtonBox(centralwidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(270, 290, 171, 71));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        VentanaPrincipal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(VentanaPrincipal);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        VentanaPrincipal->setMenuBar(menubar);
        statusbar = new QStatusBar(VentanaPrincipal);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        VentanaPrincipal->setStatusBar(statusbar);

        retranslateUi(VentanaPrincipal);

        QMetaObject::connectSlotsByName(VentanaPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaPrincipal)
    {
        VentanaPrincipal->setWindowTitle(QCoreApplication::translate("VentanaPrincipal", "VentanaPrincipal", nullptr));
        btn_Iniciar->setText(QCoreApplication::translate("VentanaPrincipal", "Iniciar", nullptr));
        btn_Pausar->setText(QCoreApplication::translate("VentanaPrincipal", "Pausa", nullptr));
        btn_Reiniciar->setText(QCoreApplication::translate("VentanaPrincipal", "Reiniciar", nullptr));
        btn_Modificar->setText(QCoreApplication::translate("VentanaPrincipal", "Modificar", nullptr));
        checkBox->setText(QCoreApplication::translate("VentanaPrincipal", "Gay", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VentanaPrincipal: public Ui_VentanaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAPRINCIPAL_H
