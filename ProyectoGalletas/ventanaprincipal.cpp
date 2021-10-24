#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
VentanaPrincipal::VentanaPrincipal(QWidget *parent): QMainWindow(parent), ui(new Ui::VentanaPrincipal){
    ui->setupUi(this);

    this->hiloPlanificador = NULL;
    this->hiloMaquinaMasa1 = NULL;//cambiar nombre de la clase porque al final se usa la misma pero con
    this->hiloMaquinaMasa2 = NULL;
    this->hiloMaquinaChoco = NULL;
    this->hiloMaquinaEnsambladora=NULL;
    this->hiloCarrito =NULL;
    this->hiloHorno=NULL;
    this->hiloSupervisores=NULL;
    this->hiloEmpacadora=NULL;
    this->punteros=NULL;


    QPixmap pix (":/Recursos/img/cookie.png");
    int w = this->ui->lbl_TextGalletasPlani->width();
    int h = this->ui->lbl_TextGalletasPlani->height();
    this->ui->lbl_TextGalletasPlani->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    QPixmap pix1 (":/Recursos/img/dough.png");
    int w1 = this->ui->lbl_TextMasaPlani->width();
    int h1 = this->ui->lbl_TextMasaPlani->height();
    this->ui->lbl_TextMasaPlani->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));

    QPixmap pix2 (":/Recursos/img/chocolate.png");
    int w2 = this->ui->lbl_TextChocoPlani->width();
    int h2 = this->ui->lbl_TextChocoPlani->height();
    this->ui->lbl_TextChocoPlani->setPixmap(pix2.scaled(w2,h2,Qt::KeepAspectRatio));

    QPixmap pix3 (":/Recursos/img/planifier.png");
    int w3 = this->ui->lbl_TextPlani->width();
    int h3 = this->ui->lbl_TextPlani->height();
    this->ui->lbl_TextPlani->setPixmap(pix3.scaled(w3,h3,Qt::KeepAspectRatio));

    QPixmap pix4 (":/Recursos/img/carro.png");
    int w4 = this->ui->lbl_Carrito->width();
    int h4 = this->ui->lbl_Carrito->height();
    this->ui->lbl_Carrito->setPixmap(pix4.scaled(w4,h4,Qt::KeepAspectRatio));

    QPixmap pix5a (":/Recursos/img/mezcladora.png");
    int w5a = this->ui->lbl_TextMaquinaMasa1->width();
    int h5a = this->ui->lbl_TextMaquinaMasa1->height();
    this->ui->lbl_TextMaquinaMasa1->setPixmap(pix5a.scaled(w5a,h5a,Qt::KeepAspectRatio));

    QPixmap pix5b (":/Recursos/img/mezcladora.png");
    int w5b = this->ui->lbl_TextMaquinaMasa2->width();
    int h5b = this->ui->lbl_TextMaquinaMasa2->height();
    this->ui->lbl_TextMaquinaMasa2->setPixmap(pix5b.scaled(w5b,h5b,Qt::KeepAspectRatio));

    QPixmap pix6 (":/Recursos/img/mezcladoraChocolate.png");
    int w6 = this->ui->lbl_TextMaquinaChoco->width();
    int h6 = this->ui->lbl_TextMaquinaChoco->height();
    this->ui->lbl_TextMaquinaChoco->setPixmap(pix6.scaled(w6,h6,Qt::KeepAspectRatio));

    QPixmap pix7 (":/Recursos/img/banda.png");
    int w7 = this->ui->lbl_TextBandaMasa->width();
    int h7 = this->ui->lbl_TextBandaMasa->height();
    this->ui->lbl_TextBandaMasa->setPixmap(pix7.scaled(w7,h7,Qt::KeepAspectRatio));

    QPixmap pix7b (":/Recursos/img/banda.png");
    int w7b = this->ui->lbl_TextBandaChoco->width();
    int h7b = this->ui->lbl_TextBandaChoco->height();
    this->ui->lbl_TextBandaChoco->setPixmap(pix7b.scaled(w7b,h7b,Qt::KeepAspectRatio));

    QPixmap pix8 (":/Recursos/img/ensambladora.png");
    int w8 = this->ui->lbl_MaquinaEnsambladora->width();
    int h8 = this->ui->lbl_MaquinaEnsambladora->height();
    this->ui->lbl_MaquinaEnsambladora->setPixmap(pix8.scaled(w8,h8,Qt::KeepAspectRatio));

    QPixmap pixbandaEnsHorno (":/Recursos/img/banda.png");
    int wEH = this->ui->lbl_TextBandaTransportadora->width();
    int hEH = this->ui->lbl_TextBandaTransportadora->height();
    this->ui->lbl_TextBandaTransportadora->setPixmap(pixbandaEnsHorno.scaled(wEH,hEH,Qt::KeepAspectRatio));

    QPixmap pix9 (":/Recursos/img/horno.png");
    int w9 = this->ui->lbl_Horno->width();
    int h9 = this->ui->lbl_Horno->height();
    this->ui->lbl_Horno->setPixmap(pix9.scaled(w9,h9,Qt::KeepAspectRatio));

    QPixmap pix10 (":/Recursos/img/banda.png");
    int w10 = this->ui->lbl_Supervisores->width();
    int h10 = this->ui->lbl_Supervisores->height();
    this->ui->lbl_Supervisores->setPixmap(pix10.scaled(w10,h10,Qt::KeepAspectRatio));

    QPixmap pixS1 (":/Recursos/img/supervisor.png");
    int wS1 = this->ui->lblSup1->width();
    int hS1 = this->ui->lblSup1->height();
    this->ui->lblSup1->setPixmap(pixS1.scaled(wS1,hS1,Qt::KeepAspectRatio));

    QPixmap pixS2 (":/Recursos/img/supervisor.png");
    int wS2 = this->ui->lblSup2->width();
    int hS2 = this->ui->lblSup2->height();
    this->ui->lblSup2->setPixmap(pixS2.scaled(wS2,hS2,Qt::KeepAspectRatio));

    QPixmap pix11 (":/Recursos/img/empacadora.png");
    int w11 = this->ui->lbl_imgEmpacadora->width();
    int h11 = this->ui->lbl_imgEmpacadora->height();
    this->ui->lbl_imgEmpacadora->setPixmap(pix11.scaled(w11,h11,Qt::KeepAspectRatio));

    QPixmap pix12 (":/Recursos/img/almacen1.png");
    int w12 = this->ui->lbl_imgAlmacen1->width();
    int h12 = this->ui->lbl_imgAlmacen1->height();
    this->ui->lbl_imgAlmacen1->setPixmap(pix12.scaled(w12,h12,Qt::KeepAspectRatio));

    QPixmap pix13 (":/Recursos/img/storage.png");
    int w13 = this->ui->lbl_imgAlmacenFinal->width();
    int h13 = this->ui->lbl_imgAlmacenFinal->height();
    this->ui->lbl_imgAlmacenFinal->setPixmap(pix13.scaled(w13,h13,Qt::KeepAspectRatio));

}
VentanaPrincipal::~VentanaPrincipal(){
    delete ui;
}
void VentanaPrincipal::on_btnIniciar_clicked(){
    this->pausa=false;
    this->corriendo=true;

    if (this->hiloPlanificador==NULL){//Es solo para ver si ya se inicio antes
        this->ui->radioButtonEncenderMaquina1->setChecked(true);
        this->ui->radioButtonEncenderMaquina2->setChecked(true);
        this->ui->radioButtonEncenderMaquina3->setChecked(true);
        this->ui->radioButtonEncenderEnsambladora->setChecked(true);
        this->ui->radioButtonEncenderHorno->setChecked(true);

        this->hiloPlanificador = new hilo_planificador();
        this->hiloMaquinaMasa1 = new hilo_maquinaMasa1();//cambiar nombre de la clase porque al final se usa la misma pero con
        this->hiloMaquinaMasa2 = new hilo_maquinaMasa1();
        this->hiloMaquinaChoco = new hilo_maquinaMasa1();
        this->hiloCarrito = new hilo_carrito();
        this->hiloMaquinaEnsambladora=new hilo_MaquinaEnsambladora();
        this->hiloHorno=new hilo_Horno();
        this->hiloSupervisores=new hilo_Supervisores();
        this->hiloEmpacadora=new hilo_Empacadora;

        this->hiloPlanificador->__init__(this->punteros->planificador,this->ui->lblCantidadGalletas,this->ui->lblMasa,this->ui->lblChoco);
        this->hiloMaquinaMasa1->__init__(this->punteros->maquinaMasa1,this->ui->lbl_MaquinaMasa1Procesada,this->ui->lbl_MaquinaMasa1EnProceso,this->ui->lbl_BandaTMasaActual,this->ui->lbl_BantaTMasaMax);
        this->hiloMaquinaMasa1->tabla=this->ui->tableWidget;
        this->hiloMaquinaMasa2->__init__(this->punteros->maquinaMasa2,this->ui->lbl_MaquinaMasa2Procesada,this->ui->lbl_MaquinaMasa2EnProceso,this->ui->lbl_BandaTMasaActual,this->ui->lbl_BantaTMasaMax);
        this->hiloMaquinaMasa2->tabla=this->ui->tableWidget;
        this->hiloMaquinaChoco->__init__(this->punteros->maquinaChocolate,this->ui->lbl_MaquinaChocoProcesada,this->ui->lbl_MaquinaChocoEnProceso,this->ui->lbl_BandaTChocoActual,this->ui->lbl_BandaTChocoMax);
        this->hiloMaquinaChoco->tabla=this->ui->tableWidget;
        this->hiloCarrito->__init__(this->punteros->carrito);
        this->hiloCarrito->tabla=this->ui->tableWidget;//tabla cola almacen
        this->hiloMaquinaEnsambladora->__init__(this->punteros->maquinaEnsambladora,this->ui->lbl_EnsambladoraProducida,this->ui->lbl_BandaTEnsambladoraActual,this->ui->lbl_BandaTEnsambladoraMax);
        this->hiloHorno->__init__(this->punteros->horno,this->ui->lbl_actualHorno,this->ui->lbl_horneadasHorno,this->ui->lbl_actualSupervisores);//orden label actualGalletas, horneadasGalletas, colaSiguienteActual
        this->hiloHorno->tabla=this->ui->tablaBandejas;
        this->hiloSupervisores->__init__(this->punteros->supervisor1,this->punteros->supervisor2,this->ui->lbl_SupervisoresAceptadas,this->ui->lbl_SupervisoresRechazadas,this->ui->lbl_AceptadasSup2,this->ui->lbl_RechazadasSup2);//lblAceptadas,QLabel* lblRechazadas
        this->hiloSupervisores->lbl_Actual=this->ui->lbl_actualSupervisores;
        this->hiloSupervisores->lbl_Max=this->ui->lbl_SupervisoresMax;
        this->hiloEmpacadora->__init__(this->punteros->maquinaEmpacadora);
        this->hiloEmpacadora->tabla=this->ui->tablaTransportes;
        this->hiloEmpacadora->lbl_galletasTotales=this->ui->lbl_TotalGalletas;

        this->hiloPlanificador->start();
        this->hiloMaquinaMasa1->start();
        this->hiloMaquinaMasa2->start();
        this->hiloMaquinaChoco->start();
        this->hiloCarrito->start();
        this->hiloMaquinaEnsambladora->start();
        this->hiloHorno->start();
        this->hiloSupervisores->start();
        this->hiloEmpacadora->start();
    }
}
//Cambiar estado de maquinas manualmente
//Maquina masa 1
void VentanaPrincipal::on_btnCambiarEstadoMaquina1_clicked(){
    if (this->hiloPlanificador!=NULL){
        if (this->ui->radioButtonApagarMaquina1->isChecked()){
            qDebug()<<"APAGAR MAQUINA 1";
            this->hiloMaquinaMasa1->pausa=true;
        }
        if (this->ui->radioButtonEncenderMaquina1->isChecked()){
            qDebug()<<"Encender MAQUINA 1";
            this->hiloMaquinaMasa1->pausa=false;
        }
    }
}

//Maquina masa 2
void VentanaPrincipal::on_btnCambiarEstadoMaquina2_clicked(){
    if (this->hiloPlanificador!=NULL){
        if (this->ui->radioButtonApagarMaquina2->isChecked()){
            qDebug()<<"APAGAR MAQUINA 2";
            this->hiloMaquinaMasa2->pausa=true;
        }
        if (this->ui->radioButtonEncenderMaquina2->isChecked()){
            qDebug()<<"Encender MAQUINA 2";
            this->hiloMaquinaMasa2->pausa=false;
        }
    }
}

//Maquina chocolate
void VentanaPrincipal::on_btnCambiarEstadoMaquina3_clicked(){
    if (this->hiloPlanificador!=NULL){
        if (this->ui->radioButtonApagarMaquina3->isChecked()){
            qDebug()<<"APAGAR MAQUINA 3";
            this->hiloMaquinaChoco->pausa=true;
        }
        if (this->ui->radioButtonEncenderMaquina3->isChecked()){
            qDebug()<<"Encender MAQUINA 3";
            this->hiloMaquinaChoco->pausa=false;
        }
    }
}
//Pausa toda la ejecucion
void VentanaPrincipal::on_btnPausa_clicked(){//FALTAN PAUSAS DE OTROS HILOS

    this->pausa=true;
    this->ui->lbl_PAUSA->setEnabled(true);
    this->ui->lbl_PAUSA->setText("La simulación está en pausa");

    if (this->hiloPlanificador!=NULL){
        //Cambia los radio button
        this->ui->radioButtonApagarMaquina1->setChecked(true);
        this->ui->radioButtonApagarMaquina2->setChecked(true);
        this->ui->radioButtonApagarMaquina3->setChecked(true);
        this->ui->radioButtonApagarEnsambladora->setChecked(true);
        this->ui->radioButtonApagarHorno->setChecked(true);
        //Pausa hilos
        this->hiloMaquinaMasa1->pausa=true;//Maquina masa 1
        this->hiloMaquinaMasa2->pausa=true;//Maquina masa 2
        this->hiloMaquinaChoco->pausa=true;//Maquina chocolate
        this->hiloPlanificador->pausa=true;//Planificador
        this->hiloMaquinaEnsambladora->pausa=true;
        this->hiloCarrito->pausa=true;
        this->hiloEmpacadora->pausa=true;
        this->hiloSupervisores->pausa=true;
        //this->hiloHorno->pausa=true;

    }
}
//Reanudar toda la ejecucion
void VentanaPrincipal::on_btnReanudar_clicked(){//FALTAN PAUSAS DE OTROS HILOS

    this->pausa=false;
    this->ui->lbl_PAUSA->setText("La simulación se ha reanudado");
    this->ui->lbl_PAUSA->setEnabled(false);
    if (this->hiloPlanificador!=NULL){
        this->hiloCarrito->pausa=false;//Carrito
        this->hiloMaquinaMasa1->pausa=false;//Masa 1
        this->hiloMaquinaMasa2->pausa=false;//Masa 2
        this->hiloMaquinaChoco->pausa=false;//Choco
        this->hiloPlanificador->pausa=false;//Planificador
        this->hiloEmpacadora->pausa=false;//Empacadora
        this->hiloMaquinaEnsambladora->pausa=false;//Ensambladora
        this->hiloHorno->pausa=false;//Horno
        this->hiloSupervisores->pausa=false;
        //Cambia los radio button
        this->ui->radioButtonEncenderMaquina1->setChecked(true);
        this->ui->radioButtonEncenderMaquina2->setChecked(true);
        this->ui->radioButtonEncenderMaquina3->setChecked(true);
        this->ui->radioButtonEncenderEnsambladora->setChecked(true);
        this->ui->radioButtonEncenderHorno->setChecked(true);
    }
}
//NO ESTA FUNCIONANDO BIEN
void VentanaPrincipal::on_btnDetener_clicked(){
    if (this->hiloPlanificador!=NULL){
        //Primero detiene los hilos
        //this->hiloHorno->stop();//con este peta
        this->hiloPlanificador->stop();
        this->hiloMaquinaEnsambladora->stop();
        this->hiloMaquinaMasa1->stop();
        this->hiloMaquinaMasa2->stop();
        this->hiloMaquinaChoco->stop();
        this->hiloCarrito->stop();
        this->hiloEmpacadora->stop();
        this->hiloSupervisores->stop();
        this->hiloMaquinaEnsambladora=NULL;
        this->hiloMaquinaMasa1=NULL;
        this->hiloMaquinaMasa2=NULL;
        this->hiloMaquinaChoco=NULL;
        this->hiloCarrito=NULL;
        this->hiloPlanificador=NULL;
        this->hiloEmpacadora=NULL;
        //this->hiloHorno=NULL;
        this->ui->lblCantidadGalletas->setText(QString::number(0));
        this->ui->lblChoco->setText(QString::number(0));
        this->ui->lblMasa->setText(QString::number(0));
        this->ui->lbl_BandaTChocoActual->setText(QString::number(0));
        this->ui->lbl_BandaTChocoMax->setText(QString::number(0));
        this->ui->lbl_BandaTEnsambladoraActual->setText(QString::number(0));
        this->ui->lbl_BandaTEnsambladoraMax->setText(QString::number(0));
        this->ui->lbl_BandaTMasaActual->setText(QString::number(0));
        this->ui->lbl_BantaTMasaMax->setText(QString::number(0));
        this->ui->lbl_EnsambladoraProducida->setText(QString::number(0));
        this->ui->lbl_MaquinaChocoEnProceso->setText(QString::number(0));
        this->ui->lbl_MaquinaChocoProcesada->setText(QString::number(0));
        this->ui->lbl_MaquinaMasa1EnProceso->setText(QString::number(0));
        this->ui->lbl_MaquinaMasa1Procesada->setText(QString::number(0));
        this->ui->lbl_MaquinaMasa2EnProceso->setText(QString::number(0));
        this->ui->lbl_MaquinaMasa2Procesada->setText(QString::number(0));
        this->ui->lbl_actualHorno->setText(QString::number(0));
        this->ui->lbl_horneadasHorno->setText(QString::number(0));
        this->ui->lbl_actualSupervisores->setText(QString::number(0));
        this->ui->lbl_TotalGalletas->setText(QString::number(0));
        Punteros * nuevosPunteros = new Punteros();
        nuevosPunteros->setPunteros();
        this->punteros=nuevosPunteros;
    }else{
        QMessageBox* reply=new QMessageBox();
        reply->setText("La simulación ya está detenida");
        reply->show();
    }
}

void VentanaPrincipal::on_btnCambiarEstadoEnsambladora_clicked(){
    if(this->hiloPlanificador!=NULL){
        if(this->ui->radioButtonApagarEnsambladora->isChecked()){
            qDebug()<<"APAGAR ENSAMBLADORA";
            this->hiloMaquinaEnsambladora->pausa=true;
        }
        if (this->ui->radioButtonEncenderEnsambladora->isChecked()){
            qDebug()<<"ENCENDER ENSAMBLADORA";
            this->hiloMaquinaEnsambladora->pausa=false;
        }
    }
}
void VentanaPrincipal::on_btnCambiarEstadoHorno_clicked(){
    if(this->hiloHorno!=NULL){
        if(this->ui->radioButtonApagarHorno->isChecked()){
            qDebug()<<"APAGAR HORNO";
            this->hiloHorno->pausa=true;
        }
        if (this->ui->radioButtonEncenderHorno->isChecked()){
            qDebug()<<"ENCENDER HORNO";
            this->hiloHorno->pausa=false;
        }
    }
}

