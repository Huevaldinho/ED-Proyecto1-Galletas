#include "controlador.h"
#include "Punteros.h"
#include "VentanaModificar.h"
#include "ventanaprincipal.h"
#include <QtDebug>


Controlador::Controlador(Punteros * punte){
    this->punteros = punte;
    this->punteros->setPunteros();
    qDebug()<<"EN CONTROLADOR MAQUINAMASA1: "<<&(this->punteros->maquinaMasa1);
    qDebug()<<"DE PLANIFICADOR A MASA 1: "<<&(this->punteros->planificador->maquinaMasa1);
    this->punteros->paquetes->insertar(16,"Tubo",250);



}
void Controlador::iniciarHiloPlanificador(){
    hilo_planificador * hiloPlanificador = new hilo_planificador();
    hiloPlanificador->__init__(this->punteros->planificador);
    hiloPlanificador->start();
}
