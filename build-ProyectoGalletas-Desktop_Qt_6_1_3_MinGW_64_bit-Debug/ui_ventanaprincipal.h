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
#include <QtWidgets/QApplication>
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
    QLabel *lblCantidadGalletas;
    QPushButton *btnIniciar;
    QLabel *lblChoco;
    QLabel *lblMasa;
    QLabel *lbl_TextGalletasPlani;
    QLabel *lbl_TextMasaPlani;
    QLabel *lbl_TextChocoPlani;
    QLabel *lbl_TextPlani;
    QLabel *lbl_TextMaquinaMasa1;
    QLabel *lbl_MaquinaMasa1EnProceso;
    QLabel *lbl_MaquinaMasa1Procesada;
    QLabel *lbl_TextMaquina1Actual;
    QLabel *lbl_TextMaquina1Procesada;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VentanaPrincipal)
    {
        if (VentanaPrincipal->objectName().isEmpty())
            VentanaPrincipal->setObjectName(QString::fromUtf8("VentanaPrincipal"));
        VentanaPrincipal->resize(1187, 653);
        centralwidget = new QWidget(VentanaPrincipal);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lblCantidadGalletas = new QLabel(centralwidget);
        lblCantidadGalletas->setObjectName(QString::fromUtf8("lblCantidadGalletas"));
        lblCantidadGalletas->setGeometry(QRect(170, 410, 121, 21));
        btnIniciar = new QPushButton(centralwidget);
        btnIniciar->setObjectName(QString::fromUtf8("btnIniciar"));
        btnIniciar->setGeometry(QRect(140, 530, 251, 71));
        lblChoco = new QLabel(centralwidget);
        lblChoco->setObjectName(QString::fromUtf8("lblChoco"));
        lblChoco->setGeometry(QRect(160, 490, 111, 21));
        lblMasa = new QLabel(centralwidget);
        lblMasa->setObjectName(QString::fromUtf8("lblMasa"));
        lblMasa->setGeometry(QRect(180, 450, 101, 21));
        lbl_TextGalletasPlani = new QLabel(centralwidget);
        lbl_TextGalletasPlani->setObjectName(QString::fromUtf8("lbl_TextGalletasPlani"));
        lbl_TextGalletasPlani->setGeometry(QRect(10, 390, 161, 51));
        QFont font;
        font.setBold(true);
        lbl_TextGalletasPlani->setFont(font);
        lbl_TextMasaPlani = new QLabel(centralwidget);
        lbl_TextMasaPlani->setObjectName(QString::fromUtf8("lbl_TextMasaPlani"));
        lbl_TextMasaPlani->setGeometry(QRect(10, 430, 121, 51));
        lbl_TextMasaPlani->setFont(font);
        lbl_TextChocoPlani = new QLabel(centralwidget);
        lbl_TextChocoPlani->setObjectName(QString::fromUtf8("lbl_TextChocoPlani"));
        lbl_TextChocoPlani->setGeometry(QRect(10, 490, 131, 16));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(true);
        lbl_TextChocoPlani->setFont(font1);
        lbl_TextPlani = new QLabel(centralwidget);
        lbl_TextPlani->setObjectName(QString::fromUtf8("lbl_TextPlani"));
        lbl_TextPlani->setGeometry(QRect(130, 350, 181, 31));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(true);
        lbl_TextPlani->setFont(font2);
        lbl_TextMaquinaMasa1 = new QLabel(centralwidget);
        lbl_TextMaquinaMasa1->setObjectName(QString::fromUtf8("lbl_TextMaquinaMasa1"));
        lbl_TextMaquinaMasa1->setGeometry(QRect(240, 80, 141, 21));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(true);
        lbl_TextMaquinaMasa1->setFont(font3);
        lbl_MaquinaMasa1EnProceso = new QLabel(centralwidget);
        lbl_MaquinaMasa1EnProceso->setObjectName(QString::fromUtf8("lbl_MaquinaMasa1EnProceso"));
        lbl_MaquinaMasa1EnProceso->setGeometry(QRect(260, 120, 55, 16));
        lbl_MaquinaMasa1Procesada = new QLabel(centralwidget);
        lbl_MaquinaMasa1Procesada->setObjectName(QString::fromUtf8("lbl_MaquinaMasa1Procesada"));
        lbl_MaquinaMasa1Procesada->setGeometry(QRect(260, 140, 55, 16));
        lbl_TextMaquina1Actual = new QLabel(centralwidget);
        lbl_TextMaquina1Actual->setObjectName(QString::fromUtf8("lbl_TextMaquina1Actual"));
        lbl_TextMaquina1Actual->setGeometry(QRect(160, 110, 91, 21));
        lbl_TextMaquina1Actual->setFont(font1);
        lbl_TextMaquina1Procesada = new QLabel(centralwidget);
        lbl_TextMaquina1Procesada->setObjectName(QString::fromUtf8("lbl_TextMaquina1Procesada"));
        lbl_TextMaquina1Procesada->setGeometry(QRect(160, 140, 71, 21));
        lbl_TextMaquina1Procesada->setFont(font);
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
        lblCantidadGalletas->setText(QString());
#if QT_CONFIG(tooltip)
        btnIniciar->setToolTip(QCoreApplication::translate("VentanaPrincipal", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnIniciar->setText(QCoreApplication::translate("VentanaPrincipal", "Iniciar", nullptr));
        lblChoco->setText(QString());
        lblMasa->setText(QString());
        lbl_TextGalletasPlani->setText(QCoreApplication::translate("VentanaPrincipal", "Cantidad de galletas: ", nullptr));
        lbl_TextMasaPlani->setText(QCoreApplication::translate("VentanaPrincipal", "Cantidad masa: ", nullptr));
        lbl_TextChocoPlani->setText(QCoreApplication::translate("VentanaPrincipal", "Cantidad chocolate: ", nullptr));
        lbl_TextPlani->setText(QCoreApplication::translate("VentanaPrincipal", "Planificador", nullptr));
        lbl_TextMaquinaMasa1->setText(QCoreApplication::translate("VentanaPrincipal", "Maquina Masa 1", nullptr));
        lbl_MaquinaMasa1EnProceso->setText(QString());
        lbl_MaquinaMasa1Procesada->setText(QString());
        lbl_TextMaquina1Actual->setText(QCoreApplication::translate("VentanaPrincipal", "Actual: ", nullptr));
        lbl_TextMaquina1Procesada->setText(QCoreApplication::translate("VentanaPrincipal", "Procesada: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VentanaPrincipal: public Ui_VentanaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAPRINCIPAL_H
