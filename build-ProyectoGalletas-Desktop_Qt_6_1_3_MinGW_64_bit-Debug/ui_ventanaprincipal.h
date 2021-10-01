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
    QPushButton *btn_Start;
    QPushButton *btn_Pause;
    QPushButton *btn_Reset;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VentanaPrincipal)
    {
        if (VentanaPrincipal->objectName().isEmpty())
            VentanaPrincipal->setObjectName(QString::fromUtf8("VentanaPrincipal"));
        VentanaPrincipal->resize(1027, 679);
        VentanaPrincipal->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(VentanaPrincipal);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btn_Start = new QPushButton(centralwidget);
        btn_Start->setObjectName(QString::fromUtf8("btn_Start"));
        btn_Start->setGeometry(QRect(320, 530, 151, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(12);
        btn_Start->setFont(font);
        btn_Pause = new QPushButton(centralwidget);
        btn_Pause->setObjectName(QString::fromUtf8("btn_Pause"));
        btn_Pause->setGeometry(QRect(510, 530, 151, 61));
        btn_Pause->setFont(font);
        btn_Reset = new QPushButton(centralwidget);
        btn_Reset->setObjectName(QString::fromUtf8("btn_Reset"));
        btn_Reset->setGeometry(QRect(700, 530, 151, 61));
        btn_Reset->setFont(font);
        btn_Reset->setAutoFillBackground(false);
        VentanaPrincipal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(VentanaPrincipal);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1027, 25));
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
        btn_Start->setText(QCoreApplication::translate("VentanaPrincipal", "Start", nullptr));
        btn_Pause->setText(QCoreApplication::translate("VentanaPrincipal", "Pause", nullptr));
        btn_Reset->setText(QCoreApplication::translate("VentanaPrincipal", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VentanaPrincipal: public Ui_VentanaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAPRINCIPAL_H
