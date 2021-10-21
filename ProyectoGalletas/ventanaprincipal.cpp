#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"


VentanaPrincipal::VentanaPrincipal(QWidget *parent): QMainWindow(parent), ui(new Ui::VentanaPrincipal){
    ui->setupUi(this);
    this->punteros=new Punteros();
    this->punteros->setPunteros();

    this->hiloPlanificador = NULL;
    this->hiloMaquinaMasa1 = NULL;//cambiar nombre de la clase porque al final se usa la misma pero con
    this->hiloMaquinaMasa2 = NULL;
    this->hiloMaquinaChoco = NULL;
    this->hiloMaquinaEnsambladora=NULL;
    this->hiloCarrito =NULL;
    this->hiloHorno=NULL;

    this->punteros->paquetes->insertar(4,"Paquetito",4);
    this->punteros->paquetes->insertar(16,"Tubos",10);
    this->punteros->paquetes->insertar(10,"Paquetes",5);




//    QMovie *movie = new QMovie("//GIFPlanificador.gif");
//    QLabel *processLabel = new QLabel(this);
//    this->ui->lbl_GIFPlanificador->setMovie(movie);
//    movie->start();

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

        this->hiloPlanificador = new hilo_planificador();
        this->hiloMaquinaMasa1 = new hilo_maquinaMasa1();//cambiar nombre de la clase porque al final se usa la misma pero con
        this->hiloMaquinaMasa2 = new hilo_maquinaMasa1();
        this->hiloMaquinaChoco = new hilo_maquinaMasa1();
        this->hiloCarrito = new hilo_carrito();
        this->hiloMaquinaEnsambladora=new hilo_MaquinaEnsambladora();
        //this->hiloHorno=new hilo_Horno();


        this->hiloPlanificador->__init__(this->punteros->planificador,this->ui->lblCantidadGalletas,this->ui->lblMasa,this->ui->lblChoco);
        this->hiloMaquinaMasa1->__init__(this->punteros->maquinaMasa1,this->ui->lbl_MaquinaMasa1Procesada,this->ui->lbl_MaquinaMasa1EnProceso,this->ui->lbl_BandaTMasaActual,this->ui->lbl_BantaTMasaMax);
        this->hiloMaquinaMasa2->__init__(this->punteros->maquinaMasa2,this->ui->lbl_MaquinaMasa2Procesada,this->ui->lbl_MaquinaMasa2EnProceso,this->ui->lbl_BandaTMasaActual,this->ui->lbl_BantaTMasaMax);
        this->hiloMaquinaChoco->__init__(this->punteros->maquinaChocolate,this->ui->lbl_MaquinaChocoProcesada,this->ui->lbl_MaquinaChocoEnProceso,this->ui->lbl_BandaTChocoActual,this->ui->lbl_BandaTChocoMax);
        this->hiloCarrito->__init__(this->punteros->carrito);
        this->hiloMaquinaEnsambladora->__init__(this->punteros->maquinaEnsambladora,this->ui->lbl_EnsambladoraProducida,this->ui->lbl_BandaTEnsambladoraActual,this->ui->lbl_BandaTEnsambladoraMax);
        //this->hiloHorno->__init__(this->punteros->horno,this->ui->lbl_actualHorno,this->ui->lbl_horneadasHorno,this->ui->lbl_actualSupervisores);//orden label actualGalletas, horneadasGalletas, colaSiguienteActual

        this->hiloPlanificador->start();
        this->hiloMaquinaMasa1->start();
        this->hiloMaquinaMasa2->start();
        this->hiloMaquinaChoco->start();
        this->hiloCarrito->start();
        this->hiloMaquinaEnsambladora->start();
        //this->hiloHorno->start();

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
    if (this->hiloPlanificador!=NULL){
        //Cambia los radio button
        this->ui->radioButtonApagarMaquina1->setChecked(true);
        this->ui->radioButtonApagarMaquina2->setChecked(true);
        this->ui->radioButtonApagarMaquina3->setChecked(true);
        //Pausa hilos
        this->hiloMaquinaMasa1->pausa=true;//Maquina masa 1
        this->hiloMaquinaMasa2->pausa=true;//Maquina masa 2
        this->hiloMaquinaChoco->pausa=true;//Maquina chocolate
        this->hiloPlanificador->pausa=true;//Planificador
        this->hiloMaquinaEnsambladora->pausa=true;
    }


}
//Reanudar toda la ejecucion
void VentanaPrincipal::on_btnReanudar_clicked(){//FALTAN PAUSAS DE OTROS HILOS
    this->pausa=false;
    if (this->hiloPlanificador!=NULL){
        this->hiloMaquinaMasa1->pausa=false;
        this->hiloMaquinaMasa2->pausa=false;
        this->hiloMaquinaChoco->pausa=false;
        this->hiloPlanificador->pausa=false;
        this->hiloPlanificador->pausa=false;
        //Cambia los radio button
        this->ui->radioButtonEncenderMaquina1->setChecked(true);
        this->ui->radioButtonEncenderMaquina2->setChecked(true);
        this->ui->radioButtonEncenderMaquina3->setChecked(true);

    }


}
//NO ESTA FUNCIONANDO BIEN
void VentanaPrincipal::on_btnDetener_clicked(){
    //Primero detiene los hilos
    //this->hiloHorno->stop();//con este peta
    this->hiloMaquinaEnsambladora->stop();
    this->hiloMaquinaMasa1->stop();
    this->hiloMaquinaMasa2->stop();
    this->hiloMaquinaChoco->stop();
    this->hiloCarrito->stop();
    this->hiloPlanificador->stop();
    this->hiloMaquinaEnsambladora->stop();
    //Reinicia toda la mica, se supone jaja
    this->hiloMaquinaEnsambladora=NULL;
    this->hiloMaquinaMasa1=NULL;
    this->hiloMaquinaMasa2=NULL;
    this->hiloMaquinaChoco=NULL;
    this->hiloCarrito=NULL;
    this->hiloPlanificador=NULL;
    this->hiloMaquinaEnsambladora=NULL;
    this->ui->lblCantidadGalletas=0;
    this->ui->lblChoco=0;
    this->ui->lblMasa=0;
    this->ui->lbl_BandaTChocoActual=0;
    this->ui->lbl_BandaTChocoMax=0;
    this->ui->lbl_BandaTEnsambladoraActual=0;
    this->ui->lbl_BandaTEnsambladoraMax=0;
    this->ui->lbl_BandaTMasaActual=0;
    this->ui->lbl_BantaTMasaMax=0;
    this->ui->lbl_EnsambladoraProducida=0;
    this->ui->lbl_Horno=0;
    this->ui->lbl_MaquinaChocoEnProceso=0;
    this->ui->lbl_MaquinaChocoProcesada=0;
    this->ui->lbl_MaquinaEnsambladora=0;
    this->ui->lbl_MaquinaMasa1EnProceso=0;
    this->ui->lbl_MaquinaMasa1Procesada=0;
    this->ui->lbl_MaquinaMasa2EnProceso=0;
    this->ui->lbl_MaquinaMasa2Procesada=0;
    this->ui->lbl_Supervisores=0;
    this->ui->lbl_actualHorno=0;
    this->ui->lbl_horneadasHorno=0;
    this->ui->lbl_actualSupervisores=0;

}

