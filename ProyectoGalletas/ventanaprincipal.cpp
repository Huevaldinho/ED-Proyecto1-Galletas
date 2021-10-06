#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent): QMainWindow(parent), ui(new Ui::VentanaPrincipal){
    ui->setupUi(this);
    /*Ejemplo para agregar un gif
    QMovie *movie = new QMovie("D:/OneDrive - Estudiantes ITCR/Downloads/ajax-loader.gif");
    QLabel *processLabel = new QLabel(this);
    processLabel->setMovie(movie);
    movie->start();
    */
}

VentanaPrincipal::~VentanaPrincipal(){
    delete ui;
}

