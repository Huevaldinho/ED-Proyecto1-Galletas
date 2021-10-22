#include "controlador.h"
#include "Punteros.h"
#include "VentanaModificar.h"
#include "ventanaprincipal.h"
#include <QtDebug>


Controlador::Controlador(Punteros * punte,QLabel*eti){
    this->punteros = punte;
    this->punteros->setPunteros();
    //this->punteros->paquetes->insertar(16,"Tubo",250);
    this->etiqueta=eti;



}
void Controlador::iniciarHiloPlanificador(){
    //hilo_planificador * hiloPlanificador = new hilo_planificador();
    //hiloPlanificador->__init__(this->punteros->planificador,this->etiqueta);
    //hiloPlanificador->start();
}
