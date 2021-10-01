/********************************************************************************
** Form generated from reading UI file 'ventanaconfigurar.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANACONFIGURAR_H
#define UI_VENTANACONFIGURAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaConfigurar
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VentanaConfigurar)
    {
        if (VentanaConfigurar->objectName().isEmpty())
            VentanaConfigurar->setObjectName(QString::fromUtf8("VentanaConfigurar"));
        VentanaConfigurar->resize(800, 600);
        menubar = new QMenuBar(VentanaConfigurar);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        VentanaConfigurar->setMenuBar(menubar);
        centralwidget = new QWidget(VentanaConfigurar);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        VentanaConfigurar->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(VentanaConfigurar);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        VentanaConfigurar->setStatusBar(statusbar);

        retranslateUi(VentanaConfigurar);

        QMetaObject::connectSlotsByName(VentanaConfigurar);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaConfigurar)
    {
        VentanaConfigurar->setWindowTitle(QCoreApplication::translate("VentanaConfigurar", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VentanaConfigurar: public Ui_VentanaConfigurar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANACONFIGURAR_H
