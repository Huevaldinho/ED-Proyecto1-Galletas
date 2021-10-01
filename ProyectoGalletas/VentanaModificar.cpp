#include "VentanaModificar.h"
#include "ui_ventana_agregarpaquete.h"

Ventana_AgregarPaquete::Ventana_AgregarPaquete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ventana_AgregarPaquete)
{
    ui->setupUi(this);
}

Ventana_AgregarPaquete::~Ventana_AgregarPaquete()
{
    delete ui;
}
