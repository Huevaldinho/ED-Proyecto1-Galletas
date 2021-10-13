#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include "Punteros.h"
#include <QMainWindow>
#include <QMovie>
#include <QLabel>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class VentanaPrincipal; }
QT_END_NAMESPACE

class VentanaPrincipal : public QMainWindow{Q_OBJECT
    public:
        VentanaPrincipal(QWidget *parent = nullptr);
        Punteros * punteros;
        hilo_planificador*hiloPlanificador;
        ~VentanaPrincipal();


        private slots:
                void on_btnIniciar_clicked();

        private:
        Ui::VentanaPrincipal *ui;

};
#endif // VENTANAPRINCIPAL_H
