#ifndef VENTANACONFIGURAR_H
#define VENTANACONFIGURAR_H

#include "Punteros.h"
#include <QMainWindow>
#include <QMovie>
#include <QLabel>
#include <QDebug>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui {class VentanaConfigurar;}
QT_END_NAMESPACE

class VentanaConfigurar : public QMainWindow{Q_OBJECT
    public:
        VentanaConfigurar(QWidget *parent = nullptr);
        Punteros*punteros;
        bool ok;
        ~VentanaConfigurar();


                                         private slots:

                                                 void on_btn_InsIns_clicked();

                                                                                          void on_btn_RecIns_clicked();

                                                                                                                                   void on_btn_CarIns_clicked();

                                                                                                                                                                            void on_btn_maq1Ins_clicked();

                                                                                                                                                                                                                     void on_btn_maq2Ins_clicked();

                                                                                                                                                                                                                                                              void on_btn_maqChIns_clicked();

                                                                                                                                                                                                                                                                                                       void on_btn_BTMIns_clicked();

                                                                                                                                                                                                                                                                                                                                                void on_btn_BTChIns_clicked();

                                                                                                                                                                                                                                                                                                                                                                                         void on_btn_maqEmsIns_clicked();

                                                                                                                                                                                                                                                                                                                                                                                                                                  void on_btn_BTEmsHorIns_clicked();

                                                                                                                                                                                                                                                                                                                                                                                                                                                                           void on_btn_BTHorSupIns_clicked();

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    void on_btn_SupIns_clicked();

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             void on_btn_HorIns_clicked();

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      void on_btn_bnd1Ins_clicked();

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               void on_btn_bnd2Ins_clicked();

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        void on_btn_bnd3Ins_clicked();

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 void on_btn_bnd4Ins_clicked();

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          void on_btn_bnd5Ins_clicked();

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   void on_btn_bnd6Ins_clicked();

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            void on_btn_maqEmpIns_clicked();

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     void on_btn_transIns_clicked();

                                         private:
        Ui::VentanaConfigurar *ui;
};

#endif // VENTANACONFIGURAR_H
