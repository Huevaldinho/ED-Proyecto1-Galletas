#ifndef VENTANACONFIGURAR_H
#define VENTANACONFIGURAR_H

#include <QMainWindow>
#include "Punteros.h"
#include <QMainWindow>
#include <QMovie>
#include <QLabel>
#include <QDebug>

namespace Ui {
    class VentanaConfigurar;
}

class VentanaConfigurar : public QMainWindow{Q_OBJECT
    public:
        explicit VentanaConfigurar(QWidget *parent = nullptr);
        Punteros*punteros;
        ~VentanaConfigurar();


                                         private slots:

                                         private:
        Ui::VentanaConfigurar *ui;
};

#endif // VENTANACONFIGURAR_H
