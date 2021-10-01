#include "ventanconfigurar.h"
#include "ui_ventanconfigurar.h"

VentanConfigurar::VentanConfigurar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanConfigurar)
{
    ui->setupUi(this);
}

VentanConfigurar::~VentanConfigurar()
{
    delete ui;
}
