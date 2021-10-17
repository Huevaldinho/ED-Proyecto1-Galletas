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
        hilo_maquinaMasa1 *hiloMaquinaMasa1;
        hilo_maquinaMasa1 *hiloMaquinaMasa2;
        hilo_maquinaMasa1 *hiloMaquinaChoco;
        hilo_carrito * hiloCarrito;
        bool pausa;
        bool corriendo;

        ~VentanaPrincipal();


        private slots:
                void on_btnIniciar_clicked();

                void on_btnPausa_clicked();

                void on_btnDetener_clicked();

        private:
        Ui::VentanaPrincipal *ui;

};
#endif // VENTANAPRINCIPAL_H
