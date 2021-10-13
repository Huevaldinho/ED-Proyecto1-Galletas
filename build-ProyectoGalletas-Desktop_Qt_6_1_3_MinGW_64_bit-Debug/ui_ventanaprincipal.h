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
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
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
    QDialogButtonBox *buttonBox;
    QLCDNumber *lcdNumber;
    QLabel *lbl_TextoTotalGalletas;
    QLabel *lbl_GalletasAProducir;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VentanaPrincipal)
    {
        if (VentanaPrincipal->objectName().isEmpty())
            VentanaPrincipal->setObjectName(QString::fromUtf8("VentanaPrincipal"));
        VentanaPrincipal->resize(1187, 653);
        centralwidget = new QWidget(VentanaPrincipal);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btn_Iniciar = new QPushButton(centralwidget);
        btn_Iniciar->setObjectName(QString::fromUtf8("btn_Iniciar"));
        btn_Iniciar->setGeometry(QRect(260, 520, 151, 81));
        btn_Pausar = new QPushButton(centralwidget);
        btn_Pausar->setObjectName(QString::fromUtf8("btn_Pausar"));
        btn_Pausar->setGeometry(QRect(430, 520, 161, 81));
        btn_Reiniciar = new QPushButton(centralwidget);
        btn_Reiniciar->setObjectName(QString::fromUtf8("btn_Reiniciar"));
        btn_Reiniciar->setGeometry(QRect(600, 520, 151, 81));
        btn_Modificar = new QPushButton(centralwidget);
        btn_Modificar->setObjectName(QString::fromUtf8("btn_Modificar"));
        btn_Modificar->setGeometry(QRect(770, 520, 171, 81));
        buttonBox = new QDialogButtonBox(centralwidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(500, 440, 171, 71));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(520, 390, 141, 61));
        lbl_TextoTotalGalletas = new QLabel(centralwidget);
        lbl_TextoTotalGalletas->setObjectName(QString::fromUtf8("lbl_TextoTotalGalletas"));
        lbl_TextoTotalGalletas->setGeometry(QRect(30, 410, 281, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(12);
        font.setBold(true);
        lbl_TextoTotalGalletas->setFont(font);
        lbl_GalletasAProducir = new QLabel(centralwidget);
        lbl_GalletasAProducir->setObjectName(QString::fromUtf8("lbl_GalletasAProducir"));
        lbl_GalletasAProducir->setGeometry(QRect(280, 420, 191, 31));
        QFont font1;
        font1.setPointSize(11);
        lbl_GalletasAProducir->setFont(font1);
        VentanaPrincipal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(VentanaPrincipal);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1187, 25));
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
        lbl_TextoTotalGalletas->setText(QCoreApplication::translate("VentanaPrincipal", "Total de galletas a producir: ", nullptr));
        lbl_GalletasAProducir->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VentanaPrincipal: public Ui_VentanaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAPRINCIPAL_H
