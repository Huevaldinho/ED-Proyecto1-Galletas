#include "ventanaconfigurar.h"
#include "ui_ventanaconfigurar.h"

VentanaConfigurar::VentanaConfigurar(QWidget *parent) :QMainWindow(parent),ui(new Ui::VentanaConfigurar){
    ui->setupUi(this);

}

VentanaConfigurar::~VentanaConfigurar()
{
    delete ui;
}
