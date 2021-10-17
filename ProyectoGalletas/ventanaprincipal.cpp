#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"


VentanaPrincipal::VentanaPrincipal(QWidget *parent): QMainWindow(parent), ui(new Ui::VentanaPrincipal){
    ui->setupUi(this);
    this->punteros=new Punteros();
    this->punteros->setPunteros();
    this->punteros->paquetes->insertar(15,"Tubos",5);


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

    this->hiloPlanificador = new hilo_planificador();
    this->hiloMaquinaMasa1 = new hilo_maquinaMasa1();//cambiar nombre de la clase porque al final se usa la misma pero con
    this->hiloMaquinaMasa2 = new hilo_maquinaMasa1();//instancias diferentes para los hilos.
    this->hiloMaquinaChoco = new hilo_maquinaMasa1();
    this->hiloCarrito = new hilo_carrito();

    this->hiloPlanificador->__init__(this->punteros->planificador,this->ui->lblCantidadGalletas,this->ui->lblMasa,this->ui->lblChoco);
    this->hiloMaquinaMasa1->__init__(this->punteros->maquinaMasa1,this->ui->lbl_MaquinaMasa1Procesada,this->ui->lbl_MaquinaMasa1EnProceso);
    this->hiloMaquinaMasa2->__init__(this->punteros->maquinaMasa2,this->ui->lbl_MaquinaMasa2Procesada,this->ui->lbl_MaquinaMasa2EnProceso);
    this->hiloMaquinaChoco->__init__(this->punteros->maquinaChocolate,this->ui->lbl_MaquinaChocoProcesada,this->ui->lbl_MaquinaChocoEnProceso);
    this->hiloCarrito->__init__(this->punteros->carrito);

    this->hiloPlanificador->start();
    this->hiloMaquinaMasa1->start();
    this->hiloMaquinaMasa2->start();
    this->hiloMaquinaChoco->start();
    this->hiloCarrito->start();
}



void VentanaPrincipal::on_btnPausa_clicked(){
     this->pausa=true;
}
void VentanaPrincipal::on_btnDetener_clicked(){
    this->corriendo=false;
}

