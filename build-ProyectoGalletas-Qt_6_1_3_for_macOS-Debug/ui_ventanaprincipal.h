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
    QPushButton *btnPausa;
    QPushButton *btnDetener;
    QLabel *lbl_TextMaquinaMasa2;
    QLabel *lbl_TextMaquina2Actual;
    QLabel *lbl_TextMaquina2Procesada;
    QLabel *lbl_MaquinaMasa2EnProceso;
    QLabel *lbl_MaquinaMasa2Procesada;
    QLabel *lbl_TextMaquinaChoco;
    QLabel *lbl_TextMaquinaChocoActual;
    QLabel *lbl_TextMaquinaChocoProcesada;
    QLabel *lbl_MaquinaChocoProcesada;
    QLabel *lbl_MaquinaChocoEnProceso;
    QLabel *lbl_TextBandaTMasaActual;
    QLabel *lbl_TextBandaChocoProcesada;
    QLabel *lbl_BantaTMasaMax;
    QLabel *lbl_BandaTChocoActual;
    QLabel *lbl_TextBandaMasa;
    QLabel *lbl_BandaTChocoMax;
    QLabel *lbl_BandaTMasaActual;
    QLabel *lbl_TextBandaTMasaProcesada;
    QLabel *lbl_TextBandaTChocoActual;
    QLabel *lbl_TextBandaChoco;
    QLabel *lbl_MaquinaEnsambladora;
    QLabel *lbl_TextEnsambladoraProducida;
    QLabel *lbl_EnsambladoraProducida;
    QLabel *lbl_TextBandaTransportadora;
    QLabel *lbl_TextBandaTEnsambladoraActual;
    QLabel *lbl_TextBandaTEnsambladoraMax;
    QLabel *lbl_BandaTEnsambladoraActual;
    QLabel *lbl_BandaTEnsambladoraMax;
    QLabel *lbl_Horno;
    QLabel *lbl_TextActualHorno;
    QLabel *lbl_TexthorneadasHorno;
    QLabel *lbl_actualHorno;
    QLabel *lbl_horneadasHorno;
    QLabel *lbl_Supervisores;
    QLabel *lbl_TextActualSupervisores;
    QLabel *lbl_actualSupervisores;
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
        lblCantidadGalletas->setGeometry(QRect(160, 410, 121, 21));
        btnIniciar = new QPushButton(centralwidget);
        btnIniciar->setObjectName(QString::fromUtf8("btnIniciar"));
        btnIniciar->setGeometry(QRect(140, 530, 251, 71));
        lblChoco = new QLabel(centralwidget);
        lblChoco->setObjectName(QString::fromUtf8("lblChoco"));
        lblChoco->setGeometry(QRect(160, 490, 111, 21));
        lblMasa = new QLabel(centralwidget);
        lblMasa->setObjectName(QString::fromUtf8("lblMasa"));
        lblMasa->setGeometry(QRect(160, 450, 101, 21));
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
        lbl_TextMaquinaMasa1->setGeometry(QRect(140, 10, 141, 21));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(true);
        lbl_TextMaquinaMasa1->setFont(font3);
        lbl_MaquinaMasa1EnProceso = new QLabel(centralwidget);
        lbl_MaquinaMasa1EnProceso->setObjectName(QString::fromUtf8("lbl_MaquinaMasa1EnProceso"));
        lbl_MaquinaMasa1EnProceso->setGeometry(QRect(160, 50, 55, 16));
        lbl_MaquinaMasa1Procesada = new QLabel(centralwidget);
        lbl_MaquinaMasa1Procesada->setObjectName(QString::fromUtf8("lbl_MaquinaMasa1Procesada"));
        lbl_MaquinaMasa1Procesada->setGeometry(QRect(160, 70, 55, 16));
        lbl_TextMaquina1Actual = new QLabel(centralwidget);
        lbl_TextMaquina1Actual->setObjectName(QString::fromUtf8("lbl_TextMaquina1Actual"));
        lbl_TextMaquina1Actual->setGeometry(QRect(60, 40, 91, 21));
        QFont font4;
        font4.setPointSize(13);
        font4.setBold(true);
        lbl_TextMaquina1Actual->setFont(font4);
        lbl_TextMaquina1Procesada = new QLabel(centralwidget);
        lbl_TextMaquina1Procesada->setObjectName(QString::fromUtf8("lbl_TextMaquina1Procesada"));
        lbl_TextMaquina1Procesada->setGeometry(QRect(60, 70, 71, 21));
        lbl_TextMaquina1Procesada->setFont(font);
        btnPausa = new QPushButton(centralwidget);
        btnPausa->setObjectName(QString::fromUtf8("btnPausa"));
        btnPausa->setGeometry(QRect(410, 530, 171, 71));
        btnDetener = new QPushButton(centralwidget);
        btnDetener->setObjectName(QString::fromUtf8("btnDetener"));
        btnDetener->setGeometry(QRect(600, 530, 221, 71));
        lbl_TextMaquinaMasa2 = new QLabel(centralwidget);
        lbl_TextMaquinaMasa2->setObjectName(QString::fromUtf8("lbl_TextMaquinaMasa2"));
        lbl_TextMaquinaMasa2->setGeometry(QRect(140, 110, 121, 21));
        lbl_TextMaquinaMasa2->setFont(font3);
        lbl_TextMaquina2Actual = new QLabel(centralwidget);
        lbl_TextMaquina2Actual->setObjectName(QString::fromUtf8("lbl_TextMaquina2Actual"));
        lbl_TextMaquina2Actual->setGeometry(QRect(60, 140, 55, 16));
        lbl_TextMaquina2Actual->setFont(font);
        lbl_TextMaquina2Procesada = new QLabel(centralwidget);
        lbl_TextMaquina2Procesada->setObjectName(QString::fromUtf8("lbl_TextMaquina2Procesada"));
        lbl_TextMaquina2Procesada->setGeometry(QRect(60, 170, 71, 16));
        lbl_TextMaquina2Procesada->setFont(font);
        lbl_MaquinaMasa2EnProceso = new QLabel(centralwidget);
        lbl_MaquinaMasa2EnProceso->setObjectName(QString::fromUtf8("lbl_MaquinaMasa2EnProceso"));
        lbl_MaquinaMasa2EnProceso->setGeometry(QRect(160, 140, 55, 16));
        lbl_MaquinaMasa2Procesada = new QLabel(centralwidget);
        lbl_MaquinaMasa2Procesada->setObjectName(QString::fromUtf8("lbl_MaquinaMasa2Procesada"));
        lbl_MaquinaMasa2Procesada->setGeometry(QRect(160, 170, 55, 16));
        lbl_TextMaquinaChoco = new QLabel(centralwidget);
        lbl_TextMaquinaChoco->setObjectName(QString::fromUtf8("lbl_TextMaquinaChoco"));
        lbl_TextMaquinaChoco->setGeometry(QRect(140, 200, 151, 16));
        lbl_TextMaquinaChoco->setFont(font3);
        lbl_TextMaquinaChocoActual = new QLabel(centralwidget);
        lbl_TextMaquinaChocoActual->setObjectName(QString::fromUtf8("lbl_TextMaquinaChocoActual"));
        lbl_TextMaquinaChocoActual->setGeometry(QRect(60, 250, 55, 16));
        lbl_TextMaquinaChocoActual->setFont(font);
        lbl_TextMaquinaChocoProcesada = new QLabel(centralwidget);
        lbl_TextMaquinaChocoProcesada->setObjectName(QString::fromUtf8("lbl_TextMaquinaChocoProcesada"));
        lbl_TextMaquinaChocoProcesada->setGeometry(QRect(60, 280, 71, 16));
        lbl_TextMaquinaChocoProcesada->setFont(font);
        lbl_MaquinaChocoProcesada = new QLabel(centralwidget);
        lbl_MaquinaChocoProcesada->setObjectName(QString::fromUtf8("lbl_MaquinaChocoProcesada"));
        lbl_MaquinaChocoProcesada->setGeometry(QRect(160, 280, 55, 16));
        lbl_MaquinaChocoEnProceso = new QLabel(centralwidget);
        lbl_MaquinaChocoEnProceso->setObjectName(QString::fromUtf8("lbl_MaquinaChocoEnProceso"));
        lbl_MaquinaChocoEnProceso->setGeometry(QRect(160, 250, 55, 16));
        lbl_TextBandaTMasaActual = new QLabel(centralwidget);
        lbl_TextBandaTMasaActual->setObjectName(QString::fromUtf8("lbl_TextBandaTMasaActual"));
        lbl_TextBandaTMasaActual->setGeometry(QRect(360, 70, 55, 16));
        lbl_TextBandaTMasaActual->setFont(font);
        lbl_TextBandaChocoProcesada = new QLabel(centralwidget);
        lbl_TextBandaChocoProcesada->setObjectName(QString::fromUtf8("lbl_TextBandaChocoProcesada"));
        lbl_TextBandaChocoProcesada->setGeometry(QRect(360, 240, 71, 16));
        lbl_TextBandaChocoProcesada->setFont(font);
        lbl_BantaTMasaMax = new QLabel(centralwidget);
        lbl_BantaTMasaMax->setObjectName(QString::fromUtf8("lbl_BantaTMasaMax"));
        lbl_BantaTMasaMax->setGeometry(QRect(470, 90, 55, 16));
        lbl_BandaTChocoActual = new QLabel(centralwidget);
        lbl_BandaTChocoActual->setObjectName(QString::fromUtf8("lbl_BandaTChocoActual"));
        lbl_BandaTChocoActual->setGeometry(QRect(450, 220, 55, 16));
        lbl_TextBandaMasa = new QLabel(centralwidget);
        lbl_TextBandaMasa->setObjectName(QString::fromUtf8("lbl_TextBandaMasa"));
        lbl_TextBandaMasa->setGeometry(QRect(340, 40, 191, 16));
        lbl_TextBandaMasa->setFont(font1);
        lbl_BandaTChocoMax = new QLabel(centralwidget);
        lbl_BandaTChocoMax->setObjectName(QString::fromUtf8("lbl_BandaTChocoMax"));
        lbl_BandaTChocoMax->setGeometry(QRect(450, 240, 55, 16));
        lbl_BandaTMasaActual = new QLabel(centralwidget);
        lbl_BandaTMasaActual->setObjectName(QString::fromUtf8("lbl_BandaTMasaActual"));
        lbl_BandaTMasaActual->setGeometry(QRect(470, 70, 55, 16));
        lbl_TextBandaTMasaProcesada = new QLabel(centralwidget);
        lbl_TextBandaTMasaProcesada->setObjectName(QString::fromUtf8("lbl_TextBandaTMasaProcesada"));
        lbl_TextBandaTMasaProcesada->setGeometry(QRect(360, 90, 71, 16));
        lbl_TextBandaTMasaProcesada->setFont(font);
        lbl_TextBandaTChocoActual = new QLabel(centralwidget);
        lbl_TextBandaTChocoActual->setObjectName(QString::fromUtf8("lbl_TextBandaTChocoActual"));
        lbl_TextBandaTChocoActual->setGeometry(QRect(360, 220, 55, 16));
        lbl_TextBandaTChocoActual->setFont(font);
        lbl_TextBandaChoco = new QLabel(centralwidget);
        lbl_TextBandaChoco->setObjectName(QString::fromUtf8("lbl_TextBandaChoco"));
        lbl_TextBandaChoco->setGeometry(QRect(350, 190, 231, 16));
        lbl_TextBandaChoco->setFont(font);
        lbl_MaquinaEnsambladora = new QLabel(centralwidget);
        lbl_MaquinaEnsambladora->setObjectName(QString::fromUtf8("lbl_MaquinaEnsambladora"));
        lbl_MaquinaEnsambladora->setGeometry(QRect(550, 100, 121, 16));
        lbl_MaquinaEnsambladora->setFont(font3);
        lbl_TextEnsambladoraProducida = new QLabel(centralwidget);
        lbl_TextEnsambladoraProducida->setObjectName(QString::fromUtf8("lbl_TextEnsambladoraProducida"));
        lbl_TextEnsambladoraProducida->setGeometry(QRect(540, 130, 81, 16));
        lbl_TextEnsambladoraProducida->setFont(font);
        lbl_EnsambladoraProducida = new QLabel(centralwidget);
        lbl_EnsambladoraProducida->setObjectName(QString::fromUtf8("lbl_EnsambladoraProducida"));
        lbl_EnsambladoraProducida->setGeometry(QRect(630, 130, 55, 16));
        lbl_TextBandaTransportadora = new QLabel(centralwidget);
        lbl_TextBandaTransportadora->setObjectName(QString::fromUtf8("lbl_TextBandaTransportadora"));
        lbl_TextBandaTransportadora->setGeometry(QRect(710, 110, 161, 16));
        lbl_TextBandaTransportadora->setFont(font);
        lbl_TextBandaTEnsambladoraActual = new QLabel(centralwidget);
        lbl_TextBandaTEnsambladoraActual->setObjectName(QString::fromUtf8("lbl_TextBandaTEnsambladoraActual"));
        lbl_TextBandaTEnsambladoraActual->setGeometry(QRect(710, 130, 55, 16));
        lbl_TextBandaTEnsambladoraActual->setFont(font);
        lbl_TextBandaTEnsambladoraMax = new QLabel(centralwidget);
        lbl_TextBandaTEnsambladoraMax->setObjectName(QString::fromUtf8("lbl_TextBandaTEnsambladoraMax"));
        lbl_TextBandaTEnsambladoraMax->setGeometry(QRect(710, 150, 55, 16));
        lbl_TextBandaTEnsambladoraMax->setFont(font);
        lbl_BandaTEnsambladoraActual = new QLabel(centralwidget);
        lbl_BandaTEnsambladoraActual->setObjectName(QString::fromUtf8("lbl_BandaTEnsambladoraActual"));
        lbl_BandaTEnsambladoraActual->setGeometry(QRect(770, 130, 55, 16));
        lbl_BandaTEnsambladoraMax = new QLabel(centralwidget);
        lbl_BandaTEnsambladoraMax->setObjectName(QString::fromUtf8("lbl_BandaTEnsambladoraMax"));
        lbl_BandaTEnsambladoraMax->setGeometry(QRect(770, 150, 55, 16));
        lbl_Horno = new QLabel(centralwidget);
        lbl_Horno->setObjectName(QString::fromUtf8("lbl_Horno"));
        lbl_Horno->setGeometry(QRect(870, 170, 71, 21));
        lbl_Horno->setFont(font);
        lbl_TextActualHorno = new QLabel(centralwidget);
        lbl_TextActualHorno->setObjectName(QString::fromUtf8("lbl_TextActualHorno"));
        lbl_TextActualHorno->setGeometry(QRect(860, 190, 51, 16));
        lbl_TextActualHorno->setFont(font);
        lbl_TexthorneadasHorno = new QLabel(centralwidget);
        lbl_TexthorneadasHorno->setObjectName(QString::fromUtf8("lbl_TexthorneadasHorno"));
        lbl_TexthorneadasHorno->setGeometry(QRect(860, 210, 81, 16));
        lbl_TexthorneadasHorno->setFont(font);
        lbl_actualHorno = new QLabel(centralwidget);
        lbl_actualHorno->setObjectName(QString::fromUtf8("lbl_actualHorno"));
        lbl_actualHorno->setGeometry(QRect(920, 190, 60, 16));
        lbl_horneadasHorno = new QLabel(centralwidget);
        lbl_horneadasHorno->setObjectName(QString::fromUtf8("lbl_horneadasHorno"));
        lbl_horneadasHorno->setGeometry(QRect(940, 210, 31, 16));
        lbl_Supervisores = new QLabel(centralwidget);
        lbl_Supervisores->setObjectName(QString::fromUtf8("lbl_Supervisores"));
        lbl_Supervisores->setGeometry(QRect(1000, 130, 91, 21));
        lbl_Supervisores->setFont(font);
        lbl_TextActualSupervisores = new QLabel(centralwidget);
        lbl_TextActualSupervisores->setObjectName(QString::fromUtf8("lbl_TextActualSupervisores"));
        lbl_TextActualSupervisores->setGeometry(QRect(1000, 150, 60, 16));
        lbl_TextActualSupervisores->setFont(font);
        lbl_actualSupervisores = new QLabel(centralwidget);
        lbl_actualSupervisores->setObjectName(QString::fromUtf8("lbl_actualSupervisores"));
        lbl_actualSupervisores->setGeometry(QRect(1050, 150, 60, 16));
        VentanaPrincipal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(VentanaPrincipal);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1187, 21));
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
        lblCantidadGalletas->setText(QCoreApplication::translate("VentanaPrincipal", "0", nullptr));
#if QT_CONFIG(tooltip)
        btnIniciar->setToolTip(QCoreApplication::translate("VentanaPrincipal", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnIniciar->setText(QCoreApplication::translate("VentanaPrincipal", "Iniciar", nullptr));
        lblChoco->setText(QCoreApplication::translate("VentanaPrincipal", "0", nullptr));
        lblMasa->setText(QCoreApplication::translate("VentanaPrincipal", "0", nullptr));
        lbl_TextGalletasPlani->setText(QCoreApplication::translate("VentanaPrincipal", "Cantidad de galletas: ", nullptr));
        lbl_TextMasaPlani->setText(QCoreApplication::translate("VentanaPrincipal", "Cantidad masa: ", nullptr));
        lbl_TextChocoPlani->setText(QCoreApplication::translate("VentanaPrincipal", "Cantidad chocolate: ", nullptr));
        lbl_TextPlani->setText(QCoreApplication::translate("VentanaPrincipal", "Planificador", nullptr));
        lbl_TextMaquinaMasa1->setText(QCoreApplication::translate("VentanaPrincipal", "Maquina Masa 1", nullptr));
        lbl_MaquinaMasa1EnProceso->setText(QCoreApplication::translate("VentanaPrincipal", "0", nullptr));
        lbl_MaquinaMasa1Procesada->setText(QCoreApplication::translate("VentanaPrincipal", "0", nullptr));
        lbl_TextMaquina1Actual->setText(QCoreApplication::translate("VentanaPrincipal", "Actual: ", nullptr));
        lbl_TextMaquina1Procesada->setText(QCoreApplication::translate("VentanaPrincipal", "Procesada: ", nullptr));
        btnPausa->setText(QCoreApplication::translate("VentanaPrincipal", "Pausa", nullptr));
        btnDetener->setText(QCoreApplication::translate("VentanaPrincipal", "Detener", nullptr));
        lbl_TextMaquinaMasa2->setText(QCoreApplication::translate("VentanaPrincipal", "Maquina Masa 2", nullptr));
        lbl_TextMaquina2Actual->setText(QCoreApplication::translate("VentanaPrincipal", "Actual:", nullptr));
        lbl_TextMaquina2Procesada->setText(QCoreApplication::translate("VentanaPrincipal", "Procesada: ", nullptr));
        lbl_MaquinaMasa2EnProceso->setText(QCoreApplication::translate("VentanaPrincipal", "0", nullptr));
        lbl_MaquinaMasa2Procesada->setText(QCoreApplication::translate("VentanaPrincipal", "0", nullptr));
        lbl_TextMaquinaChoco->setText(QCoreApplication::translate("VentanaPrincipal", "Maquina Chocolate", nullptr));
        lbl_TextMaquinaChocoActual->setText(QCoreApplication::translate("VentanaPrincipal", "Actual:", nullptr));
        lbl_TextMaquinaChocoProcesada->setText(QCoreApplication::translate("VentanaPrincipal", "Procesada:", nullptr));
        lbl_MaquinaChocoProcesada->setText(QCoreApplication::translate("VentanaPrincipal", "0", nullptr));
        lbl_MaquinaChocoEnProceso->setText(QCoreApplication::translate("VentanaPrincipal", "0", nullptr));
        lbl_TextBandaTMasaActual->setText(QCoreApplication::translate("VentanaPrincipal", "Actual:", nullptr));
        lbl_TextBandaChocoProcesada->setText(QCoreApplication::translate("VentanaPrincipal", "Max:", nullptr));
        lbl_BantaTMasaMax->setText(QCoreApplication::translate("VentanaPrincipal", "0", nullptr));
        lbl_BandaTChocoActual->setText(QCoreApplication::translate("VentanaPrincipal", "0", nullptr));
        lbl_TextBandaMasa->setText(QCoreApplication::translate("VentanaPrincipal", "Banda Transportadora Masa", nullptr));
        lbl_BandaTChocoMax->setText(QCoreApplication::translate("VentanaPrincipal", "0", nullptr));
        lbl_BandaTMasaActual->setText(QCoreApplication::translate("VentanaPrincipal", "0", nullptr));
        lbl_TextBandaTMasaProcesada->setText(QCoreApplication::translate("VentanaPrincipal", "Max:", nullptr));
        lbl_TextBandaTChocoActual->setText(QCoreApplication::translate("VentanaPrincipal", "Actual:", nullptr));
        lbl_TextBandaChoco->setText(QCoreApplication::translate("VentanaPrincipal", "Banda Transportadora Chocolate", nullptr));
        lbl_MaquinaEnsambladora->setText(QCoreApplication::translate("VentanaPrincipal", "Maquina Ensambladora", nullptr));
        lbl_TextEnsambladoraProducida->setText(QCoreApplication::translate("VentanaPrincipal", "Producidas:", nullptr));
        lbl_EnsambladoraProducida->setText(QCoreApplication::translate("VentanaPrincipal", "0", nullptr));
        lbl_TextBandaTransportadora->setText(QCoreApplication::translate("VentanaPrincipal", "Banda Transportadora", nullptr));
        lbl_TextBandaTEnsambladoraActual->setText(QCoreApplication::translate("VentanaPrincipal", "Actual:", nullptr));
        lbl_TextBandaTEnsambladoraMax->setText(QCoreApplication::translate("VentanaPrincipal", "Max:", nullptr));
        lbl_BandaTEnsambladoraActual->setText(QCoreApplication::translate("VentanaPrincipal", "0", nullptr));
        lbl_BandaTEnsambladoraMax->setText(QCoreApplication::translate("VentanaPrincipal", "0", nullptr));
        lbl_Horno->setText(QCoreApplication::translate("VentanaPrincipal", "Horno", nullptr));
        lbl_TextActualHorno->setText(QCoreApplication::translate("VentanaPrincipal", "Actual:", nullptr));
        lbl_TexthorneadasHorno->setText(QCoreApplication::translate("VentanaPrincipal", "Horneadas:", nullptr));
        lbl_actualHorno->setText(QCoreApplication::translate("VentanaPrincipal", "0", nullptr));
        lbl_horneadasHorno->setText(QCoreApplication::translate("VentanaPrincipal", "0", nullptr));
        lbl_Supervisores->setText(QCoreApplication::translate("VentanaPrincipal", "Supervisores", nullptr));
        lbl_TextActualSupervisores->setText(QCoreApplication::translate("VentanaPrincipal", "Actual:", nullptr));
        lbl_actualSupervisores->setText(QCoreApplication::translate("VentanaPrincipal", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VentanaPrincipal: public Ui_VentanaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAPRINCIPAL_H
