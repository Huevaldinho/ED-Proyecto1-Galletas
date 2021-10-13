#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"


VentanaPrincipal::VentanaPrincipal(QWidget *parent): QMainWindow(parent), ui(new Ui::VentanaPrincipal){
    ui->setupUi(this);
    this->punteros=new Punteros();
    this->punteros->setPunteros();
    this->punteros->paquetes->insertar(16,"Tubos",250);


//    QMovie *movie = new QMovie("D:/OneDrive - Estudiantes ITCR/Downloads/ajax-loader.gif");
//    QLabel *processLabel = new QLabel(this);
//    processLabel->setMovie(movie);
//    movie->start();

}

VentanaPrincipal::~VentanaPrincipal(){
    delete ui;
}

void VentanaPrincipal::on_btnIniciar_clicked()
{
    hilo_planificador * hiloPlanificador = new hilo_planificador();
    hiloPlanificador->__init__(this->punteros->planificador,this->ui->lblCantidadGalletas);
    hiloPlanificador->start();
}

