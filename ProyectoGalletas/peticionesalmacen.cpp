#include "peticionesalmacen.h"
#include "ui_peticionesalmacen.h"

PeticionesAlmacen::PeticionesAlmacen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PeticionesAlmacen)
{
    this->tabla=this->ui->tablaUI;
    ui->setupUi(this);
}

PeticionesAlmacen::~PeticionesAlmacen(){
    delete ui;
}
