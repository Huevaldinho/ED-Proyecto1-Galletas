#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include "Punteros.h"
#include <QMainWindow>
#include <QMovie>
#include <QLabel>
#include <QDebug>
#include <QMessageBox>
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
        hilo_MaquinaEnsambladora * hiloMaquinaEnsambladora;
        hilo_Horno*hiloHorno;
        hilo_Supervisores * hiloSupervisores;
        hilo_Empacadora * hiloEmpacadora;
        QTableWidget * tabla;
        QTableWidget * tablaBandejas;
        QTableWidget * tablaTransportes;
        bool pausa;
        bool corriendo;

        ~VentanaPrincipal();


        private slots:
                void on_btnIniciar_clicked();

                void on_btnPausa_clicked();

                void on_btnDetener_clicked();

                                                        void on_btnCambiarEstadoMaquina1_clicked();

                                                                                                void on_btnCambiarEstadoMaquina2_clicked();

                                                                                                                                        void on_btnCambiarEstadoMaquina3_clicked();

                                                                                                                                                                                void on_btnReanudar_clicked();

                                                                                                                                                                                                                        void on_btnCambiarEstadoEnsambladora_clicked();

                                                                                                                                                                                                                                                                void on_btnCambiarEstadoHorno_clicked();



                                        private:
        Ui::VentanaPrincipal *ui;

};
#endif // VENTANAPRINCIPAL_H
