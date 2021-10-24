/********************************************************************************
** Form generated from reading UI file 'peticionesalmacen.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PETICIONESALMACEN_H
#define UI_PETICIONESALMACEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PeticionesAlmacen
{
public:
    QLabel *label;
    QTableWidget *tablaUI;
    QLabel *label_2;

    void setupUi(QWidget *PeticionesAlmacen)
    {
        if (PeticionesAlmacen->objectName().isEmpty())
            PeticionesAlmacen->setObjectName(QString::fromUtf8("PeticionesAlmacen"));
        PeticionesAlmacen->resize(400, 300);
        label = new QLabel(PeticionesAlmacen);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 10, 151, 21));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        label->setFont(font);
        tablaUI = new QTableWidget(PeticionesAlmacen);
        if (tablaUI->columnCount() < 3)
            tablaUI->setColumnCount(3);
        QFont font1;
        font1.setPointSize(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        tablaUI->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        tablaUI->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        tablaUI->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tablaUI->setObjectName(QString::fromUtf8("tablaUI"));
        tablaUI->setGeometry(QRect(10, 70, 371, 191));
        tablaUI->setFont(font1);
        label_2 = new QLabel(PeticionesAlmacen);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 161, 16));
        QFont font2;
        font2.setBold(true);
        label_2->setFont(font2);

        retranslateUi(PeticionesAlmacen);

        QMetaObject::connectSlotsByName(PeticionesAlmacen);
    } // setupUi

    void retranslateUi(QWidget *PeticionesAlmacen)
    {
        PeticionesAlmacen->setWindowTitle(QCoreApplication::translate("PeticionesAlmacen", "Form", nullptr));
        label->setText(QCoreApplication::translate("PeticionesAlmacen", "Peticiones Almacen", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tablaUI->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("PeticionesAlmacen", "Cantidad", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tablaUI->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("PeticionesAlmacen", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tablaUI->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("PeticionesAlmacen", "Estado", nullptr));
        label_2->setText(QCoreApplication::translate("PeticionesAlmacen", "Cola Peticiones Almacen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PeticionesAlmacen: public Ui_PeticionesAlmacen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PETICIONESALMACEN_H
